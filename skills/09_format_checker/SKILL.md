---
name: format-checker
description: 检查实验报告是否符合用户提供的封面、目录和正文目录结构模板。
---

# 格式检查 Skill

## 检查项目

1. 封面是否包含课程名称、专业班级、学号、姓名、指导教师、报告日期、学院名称。
2. 是否有目录。
3. 是否包含 5 个实验章节和实验总结。
4. 每个实验是否包含实验概述、实验内容、实验设计、实验过程、实验结果、实验小结。
5. 阶段性实验是否包含任务描述、实验设计、实验过程、实验结果。
6. 实验总结是否不少于 400 字。
7. 图题是否在图下，表题是否在表上。
8. 代码块和命令输出是否排版清晰。
9. PDF 和 Word 是否均能生成。
10. 正式报告正文是否未包含 AI 使用说明。

## 输出

将检查结果写入 `report/build/format_check.md` 或对应实验 `evidence/report_claims_checklist.md`。

## 页数与附录格式检查

格式检查必须额外确认：

- PDF 页数不少于 50 页；
- 附录编号和目录项完整；
- 附录表格没有跨页破损；
- 长代码和长命令输出使用 `lstlisting` 或表格整理；
- 正文引用了附录证据编号；
- 报告不存在 `待填写`、`TODO` 等占位符。

## Human confirmation gate

If required information is missing, ambiguous, conflicting, or unsupported by evidence, invoke `skills/18_human_confirmation_gatekeeper/SKILL.md`. Do not guess. For report metadata, use only `config/report_metadata.yaml`; if it contains `待填写`, stop and ask the user.
