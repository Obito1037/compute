# lab_binary_bomb 报告正文材料库

本文件用于沉淀可写入正式总报告正文的内容。Codex 生成报告前必须先读取本文件。

## 1. 实验目的与任务拆解

| 任务 | 说明 | 对应证据 |
|---|---|---|
| 编译二进制炸弹 | 使用 `gcc -g -o bomb -D U8 bomb.c support.c phases.o` | E004 |
| 静态分析 | 使用 `nm`、`objdump -d -M intel`、`.rodata` 和 `.data` 转储分析各关逻辑 | E005、E006、E007、E008 |
| 动态调试 | 用 GDB 在各 phase 的关键位置断点，观察输入、寄存器、栈和链表 | E011、E012 |
| 推导六关输入 | 从反汇编、数据段和 GDB 记录推导 phase 1 到 phase 6 输入 | E013 |
| 最终验证 | 使用完整输入文件运行炸弹程序并通过六关 | E009、E010 |

## 2. 关键原理说明

- 二进制炸弹拆除的核心不是猜字符串，而是从机器级代码还原条件判断。
- 字符串关卡可通过数据段和字符串比较函数定位目标字符串。
- 数字关卡可通过 `sscanf` 参数位置、比较指令和跳转表推导约束。
- 递归关卡需要理解函数参数、返回值编码和分支路径。
- 链表关卡需要结合数据段节点布局和运行时指针重排，确认排序约束。

## 3. 实验设计思路

- 先根据任务书和已确认学号末位确定 `-D U8`。
- 用 WSL Ubuntu 下的 GCC 构建带调试信息的 `bomb`。
- 用 `nm` 定位 `phase_1` 到 `phase_6`、`special`、`array.0` 和链表节点符号。
- 用 `objdump` 保存完整反汇编和数据段转储。
- 用 GDB 断点确认关键运行时状态，避免只靠静态猜测。
- 用最终输入文件完整运行，保存六关通过输出。

## 4. 实验过程材料

| 步骤 | 操作 | 命令/工具 | 输出/截图 | 分析说明 |
|---|---|---|---|---|
| 1 | 编译 | `gcc -g -o bomb -D U8 bomb.c support.c phases.o` | `outputs/lab03_gcc_build_20260523.txt` | `U8` 来自学号末位 |
| 2 | 查看目标信息 | `file`、`nm`、`readelf` | `outputs/lab03_nm_20260523.txt` | 确认 ELF64 和 phase 符号 |
| 3 | 反汇编 | `objdump -d -M intel` | `outputs/lab03_objdump_intel_20260523.txt` | 分析控制流和比较条件 |
| 4 | 转储数据段 | `objdump -s -j .rodata`、`objdump -s -j .data` | `outputs/lab03_rodata_20260523.txt`、`outputs/lab03_data_20260523.txt` | 查找字符串表、查找表和链表节点 |
| 5 | GDB 验证 | `gdb -q -x ...` | `outputs/lab03_gdb_breakpoints_20260523.txt` | 记录关键断点证据 |
| 6 | 最终运行 | `./bomb ../../outputs/lab03_answers_20260523.txt` | `outputs/lab03_final_run_20260523.txt` | 六关全部通过 |

## 5. 关键代码/汇编/调试/ELF 分析材料

| 片段编号 | 文件/命令 | 片段说明 | 可写入报告的分析 |
|---|---|---|---|
| K001 | `outputs/lab03_objdump_intel_20260523.txt` / `phase_1` | 使用学号末位定位 `special + 50 * digit` | phase 1 字符串来自数据段表 |
| K002 | `outputs/lab03_objdump_intel_20260523.txt` / `phase_2` | 检查前两项和递推公式 | phase 2 为学号后两位加递推 |
| K003 | `outputs/lab03_objdump_intel_20260523.txt` / `phase_3` | `%d %d` 和 jump table | phase 3 第一个数为学号倒数第二位，第二个数来自 case |
| K004 | `outputs/lab03_objdump_intel_20260523.txt` / `func4`、`phase_4` | 二分递归返回值 | phase 4 输入 `14 7` |
| K005 | `outputs/lab03_data_20260523.txt`、`outputs/lab03_rodata_20260523.txt` / `phase_5` | 低 4 位查表 | `mfcdhg` 转换为 `bruins` |
| K006 | `outputs/lab03_gdb_breakpoints_20260523.txt` / `phase_6` | 链表节点 value 降序 | 输入 `2 5 6 3 1 4` |

## 6. 结果分析材料

- 最终输出六关全部 passed，说明输入文件已经真实通过程序验证。
- GDB 输出和静态反汇编互相支撑，避免只展示最终答案。
- phase 6 的重排链表值为 `907, 824, 528, 322, 281, 121`，满足代码中的 `>=` 检查。

## 7. 实验小结素材

- 初次 GDB 脚本里 phase 1 期望串地址表达式不严谨，修正为 `((char *)&special)+400` 后重跑。
- 只输入学号会在 Gate 1 因 EOF 退出，这不是爆炸，需要完整输入文件验证。
- 手工拆弹过程中要区分静态推导和动态验证；最终答案必须由运行输出和 GDB 记录共同支撑。
