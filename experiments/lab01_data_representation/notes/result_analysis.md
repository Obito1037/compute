# 结果分析记录

## 1. 编译结果

使用 Visual Studio Community 2026 的开发环境脚本和 MSBuild 编译 `src/work/lab1.sln`。由于原始项目文件指向 VS2010 的 `v100` 工具集，首次编译失败；修改工作副本 `lab1.vcxproj` 为 `PlatformToolset=v145` 后，最终 Debug/Win32 编译成功，生成：

```text
experiments/lab01_data_representation/src/work/Debug/lab1.exe
```

最终成功编译日志：

```text
experiments/lab01_data_representation/outputs/lab01_msbuild_debug_20260523_retry3.txt
```

## 2. 压缩与解压结果

最终运行输出显示：

- 原结构数组长度：`1080` 字节。
- 前 2 条记录逐字节压缩长度：`59` 字节。
- 后 3 条记录整体字段压缩长度：`77` 字节。
- 总压缩长度：`136` 字节。
- 解压恢复人数：`5`。

`beforecompress` 与 `decompress` 输出中 5 条记录的姓名字节、年龄、分数和备注均一致，说明当前压缩和解压函数在本次测试数据上能恢复原始信息。

## 3. message 前 40 字节

最终运行输出的前 40 字节为：

```text
D5 C5 BC D2 C1 BA 00 14
00 00 00 68 42 73 74 75
64 65 6E 74 20 69 64 20
55 32 30 32 34 31 34 35
35 38 00 6C 69 00 13 00
```

这些字节可以解释为：

- `D5 C5 BC D2 C1 BA 00`：第 0 名学生姓名“张家梁”的 GBK 字节和字符串结尾。
- `14 00`：`short age=20` 的小端表示。
- `00 00 68 42`：`float score=58.0` 的小端表示，对应原始 32 位值 `0x42680000`。
- 后续字节为备注字符串 `student id U202414558` 的 ASCII 编码，以及第 1 名学生姓名 `li` 的开头。

## 4. 浮点数编码

第 0 名学生 `score=58.0f`，输出显示 IEEE 754 单精度原始值为：

```text
raw hex: 0x42680000
sign: 0
exponent: 0x84 (132), unbiased=5
fraction: 0x680000
```

在小端内存中，它表现为 `00 00 68 42`，与 `message` 前 40 字节中的分数字节相对应。

## 5. 位运算测试结果

最终运行输出包含 `absVal`、`negate`、`bitAnd`、`bitOr`、`bitXor`、`isTmax`、`bitCount`、`bitMask`、`addOK`、`byteSwap`、`bang`、`bitParity` 的自动测试。`Select-String` 搜索最终输出中的 `FAIL` 无匹配，说明当前测试用例全部通过。

## 6. 内存观察补证

任务书要求将程序输出的 `message` 前 40 字节与调试内存观察结果比较。本机没有可直接脚本化的 CDB/WinDbg；VS 自带 `vsdbg.exe` 存在，但命令行尝试 `--help` 时返回资源 DLL 错误。因此采用等效调试记录：

1. 在 `LAB1_MEMORY_PROBE` 宏开启时，程序完成压缩后输出进程号和 `message` 地址并暂停。
2. PowerShell 通过 Windows API `ReadProcessMemory` 对该运行中 Debug 探针进程读取 `message` 地址处 40 字节。
3. 读取结果保存到 `outputs/memory_probe/lab01_message_memory_readprocessmemory_20260523.md`。
4. 与正常 Debug 程序输出中的 `message first 40 bytes` 自动比较，结果保存到 `outputs/memory_probe/lab01_message_memory_compare_20260523.md`，比较结果为 `MATCH`。

该等效记录可以支撑“程序输出的 `message` 前 40 字节与运行时内存中的实际字节一致”这一结论。
