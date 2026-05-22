---
name: human_confirmation_gatekeeper
description: Stop Codex from guessing missing or uncertain information. Use this skill whenever personal metadata, experiment requirements, environment choices, results, evidence, GitHub operations, or report claims are incomplete, ambiguous, or unverifiable.
---

# Human Confirmation Gatekeeper Skill

## Purpose

This skill enforces the project rule: **do not guess**. If required information is missing or uncertain, Codex must stop and ask the user.

## Trigger conditions

Use this skill when any of the following are unknown, incomplete, conflicting, or unverifiable:

- student name
- student ID
- major/class
- instructor
- report date
- GitHub repository URL
- whether a lab should be executed on Windows, Visual Studio, MSVC/MASM, WSL, gcc, or gdb
- mapping between a requirement document and an experiment directory
- compilation or runtime result
- GDB address, stack offset, cookie, attack string, binary bomb answer
- ELF section/symbol/relocation interpretation
- screenshot content or screenshot file path
- report claim without evidence
- deletion/overwrite/move of original materials
- GitHub push, especially first push or force push

## Required behavior

1. Stop the current action.
2. Summarize what has been verified.
3. Ask the user using the required format.
4. Record the question in `evidence/human_questions.md`.
5. Do not proceed until the user answers.

## Required question format

```text
【需要你确认】
当前实验/模块：
当前步骤：
不确定的问题：
我已经检查过的文件/命令：
可能选项：
A.
B.
C.
我的建议：
需要你回复：
```

## Forbidden behavior

- Do not fill report metadata from memory, chat history, Git config, OS username, or file names.
- Do not invent experiment results.
- Do not write “observed” unless the observation exists in `outputs/`, `screenshots/`, GDB logs, or evidence files.
- Do not use assumptions for personal information or experimental conclusions.
- Do not hide uncertainty by using vague wording.

## Output files

When this skill is used, update one of these files:

```text
experiments/<lab>/evidence/human_questions.md
experiments/<lab>/evidence/assumptions.md
```

For project-level metadata questions, also refer to:

```text
config/report_metadata.yaml
05_HUMAN_CONFIRMATION_PROTOCOL.md
```

## Completion condition

The issue is resolved only after the user explicitly answers or confirms the required value. Then update the relevant file and continue.
