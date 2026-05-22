#!/usr/bin/env python3
"""Initialize/check one experiment directory."""
from pathlib import Path
import sys

REQUIRED = [
    'evidence/environment.md',
    'evidence/commands.md',
    'evidence/errors_and_fixes.md',
    'evidence/evidence_manifest.md',
    'evidence/screenshots_index.md',
    'evidence/report_claims_checklist.md',
    'outputs/README.md',
    'screenshots/README.md',
    'notes/code_analysis.md',
]

def main():
    if len(sys.argv) != 2:
        print('Usage: python scripts/init_lab.py experiments/<lab>')
        sys.exit(1)
    lab = Path(sys.argv[1])
    lab.mkdir(parents=True, exist_ok=True)
    for rel in REQUIRED:
        p = lab / rel
        p.parent.mkdir(parents=True, exist_ok=True)
        if not p.exists():
            p.write_text(f'# {p.name}\n\n', encoding='utf-8')
            print('created', p)
    print('lab checked:', lab)

if __name__ == '__main__':
    main()
