# 证据清单

| 证据编号 | 类型 | 路径 | 内容说明 | 支撑报告章节 |
|---|---|---|---|---|
| E001 | 任务书解析文本 | `original_materials/parsed_text/2_a4_docx.txt` | 缓冲区溢出攻击任务要求，必做 smoke/fizz | 实验目的与要求 |
| E002 | 要点提示解析文本 | `original_materials/parsed_text/5_bufbomb_tips.docx.txt` | 编译开关、运行方式、fizz 技巧、选做 bang/boom 提示 | 实验内容与方法 |
| E003 | 工作源码 | `experiments/lab_bufbomb/src/work/` | `bufbomb.c`、`buf.c`、`verinfo.c` 工作副本 | 编译与代码分析 |
| E004 | 编译日志 | `experiments/lab_bufbomb/outputs/lab04_gcc_build_20260523.txt` | GCC 编译命令、退出码、可执行文件类型 | 编译记录 |
| E005 | 符号表 | `experiments/lab_bufbomb/outputs/lab04_nm_20260523.txt` | `smoke`、`fizz`、`bang`、`getbuf`、`cookie`、`global_value` 等符号地址 | 地址分析 |
| E006 | 完整反汇编 | `experiments/lab_bufbomb/outputs/lab04_objdump_intel_20260523.txt` | `test`、`getbuf`、`fizz`、`bang` 关键代码 | 栈帧与攻击方法 |
| E007 | 数据段转储 | `experiments/lab_bufbomb/outputs/lab04_data_20260523.txt` | 全局变量区域证据 | bang 分析 |
| E008 | GDB 栈探测 | `experiments/lab_bufbomb/outputs/lab04_probe_stack_20260523.txt` | `getbuf` 的 `rbp`、`buf`、保存 `rbp` 和返回地址 | 栈帧结构 |
| E009 | smoke 攻击串 | `experiments/lab_bufbomb/outputs/lab04_smoke_hex_20260523.txt` | 覆盖返回地址为 `smoke` | smoke 攻击 |
| E010 | smoke 运行输出 | `experiments/lab_bufbomb/outputs/lab04_smoke_run_20260523.txt` | 普通运行输出 `Smoke!` | smoke 验证 |
| E011 | fizz 攻击串 | `experiments/lab_bufbomb/outputs/lab04_fizz_hex_20260523.txt` | 伪造 `rbp` 并跳转到 `fizz+0xb` | fizz 攻击 |
| E012 | fizz 运行输出 | `experiments/lab_bufbomb/outputs/lab04_fizz_run_20260523.txt` | 普通运行输出 `Fizz!` | fizz 验证 |
| E013 | bang/boom 栈探测 | `experiments/lab_bufbomb/outputs/lab04_probe_bang_boom_20260523.txt` | 固定随机化环境下的 `buf` 地址和原保存 `rbp` | bang/boom 攻击 |
| E014 | bang 攻击串 | `experiments/lab_bufbomb/outputs/lab04_bang_hex_20260523.txt` | 注入代码设置 `global_value=cookie` 后跳转 `bang` | bang 攻击 |
| E015 | boom 攻击串 | `experiments/lab_bufbomb/outputs/lab04_boom_hex_20260523.txt` | 注入代码设置 `eax=cookie` 后跳回 `test` | boom 攻击 |
| E016 | bang/boom GDB 输出 | `experiments/lab_bufbomb/outputs/lab04_bang_boom_gdb_run_20260523.txt` | 选做关卡输出 `Bang!` 和 `Boom!` | 选做验证 |
| E017 | 攻击分析记录 | `experiments/lab_bufbomb/outputs/lab04_attack_analysis_20260523.md` | 四关攻击串结构、栈帧偏移和机器码解释 | 结果分析 |
| E018 | 图示源码 | `experiments/lab_bufbomb/diagrams/source/lab04_stack_frame.mmd` | `getbuf` 栈帧结构图 | 栈帧分析 |
| E019 | 图示源码 | `experiments/lab_bufbomb/diagrams/source/lab04_attack_flow.mmd` | 四关攻击流程图 | 实验过程 |
