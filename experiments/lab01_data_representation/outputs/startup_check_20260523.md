# 第 0 阶段启动检查记录

时间：2026-05-23 00:16:30 +08:00

## 1. 顶层目录检查

项目根目录存在以下关键目录：

- `codex_prompts/`
- `config/`
- `docs/`
- `experiments/`
- `journals/`
- `original_materials/`
- `report/`
- `scripts/`
- `skills/`
- `templates/`

## 2. 元数据检查

`config/report_metadata.yaml` 中以下字段仍为 `待填写`：

- `major_class`
- `instructor`
- `report_date`
- `github_repo`

用户已在 2026-05-23 00:25:04 +08:00 明确确认：

- `student_name`: 张家梁
- `student_id`: U202414558

`metadata_confirmed_by_user` 当前仍为 `false`，因为仍有字段待确认。这些信息不会被猜测，也不会在未确认时写入正式报告最终版。

## 3. 原始材料与实验目录映射

| 实验目录 | 当前映射依据 | 说明 |
|---|---|---|
| `experiments/lab01_data_representation/` | `original_materials/requirements/2026年_计算机系统基础_实验任务书_1_数据表示和等效运算.docx`；`original_materials/parsed_text/0_2026年_计算机系统基础_实验任务书_1_数据表示和等效运算.docx.txt`；`original_materials/extracted/lab01_data_representation/lab1/` | 实验一任务书路径明确 |
| `experiments/lab02_asm_c_optimization/` | `original_materials/extracted/lab02_asm_c_optimization/2026年_计算机系统基础_实验任务书_2_汇编和C的混合编程及优化.docx`；`original_materials/parsed_text/1_a3_docx.txt`；`original_materials/parsed_text/4_asm_c_operation_guide.docx.txt` | 实验二任务书与操作指导均存在 |
| `experiments/lab_binary_bomb/` | `original_materials/extracted/lab_binary_bomb/`；`original_materials/parsed_text/3_binarybomb_operation.docx.txt` | 二进制炸弹材料和操作说明存在 |
| `experiments/lab_bufbomb/` | `original_materials/extracted/lab_bufbomb/2026年_计算机系统基础_实验任务书_4_机器级语言理解(缓冲区溢出攻击 1次).docx`；`original_materials/parsed_text/2_a4_docx.txt`；`original_materials/parsed_text/5_bufbomb_tips.docx.txt` | 缓冲区溢出任务书和提示存在 |
| `experiments/lab_elf_linking/` | `original_materials/extracted/lab_elf_linking/链接实验任务_实验报告_202604.docx`；`original_materials/parsed_text/6_link_report_task.docx.txt`；`original_materials/parsed_text/link_operation_guide_pptx.txt` | ELF 链接任务书和操作指导存在 |

## 4. 报告模板结构检查

`report/main.tex` 当前包含：

- 封面：`sections/00_cover.tex`
- 目录
- 实验一至实验五章节
- 实验总结
- 参考资料
- 附录：证据索引、命令输出、代码摘录、调试日志、图表索引、Git 历史

`report/sections/00_metadata.tex` 当前由 `scripts/sync_report_metadata.py` 生成，并保留 `待填写` 字段。当前阶段未修改正式报告正文。

## 5. 脚本与工具链初检

- Python 可执行入口存在，17 个 `scripts/*.py` 文件均通过语法编译检查。
- `xelatex` 存在：`D:\texlive\2026\bin\windows\xelatex.exe`
- `lualatex` 存在：`D:\texlive\2026\bin\windows\lualatex.exe`
- `pandoc` 当前未发现；后续 Word 构建可能会跳过。
- `vswhere` 检测到 Visual Studio Community 2026，安装路径 `D:\vs`。
- 检测到 MSBuild：`D:\vs\MSBuild\Current\Bin\MSBuild.exe`。
- 检测到 Visual Studio 开发环境脚本：`D:\vs\Common7\Tools\VsDevCmd.bat`。
- 由于实验一任务书指定 VS2019/VS2022/VS2023，是否使用 VS2026 需要用户确认。

## 6. 启动检查中遇到的问题

- 当前目录不是 Git 仓库，`git status --short` 无法返回工作区状态。
- `rg --files` 被系统拒绝执行，已改用 PowerShell `Get-ChildItem` 完成文件检查。
- `python scripts\check_human_questions.py` 初次因确认记录中的门禁词触发失败，修正文案后复查通过。
- `python scripts\check_report_metadata.py` 按预期失败，原因是封面/提交元数据仍为 `待填写` 且 `metadata_confirmed_by_user=false`；当前阶段只记录，不补填。

## 7. 实验一下一步计划

实验一工作区 `experiments/lab01_data_representation/src/original_copy/` 已存在以下材料：

- `lab1.c`
- `lab1.h`
- `lab1.sln`
- `lab1.vcxproj`
- `lab1.vcxproj.filters`
- `lab1.vcxproj.user`
- `lab1.suo`

源码模板当前只包含一个 `student_t student` 示例，`lab1.c` 中的 `wangwu` 和 `90` 是源码现有示例值，不能作为学生姓名或学号信息使用。`lab1.vcxproj` 当前配置为 `Debug|Win32` 和 `Release|Win32`，目标机为 `MachineX86`。

已创建可编辑工作副本：`experiments/lab01_data_representation/src/work/`。后续源码修改只在该目录进行。

下一步计划：

1. 执行前确认姓名、学号或更新 `config/report_metadata.yaml`。
2. 执行前确认 Visual Studio 版本或检测本机可用版本后请用户确认。
3. 记录 Windows、Visual Studio、编译配置等环境信息。
4. 在 `experiments/lab01_data_representation/src/` 中操作源码，不修改 `original_materials/`。
5. 编译运行后保存输出、调试截图或等效调试记录。
