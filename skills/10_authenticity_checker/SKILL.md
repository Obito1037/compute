---
name: 10_authenticity_checker
description: authenticity checker
---

# 真实性检查器

## 触发场景

当总报告成稿前或最终提交前触发。

## 输入

- 当前实验目录 `experiments/<lab>/`
- 原始材料 `original_materials/`
- 项目规则文件 `01_PROJECT_RULES.md`

## 工作流程

1. 抽取报告中的关键结论。
2. 检查是否有证据编号或文件路径支撑。
3. 检查命令、截图、输出是否已登记。
4. 标记无证据、弱证据和推测性表述。
5. 更新 `report_claims_checklist.md`。

## 输出

- 真实性检查清单
- 无证据结论列表
- 补证建议

## 禁止事项

- 不得编造未运行的命令、未保存的输出、未登记的截图。
- 不得直接把推测写成实验事实。
- 不得修改 `original_materials/` 中的原始材料。

## 防止“水字数”与伪证据

真实性检查除检查证据外，还必须检查：

- 是否存在大段无证据支撑的空泛总结；
- 是否重复使用相同截图或输出；
- 是否复制任务书而没有实验分析；
- 是否将 AI 推测写成实验事实；
- 是否通过无意义附录凑页数。

页数只有在支撑实验过程、结果、分析或证据追溯时才算有效。

## Human confirmation gate

If required information is missing, ambiguous, conflicting, or unsupported by evidence, invoke `skills/18_human_confirmation_gatekeeper/SKILL.md`. Do not guess. For report metadata, use only `config/report_metadata.yaml`; if it contains `待填写`, stop and ask the user.
