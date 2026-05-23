# lab_elf_linking 附录候选材料

本文件用于整理适合放入总报告附录的长输出、命令记录、代码摘录、截图索引和调试日志。附录内容必须支撑正文结论。

## 1. 可进入附录的命令输出

| 编号 | 命令 | 输出文件 | 用途 | 正文引用位置 |
|---|---|---|---|---|
| APP-CMD-01 | `gcc -E/-S/-c` | `outputs/lab05_gcc_*_20260523.txt` | 编译阶段记录 | 编译流程 |
| APP-CMD-02 | `readelf -S -W main.o` | `outputs/lab05_main_o_sections_20260523.txt` | 节头表完整输出 | 可重定位目标文件解析 |
| APP-CMD-03 | `readelf -s -W main.o` | `outputs/lab05_main_o_symbols_20260523.txt` | 符号表完整输出 | 符号表分析 |
| APP-CMD-04 | `readelf -r -W main.o` | `outputs/lab05_main_o_relocations_20260523.txt` | 重定位表完整输出 | 重定位分析 |
| APP-CMD-05 | `objdump -dr -M intel main.o` | `outputs/lab05_main_o_disasm_reloc_20260523.txt` | 反汇编和重定位混合视图 | 链接前机器码 |
| APP-CMD-06 | `nm -n main_sub/sub_main` | `outputs/lab05_symbol_order_compare_20260523.txt` | 链接顺序比较 | 可执行文件解析 |
| APP-CMD-07 | `ldd/readelf/objdump` 动态链接组合 | `outputs/lab05_dynamic_printf_evidence_20260523.txt` | `printf` 定位 | 动态链接 |

## 2. 可进入附录的代码/汇编摘录

| 编号 | 文件 | 行号/函数/地址 | 摘录内容说明 | 支撑结论 |
|---|---|---|---|---|
| APP-CODE-01 | `src/work/main.c` | 全局变量定义 | 学号字符串、初始化/未初始化对象、指针对象 | 节归属 |
| APP-CODE-02 | `outputs/lab05_main_verbose_20260523.s` | `init_gstr1`、`uninit_gstr2` | `.data` 与 `.bss` 表示 | C 到汇编 |
| APP-CODE-03 | `outputs/lab05_main_o_main_disasm_20260523.txt` | `main` 偏移 `0x126`-`0x12d` | 8 条 `nop` | `.rept 8` 验证 |
| APP-CODE-04 | `outputs/lab05_main_sub_main_disasm_20260523.txt` | `main` 地址 `0x12c0` 起 | 链接后实际地址和 PC 相对位移 | 重定位效果 |
| APP-CODE-05 | `outputs/lab05_dynamic_printf_evidence_20260523.txt` | `.plt`、`.got` | PLT/GOT 结构 | 动态链接函数定位 |

## 3. 可进入附录的截图或图表

| 编号 | 文件路径 | 内容说明 | 正文引用位置 |
|---|---|---|---|
| APP-FIG-01 | `diagrams/source/lab05_build_pipeline.mmd` | 从 C 到 ELF 的构建流程 | 实验流程 |
| APP-FIG-02 | `diagrams/source/lab05_relocation_dynamic_link.mmd` | 重定位与动态链接关系 | 原理说明 |
| APP-FIG-03 | `evidence/screenshots_index.md` | 可补截图的等价证据清单 | 附录索引 |

## 4. 可进入附录的调试日志

| 编号 | 工具 | 日志文件 | 内容说明 | 支撑结论 |
|---|---|---|---|---|
| APP-DBG-01 | GDB | `outputs/lab05_gdb_printf_dynamic_20260523.txt` | `printf` 运行时地址、共享库加载范围、指令 | 动态链接库函数定位 |
| APP-DBG-02 | readelf | `outputs/lab05_program_headers_compare_20260523.txt` | 动态 PIE 与静态 EXEC 程序头比较 | 静态/动态链接差异 |
