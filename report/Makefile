PDF=build/main.pdf
DOCX=build/main.docx

sync-metadata:
	cd .. && python scripts/sync_report_metadata.py

pdf: sync-metadata
	mkdir -p build
	xelatex -interaction=nonstopmode -halt-on-error -output-directory=build main.tex
	xelatex -interaction=nonstopmode -halt-on-error -output-directory=build main.tex

word:
	mkdir -p build
	pandoc word_source.md -o $(DOCX) --metadata=lang:zh-CN

all: pdf word

clean:
	rm -rf build/*.aux build/*.log build/*.out build/*.toc

final-check:
	cd .. && python scripts/final_report_gate.py
