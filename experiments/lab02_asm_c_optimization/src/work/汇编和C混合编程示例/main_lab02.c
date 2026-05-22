#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <windows.h>

#define DISPLAY_STUDENTS_NUM 10
#define BENCH_STUDENTS_NUM 256
#define AVG_REPEAT 20000
#define SORT_REPEAT 200

typedef struct student {
    char sname[8];
    char sid[11];
    short scores[8];
    short average;
} student;

typedef void (*average_func)(student *items, int num);
typedef void (*sort_func)(student *items, int num);

void computeAverageScore_asm(student *items, int num);
void computeAverageScore_asm_opt(student *items, int num);

static void set_ascii(char *dest, size_t size, const char *src)
{
    memset(dest, 0, size);
    strncpy(dest, src, size - 1);
}

static void set_student0_name(student *item)
{
    static const unsigned char name_gbk[] = {0xD5, 0xC5, 0xBC, 0xD2, 0xC1, 0xBA, 0x00};

    memset(item->sname, 0, sizeof(item->sname));
    memcpy(item->sname, name_gbk, sizeof(name_gbk));
}

static void print_name_bytes(const student *item)
{
    int i;

    for (i = 0; i < (int)sizeof(item->sname); ++i) {
        printf("%02X%s", (unsigned char)item->sname[i], i + 1 == (int)sizeof(item->sname) ? "" : " ");
    }
}

static void init_students(student *items, int num)
{
    static const char *names[] = {
        "li", "wang", "chen", "zhao", "qian", "sun", "zhou", "wu", "zheng"
    };
    int i;
    int j;

    for (i = 0; i < num; ++i) {
        memset(&items[i], 0, sizeof(items[i]));
        if (i == 0) {
            set_student0_name(&items[i]);
            set_ascii(items[i].sid, sizeof(items[i].sid), "U202414558");
        } else {
            set_ascii(items[i].sname, sizeof(items[i].sname), names[(i - 1) % 9]);
            sprintf(items[i].sid, "U202414%03d", i);
        }

        for (j = 0; j < 8; ++j) {
            items[i].scores[j] = (short)(55 + ((i * 17 + j * 11 + 23) % 46));
        }
        items[i].average = 0;
    }
}

static void display_students(const char *title, const student *items, int num)
{
    int i;
    int j;

    printf("\n%s\n", title);
    printf("idx name_bytes              sid        scores                         average\n");
    for (i = 0; i < num; ++i) {
        printf("%2d  ", i);
        print_name_bytes(&items[i]);
        printf("  %-10s", items[i].sid);
        for (j = 0; j < 8; ++j) {
            printf(" %3d", items[i].scores[j]);
        }
        printf("    %3d\n", items[i].average);
    }
}

void computeAverageScore_c(student *items, int num)
{
    int i;
    int j;

    for (i = 0; i < num; ++i) {
        int sum = 0;
        for (j = 0; j < 8; ++j) {
            sum += items[i].scores[j];
        }
        items[i].average = (short)(sum / 8);
    }
}

void sortByAverage_bubble(student *items, int num)
{
    int i;
    int j;

    for (i = 0; i < num - 1; ++i) {
        for (j = 0; j < num - 1 - i; ++j) {
            if (items[j].average < items[j + 1].average) {
                student tmp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = tmp;
            }
        }
    }
}

static void quicksort_students(student *items, int left, int right)
{
    int i = left;
    int j = right;
    short pivot = items[(left + right) / 2].average;

    while (i <= j) {
        while (items[i].average > pivot) {
            ++i;
        }
        while (items[j].average < pivot) {
            --j;
        }
        if (i <= j) {
            student tmp = items[i];
            items[i] = items[j];
            items[j] = tmp;
            ++i;
            --j;
        }
    }

    if (left < j) {
        quicksort_students(items, left, j);
    }
    if (i < right) {
        quicksort_students(items, i, right);
    }
}

void sortByAverage_quick(student *items, int num)
{
    if (num > 1) {
        quicksort_students(items, 0, num - 1);
    }
}

static int checksum_averages(const student *items, int num)
{
    int i;
    int sum = 0;

    for (i = 0; i < num; ++i) {
        sum += items[i].average * (i + 1);
    }
    return sum;
}

static int verify_average_function(const char *name, average_func func)
{
    student expected[DISPLAY_STUDENTS_NUM];
    student actual[DISPLAY_STUDENTS_NUM];
    int i;

    init_students(expected, DISPLAY_STUDENTS_NUM);
    memcpy(actual, expected, sizeof(actual));

    computeAverageScore_c(expected, DISPLAY_STUDENTS_NUM);
    func(actual, DISPLAY_STUDENTS_NUM);

    for (i = 0; i < DISPLAY_STUDENTS_NUM; ++i) {
        if (expected[i].average != actual[i].average) {
            printf("VERIFY average %-24s MISMATCH at %d: expected=%d actual=%d\n",
                name, i, expected[i].average, actual[i].average);
            return 0;
        }
    }

    printf("VERIFY average %-24s PASS checksum=%d\n", name, checksum_averages(actual, DISPLAY_STUDENTS_NUM));
    return 1;
}

