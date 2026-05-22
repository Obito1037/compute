# 报告结论证据检查表

| 报告结论 | 是否有证据 | 证据编号/文件 | 是否需要补证 | 备注 |
|---|---|---|---|---|
| 实验一工作源码只在 `src/work/` 中修改，未修改原始材料 | 是 | LAB01-SRC-001；commands C013-C015 | 否 | `original_copy` 保持为原始副本 |
| VS2026/MSBuild Debug Win32 可成功编译实验一程序 | 是 | LAB01-BUILD-001 | 否 | 用户已确认允许使用 VS2026 |
| 第 0 名学生姓名使用 GBK/CP936 字节保存，分数为学号后两位 58 | 是 | LAB01-Q-001；LAB01-RUN-001 | 否 | 用户确认姓名和学号，用户确认 GBK/CP936 方案 |
| 压缩后总长度为 136 字节，原结构数组长度为 1080 字节 | 是 | LAB01-RUN-001 | 否 | 运行输出直接给出 |
| `message` 前 40 字节程序输出已保存，并已通过等效调试内存记录验证一致 | 是 | LAB01-RUN-002；LAB01-MEM-001；LAB01-MEM-002 | 否 | 等效记录使用 Windows API `ReadProcessMemory` 读取运行中 Debug 探针进程的 `message` 地址，比较结果为 `MATCH` |
| 第 0 名学生 `score=58.0f` 的单精度编码为 `0x42680000` | 是 | LAB01-RUN-001 | 否 | 输出含 sign、exponent、fraction |
| 当前位运算测试用例全部通过 | 是 | LAB01-RUN-001；commands C022 | 否 | 最终输出中 `FAIL` 无匹配 |
