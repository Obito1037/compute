#!/usr/bin/env python3
from pathlib import Path
import re, subprocess, sys

PDF = Path('report/build/main.pdf')
MIN_PAGES = 50


def page_count_with_pypdf(path: Path):
    try:
        from pypdf import PdfReader
        return len(PdfReader(str(path)).pages)
    except Exception:
        pass
    try:
        from PyPDF2 import PdfReader
        return len(PdfReader(str(path)).pages)
    except Exception:
        pass
    return None


def page_count_with_pdfinfo(path: Path):
    try:
        out = subprocess.check_output(['pdfinfo', str(path)], text=True, stderr=subprocess.STDOUT)
        m = re.search(r'^Pages:\s*(\d+)', out, re.M)
        if m:
            return int(m.group(1))
    except Exception:
        return None


def main():
    if not PDF.exists():
        print(f'FAIL: missing {PDF}')
        return 1
    pages = page_count_with_pypdf(PDF) or page_count_with_pdfinfo(PDF)
    if pages is None:
        print('FAIL: cannot determine PDF page count. Install pypdf/PyPDF2 or pdfinfo.')
        return 1
    print(f'PDF page count: {pages}')
    if pages < MIN_PAGES:
        print(f'FAIL: final report must be at least {MIN_PAGES} pages. Current: {pages}.')
        print('Do not add blank pages. Add evidence-backed process, analysis, figures, tables, and appendices.')
        return 1
    print('PASS: page count requirement satisfied.')
    return 0

if __name__ == '__main__':
    raise SystemExit(main())
