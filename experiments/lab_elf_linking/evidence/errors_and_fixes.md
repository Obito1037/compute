# 错误与修复记录

| 编号 | 错误现象 | 触发步骤 | 原因分析 | 修复方法 | 证据文件 | 状态 |
|---|---|---|---|---|---|---|
| F001 | 批量 WSL 命令出现 `syntax error: unexpected end of file` | 初次用 PowerShell 长字符串传递多行 Bash 命令 | PowerShell 与 Bash 引号嵌套导致命令截断 | 改为拆分命令，并用双引号包装简单 Bash 命令 | 终端输出；`evidence/commands.md` 后续 C003-C010 | 已解决 |
| F002 | 使用 `awk $7` 的筛选命令被 PowerShell 提前解释，出现引号错误 | 符号表按列筛选 | PowerShell 双引号中 `$7` 被当作变量处理 | 改用不含 `$` 的 `grep -E` 筛选，并保留完整符号表作为主证据 | `outputs/lab05_main_o_symbols_20260523.txt`；`outputs/lab05_main_o_symbol_filters_20260523.txt` | 已解决 |
| F003 | `objdump -s -j .got.plt main_sub` 报节不存在 | 动态链接证据整理 | 当前 GCC/链接器生成的 PIE 使用 `.got` 与 `.plt.got`，没有独立 `.got.plt` 节 | 改为记录 `.got` 和 `.plt.got`，并用 `readelf -S` 已保存的节头表佐证 | `outputs/lab05_dynamic_printf_evidence_20260523.txt`；`outputs/lab05_main_sub_sections_20260523.txt` | 已解决 |
| F004 | WSL 启动时终端偶发输出 `localhostForwarding` 警告 | 运行 WSL 命令 | WSL 配置警告，不影响命令退出码和重定向后的实验输出 | 以命令输出文件和 exit_code 为准；需要时在报告中不引用该警告 | `outputs/lab05_gcc_*`；`outputs/lab05_run_*` | 已解决 |
