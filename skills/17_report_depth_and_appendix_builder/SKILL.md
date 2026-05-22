---
name: report-depth-and-appendix-builder
description: Enforce a substantial 50+ page total lab report by planning content depth, evidence-backed writing, and structured appendices without padding or fabricated content.
---

# Report Depth and Appendix Builder

Use this skill whenever generating, expanding, or final-checking the total experiment report.

## Trigger

Activate when the user asks to:

- make the report content more substantial;
- ensure the final report is 50+ pages;
- add appendices;
- avoid 水字数 / filler writing;
- prepare the final PDF/DOCX for submission.

## Required inputs

Read these files first:

1. `04_REPORT_DEPTH_AND_APPENDIX_REQUIREMENTS.md`
2. `docs/report_depth_and_appendix_policy.md`
3. `report/main.tex`
4. `report/sections/*.tex`
5. `experiments/*/notes/report_material_bank.md`
6. `experiments/*/notes/appendix_candidates.md`
7. `experiments/*/evidence/evidence_manifest.md`
8. `experiments/*/evidence/content_depth_checklist.md`

## Non-negotiable rules

- Final PDF must be at least 50 pages.
- Do not add blank pages to satisfy page count.
- Do not paste long raw output without explanation.
- Do not repeat screenshots.
- Do not copy the lab task book as report content.
- Do not invent commands, outputs, screenshots, addresses, register values, timings, or conclusions.
- AI usage records stay in `journals/ai_assistance_log.md` and must not enter the formal report body.

## Content expansion method

For each experiment, expand by adding real analytical content:

1. Explain task objective and system-level significance.
2. Explain relevant theory: data representation, ABI/calling convention, disassembly, stack frame, ELF/linking, etc.
3. Describe actual steps with command/output evidence.
4. Analyze code, assembly, memory, stack, symbol table, relocation table, or runtime behavior.
5. Add figures/tables that clarify structure or results.
6. Move long commands, logs, and code listings to appendices.
7. Reference appendix evidence from the body.

## Appendix construction

Build appendices in this order:

- Appendix A: Key command and evidence index.
- Appendix B: Key code and assembly listings.
- Appendix C: GDB and debugging log excerpts.
- Appendix D: ELF/readelf/objdump outputs.
- Appendix E: Figures and screenshots index.
- Appendix F: Git commit history summary.

## Final gate

After generating PDF/DOCX, run:

```bash
python scripts/final_report_gate.py
```

If it fails, improve the report using evidence-backed content. Do not bypass the gate.

## Human confirmation gate

If required information is missing, ambiguous, conflicting, or unsupported by evidence, invoke `skills/18_human_confirmation_gatekeeper/SKILL.md`. Do not guess. For report metadata, use only `config/report_metadata.yaml`; if it contains `待填写`, stop and ask the user.
