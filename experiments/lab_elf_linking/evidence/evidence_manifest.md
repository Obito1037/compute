# 证据清单

| 证据编号 | 类型 | 路径 | 内容说明 | 支撑报告章节 |
|---|---|---|---|---|
| E001 | 任务书解析文本 | `original_materials/parsed_text/6_link_report_task.docx.txt` | ELF 文件与程序链接任务要求 | 实验目的与要求 |
| E002 | 操作指导解析文本 | `original_materials/parsed_text/link_operation_guide_pptx.txt` | readelf、objdump、hexdump、gcc 等工具使用提示 | 实验方法 |
| E003 | 原始源码副本 | `experiments/lab_elf_linking/src/original_copy/` | 任务给定 `main.c`、`sub.c` | 代码基础 |
| E004 | 工作源码 | `experiments/lab_elf_linking/src/work/main.c`；`experiments/lab_elf_linking/src/work/sub.c` | 已按确认信息修改的实验工作副本 | 实验实现 |
| E005 | 源码差异 | `experiments/lab_elf_linking/outputs/lab05_source_diff_20260523.txt` | 学号、`.rept 8`、`zjl` 修改差异 | 个性化修改 |
| E006 | 实验环境 | `experiments/lab_elf_linking/outputs/lab05_environment_20260523.txt`；`outputs/lab05_windows_environment_20260523.txt` | WSL、Ubuntu、GCC、GDB、binutils、Windows 版本 | 实验环境 |
| E007 | 预处理输出 | `experiments/lab_elf_linking/outputs/lab05_main_preprocessed_20260523.i` | `gcc -E -D U8` 结果 | 编译流程 |
| E008 | 汇编输出 | `experiments/lab_elf_linking/outputs/lab05_main_verbose_20260523.s` | `gcc -S -fverbose-asm -D U8` 结果 | C 到汇编 |
| E009 | 编译日志 | `experiments/lab_elf_linking/outputs/lab05_gcc_preprocess_20260523.txt`；`lab05_gcc_assembly_20260523.txt`；`lab05_gcc_main_o_20260523.txt`；`lab05_gcc_sub_o_20260523.txt` | 预处理、汇编、目标文件生成记录 | 编译流程 |
| E010 | 链接与运行日志 | `outputs/lab05_gcc_main_sub_20260523.txt`；`outputs/lab05_gcc_sub_main_20260523.txt`；`outputs/lab05_gcc_main_sub_static_20260523.txt`；`outputs/lab05_run_main_sub_20260523.txt`；`outputs/lab05_run_sub_main_20260523.txt`；`outputs/lab05_run_main_sub_static_20260523.txt` | 动态/静态链接和运行输出 | 结果验证 |
| E011 | main.o 文件头与节头表 | `outputs/lab05_main_o_file_header_20260523.txt`；`outputs/lab05_main_o_sections_20260523.txt` | 可重定位目标文件结构 | 可重定位文件解析 |
| E012 | main.o 符号表 | `outputs/lab05_main_o_symbols_20260523.txt`；`outputs/lab05_main_o_symbol_filters_20260523.txt` | 符号类型、绑定、节索引、未定义符号 | 符号表分析 |
| E013 | main.o 重定位表 | `outputs/lab05_main_o_relocations_20260523.txt`；`outputs/lab05_main_o_disasm_reloc_20260523.txt` | `.rela.text`、`.rela.data.rel*` 等重定位记录 | 重定位分析 |
| E014 | main.o 数据节证据 | `outputs/lab05_main_o_data_hexdump_20260523.txt`；`outputs/lab05_main_o_data_hex_20260523.txt`；`outputs/lab05_main_o_data_relocation_sections_20260523.txt` | `.data`、`.data.rel.local`、`.data.rel` 内容 | 数据节分析 |
| E015 | main.o 只读节与字符串表 | `outputs/lab05_main_o_rodata_hex_20260523.txt`；`outputs/lab05_main_o_strtab_strings_20260523.txt` | `.rodata` 和 `.strtab` 内容 | 只读节与字符串表 |
| E016 | 反汇编证据 | `outputs/lab05_main_o_main_disasm_20260523.txt`；`outputs/lab05_main_sub_main_disasm_20260523.txt`；`outputs/lab05_sub_main_main_disasm_20260523.txt` | main 函数链接前后机器码对比 | 代码节与链接 |
| E017 | 汇编关键摘录 | `outputs/lab05_assembly_key_extract_20260523.txt` | 全局/局部变量、函数调用、8 条 NOP 证据摘录 | C 到汇编 |
| E018 | 可执行文件比较 | `outputs/lab05_executable_file_compare_20260523.txt`；`outputs/lab05_symbol_order_compare_20260523.txt` | `main_sub`、`sub_main`、静态链接程序大小、类型和符号顺序 | 可执行文件解析 |
| E019 | 动态链接证据 | `outputs/lab05_dynamic_printf_evidence_20260523.txt` | `printf` 动态符号、重定位、PLT/GOT、ldd | 动态链接 |
| E020 | GDB 动态库证据 | `outputs/lab05_gdb_printf_dynamic_20260523.txt` | 运行时 `printf` 地址和共享库加载列表 | 动态库定位 |
| E021 | 程序头比较 | `outputs/lab05_program_headers_compare_20260523.txt` | 动态 PIE 与静态 EXEC 的 program header 对比 | 静态/动态链接 |
| E022 | 分析记录 | `outputs/lab05_elf_linking_analysis_20260523.md` | 实验五结论、证据限制、关键分析 | 报告材料 |
| E023 | 图示源码 | `diagrams/source/lab05_build_pipeline.mmd`；`diagrams/source/lab05_relocation_dynamic_link.mmd` | 编译链接流程图、重定位与动态链接图 | 图表 |
