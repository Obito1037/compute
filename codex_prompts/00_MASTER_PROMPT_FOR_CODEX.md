# Codex 总控提示词

请先阅读以下文件：

1. `00_README_FOR_CODEX.md`
2. `01_PROJECT_RULES.md`
3. `02_EXPERIMENT_EXECUTION_POLICY.md`
4. `docs/report_template_alignment.md`
5. `skills/00_master_workflow/SKILL.md`
6. `skills/08_latex_report_writer/SKILL.md`

你的任务是从零完成计算机系统基础实验，并维护一份总实验报告。

## 强约束

- 先做实验，后写报告。
- 每个关键命令必须保存到 `commands.md` 和 `outputs/`。
- 每张截图必须登记到 `screenshots_index.md`。
- 报告结论必须有证据编号支撑。
- 总报告必须服从用户提供的报告模板结构。
- 正式实验报告正文不得写 AI 使用说明。
- AI 使用记录只写入 `journals/ai_assistance_log.md`。

## 当前总报告位置

- LaTeX：`report/main.tex`
- Word 源：`report/word_source.md`
- 构建脚本：`report/build_total_report.ps1`


## 外部 Skill 参考要求

你可以参考 `docs/external_skill_reference_inventory.md` 中总结的外部 skill 思想，但不得直接运行第三方脚本。需要使用外部 skill 时，先按 `skills/16_external_skill_safety_auditor/SKILL.md` 做安全审查，再将安全流程改写为本项目内部操作。

优先使用以下本项目适配版 skill：

1. `11_latex_build_preview_checker`：编译和检查总 LaTeX 报告；
2. `12_mermaid_diagram_generator_validator`：生成并校验 Mermaid 图表；
3. `13_markdown_document_converter`：维护 Markdown/Word 输出链；
4. `14_git_github_workflow_manager`：生成和检查 GitHub 提交流程；
5. `15_codebase_walkthrough_generator`：生成代码阅读笔记与调用关系图；
6. `16_external_skill_safety_auditor`：审查外部 skill。

## 总报告硬性目标

最终总报告必须不少于 50 页，并且必须包含有效附录。页数必须来自真实实验过程、代码/汇编/ELF/栈帧分析、图表、结果解释和证据附录，不得通过空白页或重复内容凑页数。

你在每个实验中都必须持续积累正文材料和附录材料：

- 正文材料写入 `experiments/<lab>/notes/report_material_bank.md`；
- 附录材料写入 `experiments/<lab>/notes/appendix_candidates.md`；
- 证据映射写入 `experiments/<lab>/evidence/evidence_manifest.md`；
- 最终报告前运行 `python scripts/final_report_gate.py`。

## No-guess confirmation protocol

Before filling cover metadata or writing final report sections, read `config/report_metadata.yaml` and `05_HUMAN_CONFIRMATION_PROTOCOL.md`. If any required metadata field is `待填写`, empty, or not user-confirmed, stop and ask the user. Do not infer personal information from any other source.

When uncertain, use `codex_prompts/07_ASK_USER_WHEN_UNCERTAIN_PROMPT.md` and record the question in `evidence/human_questions.md`.
