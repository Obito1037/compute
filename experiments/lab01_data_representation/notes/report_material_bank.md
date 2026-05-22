# lab01_data_representation 报告正文材料库

本文件用于沉淀可写入正式总报告正文的内容。Codex 生成报告前必须先读取本文件。

## 1. 实验目的与任务拆解

| 任务 | 说明 | 对应证据 |
|---|---|---|
| 数据压缩与解压 | 按任务书将 5 条 `student_t` 记录紧凑存入 `message`，前 2 条使用逐字节压缩，后 3 条使用整体字段写入压缩，再从 `message` 解压回结构数组。 | LAB01-SRC-001，LAB01-RUN-001 |
| 数据表示观察 | 输出 `message` 前 40 字节、第 0 名学生 `score=58.0f` 的 IEEE 754 编码、结构体字段偏移和数组步长，并用等效调试内存读取验证 `message` 前 40 字节。 | LAB01-RUN-002，LAB01-MEM-001，LAB01-MEM-002 |
| 位运算等效实现 | 实现任务书要求的 12 个位运算函数，并与标准实现进行自动对照。 | LAB01-SRC-001，LAB01-RUN-001 |

## 2. 关键原理说明

- 结构体在内存中包含对齐填充，本次输出显示 `student_t` 大小为 216 字节，`age` 位于偏移 8，`score` 位于偏移 12，`remark` 位于偏移 16。
- 压缩存储去除了结构体中的填充字节，只保存字符串有效内容、二进制 `short` 和二进制 `float`。
- `score=58.0f` 的 IEEE 754 单精度值为 `0x42680000`，小端字节序为 `00 00 68 42`。

## 3. 实验设计思路

- 工具链使用用户确认的 Visual Studio Community 2026，工作副本项目重定向到 `v145` 平台工具集。
- 源码实现只修改 `experiments/lab01_data_representation/src/work/`，不修改 `original_materials/` 或 `src/original_copy/`。
- 对压缩/解压结果采用运行输出逐项比较；对位运算函数采用标准函数自动对照。

## 4. 实验过程材料

| 步骤 | 操作 | 命令/工具 | 输出/截图 | 分析说明 |
|---|---|---|---|---|
| 1 | 检测并确认 VS 工具链 | `vswhere`、`MSBuild.exe`、`cl` | `environment.md` | 本机只检测到 VS2026，用户确认可用 |
| 2 | 创建工作副本 | PowerShell `Copy-Item` | `src/work/` | 避免修改原始材料 |
| 3 | 编译 Debug/Win32 | `VsDevCmd.bat` + `MSBuild.exe` | `lab01_msbuild_debug_20260523_retry3.txt` | 最终编译成功 |
| 4 | 运行程序 | `src/work/Debug/lab1.exe` | `lab01_run_debug_20260523_retry1.txt` | 输出压缩/解压、编码、布局和位运算测试结果 |

## 5. 关键代码/汇编/调试/ELF 分析材料

| 片段编号 | 文件/命令 | 片段说明 | 可写入报告的分析 |
|---|---|---|---|
| LAB01-CODE-001 | `src/work/lab1.c` | `pack_student_bytebybyte` | 逐字节写入字符串、`short`、`float` 和备注，用于前 2 条记录 |
| LAB01-CODE-002 | `src/work/lab1.c` | `pack_student_whole` | 使用 `strcpy` 写字符串，对 `short` 和 `float` 用整体赋值写入，用于后 3 条记录 |
| LAB01-CODE-003 | `src/work/lab1.c` | `restore_student` | 只依赖 `buf`、`len` 和目标数组指针恢复数据 |
| LAB01-CODE-004 | `src/work/lab1.c` | 位运算函数组 | 每个函数用任务书允许的位运算构造，并保存自动对照输出 |

## 6. 结果分析材料

- 最终输出显示压缩前结构数组长度为 1080 字节，压缩后总长度为 136 字节。
- 解压恢复人数为 5，解压后各条记录与压缩前输出一致。
- 最终位运算测试输出没有 `FAIL`。

## 7. 实验小结素材

- 原始 VS 项目使用 `v100` 工具集，本机 VS2026 无法直接编译，需要在工作副本中重定向到 `v145`。
- `student.name[8]` 对中文姓名有编码限制，最终在用户确认后使用 GBK/CP936 字节序列保存。
- `addOK` 的返回语义必须严格按任务书执行，不能套用常见 Data Lab 中“无溢出返回 1”的旧语义。
