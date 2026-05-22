# 命令记录

| 编号 | 时间 | 当前目录 | 命令 | 目的 | 输出文件 | 状态 |
|---|---|---|---|---|---|---|
| C001 | 2026-05-23 01:14:55 +08:00 | 项目根目录 | 读取 `original_materials/parsed_text/1_a3_docx.txt`、`original_materials/parsed_text/4_asm_c_operation_guide.docx.txt`、实验二样例源码和项目文件 | 阅读实验二任务要求、操作指导和样例项目配置 | `experiments/lab02_asm_c_optimization/requirement_summary.md`；终端输出 | 已完成 |
| C002 | 2026-05-23 01:14:55 +08:00 | 项目根目录 | 更新 `experiments/lab02_asm_c_optimization/evidence/human_questions.md` | 记录用户确认实验二使用本机 VS2026 / MSVC / MASM 继续 | `experiments/lab02_asm_c_optimization/evidence/human_questions.md` | 已完成 |
| C003 | 2026-05-23 01:14:55 +08:00 | 项目根目录 | 复制实验二样例 `.sln`、`.vcxproj`、`.filters`、`.user`、`main.c`、`computeAverageScore.asm` 到 `src/work` | 创建可编辑工作副本，不修改 `src/original_copy` 和 `original_materials` | `experiments/lab02_asm_c_optimization/src/work/` | 已完成 |
| C004 | 2026-05-23 01:14:55 +08:00 | 项目根目录 | `VsDevCmd.bat -arch=x86 -host_arch=x64` 后执行 `where ml`、`ml`、`cl`、`MSBuild -version`、`Get-CimInstance Win32_OperatingSystem` | 记录实验二可用 MSVC、MASM、MSBuild 和 Windows 环境 | `experiments/lab02_asm_c_optimization/evidence/environment.md`；终端输出 | 已完成 |
| C005 | 2026-05-23 01:20:50 +08:00 | 项目根目录 | 新增 `main_lab02.c`、`computeAverageScore_lab02.asm`，并更新工作副本 `.vcxproj` | 实现 C 平均分、ASM 平均分、ASM 优化平均分、冒泡排序、快速排序、计时和校验；项目工具集改为 `v145` 并输出反汇编列表 | `experiments/lab02_asm_c_optimization/src/work/汇编和C混合编程示例/` | 已完成 |
| C006 | 2026-05-23 01:20:50 +08:00 | 项目根目录 | `MSBuild.exe ... /t:Rebuild /p:Configuration=Debug /p:Platform=x86` | 编译实验二 Debug 版 | `experiments/lab02_asm_c_optimization/outputs/lab02_msbuild_debug_20260523.txt` | 已完成：0 警告，0 错误 |
| C007 | 2026-05-23 01:21:04 +08:00 | 项目根目录 | `MSBuild.exe ... /t:Rebuild /p:Configuration=Release /p:Platform=x86` | 编译实验二 Release 版 | `experiments/lab02_asm_c_optimization/outputs/lab02_msbuild_release_20260523.txt` | 已完成：0 警告，0 错误 |
| C008 | 2026-05-23 01:21:20 +08:00 | 项目根目录 | 运行 `src/work/Debug/汇编和C混合编程示例.exe` | 保存 Debug 版运行输出、验证结果和计时结果 | `experiments/lab02_asm_c_optimization/outputs/lab02_run_debug_20260523.txt` | 已完成 |
| C009 | 2026-05-23 01:21:25 +08:00 | 项目根目录 | 运行 `src/work/Release/汇编和C混合编程示例.exe` | 保存 Release 版运行输出、验证结果和计时结果 | `experiments/lab02_asm_c_optimization/outputs/lab02_run_release_20260523.txt` | 已完成 |
| C010 | 2026-05-23 01:21:25 +08:00 | 项目根目录 | `Select-String ... -Pattern "MISMATCH|FAIL|error|Error"` | 检查 Debug/Release 运行输出中是否存在失败、错误或不一致标记 | 终端输出 | 已完成：无匹配 |
| C011 | 2026-05-23 01:23:59 +08:00 | 项目根目录 | `dumpbin /DISASM` Debug 可执行文件 | 保存 Debug 版完整反汇编证据 | `experiments/lab02_asm_c_optimization/outputs/lab02_disasm_debug_20260523.txt` | 已完成 |
| C012 | 2026-05-23 01:23:59 +08:00 | 项目根目录 | `dumpbin /DISASM` Release 可执行文件 | 保存 Release 版完整反汇编证据 | `experiments/lab02_asm_c_optimization/outputs/lab02_disasm_release_20260523.txt` | 已完成 |
| C013 | 2026-05-23 01:23:59 +08:00 | 项目根目录 | 摘录运行输出和反汇编观察 | 形成实验二性能与反汇编对比记录 | `experiments/lab02_asm_c_optimization/outputs/lab02_disasm_key_compare_20260523.md` | 已完成 |
| C014 | 2026-05-23 01:32:58 +08:00 | 项目根目录 | 更新实验二证据清单、截图索引、报告结论检查表、内容深度检查表、代码分析、结果分析、材料库和附录候选 | 整理实验二可用于后续报告撰写的证据链，但不撰写正式报告正文 | `experiments/lab02_asm_c_optimization/evidence/`；`experiments/lab02_asm_c_optimization/notes/`；`experiments/lab02_asm_c_optimization/diagrams/source/` | 已完成 |
| C015 | 2026-05-23 01:32:58 +08:00 | 项目根目录 | `python scripts\check_human_questions.py`；`python scripts\check_evidence.py`；`python scripts\check_report_metadata.py`；`Select-String ... -Pattern "MISMATCH|FAIL|error|Error"` | 复查人工确认、证据索引、报告元数据和实验二运行输出 | 终端输出 | 已完成：三项脚本 PASS，运行输出无失败标记 |
