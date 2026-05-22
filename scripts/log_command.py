#!/usr/bin/env python3
"""Append a command record to experiments/<lab>/evidence/commands.md."""
from pathlib import Path
import argparse, datetime, os

parser = argparse.ArgumentParser()
parser.add_argument('--lab', required=True, help='lab directory name under experiments/')
parser.add_argument('--purpose', default='')
parser.add_argument('--output', default='')
parser.add_argument('command', nargs=argparse.REMAINDER)
args = parser.parse_args()

lab = Path('experiments') / args.lab
cmd = ' '.join(args.command).strip()
if cmd.startswith('--'):
    cmd = cmd[2:].strip()
path = lab / 'evidence' / 'commands.md'
path.parent.mkdir(parents=True, exist_ok=True)
if not path.exists():
    path.write_text('| 编号 | 时间 | 当前目录 | 命令 | 目的 | 输出文件 | 状态 |\n|---|---|---|---|---|---|---|\n', encoding='utf-8')
text = path.read_text(encoding='utf-8')
count = text.count('\n| C') + 1
now = datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S')
line = f'| C{count:03d} | {now} | {os.getcwd()} | `{cmd}` | {args.purpose} | {args.output} | 待执行/已执行 |\n'
with path.open('a', encoding='utf-8') as f:
    f.write(line)
print(line)
