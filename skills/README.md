# Skills 说明

本目录包含 HUST 计算机系统基础实验专用 skills。

## 核心 Skills

| Skill | 作用 |
|---|---|
| `00_master_workflow` | 总控实验流程 |
| `01_requirement_reader` | 读取任务书并生成要求摘要 |
| `02_experiment_evidence_logger` | 记录命令、输出、截图、错误、证据 |
| `03_code_static_analyzer` | 分析源码和关键数据结构 |
| `04_gdb_disassembly_analyzer` | 分析 GDB、反汇编、寄存器和栈 |
| `05_memory_stack_diagrammer` | 生成内存布局、栈帧和控制流图 |
| `06_elf_linking_analyzer` | 分析 ELF、符号表、重定位和链接 |
| `07_asm_c_mixed_programming_analyzer` | 分析 C/ASM 混合编程与优化 |
| `08_latex_report_writer` | 生成总 LaTeX 实验报告 |
| `09_format_checker` | 检查报告格式 |
| `10_authenticity_checker` | 检查报告真实性和证据链 |

## 参考外部 Skill 后新增的适配版 Skills

| Skill | 参考方向 |
|---|---|
| `11_latex_build_preview_checker` | LaTeX document skill |
| `12_mermaid_diagram_generator_validator` | Mermaid diagram skill |
| `13_markdown_document_converter` | Markdown converter/exporter skill |
| `14_git_github_workflow_manager` | Git workflow skill |
| `15_codebase_walkthrough_generator` | Code walkthrough / literate programming skill |
| `16_external_skill_safety_auditor` | 外部 skill 安全审查 |

注意：本项目没有直接复制第三方 skill 脚本。外部 skill 只作为方法参考。

## 50 页以上总报告相关 Skill

新增 `17_report_depth_and_appendix_builder`。它负责把最终总报告的页数、内容充实度和附录组织纳入硬性检查。任何正式生成报告的流程都应同时调用：

- `08_latex_report_writer`
- `09_format_checker`
- `10_authenticity_checker`
- `11_latex_build_preview_checker`
- `17_report_depth_and_appendix_builder`

## 18_human_confirmation_gatekeeper

用于强制执行“不懂就问，不允许猜”的规则。凡是姓名、学号、专业班级、指导教师、报告日期、GitHub 仓库地址、实验环境、实验结果、GDB 地址、攻击字符串、截图内容、报告结论证据等不确定时，必须停止并向用户提问。
