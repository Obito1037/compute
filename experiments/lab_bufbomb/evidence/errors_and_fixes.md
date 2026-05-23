# 错误与修复记录

| 编号 | 错误现象 | 触发步骤 | 原因分析 | 修复方法 | 证据文件 | 状态 |
|---|---|---|---|---|---|---|
| F001 | bang/boom 不能像 smoke/fizz 一样只依赖固定代码地址 | 构造选做关卡攻击串 | bang 需要修改全局变量，boom 需要返回 cookie 并继续执行；二者使用栈上注入代码，因此必须知道 `buf` 的运行时地址 | 使用 GDB `set disable-randomization on` 探测同一命令行参数下的 `buf` 地址，并在该固定随机化环境中验证 | `outputs/lab04_probe_bang_boom_20260523.txt`；`outputs/lab04_bang_boom_gdb_run_20260523.txt` | 已解决 |
| F002 | WSL 在 PowerShell 侧偶尔输出 localhostForwarding 警告 | 运行 WSL 命令 | WSL 环境提示会污染直接捕获到 PowerShell 的输出 | 对关键运行证据使用 WSL 内部重定向到文件，证据文件保持 ASCII/UTF-8 文本 | `outputs/lab04_smoke_run_20260523.txt`；`outputs/lab04_fizz_run_20260523.txt`；`outputs/lab04_bang_boom_gdb_run_20260523.txt` | 已解决 |
