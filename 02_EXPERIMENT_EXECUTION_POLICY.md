# 实验执行政策

本项目用于从零完成计算机系统基础实验，并形成一份总实验报告。

## 执行顺序

1. 阅读原始实验要求。
2. 生成 `requirement_summary.md`。
3. 配置实验环境。
4. 执行实验命令。
5. 保存命令输出、截图索引、错误修复记录。
6. 分析代码、汇编、内存布局、ELF、GDB 输出。
7. 生成图表源文件和渲染图。
8. 更新总 LaTeX 报告。
9. 运行真实性检查和格式检查。
10. 编译 PDF 和 Word。

## 证据文件

每个实验必须维护：

- `evidence/environment.md`
- `evidence/commands.md`
- `evidence/errors_and_fixes.md`
- `evidence/evidence_manifest.md`
- `evidence/screenshots_index.md`
- `evidence/report_claims_checklist.md`
- `outputs/`
- `screenshots/`

## 报告约束

报告必须基于证据文件撰写。若证据缺失，优先补实验记录，而不是直接补文字。

## 报告材料沉淀要求

每做完一个实验阶段，不仅要保存运行结果，还要同步补充：

- `notes/report_material_bank.md`：可写入报告正文的材料；
- `notes/appendix_candidates.md`：适合放入附录的命令、输出、代码、截图；
- `evidence/report_claims_checklist.md`：报告结论与证据的对应关系。

这些文件是最终报告达到 50 页以上且不水字数的基础。

## 人工确认边界

实验过程中若出现环境选择、任务要求、文件归类、编译结果、调试结果、截图证据、报告结论、GitHub 推送等不确定问题，Codex 必须停止执行并询问用户。不得为了推进任务自行猜测。
