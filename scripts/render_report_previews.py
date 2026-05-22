#!/usr/bin/env python3
from pathlib import Path
import subprocess, shutil, sys
root = Path(__file__).resolve().parents[1]
pdf = root / 'report' / 'build' / 'main.pdf'
out = root / 'report' / 'build' / 'preview_png'
out.mkdir(parents=True, exist_ok=True)
if not pdf.exists():
    print('missing report/build/main.pdf; run build_report.py first')
    sys.exit(1)
if not shutil.which('pdftoppm'):
    print('pdftoppm not found; PDF preview skipped')
    sys.exit(0)
cmd = ['pdftoppm', '-png', '-r', '120', str(pdf), str(out/'page')]
subprocess.run(cmd, check=True)
print(f'PDF preview PNGs written to {out}')
