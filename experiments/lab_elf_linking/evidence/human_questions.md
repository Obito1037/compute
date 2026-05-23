# 人工确认问题记录

本文件记录 Codex 在不确定时向用户提出的问题。Codex 不允许把不确定内容写成事实。

| 编号 | 时间 | 实验/模块 | 当前步骤 | 不确定内容 | 已检查文件/命令 | 选项 | 用户确认 | 状态 |
|---|---|---|---|---|---|---|---|---|
| Q001 | 2026-05-23 11:33:00 +08:00 | 实验五 ELF 文件与程序链接 | 修改 `main.c` 工作副本 | 源码中 `strcpy(uninit_gstr2,"xuxy"); // 请换成自己的姓名拼音` 需要姓名拼音，但拼音写法未由 `config/report_metadata.yaml` 或用户明确确认提供，不能猜测 | `original_materials/parsed_text/6_link_report_task.docx.txt`；`experiments/lab_elf_linking/src/original_copy/main.c` | A. 使用你明确回复的姓名拼音；B. 不修改该字符串并在证据中说明任务书正文只列出两处必改项 | 用户确认“姓名是张家梁 如果溢出填zjl”；因 `char uninit_gstr2[12]` 不适合存放完整姓名拼音，工作副本使用 `zjl` | 已解决 |

状态建议：已解决 / 无需处理。最终提交前不得保留未处理问题。
