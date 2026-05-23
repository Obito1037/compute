# 命令记录

| 编号 | 时间 | 当前目录 | 命令 | 目的 | 输出文件 | 状态 |
|---|---|---|---|---|---|---|
| C001 | 2026-05-23 11:09:00 +08:00 | 项目根目录 | 读取 `original_materials/parsed_text/2_a4_docx.txt`、`original_materials/parsed_text/5_bufbomb_tips.docx.txt`、`src/original_copy/*` | 阅读实验四任务书、要点提示和源码，确认必做 smoke/fizz 与选做 bang/boom | `experiments/lab_bufbomb/requirement_summary.md`；终端输出 | 已完成 |
| C002 | 2026-05-23 11:09:00 +08:00 | 项目根目录 | 复制 `bufbomb.c`、`buf.c`、`verinfo.c` 到 `src/work` | 创建实验四工作副本，不修改原始材料 | `experiments/lab_bufbomb/src/work/` | 已完成 |
| C003 | 2026-05-23 11:09:12 +08:00 | `experiments/lab_bufbomb/src/work` | `gcc -g -fno-stack-protector -no-pie -DU8 -fcf-protection=none -z execstack verinfo.c bufbomb.c buf.c -o bufbomb` | 按提示编译生成缓冲区炸弹程序 | `outputs/lab04_gcc_build_20260523.txt` | 已完成：exit_code=0 |
| C004 | 2026-05-23 11:10:00 +08:00 | `experiments/lab_bufbomb/src/work` | `nm -n bufbomb`；`objdump -d -M intel bufbomb`；`objdump -s -j .data/.rodata bufbomb` | 保存函数地址、反汇编和数据段证据 | `outputs/lab04_nm_20260523.txt`；`outputs/lab04_objdump_intel_20260523.txt`；`outputs/lab04_data_20260523.txt`；`outputs/lab04_rodata_20260523.txt` | 已完成 |
| C005 | 2026-05-23 11:12:00 +08:00 | `experiments/lab_bufbomb/src/work` | `gdb -q -x ../../outputs/lab04_probe_stack_20260523.gdb` | 探测 `getbuf` 栈帧、`buf` 地址、保存的 `rbp` 和返回地址 | `outputs/lab04_probe_stack_20260523.gdb`；`outputs/lab04_probe_stack_20260523.txt` | 已完成 |
| C006 | 2026-05-23 11:15:00 +08:00 | 项目根目录 | 生成 `lab04_smoke_hex_20260523.txt`、`lab04_fizz_hex_20260523.txt` | 构造 smoke/fizz 攻击字符串 | `outputs/lab04_smoke_hex_20260523.txt`；`outputs/lab04_fizz_hex_20260523.txt` | 已完成 |
| C007 | 2026-05-23 11:15:30 +08:00 | `experiments/lab_bufbomb/src/work` | `./bufbomb U202414558 ../../outputs/lab04_smoke_hex_20260523.txt 0` | 验证 smoke 攻击 | `outputs/lab04_smoke_run_20260523.txt` | 已完成：输出 `Smoke!` |
| C008 | 2026-05-23 11:15:30 +08:00 | `experiments/lab_bufbomb/src/work` | `./bufbomb U202414558 ../../outputs/lab04_fizz_hex_20260523.txt 1` | 验证 fizz 攻击 | `outputs/lab04_fizz_run_20260523.txt` | 已完成：输出 `Fizz!` |
| C009 | 2026-05-23 11:18:00 +08:00 | `experiments/lab_bufbomb/src/work` | `gdb -q -x ../../outputs/lab04_probe_bang_boom_20260523.gdb` | 为 bang/boom 在同一 GDB 固定随机化环境中探测 `buf` 和原保存 `rbp` | `outputs/lab04_probe_bang_boom_20260523.gdb`；`outputs/lab04_probe_bang_boom_20260523.txt` | 已完成 |
| C010 | 2026-05-23 11:20:00 +08:00 | 项目根目录 | 生成 `lab04_bang_hex_20260523.txt`、`lab04_boom_hex_20260523.txt` | 构造带栈上注入代码的 bang/boom 攻击字符串 | `outputs/lab04_bang_hex_20260523.txt`；`outputs/lab04_boom_hex_20260523.txt` | 已完成 |
| C011 | 2026-05-23 11:21:00 +08:00 | `experiments/lab_bufbomb/src/work` | `gdb -q -x ../../outputs/lab04_run_bang_boom_20260523.gdb` | 在禁用随机化的 GDB 环境中验证 bang/boom 选做关卡 | `outputs/lab04_run_bang_boom_20260523.gdb`；`outputs/lab04_bang_boom_gdb_run_20260523.txt` | 已完成：输出 `Bang!` 和 `Boom!` |
| C012 | 2026-05-23 11:25:00 +08:00 | 项目根目录 | 整理攻击串逐字节解释和栈帧图 | 生成实验四报告材料与附录候选，但不撰写正式报告正文 | `outputs/lab04_attack_analysis_20260523.md`；`diagrams/source/lab04_stack_frame.mmd`；`diagrams/source/lab04_attack_flow.mmd` | 已完成 |
| C013 | 2026-05-23 11:21:20 +08:00 | 项目根目录 | `Select-String` 检查 smoke/fizz/bang/boom 输出；`py -3 scripts\check_human_questions.py`；`py -3 scripts\check_evidence.py`；`py -3 scripts\check_report_metadata.py` | 复查四关成功标记、失败关键字、人工确认、证据索引和报告元数据 | 终端输出 | 已完成：四关成功标记存在，成功输出无失败关键字，三项脚本 PASS |
