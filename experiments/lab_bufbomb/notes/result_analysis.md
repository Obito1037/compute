# 结果分析记录

## 已完成关卡

| 关卡 | 类型 | 验证方式 | 结果 |
|---|---|---|---|
| smoke | 必做 | 普通运行 | `Smoke!: You called smoke()` |
| fizz | 必做 | 普通运行 | `Fizz!: You called fizz(0xc1099de)` |
| bang | 选做 | GDB `set disable-randomization on` | `Bang!: You set global_value to 0xc1099de` |
| boom | 选做 | GDB `set disable-randomization on` | `Boom!: getbuf returned 0xc1099de` |

## 攻击串核心

cookie 为 `0x0c1099de`。

smoke：

- 56 字节填充。
- 返回地址改为 `0x401434`。

fizz：

- 48 字节填充。
- 保存的 `rbp` 改为 `0x4040ec`，使 `[rbp-0x4]` 对应 `cookie`。
- 返回地址改为 `0x40145c`。

bang：

- 在 `buf` 开头注入代码，写 `global_value=0x0c1099de`。
- 返回地址改为 `buf=0x7fffffffddb0`。
- 注入代码最后跳转到 `bang=0x4014a5`。

boom：

- 在 `buf` 开头注入代码，设置 `eax=0x0c1099de`。
- 保存的 `rbp` 恢复为 `0x7fffffffde20`。
- 注入代码跳回 `test` 中 `getbuf` 调用后的地址 `0x4015b8`。

## 注意事项

bang 和 boom 攻击串包含栈上代码地址，依赖运行时 `buf` 地址。本次用 GDB 禁用随机化并保存栈探测证据后验证通过。报告中不得把 bang/boom 表述成“普通运行无条件通过”，只能表述为“在固定随机化的 GDB 调试环境中通过”。
