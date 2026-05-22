---
name: markdown-document-converter
description: 参考 markdown-converter 和 markdown-exporter 思想，将实验材料、过程记录、报告草稿在 Markdown、LaTeX、Word 之间进行安全转换。
---

# Markdown / Word / LaTeX 转换 Skill

## 触发条件

当需要进行以下任务时触发：

- 将实验任务书转换为 Markdown 摘要；
- 将过程记录整理为报告素材；
- 生成 `report/word_source.md`；
- 用 Pandoc 生成 Word；
- 从 Word 模板抽取目录结构；
- 对比 Markdown 草稿与 LaTeX 章节。

## 必须读取

1. `original_materials/report_templates/实验报告封面及正文目录结构.docx`
2. `docs/report_template_alignment.md`
3. `report/word_source.md`
4. `report/sections/*.tex`
5. `original_materials/parsed_text/*.txt`

## 推荐流程

1. 先把原始 Word/PDF/PPT 转换为 Markdown 或纯文本，仅作分析材料。
2. 从转换文本中提取任务要求和报告结构。
3. 将实验过程记录整理进 `word_source.md`。
4. 使用 Pandoc 生成 Word：

```bash
cd report
pandoc word_source.md -o build/main.docx --metadata=lang:zh-CN
```

5. 生成后检查章节顺序是否和 LaTeX 一致。

## 重要约束

- Word 版是辅助输出，正式结构以用户提供模板和 `report/main.tex` 为准。
- 转换后的 Markdown 不等于原始文件，不得覆盖原始材料。
- 不能把 AI 使用记录合并进正式报告的 Word 源文件。

## 禁止事项

- 不得删除 `original_materials/`。
- 不得把转换错误当成原始要求。
- 不得用外部转换器上传含个人信息或实验代码的文件。
- 不得覆盖 `report/main.tex`。

## 输出

- `original_materials/parsed_text/*.txt` 或 `.md`
- `report/word_source.md`
- `report/build/main.docx`
