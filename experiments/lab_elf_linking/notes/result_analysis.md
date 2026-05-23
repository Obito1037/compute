# 结果分析记录

## 运行验证

- `main_sub`、`sub_main`、`main_sub_static` 均正常运行，退出码为 0。
- 运行输出均包含 `student id : U202414558`，说明学号字符串与 `-D U8` 条件编译一致。
- 输出中 `fcount` 两次调用的静态局部变量 `count` 从 1 到 2，和 `.bss` 中 `count.0` 的静态存储期一致。

## 可执行文件比较

- `main_sub` 和 `sub_main` 均为动态链接 PIE，大小均为 20312 字节。
- `main_sub_static` 为静态链接 EXEC，大小为 789616 字节，明显大于动态链接文件。
- `ldd main_sub` 显示依赖 `libc.so.6` 和动态装载器；`ldd main_sub_static` 显示 `not a dynamic executable`。

## 链接顺序影响

- `main_sub` 中 `.text` 相关符号顺序：`fcount -> fsub -> main -> fadd -> check_gcc_condition`。
- `sub_main` 中 `.text` 相关符号顺序：`fadd -> check_gcc_condition -> fcount -> fsub -> main`。
- `extern_int` 在 `main_sub` 中位于 `0x4050`，在 `sub_main` 中位于 `0x4010`，说明数据符号排列也受目标文件输入顺序影响。

## 动态链接 printf

- `printf` 在动态符号表中是 `UND`，在重定位表中对应 `R_X86_64_JUMP_SLOT`。
- `.dynamic` 中 `PLTGOT=0x3f98`，`.rela.plt` 负责记录延迟/装载期绑定所需的信息。
- 当前环境生成的 PIE 带 `BIND_NOW` 标志，因此动态符号在装载阶段完成绑定。
- GDB 运行时显示 `printf` 解析到 libc 中的 `0x7ffff7c60100 <__printf>`；该地址受 ASLR 影响，只作为本次运行证据。
