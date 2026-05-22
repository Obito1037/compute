#!/usr/bin/env python3
"""Extract original archives locally. Requires unrar/rar/7z for .rar files."""
from pathlib import Path
import shutil, subprocess, zipfile
src = Path('original_materials/source_archives')
out = Path('original_materials/extracted_local')
out.mkdir(parents=True, exist_ok=True)
for p in src.iterdir():
    target = out / p.stem
    target.mkdir(parents=True, exist_ok=True)
    if p.suffix.lower() == '.zip':
        with zipfile.ZipFile(p) as z:
            z.extractall(target)
        print('zip extracted', p)
    elif p.suffix.lower() == '.rar':
        tool = shutil.which('unrar') or shutil.which('rar') or shutil.which('7z')
        if not tool:
            print('skip rar; no unrar/rar/7z found:', p)
            continue
        if Path(tool).name == '7z':
            subprocess.run([tool, 'x', str(p), f'-o{target}', '-y'], check=False)
        else:
            subprocess.run([tool, 'x', '-y', '-o+', str(p), str(target)], check=False)
