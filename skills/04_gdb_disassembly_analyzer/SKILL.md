---
name: 04_gdb_disassembly_analyzer
description: gdb disassembly analyzer
---

# GDB 与反汇编分析器

## 触发场景

当进行 binary bomb、bufbomb、反汇编、寄存器或栈帧分析时触发。

## 输入

- 当前实验目录 `experiments/<lab>/`
- 原始材料 `original_materials/`
- 项目规则文件 `01_PROJECT_RULES.md`

## 工作流程

1. 记录 GDB 命令。
2. 保存反汇编、寄存器、栈内存输出。
3. 提取关键跳转、比较、函数地址、返回地址。
4. 对每一步推导写入 `notes/debug_notes.md`。
5. 不直接给无证据最终答案。

## 输出

- GDB 输出文件
- `notes/debug_notes.md`
- 控制流分析
- 栈帧分析

## 禁止事项

- 不得编造未运行的命令、未保存的输出、未登记的截图。
- 不得直接把推测写成实验事实。
- 不得修改 `original_materials/` 中的原始材料。
