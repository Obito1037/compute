$ErrorActionPreference = "Stop"

Write-Host "[0/3] Sync report metadata"
python ..\scripts\sync_report_metadata.py
New-Item -ItemType Directory -Force -Path build | Out-Null

Write-Host "[1/3] Build PDF"
if (Get-Command xelatex -ErrorAction SilentlyContinue) {
    xelatex -interaction=nonstopmode -halt-on-error -output-directory=build main.tex
    xelatex -interaction=nonstopmode -halt-on-error -output-directory=build main.tex
} elseif (Get-Command lualatex -ErrorAction SilentlyContinue) {
    lualatex -interaction=nonstopmode -halt-on-error -output-directory=build main.tex
    lualatex -interaction=nonstopmode -halt-on-error -output-directory=build main.tex
} else {
    throw "未找到 xelatex 或 lualatex。中文 LaTeX 报告建议使用 XeLaTeX。你当前有 TeX Live，但仍需确认 xelatex --version 可运行。"
}

Write-Host "[2/3] Build Word"
if (Get-Command pandoc -ErrorAction SilentlyContinue) {
    pandoc word_source.md -o build/main.docx --metadata=lang:zh-CN
    Write-Host "Word generated: build/main.docx"
} else {
    Write-Host "Pandoc not found. Word output skipped. Install Pandoc to generate build/main.docx."
}

Write-Host "[3/3] Done"
Write-Host "PDF: build/main.pdf"
Write-Host "Word: build/main.docx"

Write-Host "After final content is complete, run from project root:" -ForegroundColor Yellow
Write-Host "python scripts/final_report_gate.py" -ForegroundColor Yellow
