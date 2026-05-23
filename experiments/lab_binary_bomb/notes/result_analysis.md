# 结果分析记录

## 最终通过结果

最终输入文件 `outputs/lab03_answers_20260523.txt` 已通过实际运行验证。输出文件 `outputs/lab03_final_run_20260523.txt` 显示：

- `Phase 1 passed!`
- `Phase 2 passed!`
- `Phase 3 passed!`
- `Phase 4 passed!`
- `Phase 5 passed!`
- `Phase 6 passed!`
- `Congratulations! You have passed all the tests!`

## 六关输入

```text
U202414558
Computer System Foundation
8 5 14 20 35 56
5 789
14 7
mfcdhg
2 5 6 3 1 4
```

## 验证方式

本次没有把最终输入作为孤立答案使用，而是同时保存了：

- `objdump` 完整反汇编；
- `.rodata` 和 `.data` 内容；
- `nm` 符号表；
- GDB 断点脚本与运行输出；
- 逐关推导记录。

GDB 输出中已经直接验证：

- phase 1 输入和 `special+400` 字符串一致；
- phase 2 六个整数为 `8, 5, 14, 20, 35, 56`；
- phase 3 两个整数为 `5, 789`；
- phase 4 `func4` 返回值为 `7`；
- phase 5 输入转换后的字符串为 `bruins`；
- phase 6 重排后节点值为 `907, 824, 528, 322, 281, 121`，满足单调不增。
