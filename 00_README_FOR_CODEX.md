# Codex 使用总说明

你正在协助完成“华中科技大学计算机系统基础实验”项目。本项目目标是从零完成实验并生成总实验报告。

## 必须先阅读

1. `01_PROJECT_RULES.md`
2. `02_EXPERIMENT_EXECUTION_POLICY.md`
3. `docs/report_template_alignment.md`
4. `docs/report_writing_standard.md`
5. `codex_prompts/00_MASTER_PROMPT_FOR_CODEX.md`

## 总原则

- 先阅读实验要求，再执行实验。
- 先保存命令、输出、截图索引和错误修复记录，再写报告。
- 报告中的结论必须能追溯到 `experiments/*/evidence/` 或 `experiments/*/outputs/`。
- 正式实验报告正文不得写 AI 使用说明。
- AI 使用记录只写入 `journals/ai_assistance_log.md`。
- 总报告格式必须服从 `docs/report_template_alignment.md`。

## 报告结构

总报告位于 `report/main.tex`，采用用户提供的实验报告模板结构：

- 封面
- 目录
- 实验1：数据表示和等效运算
- 实验2：汇编和 C 的混合编程及优化
- 实验3：二进制炸弹
- 实验4：缓冲区溢出炸弹
- 实验5：ELF 文件与程序链接
- 实验总结（不少于 400 字）
- 附录：证据索引

## 构建报告

Windows PowerShell：

```powershell
cd report
.\build_total_report.ps1
```

Linux / WSL：

```bash
cd report
make all
```


## 外部 Skill 参考规则

本项目已经加入外部 skill 思想适配版。Codex 在使用前必须阅读：

1. `docs/external_skill_reference_inventory.md`
2. `docs/external_skill_enablement_guide.md`
3. `docs/skill_safety_policy.md`
4. `skills/README.md`

可使用的新增适配版 skill 包括：

- `11_latex_build_preview_checker`
- `12_mermaid_diagram_generator_validator`
- `13_markdown_document_converter`
- `14_git_github_workflow_manager`
- `15_codebase_walkthrough_generator`
- `16_external_skill_safety_auditor`

重要限制：不得直接运行未审查的 GitHub 外部 skill 脚本；不得覆盖本项目报告模板；不得把 AI 使用说明写入正式实验报告正文。

## 强制报告深度要求

正式总报告必须遵守 `04_REPORT_DEPTH_AND_APPENDIX_REQUIREMENTS.md` 与 `docs/report_depth_and_appendix_policy.md`。最终 PDF 少于 50 页时不得提交；不得通过空白页、重复截图、无分析的命令输出或复制任务书凑页数。所有新增内容必须服务于实验过程、结果解释、代码/汇编/ELF/栈帧分析或证据附录。

## 必须停下来询问的规则

Codex 不允许猜测任何关键缺失信息。尤其是姓名、学号、专业班级、指导教师、报告日期、GitHub 仓库地址，必须来自 `config/report_metadata.yaml` 或用户明确确认。

开始任何实验前，请先阅读：

```text
AGENTS.md
05_HUMAN_CONFIRMATION_PROTOCOL.md
codex_prompts/07_ASK_USER_WHEN_UNCERTAIN_PROMPT.md
skills/18_human_confirmation_gatekeeper/SKILL.md
```

如果不确定，必须输出“【需要你确认】”格式的问题，并记录到对应实验的 `evidence/human_questions.md`。
