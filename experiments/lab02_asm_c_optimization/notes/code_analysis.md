# 代码分析记录

## 工作副本说明

实验二没有修改 `src/original_copy` 和 `original_materials`。由于样例 `main.c` 含非 UTF-8 字节，工作副本中保留原文件作为对照，新增 `main_lab02.c` 作为本次实验实现文件；项目文件改为编译 `main_lab02.c` 与 `computeAverageScore_lab02.asm`。

## C 程序结构

`student` 结构体与任务书保持一致：

- `char sname[8]`
- `char sid[11]`
- `short scores[8]`
- `short average`

MSVC x86 下实际运行输出为 `sizeof(student)=38`，其中 `scores` 偏移 `20`，`average` 偏移 `36`。

主要 C 函数：

- `init_students`：生成 10 个展示学生和 256 个性能测试学生；第 0 个学生使用 `U202414558`，姓名字段写入 GBK/CP936 字节 `D5 C5 BC D2 C1 BA 00`。
- `computeAverageScore_c`：C 语言平均分基线。
- `sortByAverage_bubble`：按平均分降序的冒泡排序基线。
- `sortByAverage_quick` / `quicksort_students`：排序算法优化版本。
- `measure_average` / `measure_sort`：基于 `QueryPerformanceCounter` 计时。
- `verify_average_function`：用 C 平均分结果校验 ASM 平均分结果。

## ASM 程序结构

`computeAverageScore_lab02.asm` 中定义同布局的 MASM `student struct`，并实现两个函数：

- `computeAverageScore_asm`：基线版本，对 8 门课求和后使用 `idiv ebx` 除以 8。
- `computeAverageScore_asm_opt`：优化版本，对 8 门课求和后使用 `sar eax,3` 除以 8，同时用 `dec ecx` / `jne` 控制循环。

两个函数均采用 C 调用约定，供 `main_lab02.c` 直接声明并调用。

## 项目配置

工作副本 `.vcxproj` 中：

- `PlatformToolset` 从样例的 `v142` 调整为本机可用的 `v145`。
- 保留 MASM build customization：`masm.props` 与 `masm.targets`。
- Debug/Release 的 C 编译均开启 `/FAs`，生成带源码的汇编列表，便于反汇编对比。
