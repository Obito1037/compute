---
name: external-skill-safety-auditor
description: 审查准备启用的外部 GitHub skill，识别危险脚本、网络下载、密钥读取和模板覆盖风险。
---

# 外部 Skill 安全审查 Skill

## 触发条件

当用户希望启用、复制、安装或运行任何 GitHub 外部 skill 时触发。

## 必须读取

1. 外部 skill 的 `SKILL.md`；
2. 外部 skill 的脚本文件；
3. `docs/external_skill_reference_inventory.md`；
4. `docs/external_skill_enablement_guide.md`；
5. `docs/skill_safety_policy.md`。

## 审查重点

检查是否包含：

- 删除命令：`rm -rf`、`Remove-Item -Recurse`、`del /s`；
- 网络下载并执行：`curl | sh`、`wget | bash`；
- 读取敏感文件：`.ssh`、`.env`、token、cookie；
- 自动上传或同步；
- Git 强制推送或历史重写；
- 覆盖 `report/`、`original_materials/`、`experiments/`；
- 安装全局依赖；
- 不明二进制文件。

## 输出格式

```markdown
# 外部 Skill 安全审查报告

## 基本信息

- Skill 名称：
- 来源仓库：
- 审查时间：

## 风险检查

| 检查项 | 结果 | 说明 |
|---|---|---|
| 是否读取敏感文件 |  |  |
| 是否访问网络 |  |  |
| 是否删除文件 |  |  |
| 是否修改 Git 历史 |  |  |
| 是否覆盖报告模板 |  |  |

## 结论

- [ ] 可直接参考思想
- [ ] 需要改写后使用
- [ ] 不建议启用
```

## 禁止事项

- 不得在审查前运行外部脚本。
- 不得自动安装外部 skill。
- 不得把外部 skill 的危险命令复制进本项目。
- 不得绕过用户确认。
