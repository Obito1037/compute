---
name: 02_experiment_evidence_logger
description: evidence logger
---

# 实验证据记录器

## 触发场景

当执行命令、保存输出、登记截图、记录错误时触发。

## 输入

- 当前实验目录 `experiments/<lab>/`
- 原始材料 `original_materials/`
- 项目规则文件 `01_PROJECT_RULES.md`

## 工作流程

1. 每条命令登记到 `evidence/commands.md`。
2. 标准输出和错误输出保存到 `outputs/`。
3. 错误修复写入 `evidence/errors_and_fixes.md`。
4. 截图写入 `screenshots/` 并登记到 `screenshots_index.md`。
5. 关键证据登记到 `evidence_manifest.md`。

## 输出

- `commands.md`
- `outputs/*.txt`
- `errors_and_fixes.md`
- `screenshots_index.md`
- `evidence_manifest.md`

## 禁止事项

- 不得编造未运行的命令、未保存的输出、未登记的截图。
- 不得直接把推测写成实验事实。
- 不得修改 `original_materials/` 中的原始材料。
