---
name: codebase-walkthrough-generator
description: 参考 walkthrough 和 literate-programming skill 思想，为实验源码生成代码阅读笔记、调用关系图和报告可用解释。
---

# 代码 Walkthrough 生成 Skill

## 触发条件

当需要解释实验源码、汇编文件、函数调用关系、结构体布局或关键算法时触发。

## 适用实验

- 实验一：`lab1.c`、`lab1.h`、结构体、位运算、浮点表示；
- 实验二：C 与 ASM 混合编程、排序优化；
- 二进制炸弹：反汇编函数和控制流；
- 缓冲区溢出炸弹：`getbuf`、栈帧、攻击字符串；
- ELF 链接实验：`main.c`、`sub.c`、符号引用关系。

## 必须读取

1. `experiments/<lab>/src/`
2. `experiments/<lab>/outputs/`
3. `experiments/<lab>/notes/code_analysis.md`
4. `experiments/<lab>/diagrams/source/`
5. `docs/report_writing_standard.md`

## 输出

- `experiments/<lab>/notes/code_analysis.md`
- `experiments/<lab>/notes/principle_notes.md`
- `experiments/<lab>/diagrams/source/function_call_graph.mmd`
- 报告可用的关键代码节选

## 写作规则

1. 先说明代码文件职责，再说明关键函数。
2. 解释必须对应源码行、函数名或实验输出。
3. 关键代码节选不宜过长。
4. 代码解释应服务于报告的“实验设计”和“实验过程”。
5. 不确定的行为必须通过运行、GDB 或反汇编确认。

## 禁止事项

- 不得仅凭函数名编造功能。
- 不得跳过源码直接写报告结论。
- 不得把未验证的推测写成事实。
- 不得大段复制无分析的源码到报告。
