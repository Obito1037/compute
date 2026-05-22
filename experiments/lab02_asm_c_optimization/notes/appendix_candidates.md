# lab02_asm_c_optimization 附录候选材料

本文件用于整理适合放入总报告附录的长输出、命令记录、代码摘录、截图索引和调试日志。附录内容必须支撑正文结论。

## 1. 可进入附录的命令输出

| 编号 | 命令 | 输出文件 | 用途 | 正文引用位置 |
|---|---|---|---|---|
| A001 | `MSBuild ... Configuration=Debug Platform=x86` | `outputs/lab02_msbuild_debug_20260523.txt` | Debug 编译日志 | 编译与运行 |
| A002 | `MSBuild ... Configuration=Release Platform=x86` | `outputs/lab02_msbuild_release_20260523.txt` | Release 编译日志 | 编译与运行 |
| A003 | Debug exe 运行 | `outputs/lab02_run_debug_20260523.txt` | Debug 运行与性能结果 | 实验结果 |
| A004 | Release exe 运行 | `outputs/lab02_run_release_20260523.txt` | Release 运行与性能结果 | 实验结果 |
| A005 | `dumpbin /DISASM` Debug exe | `outputs/lab02_disasm_debug_20260523.txt` | Debug 完整反汇编 | 反汇编对比 |
| A006 | `dumpbin /DISASM` Release exe | `outputs/lab02_disasm_release_20260523.txt` | Release 完整反汇编 | 反汇编对比 |

## 2. 可进入附录的代码/汇编摘录

| 编号 | 文件 | 行号/函数/地址 | 摘录内容说明 | 支撑结论 |
|---|---|---|---|---|
| K001 | `src/work/汇编和C混合编程示例/main_lab02.c` | `computeAverageScore_c` | C 平均分基线 | C 与 ASM 结果对比 |
| K002 | `src/work/汇编和C混合编程示例/computeAverageScore_lab02.asm` | `computeAverageScore_asm` | 使用 `idiv` 的 ASM 基线平均分 | ASM 优化前版本 |
| K003 | `src/work/汇编和C混合编程示例/computeAverageScore_lab02.asm` | `computeAverageScore_asm_opt` | 使用 `sar eax,3` 的 ASM 优化平均分 | ASM 优化后版本 |
| K004 | `src/work/汇编和C混合编程示例/main_lab02.c` | `sortByAverage_bubble`、`sortByAverage_quick` | 冒泡排序与快速排序 | 排序算法优化 |
| K005 | `outputs/lab02_disasm_release_20260523.txt` | `_computeAverageScore_c`、`_computeAverageScore_asm`、`_computeAverageScore_asm_opt` | Release 下关键函数反汇编 | Debug/Release 与 ASM 优化分析 |

## 3. 可进入附录的截图或图表

| 编号 | 文件路径 | 内容说明 | 正文引用位置 |
|---|---|---|---|
| G001 | `evidence/screenshots_index.md` | 本实验当前使用编译、运行、反汇编文本作为等效证据，未生成真实截图 | 证据说明 |

## 4. 可进入附录的调试日志

| 编号 | 工具 | 日志文件 | 内容说明 | 支撑结论 |
|---|---|---|---|---|
| D001 | `dumpbin` | `outputs/lab02_disasm_debug_20260523.txt` | Debug 反汇编 | Debug 构建保留调试辅助 |
| D002 | `dumpbin` | `outputs/lab02_disasm_release_20260523.txt` | Release 反汇编 | Release 构建优化后的指令差异 |
