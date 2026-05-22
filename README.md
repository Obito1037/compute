# 华中科技大学计算机系统基础实验工作流包

本项目用于从零完成计算机系统基础实验，并形成可追溯的总实验报告。

## 当前版本特点

- 已接入用户提供的正式报告模板：`original_materials/report_templates/实验报告封面及正文目录结构.docx`
- 总报告采用 LaTeX 编写：`report/main.tex`
- Word 版本由 `report/word_source.md` 通过 Pandoc 生成
- PDF 版本由 XeLaTeX 生成
- AI 使用记录单独保存在 `journals/ai_assistance_log.md`，不得写入正式报告正文
- Codex 工作流采用强约束：先执行实验、保存证据、再撰写报告

## 推荐起步命令

```powershell
cd report
.\build_total_report.ps1
```

生成结果：

- `report/build/main.pdf`
- `report/build/main.docx`

## 给 Codex 的第一条指令

请阅读 `00_README_FOR_CODEX.md`、`01_PROJECT_RULES.md`、`02_EXPERIMENT_EXECUTION_POLICY.md`、`docs/report_template_alignment.md` 和 `codex_prompts/00_MASTER_PROMPT_FOR_CODEX.md`。从 `experiments/lab01_data_representation` 开始完成实验。严格遵守：先执行实验、保存命令和输出、登记截图和证据，再更新总 LaTeX 报告。正式实验报告正文不得写 AI 使用说明。


## 外部 Skill 参考适配

新版项目包新增了 `docs/external_skill_reference_inventory.md`、`docs/external_skill_enablement_guide.md` 和 `docs/skill_safety_policy.md`。这些文件说明了如何安全参考 GitHub 上的 Codex / Agent / LaTeX / Mermaid / Markdown / Git 类 skills。

本项目没有直接复制第三方脚本，而是新增了 6 个适配版 skill：

```text
skills/11_latex_build_preview_checker
skills/12_mermaid_diagram_generator_validator
skills/13_markdown_document_converter
skills/14_git_github_workflow_manager
skills/15_codebase_walkthrough_generator
skills/16_external_skill_safety_auditor
```

推荐给 Codex 的原则：外部 skill 只能作为参考，所有实验过程、证据、图表和报告内容必须在本项目目录内生成和记录。

## No-guess version update

This package includes a human confirmation protocol. Codex must not guess missing metadata or experiment facts. Required report metadata is stored in `config/report_metadata.yaml`. Final checks fail until required metadata is explicitly filled and `metadata_confirmed_by_user: true` is set.
