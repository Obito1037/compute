#!/usr/bin/env python3
"""Render Mermaid files if mmdc is installed."""
from pathlib import Path
import subprocess, shutil, sys
if shutil.which('mmdc') is None:
    print('mmdc not found. Install @mermaid-js/mermaid-cli if rendering is required.')
    sys.exit(0)
for src in Path('experiments').rglob('diagrams/source/*.mmd'):
    out = src.parents[1] / 'rendered' / (src.stem + '.png')
    out.parent.mkdir(parents=True, exist_ok=True)
    subprocess.run(['mmdc','-i',str(src),'-o',str(out)], check=False)
    print(out)
