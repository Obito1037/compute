# lab_bufbomb 附录候选材料

本文件用于整理适合放入总报告附录的长输出、命令记录、代码摘录、截图索引和调试日志。附录内容必须支撑正文结论。

## 1. 可进入附录的命令输出

| 编号 | 命令 | 输出文件 | 用途 | 正文引用位置 |
|---|---|---|---|---|
| A001 | `gcc -g -fno-stack-protector -no-pie -DU8 -fcf-protection=none -z execstack ...` | `outputs/lab04_gcc_build_20260523.txt` | 编译记录 | 编译过程 |
| A002 | `nm -n bufbomb` | `outputs/lab04_nm_20260523.txt` | 符号地址 | 地址分析 |
| A003 | `objdump -d -M intel bufbomb` | `outputs/lab04_objdump_intel_20260523.txt` | 完整反汇编 | 栈帧与关卡分析 |
| A004 | smoke/fizz 普通运行 | `outputs/lab04_smoke_run_20260523.txt`、`outputs/lab04_fizz_run_20260523.txt` | 必做关卡通过记录 | 实验结果 |
| A005 | bang/boom GDB 运行 | `outputs/lab04_bang_boom_gdb_run_20260523.txt` | 选做关卡通过记录 | 实验结果 |

## 2. 可进入附录的代码/汇编摘录

| 编号 | 文件 | 行号/函数/地址 | 摘录内容说明 | 支撑结论 |
|---|---|---|---|---|
| K001 | `outputs/lab04_objdump_intel_20260523.txt` | `getbuf` | 栈帧和 `buf` 偏移 | 攻击偏移 56 |
| K002 | `outputs/lab04_objdump_intel_20260523.txt` | `fizz` | 从 `0x40145c` 开始比较 `[rbp-0x4]` | fizz 攻击 |
| K003 | `outputs/lab04_attack_analysis_20260523.md` | smoke/fizz/bang/boom | 攻击串结构和机器码 | 四关攻击说明 |

## 3. 可进入附录的截图或图表

| 编号 | 文件路径 | 内容说明 | 正文引用位置 |
|---|---|---|---|
| G001 | `diagrams/source/lab04_stack_frame.mmd` | getbuf 栈帧结构图 | 栈帧分析 |
| G002 | `diagrams/source/lab04_attack_flow.mmd` | 四关攻击流程图 | 实验过程 |

## 4. 可进入附录的调试日志

| 编号 | 工具 | 日志文件 | 内容说明 | 支撑结论 |
|---|---|---|---|---|
| D001 | GDB | `outputs/lab04_probe_stack_20260523.txt` | 基础栈帧探测 | 偏移计算 |
| D002 | GDB | `outputs/lab04_probe_bang_boom_20260523.txt` | bang/boom 同命令行栈地址探测 | 选做攻击串地址 |
| D003 | GDB | `outputs/lab04_bang_boom_gdb_run_20260523.txt` | bang/boom 运行验证 | 选做通过 |
