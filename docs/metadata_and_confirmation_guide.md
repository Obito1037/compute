# 封面信息与人工确认指南

## 1. 唯一数据源

封面信息的唯一数据源是：

```text
config/report_metadata.yaml
```

LaTeX 封面从 `report/sections/00_metadata.tex` 读取变量，而该文件由脚本根据 `config/report_metadata.yaml` 生成。

## 2. 生成流程

```powershell
python scripts/sync_report_metadata.py
cd report
.\build_total_report.ps1
```

`build_total_report.ps1` 会自动调用同步脚本。

## 3. 最终检查

最终提交前运行：

```powershell
python scripts/final_report_gate.py
```

若 `config/report_metadata.yaml` 仍有 `待填写` 或空值，检查会失败。

## 4. 不允许猜测

Codex 不得从以下位置推断个人信息：

- 历史聊天；
- Windows 用户名；
- Git 用户名；
- GitHub SSH 邮箱；
- 文件夹名；
- 之前项目记忆。

必须由用户明确填写或确认。
