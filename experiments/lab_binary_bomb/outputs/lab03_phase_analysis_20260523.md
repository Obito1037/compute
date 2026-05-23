# 实验三二进制炸弹逐关推导记录

生成时间：2026-05-23 01:45:04 +08:00

## 基本信息

- 学号：`U202414558`
- 学号最后一位：`8`
- 编译开关：`-D U8`
- 目标文件格式：`phases.o` 为 ELF 64-bit x86-64 relocatable object。
- 最终运行证据：`outputs/lab03_final_run_20260523.txt`
- GDB 断点证据：`outputs/lab03_gdb_breakpoints_20260523.txt`

## 最终输入

```text
U202414558
Computer System Foundation
8 5 14 20 35 56
5 789
14 7
mfcdhg
2 5 6 3 1 4
```

## Phase 1

`phase_1` 读取 `studentid[9]`，即学号最后一位 `8`，计算 `special + 50 * 8` 处的字符串，并调用 `strings_not_equal` 与输入比较。

`.data` 中 `special+400` 对应字符串：

```text
Computer System Foundation
```

GDB 证据显示输入字符串和 `special+400` 均为 `Computer System Foundation`。

## Phase 2

`phase_2` 调用 `read_six_numbers` 读取 6 个整数，要求：

- 第 1 个数等于 `studentid[9] - '0'`，即 `8`。
- 第 2 个数等于 `studentid[8] - '0'`，即 `5`。
- 从第 3 个数开始满足 `a[i] = a[i-1] + a[i-2] + 1`。

因此得到：

```text
8 5 14 20 35 56
```

GDB 在 `phase_2` 解析后记录的 6 个整数为 `8, 5, 14, 20, 35, 56`。

## Phase 3

`phase_3` 用 `%d %d` 读取两个整数。第 1 个整数必须等于 `studentid[8] - '0'`，即 `5`。随后进入 switch/jump table，case 5 将期望值设置为 `0x315`，十进制为 `789`，并与第 2 个整数比较。

输入为：

```text
5 789
```

GDB 记录第 1 个整数为 `5`，第 2 个整数为 `789`。

## Phase 4

`phase_4` 用 `%d %d` 读取两个整数。第 1 个整数必须在 `[0, 14]` 范围内，随后调用：

```text
func4(first, 0, 14)
```

函数 `func4` 是二分递归编码函数，目标返回值为 `7`，且第 2 个整数也必须等于 `7`。当第 1 个整数为 `14` 时，递归路径连续走右分支，返回值为 `7`。

输入为：

```text
14 7
```

GDB 记录 `func4` 返回值 `eax = 7`，两个输入分别为 `14` 和 `7`。

## Phase 5

`phase_5` 要求输入字符串长度为 6，并将每个字符的低 4 位作为索引访问表：

```text
maduiersnfotvbyl
```

目标字符串为：

```text
bruins
```

各目标字符的索引为：

| 目标字符 | 索引 |
|---|---:|
| b | 13 |
| r | 6 |
| u | 3 |
| i | 4 |
| n | 8 |
| s | 7 |

选择低 4 位分别为 `d, 6, 3, 4, 8, 7` 的可打印字符，得到输入：

```text
mfcdhg
```

GDB 记录该输入转换后的字符串为 `bruins`。

## Phase 6

`phase_6` 读取 6 个互不重复且范围为 1 到 6 的整数。每个整数表示从链表头开始取第几个节点，随后按输入顺序重排链表，要求重排后节点 value 单调不增。

原链表节点值：

| 位置 | 节点 | value |
|---:|---|---:|
| 1 | node1 | 281 |
| 2 | node2 | 907 |
| 3 | node3 | 322 |
| 4 | node4 | 121 |
| 5 | node5 | 824 |
| 6 | node6 | 528 |

按 value 从大到小排列的位置为：

```text
2 5 6 3 1 4
```

GDB 记录重排后的节点值依次为 `907, 824, 528, 322, 281, 121`，满足单调不增。
