#!/usr/bin/env python3
from pathlib import Path
import re, sys

ROOT = Path('.')
REPORT_DIR = ROOT / 'report'
SECTIONS = REPORT_DIR / 'sections'
LAB_SECTION_FILES = [
    '01_lab01_data_representation.tex',
    '02_lab02_asm_c_optimization.tex',
    '03_binary_bomb.tex',
    '04_bufbomb.tex',
    '05_elf_linking.tex',
]
REQUIRED_APPENDICES = [
    '08_appendix_evidence_index.tex',
    '09_appendix_commands_outputs.tex',
    '10_appendix_code_listings.tex',
    '11_appendix_debug_logs.tex',
    '12_appendix_figures_tables.tex',
    '13_appendix_git_history.tex',
]
PLACEHOLDER_PATTERNS = ['待填写', 'TODO', '示例内容', '待补充']


def read(path: Path) -> str:
    return path.read_text(encoding='utf-8', errors='ignore') if path.exists() else ''


def strip_tex_commands(text: str) -> str:
    text = re.sub(r'%.*', '', text)
    text = re.sub(r'\\[a-zA-Z]+(\[[^\]]*\])?(\{[^{}]*\})?', ' ', text)
    text = re.sub(r'[{}\\]', ' ', text)
    return text


def cn_char_count(text: str) -> int:
    return len(re.findall(r'[\u4e00-\u9fff]', strip_tex_commands(text)))


def count_patterns(text: str, patterns):
    return {p: text.count(p) for p in patterns if text.count(p)}


def main():
    failed = False
    print('== Report depth check ==')
    for name in LAB_SECTION_FILES:
        path = SECTIONS / name
        if not path.exists():
            print(f'FAIL: missing {path}')
            failed = True
            continue
        text = read(path)
        count = cn_char_count(text)
        print(f'{name}: Chinese chars={count}')
        if count < 2500:
            print(f'  WARN: {name} is likely too thin for a 50+ page final report. Target 4000-6000 Chinese chars plus figures/tables.')
        for sub in ['实验概述', '实验内容', '实验设计', '实验过程', '实验结果', '实验小结']:
            if sub not in text:
                print(f'  FAIL: missing subsection keyword {sub}')
                failed = True
    for name in REQUIRED_APPENDICES:
        path = SECTIONS / name
        if not path.exists():
            print(f'FAIL: missing appendix file {path}')
            failed = True
    all_text = '\n'.join(read(p) for p in SECTIONS.glob('*.tex'))
    placeholders = count_patterns(all_text, PLACEHOLDER_PATTERNS)
    if placeholders:
        print('FAIL: placeholder text still exists:', placeholders)
        failed = True
    if 'AI 使用' in all_text or 'ai_assistance' in all_text.lower():
        print('FAIL: AI usage appears in formal report sections. Keep it only in journals/ai_assistance_log.md')
        failed = True
    if failed:
        return 1
    print('PASS: structural depth checks passed.')
    return 0

if __name__ == '__main__':
    raise SystemExit(main())
