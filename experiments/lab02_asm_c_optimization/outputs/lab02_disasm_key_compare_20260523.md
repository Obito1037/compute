# 实验二关键反汇编与性能对比记录

生成时间：2026-05-23 01:23:59 +08:00

## 证据来源

- Debug 运行输出：`experiments/lab02_asm_c_optimization/outputs/lab02_run_debug_20260523.txt`
- Release 运行输出：`experiments/lab02_asm_c_optimization/outputs/lab02_run_release_20260523.txt`
- Debug 反汇编：`experiments/lab02_asm_c_optimization/outputs/lab02_disasm_debug_20260523.txt`
- Release 反汇编：`experiments/lab02_asm_c_optimization/outputs/lab02_disasm_release_20260523.txt`
- 工作源码：`experiments/lab02_asm_c_optimization/src/work/汇编和C混合编程示例/main_lab02.c`
- 工作汇编：`experiments/lab02_asm_c_optimization/src/work/汇编和C混合编程示例/computeAverageScore_lab02.asm`

## 运行结果摘录

| 构建 | C 平均分 / ms | ASM 平均分 idiv / ms | ASM 平均分 shift / ms | 冒泡排序 / ms | 快速排序 / ms |
|---|---:|---:|---:|---:|---:|
| Debug | 29.995 | 14.023 | 4.120 | 154.377 | 7.488 |
| Release | 5.670 | 14.262 | 4.414 | 6.773 | 0.478 |

补充校验：

- `struct student size=38`
- `scores` 偏移为 `20`，即反汇编中的 `0x14`
- `average` 偏移为 `36`，即反汇编中的 `0x24`
- 两个 ASM 平均分函数均通过 C 版本结果校验，checksum 均为 `4244`
- 两个排序函数最终输出 `sorted=PASS`

## 平均分函数反汇编观察

Debug 版 C 平均分函数包含明显的调试构建开销，例如函数入口处调用 `@__CheckForDebuggerJustMyCode@4`，并使用栈上局部变量保存循环变量和临时和。

Release 版 C 平均分函数被优化为更紧凑的寻址和累加形式。由于除数是常量 `8`，编译器没有生成通用除法，而是使用 `sar eax,3` 完成除以 8 的计算。

手写 ASM 基线版本在求和后执行 `idiv ebx`，对应通用整数除法。手写 ASM 优化版本去掉 `idiv`，改用 `sar eax,3`，并用 `dec ecx` / `jne` 控制循环。

## 排序函数反汇编观察

冒泡排序版本保留两层循环结构；Release 反汇编中虽然对结构体交换使用了 `movups` 等较高效的复制指令，但算法层面仍需要大量相邻比较与交换。

快速排序版本使用分区递归逻辑，Release 反汇编中可看到 pivot 相关比较、左右指针移动和递归调用。运行输出中快速排序在 Debug 与 Release 下均明显快于冒泡排序。

## 可用于报告的谨慎结论

- Debug 到 Release 的 C 代码性能提升来自编译器优化、调试辅助代码减少、循环与寻址优化等因素。
- 手写 ASM 不一定天然快于 Release C；本次证据中 ASM 基线使用 `idiv`，在 Release 下慢于 C 版本。
- 针对 8 门课程求平均值时，用移位替代除法是有效的局部优化，本次 Debug/Release 输出均显示 ASM shift 版本快于 ASM idiv 版本。
- 排序优化的主要收益来自算法复杂度变化；在 `n=256`、`repeat=200` 的测试中，快速排序明显快于冒泡排序。
