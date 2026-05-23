# 证据清单

| 证据编号 | 类型 | 路径 | 内容说明 | 支撑报告章节 |
|---|---|---|---|---|
| E001 | 操作说明解析文本 | `original_materials/parsed_text/3_binarybomb_operation.docx.txt` | 二进制炸弹实验任务、编译方法和运行要求 | 实验目的与要求 |
| E002 | 原始源码/目标文件 | `experiments/lab_binary_bomb/src/original_copy/` | 教师提供的 `bomb.c`、`support.c`、`support.h`、`phases.o` | 实验材料说明 |
| E003 | 工作副本源码 | `experiments/lab_binary_bomb/src/work/` | 实验三构建和运行使用的工作副本 | 编译与运行 |
| E004 | 编译日志 | `experiments/lab_binary_bomb/outputs/lab03_gcc_build_20260523.txt` | 使用 `gcc -g -o bomb -D U8 bomb.c support.c phases.o` 编译 | 编译记录 |
| E005 | 符号表 | `experiments/lab_binary_bomb/outputs/lab03_nm_20260523.txt` | phase 函数、全局数据和链表节点符号 | 反汇编分析 |
| E006 | 完整反汇编 | `experiments/lab_binary_bomb/outputs/lab03_objdump_intel_20260523.txt` | `objdump -d -M intel` 输出 | 逐关推导 |
| E007 | 只读数据段 | `experiments/lab_binary_bomb/outputs/lab03_rodata_20260523.txt` | 字符串常量、phase 3 jump table、phase 5 目标字符串 | 逐关推导 |
| E008 | 数据段 | `experiments/lab_binary_bomb/outputs/lab03_data_20260523.txt` | `special` 字符串表、phase 5 查表数组、phase 6 链表节点 | 逐关推导 |
| E009 | 最终输入文件 | `experiments/lab_binary_bomb/outputs/lab03_answers_20260523.txt` | 已验证通过的学号和六关输入 | 实验结果 |
| E010 | 最终运行输出 | `experiments/lab_binary_bomb/outputs/lab03_final_run_20260523.txt` | 六关全部通过并输出 Congratulations | 实验结果 |
| E011 | GDB 脚本 | `experiments/lab_binary_bomb/outputs/lab03_gdb_breakpoints_20260523.gdb` | 关键断点和内存观察脚本 | 调试过程 |
| E012 | GDB 输出 | `experiments/lab_binary_bomb/outputs/lab03_gdb_breakpoints_20260523.txt` | phase 1 期望串、phase 2/3 数字、phase 4 返回值、phase 5 转换串、phase 6 链表重排 | 调试过程与结果验证 |
| E013 | 逐关分析记录 | `experiments/lab_binary_bomb/outputs/lab03_phase_analysis_20260523.md` | phase 1 到 phase 6 的推导过程与最终输入 | 结果分析 |
| E014 | 图示源码 | `experiments/lab_binary_bomb/diagrams/source/lab03_phase_flow.mmd` | 六关分析流程图 | 实验过程 |
| E015 | 图示源码 | `experiments/lab_binary_bomb/diagrams/source/lab03_phase6_reorder.mmd` | phase 6 链表重排图 | phase 6 分析 |
