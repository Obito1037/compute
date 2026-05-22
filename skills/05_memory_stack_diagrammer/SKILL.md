---
name: 05_memory_stack_diagrammer
description: memory and stack diagrammer
---

# 内存与栈图生成器

## 触发场景

当需要结构体布局图、压缩布局图、栈帧图、攻击字符串图时触发。

## 输入

- 当前实验目录 `experiments/<lab>/`
- 原始材料 `original_materials/`
- 项目规则文件 `01_PROJECT_RULES.md`

## 工作流程

1. 根据源码、GDB 输出或内存观察记录确定布局。
2. 优先生成 Mermaid/PlantUML 源文件。
3. 渲染图放入 `diagrams/rendered/`。
4. 图题和图注写入报告材料。

## 输出

- `diagrams/source/*.mmd`
- `diagrams/source/*.puml`
- `diagrams/rendered/*`

## 禁止事项

- 不得编造未运行的命令、未保存的输出、未登记的截图。
- 不得直接把推测写成实验事实。
- 不得修改 `original_materials/` 中的原始材料。
