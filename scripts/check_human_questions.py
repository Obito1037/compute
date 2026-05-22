#!/usr/bin/env python3
from pathlib import Path
import sys

ROOT = Path(__file__).resolve().parents[1]
FLAGS = ['待回复', '未确认', 'UNRESOLVED', 'TODO_CONFIRM', '需要确认但未回复']


def main():
    failed = False
    for path in sorted((ROOT / 'experiments').glob('*/evidence/human_questions.md')):
        text = path.read_text(encoding='utf-8', errors='ignore')
        hits = [f for f in FLAGS if f in text]
        if hits:
            failed = True
            print(f'HUMAN QUESTION CHECK: unresolved markers in {path.relative_to(ROOT)}: {hits}')
    if failed:
        print('\nHUMAN QUESTION CHECK: FAIL')
        print('请先解决所有人工确认问题，不要让 Codex 猜测。')
        return 1
    print('HUMAN QUESTION CHECK: PASS')
    return 0

if __name__ == '__main__':
    raise SystemExit(main())
