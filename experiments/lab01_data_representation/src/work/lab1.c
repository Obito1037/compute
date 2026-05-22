#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab1.h"

#ifdef LAB1_MEMORY_PROBE
#include <windows.h>
#endif

#define N 5
#define N1 2
#define N2 3
#define MESSAGE_SIZE 1200

static student_t beforecompress[N];
static student_t decompress[N];
static char message[MESSAGE_SIZE];

static void copy_bytes(char *dst, const void *src, int len)
{
    const unsigned char *p = (const unsigned char *)src;
    int i;

    for (i = 0; i < len; ++i) {
        dst[i] = (char)p[i];
    }
}

static int write_string_bytebybyte(char *buf, const char *text)
{
    int i = 0;

    do {
        buf[i] = text[i];
    } while (text[i++] != '\0');

    return i;
}

int pack_student_bytebybyte(student_t *s, int sno, char *buf)
{
    int i;
    int offset = 0;

    for (i = 0; i < sno; ++i) {
        offset += write_string_bytebybyte(buf + offset, s[i].name);
        copy_bytes(buf + offset, &s[i].age, (int)sizeof(s[i].age));
        offset += (int)sizeof(s[i].age);
        copy_bytes(buf + offset, &s[i].score, (int)sizeof(s[i].score));
        offset += (int)sizeof(s[i].score);
        offset += write_string_bytebybyte(buf + offset, s[i].remark);
    }

    return offset;
}

int pack_student_whole(student_t *s, int sno, char *buf)
{
    int i;
    int offset = 0;

    for (i = 0; i < sno; ++i) {
        strcpy(buf + offset, s[i].name);
        offset += (int)strlen(s[i].name) + 1;

        *(short *)(buf + offset) = s[i].age;
        offset += (int)sizeof(s[i].age);

        *(float *)(buf + offset) = s[i].score;
        offset += (int)sizeof(s[i].score);

        strcpy(buf + offset, s[i].remark);
        offset += (int)strlen(s[i].remark) + 1;
    }

    return offset;
}

int restore_student(char *buf, int len, student_t *s)
{
    int count = 0;
    int offset = 0;

    while (offset < len) {
        strcpy(s[count].name, buf + offset);
        offset += (int)strlen(buf + offset) + 1;

        s[count].age = *(short *)(buf + offset);
        offset += (int)sizeof(s[count].age);

        s[count].score = *(float *)(buf + offset);
        offset += (int)sizeof(s[count].score);

        strcpy(s[count].remark, buf + offset);
        offset += (int)strlen(buf + offset) + 1;

        ++count;
    }

    return count;
}

int absVal_standard(int x) { return (x < 0) ? -x : x; }
int negate_standard(int x) { return -x; }
int bitAnd_standard(int x, int y) { return x & y; }
int bitOr_standard(int x, int y) { return x | y; }
int bitXor_standard(int x, int y) { return x ^ y; }
int isTmax_standard(int x) { return x == 0x7fffffff; }
int bitCount_standard(int x)
{
    unsigned int ux = (unsigned int)x;
    int count = 0;

    while (ux != 0U) {
        count += (int)(ux & 1U);
        ux >>= 1;
    }

    return count;
}
int bitMask_standard(int highbit, int lowbit)
{
    int i;
    int result = 0;

    for (i = lowbit; i <= highbit; ++i) {
        result |= 1 << i;
    }

    return result;
}
int addOK_standard(int x, int y)
{
    int sum = x + y;
    int sx = x >> 31;
    int sy = y >> 31;
    int ss = sum >> 31;

    return (sx == sy) && (sx != ss);
}
int byteSwap_standard(int x, int n, int m)
{
    unsigned int ux = (unsigned int)x;
    unsigned int nshift = (unsigned int)(n << 3);
    unsigned int mshift = (unsigned int)(m << 3);
    unsigned int nb = (ux >> nshift) & 0xffU;
    unsigned int mb = (ux >> mshift) & 0xffU;

    ux &= ~(0xffU << nshift);
    ux &= ~(0xffU << mshift);
    ux |= nb << mshift;
    ux |= mb << nshift;
    return (int)ux;
}
int bang_standard(int x) { return !x; }
int bitParity_standard(int x)
{
    return bitCount_standard(x) & 1;
}

int absVal(int x)
{
    int mask = x >> 31;
    return (x ^ mask) + (mask & 1);
}

int negate(int x)
{
    return ~x + 1;
}

int bitAnd(int x, int y)
{
    return ~(~x | ~y);
}

int bitOr(int x, int y)
{
    return ~(~x & ~y);
}

int bitXor(int x, int y)
{
    return ~(~(x & ~y) & ~(~x & y));
}

