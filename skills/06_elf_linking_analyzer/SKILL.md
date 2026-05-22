---
name: 06_elf_linking_analyzer
description: elf linking analyzer
---

# ELF 与链接分析器

## 触发场景

当进行 readelf、objdump、重定位、符号表、静态/动态链接分析时触发。

## 输入

- 当前实验目录 `experiments/<lab>/`
- 原始材料 `original_materials/`
- 项目规则文件 `01_PROJECT_RULES.md`

## 工作流程

1. 保存 gcc 编译阶段输出。
2. 保存 `readelf -S -W`、`readelf -s`、`readelf -r` 输出。
3. 保存 `objdump -d` 和节十六进制输出。
4. 分析节、符号、重定位、链接顺序和动态链接机制。
5. 输出到 `notes/result_analysis.md`。

## 输出

- ELF 分析笔记
- 符号表解释
- 重定位解释
- 静态/动态链接对比

## 禁止事项

- 不得编造未运行的命令、未保存的输出、未登记的截图。
- 不得直接把推测写成实验事实。
- 不得修改 `original_materials/` 中的原始材料。
