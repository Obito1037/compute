---
name: latex-build-preview-checker
description: 参考 LaTeX document skill 思想，对总实验报告执行编译、日志保存、PDF/DOCX 输出和预览检查。
---

# LaTeX 编译与预览检查 Skill

## 触发条件

当用户或 Codex 要求：

- 编译总实验报告；
- 生成 PDF；
- 生成 Word；
- 检查 LaTeX 错误；
- 检查 PDF/DOCX 输出是否存在；
- 修复报告编译问题。

## 必须读取

1. `report/main.tex`
2. `report/preamble.tex`
3. `report/sections/*.tex`
4. `report/build_total_report.ps1`
5. `report/Makefile`
6. `experiments/*/evidence/latex_build_log.md`
7. `docs/report_template_alignment.md`
8. `docs/latex_usage_guide.md`

## 推荐流程

1. 先检查 `report/main.tex` 是否引用了全部章节。
2. 检查封面、目录、五个实验章节、实验总结、参考资料、附录是否存在。
3. 执行 XeLaTeX：

```bash
cd report
xelatex -interaction=nonstopmode -halt-on-error -output-directory=build main.tex
xelatex -interaction=nonstopmode -halt-on-error -output-directory=build main.tex
```

4. 若存在 `pandoc`，生成 Word：

```bash
pandoc word_source.md -o build/main.docx --metadata=lang:zh-CN
```

5. 保存编译摘要到：

```text
report/build/template_build_note.md
```

6. 若编译失败，只修复最小必要问题，不得重写整个报告。

## 中文 LaTeX 约束

- 优先使用 `xelatex`。
- 使用 `ctexart`。
- 不优先使用 `minted`，避免 `-shell-escape`。
- 代码排版优先使用 `listings`。
- 图片路径应使用相对路径，避免 Windows 绝对路径。

## 禁止事项

- 不得删除用户提供的报告模板文件。
- 不得把 AI 使用说明写进 `report/sections/*.tex`。
- 不得为了通过编译而删除实验章节。
- 不得在未确认原因时清空 `.tex` 文件。
- 不得把 LaTeX 编译错误伪装成成功。

## 输出

- `report/build/main.pdf`
- `report/build/main.docx`（若有 Pandoc）
- `report/build/template_build_note.md`
- 必要时更新 `experiments/*/evidence/latex_build_log.md`
