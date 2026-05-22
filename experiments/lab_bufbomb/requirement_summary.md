# 缓冲区溢出炸弹 requirement_summary

## 实验名称
缓冲区溢出攻击

## 实验环境
- Ubuntu / WSL
- GCC、GDB

## 核心任务
1. 使用指定编译开关生成 `bufbomb`。
2. 完成 `smoke` 和 `fizz` 两个 level。
3. 构造攻击字符串文件。
4. 通过 GDB 分析 `getbuf` 栈帧、保存的 rbp、返回地址和局部变量位置。
5. 说明攻击字符串产生方法。

## 必须保存的证据
- 编译命令。
- `smoke`、`fizz` 地址和 cookie 值获取过程。
- GDB 栈帧观察记录。
- 攻击字符串文件及其逐字节解释。
- 成功运行输出。
- 栈帧结构图。
