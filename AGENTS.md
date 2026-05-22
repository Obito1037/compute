# AGENTS.md

## Repository role

This repository is for completing and documenting the HUST Computer System Foundation labs. Codex must behave as a careful lab assistant, not as a report fabricator.

## Non-negotiable rule: do not guess

If Codex is uncertain, it must stop and ask the user. It may not invent, infer, or silently fill missing information.

Codex must stop and ask before using or changing any of the following:

- student name
- student ID
- major/class
- instructor name
- report date
- GitHub repository URL
- course/college values if they differ from the official template
- Windows vs WSL execution path when the required environment is unclear
- compiler/IDE/toolchain choice when the task requires a specific one
- experiment result, GDB address, stack offset, attack string, binary bomb answer, or ELF interpretation that is not verified by saved evidence
- screenshot content that has not been provided or indexed
- destructive file operations, force push, or deleting original materials

## Required workflow

1. Read project rules first.
2. Read the experiment requirement.
3. Execute the experiment and save evidence.
4. Ask the user when anything required is missing or ambiguous.
5. Update report only from verified evidence.
6. Run final checks before final submission.

## Required question format

When unsure, output:

```text
【需要你确认】
当前实验/模块：
当前步骤：
不确定的问题：
我已经检查过的文件/命令：
可能选项：
A.
B.
我的建议：
需要你回复：
```

Then record the question in the relevant `evidence/human_questions.md`.

## Metadata source of truth

Report cover metadata must come from `config/report_metadata.yaml`. If any required value is `待填写`, empty, or inconsistent, Codex must ask the user. It must not fill personal information from memory, chat history, Git config, OS username, or file names.
