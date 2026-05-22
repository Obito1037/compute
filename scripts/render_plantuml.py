#!/usr/bin/env python3
"""Render PlantUML files if plantuml is installed."""
from pathlib import Path
import subprocess, shutil, sys
if shutil.which('plantuml') is None:
    print('plantuml not found. Install PlantUML if rendering is required.')
    sys.exit(0)
for src in Path('experiments').rglob('diagrams/source/*.puml'):
    subprocess.run(['plantuml','-tpng',str(src)], check=False)
    print(src)
