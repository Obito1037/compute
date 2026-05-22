# 人工确认问题记录

本文件记录 Codex 在不确定时向用户提出的问题。Codex 不允许把不确定内容写成事实。

| 编号 | 时间 | 实验/模块 | 当前步骤 | 不确定内容 | 已检查文件/命令 | 选项 | 用户确认 | 状态 |
|---|---|---|---|---|---|---|---|---|
| Q001 | 2026-05-23 00:16:30 +08:00 | 项目启动 / 封面与提交信息 | 读取 `config/report_metadata.yaml` | 封面/提交必填信息已由用户明确确认；GitHub 地址已记录但未获得 push 授权，不执行推送。 | `config/report_metadata.yaml`；`PROJECT_METADATA.yaml`；用户消息“我的姓名是张家梁 学号U202414558 继续”；用户消息“专业班级是计算机2401班 指导老师张宇 github仓库地址git@github.com:Obito1037/compute.git”；用户消息“报告日期写2026年5月23日” | A. 使用已确认元数据继续后续报告生成；B. 若用户后续更正，则同步更新配置和证据 | 姓名：张家梁；学号：U202414558；专业班级：计算机2401班；指导老师：张宇；报告日期：2026年5月23日；GitHub：git@github.com:Obito1037/compute.git | 已解决 |
| Q002 | 2026-05-23 00:16:30 +08:00 | 实验一：数据表示和等效运算 | 要求阅读与任务摘要 | 任务 1 要求第 0 个学生姓名为自己的名字，分数为学号最后两位。用户已明确确认姓名和学号，可用于实验一输入；学号最后两位为 `58`。 | `original_materials/parsed_text/0_2026年_计算机系统基础_实验任务书_1_数据表示和等效运算.docx.txt`；`config/report_metadata.yaml`；用户消息“我的姓名是张家梁 学号U202414558 继续” | A. 使用已确认姓名和学号继续实验一；B. 若用户后续更正，则同步更新配置和证据 | 姓名：张家梁；学号：U202414558；分数：58 | 已解决 |
| Q003 | 2026-05-23 00:16:30 +08:00 | 实验一：数据表示和等效运算 | 执行步骤规划 | 任务书指定 Visual Studio 2019/2022/2023；当前 `vswhere` 只检测到 Visual Studio Community 2026，MSBuild 和 MSVC 工具存在于 `D:\vs`。已向用户确认是否允许使用 VS2026。 | 实验一任务书解析文本；`vswhere -all -products * -format json`；`Get-ChildItem D:\vs -Filter MSBuild.exe/cl.exe/VsDevCmd.bat` | A. 使用本机 Visual Studio Community 2026 继续；B. 用户提供/指定 VS2019、VS2022 或 VS2023 | 用户回复：A | 已解决 |
| Q004 | 2026-05-23 00:25:04 +08:00 | 实验一：数据表示和等效运算 | 源码实现前 | `student.name[8]` 需要存放姓名“张家梁”。若 C 源码按 UTF-8 字符串字面量保存，3 个汉字占 9 字节，加上结尾 `\0` 会超过 8 字节；若按 Windows 中文环境常见 GBK/CP936 字节存放，则为 6 字节，加上 `\0` 可放入 `name[8]`。已向用户确认编码处理方式。 | `lab1.h` 中 `char name[8]`；用户确认姓名“张家梁”；Python Unicode escape 编码检查：GBK `D5 C5 BC D2 C1 BA`，UTF-8 `E5 BC A0 E5 AE B6 E6 A2 81` | A. 在源码中用 GBK/CP936 字节序列保存“张家梁”；B. 用户指定其他姓名字段写法 | 用户回复：A | 已解决 |
| Q005 | 2026-05-23 01:04:44 +08:00 | Git / GitHub | 初始化仓库、首次提交和首次 push 前 | 用户询问是否已 Git/GitHub 后，Codex 说明尚未初始化、提交或 push，并说明如需继续需授权“初始化仓库、创建提交、设置远程并首次 push”。用户回复“授权”。本次提交包含已确认的封面个人信息和实验一证据；GitHub 地址来自用户确认。 | `config/report_metadata.yaml`；`git status --short`；`git remote -v`；用户消息“授权” | A. 按用户授权进行 Git 初始化、提交、设置远程并首次 push；B. 用户取消 GitHub 推送 | 用户回复：授权 | 已解决 |
| Q006 | 2026-05-23 01:23:59 +08:00 | 实验一：数据表示和等效运算 | `message` 前 40 字节内存证据表述确认 | 用户要求补充 Visual Studio 调试内存窗口截图或等效调试记录。当前已保存 Windows API `ReadProcessMemory` 等效调试记录，并与程序输出比较为 `MATCH`；用户确认“可以认为是一致的”。报告表述仍应区分“等效外部内存读取记录”与“真实 VS 内存窗口截图”。 | `experiments/lab01_data_representation/outputs/memory_probe/lab01_message_memory_readprocessmemory_20260523.md`；`experiments/lab01_data_representation/outputs/memory_probe/lab01_message_memory_compare_20260523.md`；用户消息“可以认为是一致的” | A. 使用等效调试记录支撑一致性结论；B. 若后续提供真实 VS 内存窗口截图，再补充截图索引 | 用户回复：可以认为是一致的 | 已解决 |

状态建议：已解决 / 无需处理。最终提交前不得保留待处理问题。