int isTmax(int x)
{
    int y = x + 1;
    return !(~(x + y)) & !!y;
}

int bitCount(int x)
{
    int mask1 = 0x55 | (0x55 << 8);
    int mask2 = 0x33 | (0x33 << 8);
    int mask4 = 0x0f | (0x0f << 8);
    int mask8 = 0xff | (0xff << 16);
    int mask16 = 0xff | (0xff << 8);

    mask1 = mask1 | (mask1 << 16);
    mask2 = mask2 | (mask2 << 16);
    mask4 = mask4 | (mask4 << 16);

    x = (x & mask1) + ((x >> 1) & mask1);
    x = (x & mask2) + ((x >> 2) & mask2);
    x = (x & mask4) + ((x >> 4) & mask4);
    x = (x + (x >> 8)) & mask8;
    x = (x + (x >> 16)) & mask16;
    return x;
}

int bitMask(int highbit, int lowbit)
{
    int allones = ~0;
    int high = allones << highbit << 1;
    int low = allones << lowbit;
    return low & ~high;
}

int addOK(int x, int y)
{
    int sum = x + y;
    int same_sign = !((x ^ y) >> 31);
    int diff_sum_sign = (x ^ sum) >> 31;
    return !!(same_sign & diff_sum_sign);
}

int byteSwap(int x, int n, int m)
{
    int nshift = n << 3;
    int mshift = m << 3;
    int nbyte = (x >> nshift) & 0xff;
    int mbyte = (x >> mshift) & 0xff;
    int mask = (0xff << nshift) | (0xff << mshift);
    int cleared = x & ~mask;

    return cleared | (nbyte << mshift) | (mbyte << nshift);
}

int bang(int x)
{
    return ((x | (~x + 1)) >> 31) + 1;
}

int bitParity(int x)
{
    x = x ^ (x >> 16);
    x = x ^ (x >> 8);
    x = x ^ (x >> 4);
    x = x ^ (x >> 2);
    x = x ^ (x >> 1);
    return x & 1;
}

static void init_students(void)
{
    memset(beforecompress, 0, sizeof(beforecompress));
    memset(decompress, 0, sizeof(decompress));
    memset(message, 0, sizeof(message));

    strcpy(beforecompress[0].name, "\xD5\xC5\xBC\xD2\xC1\xBA");
    beforecompress[0].age = 20;
    beforecompress[0].score = 58.0f;
    strcpy(beforecompress[0].remark, "student id U202414558");

    strcpy(beforecompress[1].name, "li");
    beforecompress[1].age = 19;
    beforecompress[1].score = 86.5f;
    strcpy(beforecompress[1].remark, "byte pack test");

    strcpy(beforecompress[2].name, "zhao");
    beforecompress[2].age = 21;
    beforecompress[2].score = 91.0f;
    strcpy(beforecompress[2].remark, "whole pack test");

    strcpy(beforecompress[3].name, "sun");
    beforecompress[3].age = 18;
    beforecompress[3].score = 77.5f;
    strcpy(beforecompress[3].remark, "memory layout");

    strcpy(beforecompress[4].name, "zhou");
    beforecompress[4].age = 22;
    beforecompress[4].score = 64.25f;
    strcpy(beforecompress[4].remark, "restore verify");
}

static void print_name_bytes(const char *label, const char *name)
{
    int i;

    printf("%s", label);
    for (i = 0; name[i] != '\0'; ++i) {
        printf("%02X ", (unsigned char)name[i]);
    }
    printf("00\n");
}

static void print_students(const char *title, const student_t *students, int count)
{
    int i;

    printf("\n%s\n", title);
    printf("index name_bytes age score remark\n");
    for (i = 0; i < count; ++i) {
        printf("%d ", i);
        print_name_bytes("", students[i].name);
        printf("  age=%d score=%.2f remark=%s\n",
            students[i].age, students[i].score, students[i].remark);
    }
}

static void print_first_40_bytes(const char *buf)
{
    int i;

    printf("\nmessage first 40 bytes:\n");
    for (i = 0; i < 40; ++i) {
        printf("%02X", (unsigned char)buf[i]);
        if ((i + 1) % 8 == 0) {
            printf("\n");
        } else {
            printf(" ");
        }
    }
}

static void print_score_encoding(float value)
{
    union {
        float f;
        unsigned int u;
    } bits;
    unsigned int sign;
    unsigned int exponent;
    unsigned int fraction;

    bits.f = value;
    sign = bits.u >> 31;
    exponent = (bits.u >> 23) & 0xffU;
    fraction = bits.u & 0x7fffffU;

    printf("\nscore %.2f IEEE754 single precision:\n", value);
    printf("raw hex: 0x%08X\n", bits.u);
    printf("sign: %u\n", sign);
    printf("exponent: 0x%02X (%u), unbiased=%d\n",
        exponent, exponent, (int)exponent - 127);
    printf("fraction: 0x%06X\n", fraction);
}

