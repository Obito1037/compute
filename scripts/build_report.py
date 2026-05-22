#!/usr/bin/env python3
import subprocess, shutil, sys
from pathlib import Path
report = Path('report')
# Generate LaTeX metadata from config/report_metadata.yaml. This does not validate completeness.
subprocess.run([sys.executable, 'scripts/sync_report_metadata.py'], check=True)
(report/'build').mkdir(exist_ok=True)
cmd = ['xelatex','-interaction=nonstopmode','-halt-on-error','-output-directory=build','main.tex']
for _ in range(2):
    subprocess.run(cmd, cwd=report, check=True)
if shutil.which('pandoc'):
    subprocess.run(['pandoc','word_source.md','-o','build/main.docx'], cwd=report, check=True)
else:
    print('pandoc not found; Word output skipped')
