# ELF 链接实验 requirement_summary

## 实验名称
ELF 文件与程序链接

## 任务书来源
- `original_materials/parsed_text/6_link_report_task.docx.txt`
- `original_materials/parsed_text/link_operation_guide_pptx.txt`
- 原始源码副本：`experiments/lab_elf_linking/src/original_copy/main.c`、`experiments/lab_elf_linking/src/original_copy/sub.c`

## 实验环境
- Ubuntu / WSL
- GCC、GDB、readelf、objdump、hexdump、objcopy

## 个性化修改
- 将 `main.c` 中 `init_gstr1[12]` 的初始化值改为已确认学号 `U202414558`。
- 将内联汇编 `.rept #` 的 `#` 改为学号末位 `8`，编译时使用 `-D U8`。
- 源码中 `uninit_gstr2` 注释要求替换姓名拼音；用户确认“如果溢出填 zjl”，因此工作副本使用 `zjl`。

## 核心任务
1. 从 C 到汇编：生成预处理文件、汇编文件，说明全局变量、局部变量、函数调用在汇编中的表示。
2. 可重定位目标文件解析：分析 `main.o` 的 ELF 头、节头表、数据节、代码节、符号表、字符串表、重定位表。
3. 可执行目标文件解析：生成 `main_sub`、`sub_main`，比较符号地址、全局变量和函数排列顺序，说明链接后机器码与重定位信息变化。
4. 静态链接：生成静态链接可执行程序并与动态链接程序比较。
5. 动态链接函数定位：围绕 `printf` 分析 `.plt`、`.got.plt`、动态符号表和重定位项。

## 必须保存的证据
- `gcc` 编译各阶段命令输出。
- `readelf -S -W` 节头表输出。
- `readelf -s` 符号表输出。
- `readelf -r` 重定位表输出。
- `objdump -d` 反汇编输出。
- `.data`、`.rodata`、`.strtab` 等节的十六进制输出。
- 静态/动态链接文件大小、节表、符号表差异对比。
- 运行输出，证明 `-D U8` 与学号末位一致。

## 暂不写入正式报告的内容
- 不在正式报告正文中写 AI 使用说明。
- 结论只引用已保存的命令输出、调试记录和分析文件。
