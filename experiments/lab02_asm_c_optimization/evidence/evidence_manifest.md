# 证据清单

| 证据编号 | 类型 | 路径 | 内容说明 | 支撑报告章节 |
|---|---|---|---|---|
| E001 | 任务书解析文本 | `original_materials/parsed_text/1_a3_docx.txt` | 实验二任务要求：C 成绩管理、Debug/Release 对比、ASM 平均分、ASM 优化、排序优化 | 实验目的与要求、实验内容 |
| E002 | 操作指导解析文本 | `original_materials/parsed_text/4_asm_c_operation_guide.docx.txt` | Visual Studio 中启用 MASM 生成自定义的操作说明 | 实验环境与配置 |
| E003 | 工作源码 | `experiments/lab02_asm_c_optimization/src/work/汇编和C混合编程示例/main_lab02.c` | C 版成绩管理、计时、验证、冒泡排序和快速排序实现 | 程序设计与实现 |
| E004 | 工作汇编源码 | `experiments/lab02_asm_c_optimization/src/work/汇编和C混合编程示例/computeAverageScore_lab02.asm` | ASM 平均分基线版本与 shift 优化版本 | 程序设计与实现、优化分析 |
| E005 | 工作项目配置 | `experiments/lab02_asm_c_optimization/src/work/汇编和C混合编程示例/汇编和C混合编程示例.vcxproj` | `v145` 工具集、MASM 引用、Debug/Release C 反汇编列表输出配置 | 实验环境与配置 |
| E006 | 编译日志 | `experiments/lab02_asm_c_optimization/outputs/lab02_msbuild_debug_20260523.txt` | Debug x86 编译日志，0 警告，0 错误 | 编译与运行记录 |
| E007 | 编译日志 | `experiments/lab02_asm_c_optimization/outputs/lab02_msbuild_release_20260523.txt` | Release x86 编译日志，0 警告，0 错误 | 编译与运行记录 |
| E008 | 运行输出 | `experiments/lab02_asm_c_optimization/outputs/lab02_run_debug_20260523.txt` | Debug 版排序前后学生信息、ASM 校验、性能数据 | 实验结果 |
| E009 | 运行输出 | `experiments/lab02_asm_c_optimization/outputs/lab02_run_release_20260523.txt` | Release 版排序前后学生信息、ASM 校验、性能数据 | 实验结果 |
| E010 | 反汇编输出 | `experiments/lab02_asm_c_optimization/outputs/lab02_disasm_debug_20260523.txt` | Debug 可执行文件完整反汇编 | 反汇编对比 |
| E011 | 反汇编输出 | `experiments/lab02_asm_c_optimization/outputs/lab02_disasm_release_20260523.txt` | Release 可执行文件完整反汇编 | 反汇编对比 |
| E012 | 对比记录 | `experiments/lab02_asm_c_optimization/outputs/lab02_disasm_key_compare_20260523.md` | Debug/Release 性能表、关键反汇编观察和谨慎结论 | 结果分析与优化分析 |
| E013 | 图示源码 | `experiments/lab02_asm_c_optimization/diagrams/source/lab02_c_asm_call_flow.mmd` | C 与 ASM 函数调用关系图 | 程序设计与实现 |
| E014 | 图示源码 | `experiments/lab02_asm_c_optimization/diagrams/source/lab02_optimization_compare.mmd` | 平均分和排序优化对比图 | 结果分析与优化分析 |
