# 代码分析记录

## 工作副本与编译

实验四工作副本位于 `experiments/lab_bufbomb/src/work/`，由原始材料复制得到，不修改 `src/original_copy` 或 `original_materials`。

编译命令：

```bash
gcc -g -fno-stack-protector -no-pie -DU8 -fcf-protection=none -z execstack verinfo.c bufbomb.c buf.c -o bufbomb
```

关键开关作用：

- `-fno-stack-protector`：关闭栈保护，允许覆盖返回地址后观察攻击效果。
- `-no-pie`：固定代码段地址，使 `smoke/fizz/bang` 地址可复现。
- `-fcf-protection=none`：关闭控制流保护相关指令。
- `-z execstack`：允许执行栈上注入代码，供 bang/boom 使用。
- `-DU8`：对应学号末位 `8`。

## 关键函数

`getbuf`：

- 在 `rbp-0x30` 创建 `buf`。
- 调用 `Gets(buf, src, len)`，其中 `Gets` 实际调用 `memcpy`，可复制任意字节。
- 正常返回 `1`。

`test`：

- 调用 `getbuf` 后将返回值保存到 `[rbp-0x4]`。
- 若返回值等于 `cookie`，输出 `Boom!`。

`fizz`：

- 正常入口会将 `edi` 写入 `[rbp-0x4]`。
- 本次攻击从 `0x40145c` 开始执行，直接比较 `[rbp-0x4]` 与 `cookie`。

`bang`：

- 检查全局变量 `global_value` 是否等于 `cookie`。
- 本次攻击通过注入代码先写 `global_value`，再跳转到 `bang`。

## 栈帧结论

`getbuf` 中 `buf` 到保存返回地址的偏移为 56 字节：

- `buf`：`rbp-0x30`
- 保存的 `rbp`：`rbp`
- 返回地址：`rbp+8`

因此攻击串通用形态为：

```text
前 48 字节控制 buf 到保存 rbp 之前的区域
第 49-56 字节覆盖保存 rbp
第 57-64 字节覆盖返回地址
```

bang/boom 的 GDB 固定随机化环境中，`buf` 地址为 `0x7fffffffddb0`，原保存 `rbp` 为 `0x7fffffffde20`。
