# GDB 记录指南

建议记录以下命令输出：

```gdb
disas <function>
b <function>
run
info registers
x/32gx $rsp
x/32gx $rbp-0x80
bt
```

输出应保存到 `outputs/`，关键解释写入 `notes/debug_notes.md`。
