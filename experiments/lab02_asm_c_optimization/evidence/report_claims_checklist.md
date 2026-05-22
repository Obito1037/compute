# 报告结论证据检查表

| 报告结论 | 是否有证据 | 证据编号/文件 | 是否需要补证 | 备注 |
|---|---|---|---|---|
| 实验二使用 VS2026 / MSVC / MASM 完成，属于用户确认后的本机环境执行 | 是 | E005、E006、E007；`evidence/human_questions.md` Q001 | 否 | 任务书列出 VS2019/VS2022/VS2023，用户已确认使用 VS2026 |
| `student` 结构体大小为 38 字节，`scores` 偏移 20，`average` 偏移 36 | 是 | E008、E009、E010、E011 | 否 | 运行输出和反汇编偏移一致 |
| C 程序显示排序前、排序后的学生信息，第 0 个学生使用本人学号和姓名 GBK 字节 | 是 | E003、E008、E009 | 否 | 姓名以 `D5 C5 BC D2 C1 BA 00` 字节保存 |
| ASM 平均分函数与 C 平均分函数结果一致 | 是 | E008、E009 | 否 | Debug/Release 均输出 `VERIFY ... PASS` |
| ASM shift 优化版本快于 ASM idiv 基线版本 | 是 | E008、E009、E012 | 否 | Debug：4.120ms vs 14.023ms；Release：4.414ms vs 14.262ms |
| Release 版 C 平均分比 Debug 版 C 平均分快 | 是 | E008、E009、E012 | 否 | Debug C 29.995ms；Release C 5.670ms |
| Release C 平均分不一定慢于手写 ASM；本次 Release C 快于 ASM idiv 基线 | 是 | E009、E012 | 否 | 只能基于本次运行结果表述，不泛化 |
| 快速排序优化明显快于冒泡排序 | 是 | E008、E009、E012 | 否 | Debug：7.488ms vs 154.377ms；Release：0.478ms vs 6.773ms |
| Debug/Release 反汇编存在差异，Release 减少调试开销并进行更紧凑优化 | 是 | E010、E011、E012 | 否 | Debug 含 JMC 调用；Release 平均分 C 代码展开并使用 `sar eax,3` |
