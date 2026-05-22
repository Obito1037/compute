---
name: 01_requirement_reader
description: requirement reader
---

# 实验要求读取器

## 触发场景

当需要从任务书中提取实验目标、任务和提交要求时触发。

## 输入

- 当前实验目录 `experiments/<lab>/`
- 原始材料 `original_materials/`
- 项目规则文件 `01_PROJECT_RULES.md`

## 工作流程

1. 阅读原始 docx/pptx 解析文本。
2. 提取实验目的、实验内容、必须回答的问题和截图要求。
3. 写入 `experiments/<lab>/requirement_summary.md`。
4. 标记评分风险点和容易遗漏的证据。

## 输出

- `requirement_summary.md`
- 必做任务清单
- 证据需求清单

## 禁止事项

- 不得编造未运行的命令、未保存的输出、未登记的截图。
- 不得直接把推测写成实验事实。
- 不得修改 `original_materials/` 中的原始材料。
