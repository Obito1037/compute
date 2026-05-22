# lab01_data_representation 附录候选材料

本文件用于整理适合放入总报告附录的长输出、命令记录、代码摘录、截图索引和调试日志。附录内容必须支撑正文结论。

## 1. 可进入附录的命令输出

| 编号 | 命令 | 输出文件 | 用途 | 正文引用位置 |
|---|---|---|---|---|
| LAB01-APP-CMD-001 | `VsDevCmd.bat` + `MSBuild.exe lab1.sln /p:Configuration=Debug /p:Platform=Win32` | `outputs/lab01_msbuild_debug_20260523_retry3.txt` | 证明实验一工作副本可在 VS2026/MSBuild 下编译生成可执行文件 | 实验一实验过程 |
| LAB01-APP-CMD-002 | `src/work/Debug/lab1.exe` | `outputs/lab01_run_debug_20260523_retry2.txt` | 保存压缩/解压、编码、布局和位运算测试结果 | 实验一实验结果 |
| LAB01-APP-CMD-003 | `LAB1_MEMORY_PROBE` 探针版 + Windows API `ReadProcessMemory` | `outputs/memory_probe/lab01_message_memory_readprocessmemory_20260523.md` | 等效调试读取运行中进程 `message` 前 40 字节 | 实验一实验过程 |
| LAB01-APP-CMD-004 | PowerShell 自动比较脚本 | `outputs/memory_probe/lab01_message_memory_compare_20260523.md` | 比较程序输出与外部内存读取结果 | 实验一实验结果 |

## 2. 可进入附录的代码/汇编摘录

| 编号 | 文件 | 行号/函数/地址 | 摘录内容说明 | 支撑结论 |
|---|---|---|---|---|
| LAB01-APP-CODE-001 | `src/work/lab1.c` | `pack_student_bytebybyte` | 逐字节压缩函数 | 前 2 条记录使用逐字节压缩 |
| LAB01-APP-CODE-002 | `src/work/lab1.c` | `pack_student_whole` | 整体字段压缩函数 | 后 3 条记录使用整体字段写入 |
| LAB01-APP-CODE-003 | `src/work/lab1.c` | `restore_student` | 解压函数 | 解压只依赖接口参数 |
| LAB01-APP-CODE-004 | `src/work/lab1.c` | `addOK` | 溢出检测函数 | 溢出返回 1，非溢出返回 0 |

## 3. 可进入附录的截图或图表

| 编号 | 文件路径 | 内容说明 | 正文引用位置 |
|---|---|---|---|
| LAB01-APP-FIG-001 | `outputs/memory_probe/lab01_message_memory_readprocessmemory_20260523.md` | 等效调试内存读取记录：`message` 前 40 字节 | 实验一实验过程 |
| LAB01-APP-FIG-002 | `outputs/memory_probe/lab01_message_memory_compare_20260523.md` | 程序输出与等效调试内存读取对比，结果为 `MATCH` | 实验一实验结果 |

## 4. 可进入附录的调试日志

| 编号 | 工具 | 日志文件 | 内容说明 | 支撑结论 |
|---|---|---|---|---|
| LAB01-APP-DBG-001 | MSBuild | `outputs/lab01_msbuild_debug_20260523.txt` | 首次编译失败，提示缺少 v100 工具集 | 说明项目重定向原因 |
| LAB01-APP-DBG-002 | MSBuild | `outputs/lab01_msbuild_debug_20260523_retry1.txt` | 第二次编译失败，暴露 `byteSwap` 测试辅助函数错误 | 说明测试代码修复过程 |
| LAB01-APP-DBG-003 | ReadProcessMemory | `outputs/memory_probe/lab01_message_memory_readprocessmemory_20260523.md` | 运行中进程内存读取记录 | 支撑 `message` 前 40 字节内存观察 |
