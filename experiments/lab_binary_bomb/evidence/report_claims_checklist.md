# 报告结论证据检查表

| 报告结论 | 是否有证据 | 证据编号/文件 | 是否需要补证 | 备注 |
|---|---|---|---|---|
| 实验三使用 WSL Ubuntu、GCC、GDB、objdump 完成 | 是 | E004、`evidence/environment.md` | 否 | WSL Ubuntu 24.04.1，GCC 13.3，GDB 15.1 |
| 编译命令使用 `-D U8`，对应学号 `U202414558` 末位 8 | 是 | E004、E009、E010 | 否 | 学号来自已确认元数据 |
| `phases.o` 为 ELF64 x86-64 relocatable object，最终 `bomb` 为 ELF64 PIE executable | 是 | C002 终端记录、E004、E005 | 否 | 可在报告中谨慎表述 |
| phase 1 输入为 `Computer System Foundation` | 是 | E006、E008、E012、E013 | 否 | GDB 显示输入与 `special+400` 一致 |
| phase 2 输入为 `8 5 14 20 35 56` | 是 | E006、E012、E013 | 否 | 前两位来自学号后两位，后续按递推 |
| phase 3 输入为 `5 789` | 是 | E006、E007、E012、E013 | 否 | 第一个数为学号倒数第二位，case 5 目标值为 `0x315` |
| phase 4 输入为 `14 7` | 是 | E006、E012、E013 | 否 | `func4(14,0,14)` 返回 7，第二个数也为 7 |
| phase 5 输入为 `mfcdhg` | 是 | E006、E007、E008、E012、E013 | 否 | 低 4 位查表后得到 `bruins` |
| phase 6 输入为 `2 5 6 3 1 4` | 是 | E006、E008、E012、E013 | 否 | 重排后节点 value 为 `907,824,528,322,281,121` |
| 最终六关全部通过 | 是 | E010 | 否 | 输出包含 Phase 1-6 passed 和 Congratulations |
