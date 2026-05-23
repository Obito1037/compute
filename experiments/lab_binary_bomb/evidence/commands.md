# 命令记录

| 编号 | 时间 | 当前目录 | 命令 | 目的 | 输出文件 | 状态 |
|---|---|---|---|---|---|---|
| C001 | 2026-05-23 01:35:00 +08:00 | 项目根目录 | 读取 `original_materials/parsed_text/3_binarybomb_operation.docx.txt`、`experiments/lab_binary_bomb/src/original_copy/*` | 阅读二进制炸弹操作说明和源码结构 | `experiments/lab_binary_bomb/requirement_summary.md`；终端输出 | 已完成 |
| C002 | 2026-05-23 01:35:00 +08:00 | 项目根目录 | `wsl -e bash -lc "uname -a"`；`gcc --version`；`gdb --version`；`objdump --version`；`file phases.o`；`readelf -h phases.o` | 检查 WSL、GCC、GDB、objdump 和 `phases.o` 目标格式 | `experiments/lab_binary_bomb/evidence/environment.md`；终端输出 | 已完成：`phases.o` 为 ELF64 x86-64 relocatable |
| C003 | 2026-05-23 01:36:00 +08:00 | 项目根目录 | 复制 `bomb.c`、`support.c`、`support.h`、`phases.o` 到 `src/work` | 创建实验三工作副本，不修改原始材料 | `experiments/lab_binary_bomb/src/work/` | 已完成 |
| C004 | 2026-05-23 01:36:30 +08:00 | `experiments/lab_binary_bomb/src/work` | `gcc -g -o bomb -D U8 bomb.c support.c phases.o` | 按任务书要求用学号末位 `8` 生成炸弹程序 | `experiments/lab_binary_bomb/outputs/lab03_gcc_build_20260523.txt`；`src/work/bomb` | 已完成 |
| C005 | 2026-05-23 01:37:00 +08:00 | `experiments/lab_binary_bomb/src/work` | `file bomb`；`nm -n bomb | grep ' phase_'` | 确认可执行文件类型和 phase 函数符号地址 | 终端输出 | 已完成：ELF64 PIE，带调试信息，未 stripped |
| C006 | 2026-05-23 01:37:30 +08:00 | `experiments/lab_binary_bomb/src/work` | `printf 'U202414558\n' | ./bomb` | 试运行并确认学号输入后进入 Gate 1 | 终端输出 | 已完成：因 EOF 退出，未触发炸弹 |
| C007 | 2026-05-23 01:38:00 +08:00 | `experiments/lab_binary_bomb/src/work` | `objdump -d -M intel bomb`；`objdump -s -j .rodata bomb`；`objdump -s -j .data bomb`；`nm -n bomb` | 保存完整反汇编、只读数据、数据段和符号表 | `outputs/lab03_objdump_intel_20260523.txt`；`outputs/lab03_rodata_20260523.txt`；`outputs/lab03_data_20260523.txt`；`outputs/lab03_nm_20260523.txt` | 已完成 |
| C008 | 2026-05-23 01:41:00 +08:00 | 项目根目录 | 编写 `outputs/lab03_answers_20260523.txt` 并运行 `./bomb ../../outputs/lab03_answers_20260523.txt` | 验证推导出的六关输入是否通过 | `outputs/lab03_answers_20260523.txt`；`outputs/lab03_final_run_20260523.txt` | 已完成：六关全部通过 |
| C009 | 2026-05-23 01:42:30 +08:00 | `experiments/lab_binary_bomb/src/work` | `gdb -q -x ../../outputs/lab03_gdb_breakpoints_20260523.gdb` | 保存关键断点、寄存器、内存、栈和链表观察记录 | `outputs/lab03_gdb_breakpoints_20260523.gdb`；`outputs/lab03_gdb_breakpoints_20260523.txt` | 初次 phase 1 指针表达式不严谨，已修正后重跑 |
| C010 | 2026-05-23 01:45:04 +08:00 | 项目根目录 | 整理逐关推导记录 | 将 phase 1 到 phase 6 的推导依据与最终输入关联到反汇编和 GDB 证据 | `outputs/lab03_phase_analysis_20260523.md` | 已完成 |
| C011 | 2026-05-23 01:45:04 +08:00 | 项目根目录 | 新增 Mermaid 图示 | 记录六关分析流程和 phase 6 链表重排关系 | `diagrams/source/lab03_phase_flow.mmd`；`diagrams/source/lab03_phase6_reorder.mmd` | 已完成 |
| C012 | 2026-05-23 01:50:00 +08:00 | 项目根目录 | `py -3 scripts\check_human_questions.py`；`py -3 scripts\check_evidence.py`；`py -3 scripts\check_report_metadata.py` | 复查人工确认、证据索引和报告元数据 | 终端输出 | 已完成：全部 PASS |
| C013 | 2026-05-23 01:50:00 +08:00 | 项目根目录 | `Select-String ... -Pattern "BOOM|You failed|Cannot access memory|Error:"` | 检查最终运行输出和 GDB 输出是否含失败或不可访问内存标记 | 终端输出 | 已完成：无匹配 |
