# lab_binary_bomb 附录候选材料

本文件用于整理适合放入总报告附录的长输出、命令记录、代码摘录、截图索引和调试日志。附录内容必须支撑正文结论。

## 1. 可进入附录的命令输出

| 编号 | 命令 | 输出文件 | 用途 | 正文引用位置 |
|---|---|---|---|---|
| A001 | `gcc -g -o bomb -D U8 bomb.c support.c phases.o` | `outputs/lab03_gcc_build_20260523.txt` | 编译记录 | 编译过程 |
| A002 | `nm -n bomb` | `outputs/lab03_nm_20260523.txt` | 符号地址索引 | 静态分析 |
| A003 | `objdump -d -M intel bomb` | `outputs/lab03_objdump_intel_20260523.txt` | 完整反汇编 | 逐关分析 |
| A004 | `objdump -s -j .rodata bomb` | `outputs/lab03_rodata_20260523.txt` | 只读数据段 | 字符串和跳转表分析 |
| A005 | `objdump -s -j .data bomb` | `outputs/lab03_data_20260523.txt` | 数据段 | 字符串表、查找表和链表分析 |
| A006 | `./bomb ../../outputs/lab03_answers_20260523.txt` | `outputs/lab03_final_run_20260523.txt` | 最终通过输出 | 实验结果 |

## 2. 可进入附录的代码/汇编摘录

| 编号 | 文件 | 行号/函数/地址 | 摘录内容说明 | 支撑结论 |
|---|---|---|---|---|
| K001 | `outputs/lab03_objdump_intel_20260523.txt` | `phase_1` | `special + 50 * digit` 字符串比较 | phase 1 输入 |
| K002 | `outputs/lab03_objdump_intel_20260523.txt` | `phase_2` | 六整数递推检查 | phase 2 输入 |
| K003 | `outputs/lab03_objdump_intel_20260523.txt` | `phase_3` | jump table 和 case 常量 | phase 3 输入 |
| K004 | `outputs/lab03_objdump_intel_20260523.txt` | `func4` / `phase_4` | 二分递归返回值 | phase 4 输入 |
| K005 | `outputs/lab03_data_20260523.txt` | `array.0`、链表节点 | 查表和链表数据 | phase 5 / phase 6 输入 |

## 3. 可进入附录的截图或图表

| 编号 | 文件路径 | 内容说明 | 正文引用位置 |
|---|---|---|---|
| G001 | `diagrams/source/lab03_phase_flow.mmd` | 六关分析流程 | 实验过程 |
| G002 | `diagrams/source/lab03_phase6_reorder.mmd` | phase 6 链表重排 | phase 6 分析 |

## 4. 可进入附录的调试日志

| 编号 | 工具 | 日志文件 | 内容说明 | 支撑结论 |
|---|---|---|---|---|
| D001 | GDB | `outputs/lab03_gdb_breakpoints_20260523.gdb` | 断点脚本 | 动态调试方法 |
| D002 | GDB | `outputs/lab03_gdb_breakpoints_20260523.txt` | 断点输出 | 六关关键状态验证 |
