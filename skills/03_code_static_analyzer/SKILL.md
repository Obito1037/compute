---
name: 03_code_static_analyzer
description: code static analyzer
---

# 代码静态分析器

## 触发场景

当需要解释 C、头文件、汇编文件、函数调用关系和数据结构时触发。

## 输入

- 当前实验目录 `experiments/<lab>/`
- 原始材料 `original_materials/`
- 项目规则文件 `01_PROJECT_RULES.md`

## 工作流程

1. 阅读 `src/` 中源码。
2. 提取函数、结构体、全局变量和关键逻辑。
3. 分析结构体布局、字段偏移、调用关系。
4. 生成 `notes/code_analysis.md`。
5. 必要时生成 Mermaid/PlantUML 图表源文件。

## 输出

- `notes/code_analysis.md`
- 调用关系图
- 结构体布局说明

## 禁止事项

- 不得编造未运行的命令、未保存的输出、未登记的截图。
- 不得直接把推测写成实验事实。
- 不得修改 `original_materials/` 中的原始材料。
