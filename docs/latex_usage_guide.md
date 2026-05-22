# LaTeX 使用指南

本项目使用 XeLaTeX 编译中文报告。

## Windows PowerShell

```powershell
cd report
.\build_total_report.ps1
```

## Linux / WSL

```bash
cd report
make pdf
```

## Word 输出

优先使用 Pandoc：

```bash
pandoc word_source.md -o build/main.docx
```

如果没有 Pandoc，可先只提交 PDF，并在 `evidence/latex_build_log.md` 记录 Word 生成环境缺失。


## 参考 LaTeX Document Skill 后的补充流程

每次修改报告后建议执行：

```bash
python scripts/check_latex_report.py
python scripts/build_report.py
python scripts/render_report_previews.py
```

检查内容：

1. `report/build/main.pdf` 是否生成；
2. `report/build/main.docx` 是否生成；
3. PDF 预览图是否可读；
4. 封面、目录、实验章节、实验总结是否完整；
5. 正式报告正文是否不包含 AI 使用说明。
