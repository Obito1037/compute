# Git 与 GitHub 提交流程

## 初始化

```bash
git init
git branch -M main
git add .
git commit -m "chore: initialize computer system lab workflow"
```

## 关联 GitHub

```bash
git remote add origin git@github.com:<你的用户名>/<仓库名>.git
git push -u origin main
```

## 推荐提交节奏

```bash
git add .
git commit -m "lab01: record requirements and environment"
git commit -m "lab01: save build outputs and result evidence"
git commit -m "bomb: collect gdb disassembly evidence"
git commit -m "bufbomb: document stack frame and attack strings"
git commit -m "elf: collect readelf and objdump outputs"
git commit -m "report: build total pdf and word outputs"
```


## 外部 Git Skill 参考后的补充规则

本项目只吸收 Git workflow skill 的提交粒度思想，不允许第三方脚本自动提交或推送。建议由 Codex 先生成提交建议，再由用户确认执行。

推荐流程：

```bash
git status
git add <明确文件>
git commit -m "lab01: record commands and outputs"
git push origin main
```

禁止：

```bash
git push --force
```
