# 代码分析记录

## 个性化源码修改

- `init_gstr1[12]` 从 `U202415001` 改为 `U202414558`。
- 内联汇编从 `.rept 5` 改为 `.rept 8`。
- `uninit_gstr2` 的测试字符串使用用户确认的 `zjl`，避免完整姓名拼音超过 `char[12]`。

## 全局变量与节

| C 符号 | 初始化状态 | main.o 节 | 符号表 Value/Size | 说明 |
|---|---|---|---|---|
| `init_gv1` | `10` | `.data` | `0x0 / 4` | `.data` 偏移 0，字节 `0a 00 00 00` |
| `init_gstr1` | `"U202414558"` | `.data` | `0x8 / 12` | `.data` 偏移 8，包含学号字符串和补零 |
| `init_garr1` | `{11,12,13}` | `.data` | `0x18 / 12` | `.data` 偏移 0x18 |
| `gv` | `NUMBER=6` | `.data` | `0x24 / 4` | `.data` 偏移 0x24 |
| `uninit_gv2` | 未初始化 | `.bss` | `0x0 / 4` | 不占用文件数据 |
| `uninit_gstr2` | 未初始化 | `.bss` | `0x8 / 12` | 运行时由指令写入 `zjl` |
| `uninit_garr2` | 未初始化 | `.bss` | `0x18 / 12` | 不占用文件数据 |
| `count.0` | 静态局部变量 | `.bss` | `0x38 / 4` | `fcount` 内部 `static int count` |

## 指针与重定位数据节

- `init_gp1 = &init_gv1` 与 `init_gp2 = &uninit_gv2` 位于 `.data.rel.local`，节内容初始为 0，由 `.rela.data.rel.local` 指向实际符号。
- `init_gfp1 = fadd` 位于 `.data.rel`，由 `.rela.data.rel` 指向 `fadd`。
- 普通 `.data` 能直接保存整数和字符串字节；保存地址的全局对象需要重定位节参与。

## 汇编与机器码观察

- `init_gstr1` 在汇编中为 `.string "U202414558"`，`uninit_gstr2` 为 `.zero 12`。
- `lv1/lv2/sum` 使用 `rbp` 相对偏移；全局对象使用 RIP 相对寻址。
- `.rept 8` 在 `main.o` 的 main 反汇编偏移 `0x126` 到 `0x12d` 展开为 8 条 `90 nop`。
- 链接前 `call` 操作数是 0 并配有重定位记录；链接后 `main_sub` 中对应位置变成实际 PC 相对位移。
