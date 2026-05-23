# 代码分析记录

## 构建对象

实验三工作副本位于 `experiments/lab_binary_bomb/src/work/`，由原始材料复制得到，不修改 `src/original_copy` 或 `original_materials`。

编译命令：

```bash
gcc -g -o bomb -D U8 bomb.c support.c phases.o
```

其中 `U8` 来自已确认学号 `U202414558` 的最后一位。

## 已知源代码

`bomb.c`：

- 读取学号并调用 `initialize_bomb`。
- 按顺序读取六关输入并调用 `phase_1` 到 `phase_6`。
- 每关通过后打印 `Phase X passed!`。

`support.c`：

- `read_line` 负责读取输入行。
- `read_six_numbers` 用 `sscanf` 读取六个整数，不足六个会调用 `explode_bomb`。
- `strings_not_equal` 和 `string_length` 用于字符串比较和长度检查。
- `explode_bomb` 打印失败信息并退出。

`phases.o`：

- 教师未提供源代码，需要通过 `objdump`、`nm` 和 GDB 推导。
- 最终链接后，`phase_1` 到 `phase_6` 保留符号，便于反汇编定位。

## 关键结构和数据

`phase_1` 使用 `.data` 中的 `special` 字符串表。学号末位为 8，因此比较 `special + 50 * 8`，对应 `Computer System Foundation`。

`phase_5` 使用表 `maduiersnfotvbyl`，输入字符低 4 位作为索引，目标字符串为 `bruins`。

`phase_6` 使用链表节点，每个节点包含 `value`、`index` 和 `next`。GDB 记录原节点值为：

| 节点 | value | index |
|---|---:|---:|
| node1 | 281 | 1 |
| node2 | 907 | 2 |
| node3 | 322 | 3 |
| node4 | 121 | 4 |
| node5 | 824 | 5 |
| node6 | 528 | 6 |

按 value 降序应输入节点位置 `2 5 6 3 1 4`。
