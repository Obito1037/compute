# 外部 Skill 参考清单与本项目适配说明

本文件记录本项目参考过的外部 skill / agent skill 规范。原则是：**只吸收方法，不直接复制第三方脚本，不允许外部 skill 覆盖本项目的实验模板、证据规则和报告结构。**

## 1. 参考来源类型

| 类别 | 参考对象 | 本项目吸收的思想 | 是否直接引入代码 |
|---|---|---|---|
| Skill 规范 | OpenAI Codex Skills、Agent Skills 规范、VS Code Agent Skills | `SKILL.md` + 可选脚本/资料/模板的文件夹化结构；每个 skill 写明触发条件、输入、输出、禁止事项 | 否 |
| LaTeX 文档 | latex-document-skill 类项目 | 编译前检查、编译日志、PDF 预览、LaTeX 错误定位、中文文档兼容性 | 否 |
| Mermaid 图表 | mermaid-diagrams / mermaid-skill 类项目 | 图即代码、`.mmd` 源文件与渲染图分离、图表语义校验 | 否 |
| 文档转换 | markdown-converter / markdown-exporter 类项目 | 将 Word/PDF/PPT/Markdown 资料转为可检索文本；Markdown 到 Word 的导出流程 | 否 |
| Git 工作流 | here-be-git 类项目 | 初始化仓库、分阶段 commit、推送 GitHub、提交前检查 | 否 |
| 代码讲解 | walkthrough / literate-programming 类项目 | 代码 walkthrough、函数调用图、关键代码与解释结合 | 否 |
| 安全审查 | Agent Skill 安全建议 | 外部 skill 使用前必须阅读、审查脚本、限制权限、禁止执行不明下载命令 | 否 |

## 2. 本项目中新增的适配版 Skill

| 新增 Skill | 参考方向 | 适配目标 |
|---|---|---|
| `11_latex_build_preview_checker` | LaTeX document skill | 编译总报告、保存日志、渲染预览、记录 PDF/DOCX 输出状态 |
| `12_mermaid_diagram_generator_validator` | Mermaid diagram skill | 生成并校验结构图、流程图、栈帧图、ELF 链接图 |
| `13_markdown_document_converter` | markdown-converter / markdown-exporter | 将实验要求、过程记录、报告草稿转为 Markdown / DOCX 辅助材料 |
| `14_git_github_workflow_manager` | here-be-git | 约束 Git commit 粒度、提交信息格式、GitHub 推送流程 |
| `15_codebase_walkthrough_generator` | walkthrough / literate programming | 为实验源码生成代码阅读笔记、调用关系图和报告可用解释 |
| `16_external_skill_safety_auditor` | skill 安全审查 | 检查外部 skill 是否包含高风险命令、网络下载、密钥读取等行为 |

## 3. 使用边界

1. 外部 skill 只能作为参考，不作为本项目的真实实验过程证据。
2. 正式报告正文不得出现“参考某 AI skill 自动生成”的说明。
3. AI 使用记录只能写入 `journals/ai_assistance_log.md`。
4. 所有实验结论必须来自 `experiments/*/evidence/`、`experiments/*/outputs/`、源码或调试记录。
5. 不允许任何外部 skill 修改 `original_materials/`。
6. 不允许任何外部 skill 在未经人工确认时执行删除、覆盖、上传、推送等操作。
