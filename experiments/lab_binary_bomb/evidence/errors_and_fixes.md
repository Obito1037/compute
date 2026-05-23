# 错误与修复记录

| 编号 | 错误现象 | 触发步骤 | 原因分析 | 修复方法 | 证据文件 | 状态 |
|---|---|---|---|---|---|---|
| F001 | 只输入学号试运行后程序提示 `Error: Premature EOF on stdin` | 用 `printf 'U202414558\n' | ./bomb` 做初始运行检查 | 炸弹程序进入 Gate 1 后还需要后续六关输入，管道提前结束；这不是拆弹失败 | 将该运行只作为入口检查；后续使用完整输入文件运行 | 终端输出；`outputs/lab03_final_run_20260523.txt` | 已解决 |
| F002 | 初次 GDB 脚本中 phase 1 期望串表达式输出不可访问地址 | `gdb -q -x lab03_gdb_breakpoints_20260523.gdb` | 表达式 `(char*)special+400` 被 GDB 按数组内容解释，地址计算不严谨 | 改为 `((char *)&special)+400`，重新运行 GDB 并覆盖保存干净证据 | `outputs/lab03_gdb_breakpoints_20260523.gdb`；`outputs/lab03_gdb_breakpoints_20260523.txt` | 已解决 |
