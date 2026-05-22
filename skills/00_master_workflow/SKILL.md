---
name: 00_master_workflow
description: master workflow
---

# 总控实验流程

## 触发场景

当用户要求开始某个实验、整理实验过程或生成总报告时触发。

## 输入

- 当前实验目录 `experiments/<lab>/`
- 原始材料 `original_materials/`
- 项目规则文件 `01_PROJECT_RULES.md`

## 工作流程

1. 读取项目规则。
2. 读取当前实验 `requirement_summary.md`。
3. 检查证据文件是否存在。
4. 指导 Codex 按“读要求→执行→记录→分析→写报告→检查”顺序工作。
5. 在总报告生成前调用真实性和格式检查。

## 输出

- 实验阶段计划
- 待补证据清单
- 总报告生成任务列表

## 禁止事项

- 不得编造未运行的命令、未保存的输出、未登记的截图。
- 不得直接把推测写成实验事实。
- 不得修改 `original_materials/` 中的原始材料。

## Human confirmation gate

If required information is missing, ambiguous, conflicting, or unsupported by evidence, invoke `skills/18_human_confirmation_gatekeeper/SKILL.md`. Do not guess. For report metadata, use only `config/report_metadata.yaml`; if it contains `待填写`, stop and ask the user.
