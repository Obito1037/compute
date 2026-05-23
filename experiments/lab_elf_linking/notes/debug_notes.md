# 调试记录

| 编号 | 时间 | 工具 | 操作 | 结果 | 证据 |
|---|---|---|---|---|---|
| D001 | 2026-05-23 11:55:00 +08:00 | GDB | `break main` 后运行 `main_sub`，查看 `printf` 地址和共享库 | `printf` 解析到 libc 中的 `0x7ffff7c60100 <__printf>`；共享库包括动态装载器和 libc | `outputs/lab05_gdb_printf_dynamic_20260523.txt` |
| D002 | 2026-05-23 11:55:00 +08:00 | readelf | 比较 `main_sub` 与 `main_sub_static` 程序头 | 动态 PIE 有 `INTERP`、`DYNAMIC`；静态 EXEC 无动态解释器依赖 | `outputs/lab05_program_headers_compare_20260523.txt` |
