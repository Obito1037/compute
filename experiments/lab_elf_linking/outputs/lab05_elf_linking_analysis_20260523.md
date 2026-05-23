# 实验五 ELF 文件与程序链接分析记录

## 1. 个性化修改与构建结果

- 工作副本位于 `experiments/lab_elf_linking/src/work/`，原始材料保留在 `src/original_copy/`。
- `main.c` 中 `init_gstr1` 修改为 `U202414558`，内联汇编 `.rept` 修改为 `8`，`uninit_gstr2` 使用用户确认的安全字符串 `zjl`。
- 运行输出显示 `student id : U202414558`，说明 `-D U8` 与学号末位条件分支匹配。
- `main.o` 被 `file` 识别为 `ELF 64-bit LSB relocatable`；`main_sub`、`sub_main` 被识别为动态链接 PIE；`main_sub_static` 被识别为静态链接 ELF executable。

## 2. 从 C 到汇编

- `init_gstr1` 在汇编中位于 `.data`，以 `.string "U202414558"` 和补零表示；`uninit_gstr2` 位于 `.bss`，以 `.zero 12` 表示。
- `lv1`、`lv2`、`sum` 等自动局部变量使用 `rbp` 相对地址访问，例如 `DWORD PTR [rbp-0xc]`。
- 全局变量在 x86-64 代码中通过 RIP 相对寻址访问，例如 `init_gv1(%rip)`、`uninit_gv2(%rip)`。
- `.rept 8` 在 `main.o` 与 `main_sub` 的反汇编中展开为 8 条连续 `nop` 指令。
- `strcpy(uninit_gstr2, "zjl")` 被编译器优化为向 `uninit_gstr2` 写入立即数 `0x006c6a7a`，没有形成对 `strcpy` 的动态符号引用。

## 3. 可重定位目标文件 main.o

- `main.o` 节头表共有 27 个节，关键节包括 `.text`、`.rela.text`、`.data`、`.bss`、`.data.rel.local`、`.rela.data.rel.local`、`.data.rel`、`.rela.data.rel`、`.rodata`、`.symtab`、`.strtab`。
- `.data` 十六进制转储中，偏移 `0x00` 是 `init_gv1=10`，偏移 `0x08` 起是 `U202414558`，偏移 `0x18` 起是数组 `11, 12, 13`，偏移 `0x24` 是 `gv=6`。
- `.bss` 不占用文件内容，符号表显示 `uninit_gv2`、`uninit_gstr2`、`uninit_garr2`、`uninit_gp2`、`uninit_gfp2` 和静态局部变量 `count.0` 属于该节。
- `.data.rel.local` 存放 `init_gp1=&init_gv1`、`init_gp2=&uninit_gv2` 这种需要链接器填入地址的本地数据引用；对应重定位项位于 `.rela.data.rel.local`。
- `.data.rel` 存放 `init_gfp1=fadd` 这种函数地址引用；对应重定位项位于 `.rela.data.rel`。
- `.rela.text` 中包含对 `printf`、`check_gcc_condition`、`fcount`、`fadd`、全局变量和 `.rodata` 的重定位记录。

## 4. 符号表与重定位

- `main.o` 的符号表中，`init_gv1`、`init_gstr1`、`init_garr1`、`gv` 位于 `.data`；未初始化对象位于 `.bss`；`fcount` 和 `main` 位于 `.text`。
- `fadd`、`printf`、`__stack_chk_fail`、`check_gcc_condition`、`extern_int` 在 `main.o` 中是 `UND`，原因是它们由其他目标文件或动态库提供。
- `main.o` 中 call 指令的机器码操作数多为 `00 00 00 00`，同时在 `.rela.text` 中记录 `R_X86_64_PLT32` 或 `R_X86_64_PC32`；链接后的 `main_sub` 中这些位置已替换为具体 PC 相对位移。

## 5. main_sub 与 sub_main 比较

- `main_sub` 的函数顺序为 `fcount -> fsub -> main -> fadd -> check_gcc_condition`，对应链接命令中 `main.c` 在前、`sub.c` 在后。
- `sub_main` 的函数顺序为 `fadd -> check_gcc_condition -> fcount -> fsub -> main`，对应链接命令中 `sub.c` 在前、`main.c` 在后。
- 数据符号也受目标文件输入顺序影响：`main_sub` 中 `extern_int` 位于 `0x4050`，而 `sub_main` 中 `extern_int` 位于 `0x4010`。

## 6. 静态链接与动态链接

- 动态链接 `main_sub` 大小为 20312 字节，文件类型为 PIE executable，并包含 `INTERP`、`DYNAMIC`、`.dynsym`、`.rela.plt`、`.plt`、`.got` 等动态链接相关结构。
- 静态链接 `main_sub_static` 大小为 789616 字节，`ldd` 输出为 `not a dynamic executable`，文件头类型为 `EXEC`。
- 动态链接程序的 `.dynamic` 中存在 `NEEDED libc.so.6`、`PLTGOT 0x3f98`、`JMPREL 0x700`；静态链接程序没有运行时解释器依赖。

## 7. printf 动态定位

- `readelf --dyn-syms main_sub` 显示 `printf@GLIBC_2.2.5` 是未定义动态符号，由 libc 在运行时提供。
- `readelf -r main_sub` 显示 `printf` 的 `R_X86_64_JUMP_SLOT` 重定位项位于 `0x3fc8`。
- `objdump -d -j .plt main_sub` 显示 PLT 入口通过 GOT 间接跳转；`.dynamic` 中的 `BIND_NOW` 表明本环境生成的 PIE 在装载阶段完成绑定。
- GDB 在 `main` 断点处显示 `printf` 实际解析到 `/lib/x86_64-linux-gnu/libc.so.6` 中的 `0x7ffff7c60100 <__printf>`。

## 8. 证据限制

- 以上结论仅对应本次 WSL/Ubuntu/GCC 环境下保存的输出。不同 GCC 版本、默认 PIE/RELRO 选项、ASLR 设置可能改变地址、节数量或动态绑定细节。
