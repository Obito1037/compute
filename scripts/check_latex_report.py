#!/usr/bin/env python3
from pathlib import Path
import sys

main = Path('report/main.tex')
if not main.exists():
    print('FAIL: missing report/main.tex')
    raise SystemExit(1)
text = main.read_text(encoding='utf-8', errors='ignore')
required = [
    '01_lab01_data_representation',
    '02_lab02_asm_c_optimization',
    '03_binary_bomb',
    '04_bufbomb',
    '05_elf_linking',
    '06_final_summary',
    '08_appendix_evidence_index',
    '09_appendix_commands_outputs',
    '10_appendix_code_listings',
    '11_appendix_debug_logs',
    '12_appendix_figures_tables',
    '13_appendix_git_history',
]
failed = False
for s in required:
    ok = s in text
    print(s, 'OK' if ok else 'FAIL')
    failed = failed or not ok
if 'ai_assistance' in text.lower() or 'AI 使用' in text:
    print('FAIL: formal LaTeX report must not include AI usage notes')
    failed = True
if failed:
    raise SystemExit(1)
print('PASS: LaTeX main structure contains all required sections and appendices.')
