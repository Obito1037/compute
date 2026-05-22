#!/usr/bin/env python3
from pathlib import Path
labs = Path('experiments')
required = ['evidence/commands.md','evidence/evidence_manifest.md','evidence/screenshots_index.md','evidence/report_claims_checklist.md']
ok = True
for lab in sorted(labs.iterdir()):
    if not lab.is_dir():
        continue
    print(f'[{lab.name}]')
    for rel in required:
        p = lab / rel
        status = 'OK' if p.exists() and p.stat().st_size > 0 else 'MISSING/EMPTY'
        print(' ', rel, status)
        if status != 'OK': ok = False
raise SystemExit(0 if ok else 1)
