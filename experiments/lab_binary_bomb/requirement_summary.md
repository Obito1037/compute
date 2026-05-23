# 二进制炸弹 requirement_summary

## 实验名称
机器级语言理解（二进制炸弹拆除）

## 实验环境
- Linux / WSL Ubuntu
- GCC、GDB、objdump

## 已确认执行环境
- 实际环境：WSL2 Ubuntu 24.04.1 LTS。
- 工具：GCC 13.3.0、GDB 15.1、objdump 2.42。
- `phases.o`：ELF 64-bit x86-64 relocatable object。
- 编译开关：`-D U8`，来自已确认学号 `U202414558` 的最后一位。

## 核心任务
1. 使用 `gcc -g -o bomb -D U* bomb.c support.c phases.o` 生成二进制炸弹程序。
2. 运行程序并输入学号。
3. 使用 GDB、反汇编和动态调试分析各关逻辑。
4. 推导每一关正确输入。
5. 保存拆弹过程和通过结果。

## 必须保存的证据
- 编译命令和输出。
- GDB 断点、反汇编、寄存器和栈观察记录。
- 每一关推导过程。
- 最终通过运行截图或输出。

## 注意
报告中不应只给最终输入，必须解释推导依据。

## 本次任务书来源
- 操作说明：`original_materials/parsed_text/3_binarybomb_operation.docx.txt`
- 原始材料副本：`experiments/lab_binary_bomb/src/original_copy/`
