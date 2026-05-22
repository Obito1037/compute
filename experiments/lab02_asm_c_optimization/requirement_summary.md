# 实验二 requirement_summary

## 实验名称
汇编和 C 的混合编程及优化

## 实验环境
- Windows：Visual Studio 2019/2022/2023
- MASM：通过“生成依赖项 / 生成自定义”启用

## 已确认执行环境
- 本机仅检测到 Visual Studio Community 2026；用户已确认实验二可使用 VS2026 / MSVC / MASM 继续。
- 实际构建平台：x86 / Win32。
- 实际工作副本：`experiments/lab02_asm_c_optimization/src/work/`。

## 核心任务
1. 用 C 语言实现学生成绩管理程序。
2. 对“计算平均成绩”和“排序”分别计时。
3. 对 Debug 版与 Release 版运行效率和反汇编差异进行对比。
4. 用汇编语言实现“计算平均成绩”函数，替换 C 语言版本。
5. 对汇编平均成绩函数进行优化。
6. 对排序函数进行算法优化。

## 必须保存的证据
- Visual Studio 项目配置截图或说明。
- Debug/Release 编译与运行结果。
- 计时结果表。
- C 与 ASM 调用关系说明。
- 反汇编对比输出或截图索引。
- 优化前后性能对比。

## 本次任务书来源
- 实验任务文本：`original_materials/parsed_text/1_a3_docx.txt`
- MASM 操作指导：`original_materials/parsed_text/4_asm_c_operation_guide.docx.txt`
