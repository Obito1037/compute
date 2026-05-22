#!/usr/bin/env python3
from pathlib import Path
import subprocess, sys, os

ROOT = Path('.')


def run(cmd):
    print('> ' + ' '.join(cmd))
    return subprocess.call(cmd)


def main():
    checks = [
        ['python', 'scripts/check_report_metadata.py'],
        ['python', 'scripts/check_human_questions.py'],
        ['python', 'scripts/check_latex_report.py'],
        ['python', 'scripts/check_evidence.py'],
        ['python', 'scripts/check_report_depth.py'],
        ['python', 'scripts/check_report_page_count.py'],
    ]
    failed = False
    for cmd in checks:
        code = run(cmd)
        if code != 0:
            failed = True
    if failed:
        print('\nFINAL GATE: FAIL')
        print('Fix the report using real evidence-backed content. Do not pad with blank pages or duplicated material.')
        return 1
    print('\nFINAL GATE: PASS')
    return 0

if __name__ == '__main__':
    raise SystemExit(main())
