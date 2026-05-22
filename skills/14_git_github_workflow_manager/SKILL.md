---
name: git-github-workflow-manager
description: 参考 Git 工作流 skill 思想，约束实验项目的 Git 初始化、分阶段提交、GitHub 推送和提交前检查。
---

# GitHub 提交流程 Skill

## 触发条件

当用户或 Codex 要求：

- 初始化 Git 仓库；
- 添加 `.gitignore`；
- 生成 commit；
- 推送 GitHub；
- 检查 Git 状态；
- 制定提交记录。

## 必须读取

1. `docs/git_github_workflow.md`
2. `.gitignore`
3. `03_FINAL_CHECKLIST.md`
4. `experiments/*/evidence/evidence_manifest.md`
5. `report/build/`

## 推荐 commit 粒度

每个实验至少使用以下提交阶段：

```text
docs: add original lab materials
chore: initialize lab workflow
lab01: summarize requirements and environment
lab01: record commands and outputs
lab01: add diagrams and notes
lab01: update report section
lab01: run evidence and format checks
```

后续实验依次使用：

```text
lab02:
bomb:
bufbomb:
elf:
report:
```

## 推送前检查

1. `git status` 查看变更。
2. 检查是否误加入临时文件、编译缓存、大型中间文件。
3. 确认 `original_materials/` 保留。
4. 确认 `journals/ai_assistance_log.md` 未进入正式报告。
5. 确认 `report/build/main.pdf` 和 `report/build/main.docx` 是否按需要保留。

## 禁止事项

- 未经用户确认不得执行 `git push --force`。
- 未经用户确认不得删除 Git 历史。
- 不得把 SSH 私钥、token、`.env`、个人隐私文件提交到仓库。
- 不得在未检查状态时批量提交全部文件。

## 输出

- 清晰的 commit 历史；
- GitHub 远程仓库推送记录；
- 必要时更新 `journals/progress_log.md`。

## Human confirmation gate

If required information is missing, ambiguous, conflicting, or unsupported by evidence, invoke `skills/18_human_confirmation_gatekeeper/SKILL.md`. Do not guess. For report metadata, use only `config/report_metadata.yaml`; if it contains `待填写`, stop and ask the user.
