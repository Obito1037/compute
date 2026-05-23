# 报告结论证据检查表

| 报告结论 | 是否有证据 | 证据编号/文件 | 是否需要补证 | 备注 |
|---|---|---|---|---|
| 实验四使用 WSL Ubuntu、GCC、GDB、objdump 完成 | 是 | E004、`evidence/environment.md` | 否 | Ubuntu 24.04.1，GCC 13.3，GDB 15.1 |
| 编译使用 `-DU8`，对应学号 `U202414558` 末位 8 | 是 | E004 | 否 | 学号来自已确认元数据 |
| cookie 为 `0x0c1099de` | 是 | E010、E012、E016、E017 | 否 | 程序运行输出显示 `cookie : 0xc1099de` |
| `getbuf` 中 `buf` 到返回地址偏移为 56 字节 | 是 | E006、E008、E017 | 否 | `buf=rbp-0x30`，返回地址为 `rbp+8` |
| smoke 攻击通过 | 是 | E009、E010、E017 | 否 | 普通运行输出 `Smoke!` |
| fizz 攻击通过 | 是 | E011、E012、E017 | 否 | 普通运行输出 `Fizz!` |
| bang 选做攻击通过 | 是 | E013、E014、E016、E017 | 否 | 在 GDB 固定随机化环境中输出 `Bang!` |
| boom 选做攻击通过 | 是 | E013、E015、E016、E017 | 否 | 在 GDB 固定随机化环境中输出 `Boom!` 并回到主程序 |
| bang/boom 依赖运行时 `buf` 栈地址 | 是 | E013、E016、E017 | 否 | 报告中必须说明验证环境为 GDB `set disable-randomization on` |
