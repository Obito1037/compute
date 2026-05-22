# 外部 Skill 启用指南

本项目已经内置 HUST 计算机系统基础实验专用 skills。若需要启用 GitHub 上的外部 skill，只能按以下流程进行。

## 一、启用前检查

1. 阅读外部仓库的 `SKILL.md`。
2. 阅读该 skill 内所有脚本，特别是 `.sh`、`.py`、`.ps1`、`.js` 文件。
3. 检查是否包含以下高风险行为：
   - 删除目录：`rm -rf`、`del /s`、`Remove-Item -Recurse`；
   - 修改 Git 远程仓库：`git push --force`、自动重写历史；
   - 下载并执行脚本：`curl ... | sh`、`wget ... | bash`；
   - 读取密钥：`.ssh`、`.env`、token、cookie、浏览器数据；
   - 上传文件到未知服务；
   - 自动修改系统环境变量或安装全局依赖。
4. 将可用部分改写到本项目的专用 skill，而不是直接运行第三方 skill。

## 二、建议启用顺序

1. LaTeX 编译与预览流程：对应 `skills/11_latex_build_preview_checker/`。
2. Mermaid 图表生成与校验：对应 `skills/12_mermaid_diagram_generator_validator/`。
3. Markdown / DOCX 转换：对应 `skills/13_markdown_document_converter/`。
4. GitHub 提交流程：对应 `skills/14_git_github_workflow_manager/`。
5. 代码 walkthrough：对应 `skills/15_codebase_walkthrough_generator/`。
6. 外部 skill 安全审查：对应 `skills/16_external_skill_safety_auditor/`。

## 三、Codex 使用提示

给 Codex 的推荐指令：

```text
请只参考 external_skill_reference_inventory.md 中记录的外部 skill 思想，不要直接复制或运行第三方仓库脚本。若确实需要借鉴某个 skill，请先使用 16_external_skill_safety_auditor 检查风险，再将安全的流程改写为本项目目录结构下的操作。
```

## 四、正式报告限制

正式实验报告只应体现实验目的、设计、过程、结果、分析和总结，不写 AI 工具或外部 skill 使用说明。AI 使用过程仅记录在：

```text
journals/ai_assistance_log.md
```
