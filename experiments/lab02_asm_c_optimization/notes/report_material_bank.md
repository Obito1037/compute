# lab02_asm_c_optimization 报告正文材料库

本文件用于沉淀可写入正式总报告正文的内容。Codex 生成报告前必须先读取本文件。

## 1. 实验目的与任务拆解

| 任务 | 说明 | 对应证据 |
|---|---|---|
| C 成绩管理程序 | 定义 `student` 结构，初始化学生信息，计算平均分，显示排序前后学生信息 | E003、E008、E009 |
| Debug/Release 对比 | 分别编译运行 Debug x86 与 Release x86，保存计时结果和反汇编 | E006、E007、E008、E009、E010、E011 |
| ASM 平均分 | 用 MASM 实现 `computeAverageScore_asm` 替代 C 平均分函数并验证结果一致 | E004、E008、E009 |
| ASM 优化 | 将 ASM 中除以 8 的 `idiv` 优化为 `sar eax,3` | E004、E008、E009、E012 |
| 排序优化 | 保留冒泡排序基线，新增快速排序优化版本并比较性能 | E003、E008、E009、E012 |

## 2. 关键原理说明

- C 与 ASM 混合编程通过 C 调用约定衔接：C 文件声明外部函数，MASM 文件用 `.model flat, c` 和 `proc` 定义同名函数。
- 结构体跨语言访问必须保持布局一致。本次运行确认 `student` 大小为 38 字节，`scores` 偏移 20，`average` 偏移 36。
- 平均分优化利用 8 是 2 的幂这一事实，用算术右移替代通用整数除法。
- 排序优化属于算法层面变化，快速排序减少了冒泡排序的大量相邻比较和交换。

## 3. 实验设计思路

- 在 `src/work` 创建工作副本，不修改原始样例和原始实验材料。
- 新增 `main_lab02.c` 和 `computeAverageScore_lab02.asm`，项目文件改为引用新文件。
- 使用 VS2026 x86 开发环境执行 Debug/Release 编译。
- 使用程序内校验保证 ASM 平均分结果与 C 平均分结果一致。
- 使用 `QueryPerformanceCounter` 记录平均分和排序函数耗时。
- 使用 `dumpbin /DISASM` 保存 Debug/Release 反汇编证据。

## 4. 实验过程材料

| 步骤 | 操作 | 命令/工具 | 输出/截图 | 分析说明 |
|---|---|---|---|---|
| 1 | 确认工具链 | `VsDevCmd.bat`、`ml`、`cl`、`MSBuild -version` | `evidence/environment.md` | 用户确认使用 VS2026 后继续 |
| 2 | 编译 Debug | `MSBuild ... Configuration=Debug Platform=x86` | `outputs/lab02_msbuild_debug_20260523.txt` | 0 警告，0 错误 |
| 3 | 编译 Release | `MSBuild ... Configuration=Release Platform=x86` | `outputs/lab02_msbuild_release_20260523.txt` | 0 警告，0 错误 |
| 4 | 运行 Debug | Debug exe | `outputs/lab02_run_debug_20260523.txt` | 保存排序前后、校验和计时结果 |
| 5 | 运行 Release | Release exe | `outputs/lab02_run_release_20260523.txt` | 保存排序前后、校验和计时结果 |
| 6 | 生成反汇编 | `dumpbin /DISASM` | `outputs/lab02_disasm_debug_20260523.txt`、`outputs/lab02_disasm_release_20260523.txt` | 支撑 Debug/Release 代码差异分析 |

## 5. 关键代码/汇编/调试/ELF 分析材料

| 片段编号 | 文件/命令 | 片段说明 | 可写入报告的分析 |
|---|---|---|---|
| K001 | `main_lab02.c` / `computeAverageScore_c` | C 平均分基线 | 对 8 门课累加后除以 8 |
| K002 | `computeAverageScore_lab02.asm` / `computeAverageScore_asm` | ASM 基线平均分 | 使用 `idiv ebx` 完成除法 |
| K003 | `computeAverageScore_lab02.asm` / `computeAverageScore_asm_opt` | ASM 优化平均分 | 使用 `sar eax,3` 替代除法 |
| K004 | `main_lab02.c` / `sortByAverage_bubble` | 排序基线 | 双重循环相邻交换 |
| K005 | `main_lab02.c` / `sortByAverage_quick` | 排序优化 | 快速排序分区递归 |
| K006 | `outputs/lab02_disasm_key_compare_20260523.md` | 反汇编和性能摘要 | 记录 Debug/Release 差异和谨慎结论 |

## 6. 结果分析材料

- Debug/Release 输出均显示 ASM 平均分校验 PASS，说明汇编函数与 C 版本计算结果一致。
- Debug/Release 输出均显示排序结果 `sorted=PASS`，说明排序后平均分为降序。
- ASM shift 版本比 ASM idiv 版本快，说明在固定除数为 8 的场景下移位优化有效。
- Release C 平均分比 Debug C 平均分快；Release C 还快于 ASM idiv 基线，说明编译器优化不可忽略。
- 快速排序明显快于冒泡排序，说明本次排序优化主要来自算法复杂度改进。

## 7. 实验小结素材

- 样例 `main.c` 不是 UTF-8 文本，直接补丁编辑失败；最终保留原文件，新建 `main_lab02.c` 并调整项目引用。
- 本机工具链为 VS2026，与任务书列出的 VS2019/VS2022/VS2023 不完全一致；已按人工确认继续，并在证据中记录。
- 本次结果提醒：手写汇编需要具体优化点支撑，不能笼统声称一定快于优化后的 C。
