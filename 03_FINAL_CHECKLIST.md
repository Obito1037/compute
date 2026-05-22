# 最终检查清单

## 报告模板

- [ ] 封面字段完整
- [ ] 目录存在且章节编号正确
- [ ] 每个实验均包含实验概述、实验内容、实验设计、实验过程、实验结果、实验小结
- [ ] 阶段性实验的各阶段包含任务描述、实验设计、实验过程、实验结果
- [ ] 实验总结不少于 400 字

## 证据链

- [ ] 每个实验都有 `commands.md`
- [ ] 每个实验都有 `outputs/` 输出文件
- [ ] 截图都登记在 `screenshots_index.md`
- [ ] 报告结论能追溯到证据编号
- [ ] GDB/readelf/objdump 的关键输出已保存

## 输出文件

- [ ] `report/build/main.pdf` 已生成
- [ ] `report/build/main.docx` 已生成
- [ ] LaTeX 编译无致命错误
- [ ] Word 版本和 LaTeX 章节结构一致

## AI 使用记录

- [ ] AI 使用记录位于 `journals/ai_assistance_log.md`
- [ ] 正式实验报告正文没有 AI 使用说明

## GitHub

- [ ] Git 提交记录按实验阶段保存
- [ ] 已推送到 GitHub 远程仓库


## 外部 Skill 适配检查

- [ ] 已阅读 `docs/external_skill_reference_inventory.md`
- [ ] 未直接运行未经审查的第三方 skill 脚本
- [ ] LaTeX 编译检查使用 `11_latex_build_preview_checker` 流程
- [ ] Mermaid 图表保留 `.mmd` 源文件
- [ ] Markdown / Word 转换未覆盖原始报告模板
- [ ] GitHub 提交前已检查敏感文件
- [ ] 正式报告正文没有 AI 使用说明

## 内容深度与页数检查

- [ ] `report/build/main.pdf` 已生成。
- [ ] PDF 页数不少于 50 页。
- [ ] 五个实验均包含概述、内容、设计、过程、结果、小结。
- [ ] 每个实验至少包含 2 张图表或结构图。
- [ ] 每个实验至少有 4 个关键输出/截图/日志证据。
- [ ] 附录包含命令索引、代码/汇编摘录、调试日志摘录、图表/截图索引、Git 提交摘要。
- [ ] 最终实验总结不少于 400 字，建议 800 字以上。
- [ ] 报告中不存在 `待填写`、`TODO`、`示例内容` 等占位符。
- [ ] 已运行 `python scripts/final_report_gate.py` 并通过。
