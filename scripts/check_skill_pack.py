#!/usr/bin/env python3
from pathlib import Path
import re, sys
root = Path(__file__).resolve().parents[1]
skills = root / 'skills'
errors = []
for d in sorted(p for p in skills.iterdir() if p.is_dir()):
    sk = d / 'SKILL.md'
    if not sk.exists():
        errors.append(f'missing SKILL.md: {d.name}')
        continue
    text = sk.read_text(encoding='utf-8', errors='ignore')
    if 'name:' not in text or 'description:' not in text:
        errors.append(f'missing name/description frontmatter: {d.name}')
    risky = [r'rm\s+-rf', r'curl\s+.*\|\s*(sh|bash)', r'wget\s+.*\|\s*(sh|bash)', r'git\s+push\s+--force', r'\.ssh', r'token', r'cookie']
    for pat in risky:
        if re.search(pat, text, re.I):
            print(f'[review] {d.name}: pattern mentioned for safety check: {pat}')
if errors:
    print('\n'.join(errors))
    sys.exit(1)
print(f'OK: {len([p for p in skills.iterdir() if p.is_dir()])} skill folders checked')
