# lab_bufbomb 报告正文材料库

本文件用于沉淀可写入正式总报告正文的内容。Codex 生成报告前必须先读取本文件。

## 1. 实验目的与任务拆解

| 任务 | 说明 | 对应证据 |
|---|---|---|
| 编译 bufbomb | 使用提示文档要求的 GCC 开关生成程序 | E004 |
| 分析栈帧 | 通过反汇编和 GDB 确认 `buf`、保存 `rbp`、返回地址位置 | E006、E008 |
| smoke | 覆盖返回地址为 `smoke` 地址 | E009、E010、E017 |
| fizz | 伪造 `rbp` 并跳入 `fizz+0xb` | E011、E012、E017 |
| bang 选做 | 注入代码写 `global_value` 并跳到 `bang` | E013、E014、E016、E017 |
| boom 选做 | 注入代码设置 `eax` 并跳回 `test` | E013、E015、E016、E017 |

## 2. 关键原理说明

- 缓冲区溢出攻击的核心是利用 `Gets` 对 `buf` 的无边界复制，覆盖保存的 `rbp` 和返回地址。
- 64 位 System V ABI 中，普通函数第一个整型参数通过 `edi` 传递；fizz 关卡采用提示中的绕行方式，让 `[rbp-0x4]` 指向 `cookie`。
- bang/boom 需要执行栈上注入代码，因此必须关闭栈不可执行保护并记录运行时 `buf` 地址。
- boom 要返回主调函数继续执行，因此不仅要设置 `eax=cookie`，还要恢复原保存 `rbp` 并跳回 `test` 中 `getbuf` 调用后的地址。

## 3. 实验设计思路

- 先创建工作副本，使用 `-DU8`、`-fno-stack-protector`、`-no-pie`、`-z execstack` 编译。
- 用 `nm` 和 `objdump` 记录函数和全局变量地址。
- 用 GDB 断点记录 `getbuf` 栈帧。
- 分别构造四个 hex 攻击串文件。
- smoke/fizz 用普通运行验证；bang/boom 用 GDB 固定随机化验证。

## 4. 实验过程材料

| 步骤 | 操作 | 命令/工具 | 输出/截图 | 分析说明 |
|---|---|---|---|---|
| 1 | 编译 | `gcc ... -DU8 ... -z execstack` | `outputs/lab04_gcc_build_20260523.txt` | 生成非 PIE、栈可执行程序 |
| 2 | 静态分析 | `nm`、`objdump` | `outputs/lab04_nm_20260523.txt`、`outputs/lab04_objdump_intel_20260523.txt` | 得到地址和栈帧结构 |
| 3 | 栈探测 | GDB | `outputs/lab04_probe_stack_20260523.txt` | `buf` 到返回地址偏移为 56 |
| 4 | 必做关卡 | 普通运行 smoke/fizz | `outputs/lab04_smoke_run_20260523.txt`、`outputs/lab04_fizz_run_20260523.txt` | 两关通过 |
| 5 | 选做关卡 | GDB 固定随机化运行 bang/boom | `outputs/lab04_bang_boom_gdb_run_20260523.txt` | 两个选做通过 |

## 5. 关键代码/汇编/调试/ELF 分析材料

| 片段编号 | 文件/命令 | 片段说明 | 可写入报告的分析 |
|---|---|---|---|
| K001 | `outputs/lab04_objdump_intel_20260523.txt` / `getbuf` | `buf=rbp-0x30`，返回地址在 `rbp+8` | 返回地址覆盖偏移 56 |
| K002 | `outputs/lab04_objdump_intel_20260523.txt` / `fizz` | `0x40145c` 开始比较 `[rbp-0x4]` 与 `cookie` | fizz 伪造 `rbp` 技巧 |
| K003 | `outputs/lab04_attack_analysis_20260523.md` / bang | 注入代码写 `global_value` | bang 选做攻击 |
| K004 | `outputs/lab04_attack_analysis_20260523.md` / boom | 注入代码设置 `eax` 并跳回 `test` | boom 选做攻击 |

## 6. 结果分析材料

- smoke/fizz 的普通运行输出证明必做两关完成。
- bang/boom 的 GDB 输出证明选做两关在固定随机化环境中完成。
- 攻击串分析记录给出每一段字节的目的，可支撑报告中的攻击字符串产生方法说明。

## 7. 实验小结素材

- bang/boom 与 smoke/fizz 不同，必须处理栈地址随机化；本次通过 GDB 禁用随机化、记录 `buf` 地址后构造攻击串。
- boom 需要恢复 `rbp`，否则即使 `eax` 设置正确也可能无法回到 `test` 后续逻辑。
- 报告中要区分普通运行验证和 GDB 固定随机化验证，避免夸大结论。