static int verify_sorted_descending(const student *items, int num)
{
    int i;

    for (i = 1; i < num; ++i) {
        if (items[i - 1].average < items[i].average) {
            return 0;
        }
    }
    return 1;
}

static double ticks_to_ms(LONGLONG ticks, LARGE_INTEGER frequency)
{
    return (double)ticks * 1000.0 / (double)frequency.QuadPart;
}

static double measure_average(const char *name, average_func func, student *items, int num, int repeat)
{
    LARGE_INTEGER start;
    LARGE_INTEGER finish;
    LARGE_INTEGER frequency;
    int r;
    int checksum;
    double ms;

    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start);
    for (r = 0; r < repeat; ++r) {
        func(items, num);
    }
    QueryPerformanceCounter(&finish);

    checksum = checksum_averages(items, num);
    ms = ticks_to_ms(finish.QuadPart - start.QuadPart, frequency);
    printf("TIME average %-24s n=%d repeat=%d ms=%.3f checksum=%d\n",
        name, num, repeat, ms, checksum);
    return ms;
}

static double measure_sort(const char *name, sort_func func, const student *source, student *work, int num, int repeat)
{
    LARGE_INTEGER start;
    LARGE_INTEGER finish;
    LARGE_INTEGER frequency;
    LONGLONG total_ticks = 0;
    int r;
    int checksum = 0;
    double ms;

    QueryPerformanceFrequency(&frequency);
    for (r = 0; r < repeat; ++r) {
        memcpy(work, source, (size_t)num * sizeof(work[0]));
        QueryPerformanceCounter(&start);
        func(work, num);
        QueryPerformanceCounter(&finish);
        total_ticks += finish.QuadPart - start.QuadPart;
    }

    checksum = checksum_averages(work, num);
    ms = ticks_to_ms(total_ticks, frequency);
    printf("TIME sort    %-24s n=%d repeat=%d ms=%.3f checksum=%d sorted=%s\n",
        name, num, repeat, ms, checksum, verify_sorted_descending(work, num) ? "PASS" : "MISMATCH");
    return ms;
}

int main(void)
{
    student display_items[DISPLAY_STUDENTS_NUM];
    student sorted_items[DISPLAY_STUDENTS_NUM];
    student bench_source[BENCH_STUDENTS_NUM];
    student bench_work[BENCH_STUDENTS_NUM];
    double t_avg_c;
    double t_avg_asm;
    double t_avg_asm_opt;
    double t_sort_bubble;
    double t_sort_quick;

    printf("LAB02 ASM/C mixed programming and optimization\n");
    printf("struct student size=%u offset scores=%u offset average=%u\n",
        (unsigned)sizeof(student),
        (unsigned)offsetof(student, scores),
        (unsigned)offsetof(student, average));
    printf("student[0] name is stored as GBK/CP936 bytes for Zhang Jialiang: D5 C5 BC D2 C1 BA 00\n");

    init_students(display_items, DISPLAY_STUDENTS_NUM);
    display_students("Before average and sorting", display_items, DISPLAY_STUDENTS_NUM);

    computeAverageScore_c(display_items, DISPLAY_STUDENTS_NUM);
    memcpy(sorted_items, display_items, sizeof(sorted_items));
    sortByAverage_bubble(sorted_items, DISPLAY_STUDENTS_NUM);
    display_students("After C average and bubble sorting", sorted_items, DISPLAY_STUDENTS_NUM);

    verify_average_function("ASM baseline", computeAverageScore_asm);
    verify_average_function("ASM optimized", computeAverageScore_asm_opt);

    init_students(bench_source, BENCH_STUDENTS_NUM);
    t_avg_c = measure_average("C baseline", computeAverageScore_c, bench_source, BENCH_STUDENTS_NUM, AVG_REPEAT);

    init_students(bench_source, BENCH_STUDENTS_NUM);
    t_avg_asm = measure_average("ASM baseline idiv", computeAverageScore_asm, bench_source, BENCH_STUDENTS_NUM, AVG_REPEAT);

    init_students(bench_source, BENCH_STUDENTS_NUM);
    t_avg_asm_opt = measure_average("ASM optimized shift", computeAverageScore_asm_opt, bench_source, BENCH_STUDENTS_NUM, AVG_REPEAT);

    init_students(bench_source, BENCH_STUDENTS_NUM);
    computeAverageScore_c(bench_source, BENCH_STUDENTS_NUM);
    t_sort_bubble = measure_sort("C bubble baseline", sortByAverage_bubble, bench_source, bench_work, BENCH_STUDENTS_NUM, SORT_REPEAT);
    t_sort_quick = measure_sort("C quicksort optimized", sortByAverage_quick, bench_source, bench_work, BENCH_STUDENTS_NUM, SORT_REPEAT);

    printf("SUMMARY average_ms C=%.3f ASM=%.3f ASM_OPT=%.3f\n", t_avg_c, t_avg_asm, t_avg_asm_opt);
    printf("SUMMARY sort_ms bubble=%.3f quicksort=%.3f\n", t_sort_bubble, t_sort_quick);

    return 0;
}
