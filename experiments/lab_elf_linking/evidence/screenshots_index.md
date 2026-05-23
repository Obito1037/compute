# 截图索引

本实验当前以命令输出和 GDB 记录作为等价证据；正式报告若需要截图，可从下列文件对应终端内容补截。

| 截图编号 | 文件名 | 内容 | 生成时间 | 对应实验步骤 | 报告引用位置 |
|---|---|---|---|---|---|
| S001 | `outputs/lab05_main_verbose_20260523.s` | `init_gstr1`、`uninit_gstr2`、`.rept 8` 汇编证据 | 2026-05-23 | C 到汇编 | 任务 1 |
| S002 | `outputs/lab05_main_o_sections_20260523.txt` | `main.o` 节头表 | 2026-05-23 | 可重定位目标文件解析 | 任务 2 |
| S003 | `outputs/lab05_main_o_symbols_20260523.txt` | `main.o` 符号表 | 2026-05-23 | 符号表分析 | 任务 2 |
| S004 | `outputs/lab05_main_o_relocations_20260523.txt` | `.rela.text`、`.rela.data.rel*` 重定位表 | 2026-05-23 | 重定位分析 | 任务 2 |
| S005 | `outputs/lab05_symbol_order_compare_20260523.txt` | `main_sub` 与 `sub_main` 符号顺序比较 | 2026-05-23 | 可执行文件解析 | 任务 3 |
| S006 | `outputs/lab05_dynamic_printf_evidence_20260523.txt` | `printf` 动态符号、PLT/GOT 和重定位 | 2026-05-23 | 动态链接库函数定位 | 任务 5 |
| S007 | `outputs/lab05_gdb_printf_dynamic_20260523.txt` | GDB 中 `printf` 运行时地址与共享库列表 | 2026-05-23 | 动态链接库函数定位 | 任务 5 |
