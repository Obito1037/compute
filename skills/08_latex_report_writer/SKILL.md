---
name: latex-report-writer
description: 基于真实证据生成计算机系统基础实验总 LaTeX 报告，严格对齐用户提供的实验报告模板。
---

# LaTeX 总报告撰写 Skill

## 触发条件

当用户或 Codex 要求生成、更新或检查实验报告时触发。

## 必须读取

1. `docs/report_template_alignment.md`
2. `report/main.tex`
3. `report/sections/*.tex`
4. `experiments/*/requirement_summary.md`
5. `experiments/*/evidence/evidence_manifest.md`
6. `experiments/*/evidence/commands.md`
7. `experiments/*/outputs/`
8. `journals/experiment_feelings_and_reflections.md`

## 模板结构强约束

正式报告必须采用：

- 封面
- 目录
- 实验1：数据表示和等效运算
- 实验2：汇编和 C 的混合编程及优化
- 实验3：二进制炸弹
- 实验4：缓冲区溢出炸弹
- 实验5：ELF 文件与程序链接
- 实验总结：不少于 400 字
- 参考资料
- 附录：关键命令与证据索引

每个实验必须包含：

- 实验概述
- 实验内容
- 实验设计
- 实验过程
- 实验结果
- 实验小结

阶段性实验在“实验内容”中按阶段展开，每个阶段包含：任务描述、实验设计、实验过程、实验结果。

## 禁止事项

- 不得无证据写“实验成功”“结果正确”“观察到”。
- 不得把 AI 使用说明写入正式实验报告正文。
- 不得把命令输出全文无筛选堆入正文。
- 不得删除封面和目录结构。

## 输出

- 更新 `report/sections/*.tex`
- 必要时同步更新 `report/word_source.md`
- 运行或提示运行 `report/build_total_report.ps1` 或 `make all`

## 50 页以上总报告写作要求

生成总 LaTeX 报告时必须遵守：

- 正式 PDF 不少于 50 页；
- 每个实验必须有足量的实验过程、代码/汇编/调试/ELF 分析、结果分析和图表；
- 附录必须结构化，不能只堆原始输出；
- 长输出放附录，正文保留关键片段并解释其意义；
- 最终运行 `python scripts/final_report_gate.py`。

不要通过空白页、重复截图或无分析文本凑页数。

## Human confirmation gate

If required information is missing, ambiguous, conflicting, or unsupported by evidence, invoke `skills/18_human_confirmation_gatekeeper/SKILL.md`. Do not guess. For report metadata, use only `config/report_metadata.yaml`; if it contains `待填写`, stop and ask the user.
