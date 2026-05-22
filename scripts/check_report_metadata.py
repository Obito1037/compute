#!/usr/bin/env python3
from pathlib import Path
import sys

ROOT = Path(__file__).resolve().parents[1]
META = ROOT / 'config' / 'report_metadata.yaml'
REQUIRED = {
    'course_name': '课程名称',
    'college': '学院',
    'major_class': '专业班级',
    'student_id': '学号',
    'student_name': '姓名',
    'instructor': '指导教师',
    'report_date': '报告日期',
    'github_repo': 'GitHub 仓库地址',
}
BAD_VALUES = {'', '待填写', 'TODO', 'todo', 'TBD', 'tbd', '未填写', 'unknown', 'Unknown'}


def parse_simple_yaml(path: Path):
    data = {}
    if not path.exists():
        print(f'Metadata file missing: {path}')
        return data
    for raw in path.read_text(encoding='utf-8').splitlines():
        line = raw.strip()
        if not line or line.startswith('#') or ':' not in line:
            continue
        key, val = line.split(':', 1)
        key = key.strip()
        val = val.strip().strip('"').strip("'")
        data[key] = val
    return data


def main():
    data = parse_simple_yaml(META)
    missing = []
    for key, label in REQUIRED.items():
        val = data.get(key, '').strip()
        if val in BAD_VALUES:
            missing.append((key, label))
    confirmed = data.get('metadata_confirmed_by_user', '').strip().lower()
    if confirmed not in {'true', 'yes', '1'}:
        missing.append(('metadata_confirmed_by_user', '用户确认标记 metadata_confirmed_by_user'))
    if missing:
        print('REPORT METADATA CHECK: FAIL')
        print('以下封面/提交信息未明确确认，Codex 不得猜测：')
        for key, label in missing:
            print(f'- {label} ({key})')
        print('\n请填写 config/report_metadata.yaml，并将 metadata_confirmed_by_user 设为 true。')
        return 1
    print('REPORT METADATA CHECK: PASS')
    return 0

if __name__ == '__main__':
    raise SystemExit(main())
