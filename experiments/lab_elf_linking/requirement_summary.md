# ELF 链接实验 requirement_summary

## 实验名称
ELF 文件与程序链接

## 实验环境
- Ubuntu / WSL
- GCC、GDB、readelf、objdump、hexdump、objcopy

## 核心任务
1. 修改 `main.c` 中学号字符串和 `.rept #` 的数字。
2. 生成 `.i`、`.s`、`.o` 和 ELF 可执行文件。
3. 分析可重定位目标文件中的节头表、`.data`、`.bss`、`.rodata`、`.symtab`、`.rela.text`、`.strtab` 等。
4. 分析符号表各列含义、未定义符号、符号定义位置和符号值。
5. 分析重定位表和需要重定位的位置。
6. 比较 `main_sub` 与 `sub_main` 中符号地址、全局变量和函数排列顺序。
7. 比较静态链接与动态链接生成的可执行程序差异。
8. 研究动态链接库函数定位方法。

## 必须保存的证据
- `gcc` 编译各阶段命令输出。
- `readelf -S -W` 节头表输出。
- `readelf -s` 符号表输出。
- `readelf -r` 重定位表输出。
- `objdump -d` 反汇编输出。
- `.data`、`.rodata`、`.strtab` 等节的十六进制输出。
- 静态/动态链接文件大小、节表、符号表差异对比。
