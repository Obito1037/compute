# 缓冲区溢出炸弹 requirement_summary

## 实验名称
缓冲区溢出攻击

## 实验环境
- Ubuntu / WSL
- GCC、GDB

## 核心任务
1. 使用指定编译开关生成 `bufbomb`。
2. 完成 `smoke` 和 `fizz` 两个 level。
3. 按用户要求完成选做 `bang` 和 `boom`。
4. 构造攻击字符串文件。
5. 通过 GDB 分析 `getbuf` 栈帧、保存的 rbp、返回地址和局部变量位置。
6. 说明攻击字符串产生方法。

## 已确认执行环境
- 实际环境：WSL2 Ubuntu 24.04.1 LTS。
- 工具：GCC 13.3.0、GDB 15.1、objdump 2.42。
- 编译开关：`-DU8`，来自已确认学号 `U202414558` 的最后一位。
- 必做关卡：`smoke`、`fizz`。
- 选做关卡：`bang`、`boom`，用户要求一并完成。

## 必须保存的证据
- 编译命令。
- `smoke`、`fizz` 地址和 cookie 值获取过程。
- GDB 栈帧观察记录。
- 攻击字符串文件及其逐字节解释。
- 成功运行输出。
- 栈帧结构图。

## 本次任务书来源
- 实验任务文本：`original_materials/parsed_text/2_a4_docx.txt`
- 要点提示：`original_materials/parsed_text/5_bufbomb_tips.docx.txt`
- 原始源码副本：`experiments/lab_bufbomb/src/original_copy/`
