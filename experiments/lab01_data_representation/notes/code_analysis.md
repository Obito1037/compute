# 代码分析记录

## 1. 源码位置

- 工作源码：`experiments/lab01_data_representation/src/work/lab1.c`
- 结构定义：`experiments/lab01_data_representation/src/work/lab1.h`

## 2. 结构体与压缩格式

`student_t` 的字段顺序为 `name[8]`、`age`、`score`、`remark[200]`。最终运行输出显示：

- `sizeof(student_t)=216`
- `name` 偏移为 0
- `age` 偏移为 8
- `score` 偏移为 12
- `remark` 偏移为 16
- 结构数组步长为 216

这说明 `age` 后存在对齐填充，使 `score` 从偏移 12 开始，而不是紧跟 `age` 的偏移 10。压缩存储格式没有保留这些结构体填充字节，而是按如下顺序紧凑写入：

1. `name` 的字符串字节，含结尾 `00`。
2. `age` 的 2 字节二进制表示。
3. `score` 的 4 字节二进制表示。
4. `remark` 的字符串字节，含结尾 `00`。

## 3. 两个压缩函数

`pack_student_bytebybyte` 用 `write_string_bytebybyte` 和 `copy_bytes` 逐字节写入所有字段，满足前 `N1=2` 个记录逐字节压缩的要求。

`pack_student_whole` 对字符串使用 `strcpy`，对 `short` 和 `float` 使用一次整体赋值：

```c
*(short *)(buf + offset) = s[i].age;
*(float *)(buf + offset) = s[i].score;
```

该函数用于后 `N2=3` 个记录，调用次数为 1。

## 4. 解压函数

`restore_student(char *buf, int len, student_t *s)` 只使用接口参数恢复数据。它通过字符串结尾 `\0` 判断 `name` 和 `remark` 的长度，再按固定字段宽度读取 `age` 和 `score`。最终运行输出中 `beforecompress` 与 `decompress` 的 5 条记录一致。

## 5. 姓名编码处理

用户确认姓名为“张家梁”，学号为 `U202414558`。由于 `name[8]` 不能容纳 UTF-8 下的 9 个姓名字节和结尾 `\0`，经用户确认，源码使用 GBK/CP936 字节序列：

```c
"\xD5\xC5\xBC\xD2\xC1\xBA"
```

运行输出中第 0 条姓名字节为：

```text
D5 C5 BC D2 C1 BA 00
```

## 6. 位运算实现检查

位运算函数均带有标准实现或对照实现，最终输出文件 `lab01_run_debug_20260523_retry1.txt` 中未出现 `FAIL`。其中 `addOK` 初始实现曾按“无溢出返回 1”的语义判断，后根据任务书改为“溢出返回 1，否则返回 0”，并重新编译运行验证。
