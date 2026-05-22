# 生成总 LaTeX 报告提示词

请基于 `docs/report_template_alignment.md` 和 `report/main.tex` 更新总实验报告。

要求：

1. 每个实验章节必须包含实验概述、实验内容、实验设计、实验过程、实验结果、实验小结。
2. 阶段性实验必须在实验内容中分阶段写，每个阶段包含任务描述、实验设计、实验过程、实验结果。
3. 所有“实验过程”和“实验结果”必须引用 `experiments/*/evidence/` 或 `experiments/*/outputs/` 中已有证据。
4. 不得把 AI 使用说明写入正式报告。
5. 实验总结不少于 400 字。
6. 更新完成后，运行 `report/build_total_report.ps1` 或 `make all`，并记录 LaTeX 构建日志。

## 内容深度要求

生成 LaTeX 总报告时，必须先读取：

- `04_REPORT_DEPTH_AND_APPENDIX_REQUIREMENTS.md`
- `docs/report_depth_and_appendix_policy.md`
- 各实验的 `notes/report_material_bank.md`
- 各实验的 `notes/appendix_candidates.md`
- 各实验的 `evidence/evidence_manifest.md`

不得直接用空泛语言填满章节。每个实验至少要有：实验任务拆解、关键原理、实际操作步骤、关键代码/汇编/ELF/GDB 分析、结果解释、错误修复或易错点、图表/截图引用、实验小结。

LaTeX 报告必须包含附录文件：

- `08_appendix_evidence_index.tex`
- `09_appendix_commands_outputs.tex`
- `10_appendix_code_listings.tex`
- `11_appendix_debug_logs.tex`
- `12_appendix_figures_tables.tex`
- `13_appendix_git_history.tex`

生成 PDF 后必须运行 `python scripts/final_report_gate.py`。少于 50 页时继续补充有效内容，不得通过空白页凑页数。
