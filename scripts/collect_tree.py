#!/usr/bin/env python3
from pathlib import Path
import sys
root = Path(sys.argv[1]) if len(sys.argv) > 1 else Path('.')
for p in sorted(root.rglob('*')):
    if '.git' in p.parts:
        continue
    print(p)