static void print_layout_info(void)
{
    printf("\nlayout information:\n");
    printf("sizeof(student_t)=%u\n", (unsigned int)sizeof(student_t));
    printf("offset name=%u\n", (unsigned int)((char *)&beforecompress[0].name - (char *)&beforecompress[0]));
    printf("offset age=%u\n", (unsigned int)((char *)&beforecompress[0].age - (char *)&beforecompress[0]));
    printf("offset score=%u\n", (unsigned int)((char *)&beforecompress[0].score - (char *)&beforecompress[0]));
    printf("offset remark=%u\n", (unsigned int)((char *)&beforecompress[0].remark - (char *)&beforecompress[0]));
    printf("array stride=%u\n", (unsigned int)((char *)&beforecompress[1] - (char *)&beforecompress[0]));
}

static void check_one_arg(const char *name, int (*func)(int), int (*standard)(int), int x)
{
    int actual = func(x);
    int expected = standard(x);

    printf("%s(%d): actual=%d expected=%d %s\n",
        name, x, actual, expected, actual == expected ? "PASS" : "FAIL");
}

static void check_two_arg(const char *name, int (*func)(int, int), int (*standard)(int, int), int x, int y)
{
    int actual = func(x, y);
    int expected = standard(x, y);

    printf("%s(%d,%d): actual=%d expected=%d %s\n",
        name, x, y, actual, expected, actual == expected ? "PASS" : "FAIL");
}

static void check_three_arg(const char *name, int (*func)(int, int, int), int (*standard)(int, int, int), int x, int y, int z)
{
    int actual = func(x, y, z);
    int expected = standard(x, y, z);

    printf("%s(%d,%d,%d): actual=%d expected=%d %s\n",
        name, x, y, z, actual, expected, actual == expected ? "PASS" : "FAIL");
}

static void run_bit_tests(void)
{
    printf("\nbit operation tests:\n");
    check_one_arg("absVal", absVal, absVal_standard, -12345);
    check_one_arg("absVal", absVal, absVal_standard, 12345);
    check_one_arg("negate", negate, negate_standard, 58);
    check_two_arg("bitAnd", bitAnd, bitAnd_standard, 0x5a, 0x33);
    check_two_arg("bitOr", bitOr, bitOr_standard, 0x5a, 0x33);
    check_two_arg("bitXor", bitXor, bitXor_standard, 0x5a, 0x33);
    check_one_arg("isTmax", isTmax, isTmax_standard, 0x7fffffff);
    check_one_arg("isTmax", isTmax, isTmax_standard, -1);
    check_one_arg("bitCount", bitCount, bitCount_standard, 0x12345678);
    check_two_arg("bitMask", bitMask, bitMask_standard, 5, 3);
    check_two_arg("addOK", addOK, addOK_standard, 0x70000000, 0x10000000);
    check_two_arg("addOK", addOK, addOK_standard, 100, 58);
    check_three_arg("byteSwap", byteSwap, byteSwap_standard, 0x12345678, 1, 3);
    check_three_arg("byteSwap", byteSwap, byteSwap_standard, 0xDEADBEEF, 0, 2);
    check_one_arg("bang", bang, bang_standard, 0);
    check_one_arg("bang", bang, bang_standard, 3);
    check_one_arg("bitParity", bitParity, bitParity_standard, 5);
    check_one_arg("bitParity", bitParity, bitParity_standard, 7);
}

int main(void)
{
    int len1;
    int len2;
    int total_len;
    int restored;

    init_students();

    len1 = pack_student_bytebybyte(beforecompress, N1, message);
    len2 = pack_student_whole(beforecompress + N1, N2, message + len1);
    total_len = len1 + len2;
    restored = restore_student(message, total_len, decompress);

#ifdef LAB1_MEMORY_PROBE
    printf("MEMORY_PROBE pid=%lu message_address=%p length=40\n",
        (unsigned long)GetCurrentProcessId(), (void *)message);
    fflush(stdout);
    Sleep(15000);
#endif

    print_students("beforecompress", beforecompress, N);
    print_students("decompress", decompress, restored);

    printf("\noriginal structured length=%u\n", (unsigned int)sizeof(beforecompress));
    printf("compressed length bytebybyte=%d\n", len1);
    printf("compressed length whole=%d\n", len2);
    printf("compressed total length=%d\n", total_len);
    printf("restored count=%d\n", restored);

    print_first_40_bytes(message);
    print_score_encoding(beforecompress[0].score);
    print_layout_info();
    run_bit_tests();

    return 0;
}
