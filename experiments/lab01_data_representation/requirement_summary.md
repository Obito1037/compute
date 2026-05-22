# 实验一 requirement_summary

## 实验名称

数据的表示和等效运算。

## 要求来源

- 原始任务书：`original_materials/requirements/2026年_计算机系统基础_实验任务书_1_数据表示和等效运算.docx`
- 解析文本：`original_materials/parsed_text/0_2026年_计算机系统基础_实验任务书_1_数据表示和等效运算.docx.txt`
- 源码材料：`original_materials/extracted/lab01_data_representation/lab1/`
- 实验工作目录：`experiments/lab01_data_representation/`

## 实验目的与要求

1. 熟练掌握 Visual Studio 2019/2022/2023 程序开发平台的基本用法，包括编译、链接和调试。
2. 熟悉数据在内存中的表示形式。
3. 熟悉地址计算方法和地址的内存转换。
4. 使用移位、按位与、按位或、按位非、按位异或等常见位运算，实现若干表达式的等效运算。

## 实验内容概览

实验一包含两个主任务：

1. 数据存放的压缩与解压编程。
2. 编写并验证位运算程序。

## 任务 1：数据存放的压缩与解压编程

### 已给数据结构

任务书给出 `student` 结构和两个结构数组变量 `beforecompress[N]`、`decompress[N]`，其中 `N=5`。

```c
struct student {
    char  name[8];
    short age;
    float score;
    char  remark[200];
};
```

### 任务目标

1. 将 `beforecompress[N]` 中的信息依次紧凑存放到字符数组 `message` 中。
2. 从 `message` 解压缩到结构数组 `decompress[N]` 中。
3. 打印压缩前、解压后的学生信息。
4. 打印压缩前和压缩后的数据长度。
5. 输出 `message` 前 40 个字节的十六进制内容，并与调试器内存窗口观察结果比较。
6. 分析第 0 个学生 `score` 的浮点数编码，并与内存表示比较。
7. 分析结构数组元素、字符串数组、`short` 类型、`float` 类型在内存中的存放规律。

### 压缩函数接口

任务书指定两个压缩函数：

```c
int pack_student_bytebybyte(student* s, int sno, char *buf);
int pack_student_whole(student* s, int sno, char *buf);
```

要求：

1. `s` 是待压缩数组的起始地址。
2. `sno` 是压缩人数。
3. `buf` 是压缩存储区首地址。
4. 返回值是压缩后的字节数。
5. `pack_student_bytebybyte` 必须逐字节向 `buf` 写数据。
6. `pack_student_whole` 对 `short`、`float` 字段必须使用一条语句整体写入，字符串写入使用 `strcpy`。

### 指定调用方式

1. `beforecompress` 数组前 `N1=2` 个记录必须用 `pack_student_bytebybyte` 完成压缩。
2. 后 `N2=3` 个记录必须用 `pack_student_whole` 完成压缩。
3. 两种压缩函数都只调用 1 次。

### 解压函数接口

任务书指定解压函数：

```c
int restore_student(char *buf, int len, student* s);
```

要求：

1. `buf` 是压缩区域存储区首地址。
2. `len` 是 `buf` 中存放数据的长度。
3. `s` 是存放解压数据的结构数组起始地址。
4. 返回值是解压得到的人数。
5. 解压时不允许使用函数接口之外的信息，也就是不能依赖其他全局变量。

### 当前待确认项

任务书要求“第 0 个人姓名为自己的名字，分数为学号的最后两位”。当前 `config/report_metadata.yaml` 中 `student_name` 和 `student_id` 仍为 `待填写`，因此在正式执行任务 1 前必须由用户确认或更新配置。当前阶段只记录该要求，不填入源码和报告。

## 任务 2：位运算程序

任务书要求按照限制运算符和运算次数完成函数，并用标准实现自动判断结果是否正确。

| 函数 | 功能 | 运算限制/要求 |
|---|---|---|
| `int absVal(int x)` | 返回 `x` 的绝对值 | 仅使用 `! ~ & ^ | + << >>`，运算次数不超过 10 次 |
| `int negate(int x)` | 不使用负号实现 `-x` | 用标准函数 `return -x;` 判断 |
| `int bitAnd(int x, int y)` | 仅用 `~` 和 `|` 实现 `&` | 用 `x & y` 判断 |
| `int bitOr(int x, int y)` | 仅用 `~` 和 `&` 实现 `|` | 用标准函数判断 |
| `int bitXor(int x, int y)` | 仅用 `~` 和 `&` 实现 `^` | 用标准函数判断 |
| `int isTmax(int x)` | 判断是否为最大正整数 `0x7fffffff` | 只能使用 `! ~ & ^ | +` |
| `int bitCount(int x)` | 统计二进制表示中 1 的个数 | 仅使用 `! ~ & ^ | + << >>`，运算次数不超过 40 次 |
| `int bitMask(int highbit, int lowbit)` | 生成从 `lowbit` 到 `highbit` 全为 1 的掩码 | 仅使用 `! ~ & ^ | + << >>`，运算次数不超过 16 次 |
| `int addOK(int x, int y)` | 当 `x+y` 产生溢出时返回 1，否则返回 0 | 仅使用 `! ~ & ^ | + << >>`，运算次数不超过 20 次 |
| `int byteSwap(int x, int n, int m)` | 交换 `x` 的第 `n` 个字节和第 `m` 个字节 | `n,m` 取值为 0 到 3，运算次数不超过 25 次 |
| `int bang(int x)` | 实现逻辑非，`x=0` 返回 1，否则返回 0 | 不能使用 `!`，运算次数不超过 12 次 |
| `int bitParity(int x)` | 当 `x` 有奇数个二进制位 1 时返回 1，否则返回 0 | 仅使用 `! ~ & ^ | + << >>`，运算次数不超过 20 次 |

## 需要保存的证据

1. 实验环境记录：Windows/Visual Studio 版本、编译配置、调试方式。
2. 编译和运行命令或 Visual Studio 操作记录。
3. 程序运行输出：压缩前数据、解压后数据、压缩前后长度、位运算测试结果。
4. `message` 前 40 字节十六进制输出。
5. 调试器内存窗口截图或可替代的完整调试记录。
6. 第 0 个学生 `score` 的 IEEE 754 编码分析证据。
7. 结构数组、字符串数组、`short`、`float` 内存布局分析证据。
8. 关键源码改动说明和函数实现摘录。
9. 错误与修复记录；若实验顺利，也要记录易错点和验证方式。

## 实验一执行前检查清单

1. 确认 `config/report_metadata.yaml` 中 `student_name` 和 `student_id` 已由用户确认，或用户明确给出实验输入值。
2. 确认使用的 Visual Studio 版本，或检查本机可用版本后再由用户确认。
3. 只在 `experiments/lab01_data_representation/src/` 下操作源码，不修改 `original_materials/`。
4. 执行前先记录环境到 `evidence/environment.md`。
5. 每个关键编译、运行、调试动作写入 `evidence/commands.md`。
6. 运行输出保存到 `outputs/`。
7. 截图或调试记录登记到 `evidence/screenshots_index.md`。
8. 所有准备写入报告的结论登记到 `evidence/report_claims_checklist.md` 和 `evidence/evidence_manifest.md`。
