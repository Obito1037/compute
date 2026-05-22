# 项目规则

## 1. 实验真实性规则

- 不得编造未运行的命令。
- 不得编造未观察到的 GDB、readelf、objdump、程序输出或截图。
- 若某个结论暂时缺少证据，应在报告草稿中标记为“待补证”，不得写成已验证事实。

## 2. 报告模板规则

正式报告必须遵守用户提供的《实验报告封面及正文目录结构.doc》的结构：

- 封面字段完整。
- 正文前有目录。
- 每个实验包含实验概述、实验内容、实验设计、实验过程、实验结果、实验小结。
- 阶段性实验在实验内容中分阶段展开，每个阶段包含任务描述、实验设计、实验过程、实验结果。
- 最终实验总结不少于 400 字。

本项目实际包含 5 个实验，已按模板逻辑扩展为 5 个实验章节。

## 3. AI 使用记录规则

- 可以记录 AI 在项目组织、流程提醒、格式检查方面的辅助。
- AI 使用记录只能写入 `journals/ai_assistance_log.md`。
- 正式实验报告正文不得出现“AI 使用说明”“由 AI 生成”等内容。

## 4. Git 规则

- 每完成一个阶段应提交一次 Git 记录。
- 提交记录应描述真实实验进展。
- 不得伪造过去时间线。

示例：

```text
lab01: collect build outputs and screenshots
lab01: analyze data representation results
report: update lab01 section with evidence references
```


## 外部 Skill 参考规则

- 可以参考公开 GitHub skill 的组织方式、编译检查流程、图表生成流程、Git 工作流。
- 不得直接复制或运行第三方脚本。
- 使用任何外部 skill 前必须执行 `16_external_skill_safety_auditor` 的审查逻辑。
- 外部 skill 不得覆盖 `original_materials/`、`report/`、`experiments/` 中已有结构。
- 外部 skill 不能作为实验结果证据；实验结果只能来自真实运行输出、调试记录、截图和源码分析。

## 报告页数与内容质量硬规则

1. 最终总报告 PDF 必须不少于 50 页。
2. 每个实验必须有充分的过程、结果、图表、代码/调试分析和证据索引。
3. 最终报告必须包含附录，附录至少包括命令索引、代码/汇编摘录、调试日志摘录、图表/截图索引和 Git 提交记录摘要。
4. 禁止使用空白页、重复截图、无解释的长输出、复制任务书等方式凑页数。
5. 提交前必须运行 `python scripts/final_report_gate.py`。

## No guessing rule

Codex must not infer, invent, or silently fill missing information. If `config/report_metadata.yaml` contains `待填写` or an empty value, Codex must ask the user before producing the final report.

No report claim may be written as a fact unless supported by evidence files. No personal information may be inferred from memory, chat history, operating-system username, Git configuration, or file names.
