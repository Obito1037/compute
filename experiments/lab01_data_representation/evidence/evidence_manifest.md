# 证据清单

| 证据编号 | 类型 | 路径 | 内容说明 | 支撑报告章节 |
|---|---|---|---|---|
| LAB01-REQ-001 | 原始任务书解析文本 | `original_materials/parsed_text/0_2026年_计算机系统基础_实验任务书_1_数据表示和等效运算.docx.txt` | 实验一“数据的表示和等效运算”的目的、要求、任务 1 和任务 2 说明 | 后续实验一报告的任务要求来源 |
| LAB01-START-001 | 启动检查记录 | `experiments/lab01_data_representation/outputs/startup_check_20260523.md` | 第 0 阶段目录结构、任务书映射、模板与脚本检查结果 | 项目启动记录，不作为实验结果 |
| LAB01-Q-001 | 人工确认记录 | `experiments/lab01_data_representation/evidence/human_questions.md` | 记录元数据、实验一个人输入、VS 版本等待确认项 | 后续执行前确认依据 |
| LAB01-PLAN-001 | 执行计划 | `experiments/lab01_data_representation/notes/execution_plan.md` | 基于任务书和源码模板整理的实验一执行步骤 | 后续实验一执行准备，不作为实验结果 |
| LAB01-SRC-001 | 源码 | `experiments/lab01_data_representation/src/work/lab1.c` | 实验一工作源码，实现压缩/解压、数据表示输出和位运算测试 | 实验一代码实现 |
| LAB01-BUILD-001 | 编译日志 | `experiments/lab01_data_representation/outputs/lab01_msbuild_debug_20260523_retry3.txt` | VS2026 / MSBuild Debug Win32 最终成功编译日志 | 实验一编译证据 |
| LAB01-RUN-001 | 运行输出 | `experiments/lab01_data_representation/outputs/lab01_run_debug_20260523_retry1.txt` | 实验一最终运行输出，包含压缩/解压结果、前 40 字节、浮点编码、结构布局和位运算测试 | 实验一运行结果 |
| LAB01-FIX-001 | 错误修复记录 | `experiments/lab01_data_representation/evidence/errors_and_fixes.md` | 记录 v100 工具集、`byteSwap` 测试、`addOK` 语义等问题和修复 | 实验一过程记录 |
| LAB01-RUN-002 | 运行输出 | `experiments/lab01_data_representation/outputs/lab01_run_debug_20260523_retry2.txt` | 添加内存探针条件代码后重新运行正常 Debug 程序，输出压缩/解压结果、前 40 字节、浮点编码、结构布局和位运算测试 | 实验一运行结果 |
| LAB01-MEM-001 | 等效调试内存记录 | `experiments/lab01_data_representation/outputs/memory_probe/lab01_message_memory_readprocessmemory_20260523.md` | 运行探针版程序，在暂停期间通过 Windows API `ReadProcessMemory` 从进程内存读取 `message` 前 40 字节 | 实验一调试内存观察 |
| LAB01-MEM-002 | 对比记录 | `experiments/lab01_data_representation/outputs/memory_probe/lab01_message_memory_compare_20260523.md` | 对比正常程序输出的 `message` 前 40 字节与 `ReadProcessMemory` 读取结果，结果为 `MATCH` | 实验一调试内存观察与输出对照 |
