# 实验一执行计划

本计划只用于实验执行准备，不属于正式报告正文。

## 1. 已确认材料

- 任务书解析文本：`original_materials/parsed_text/0_2026年_计算机系统基础_实验任务书_1_数据表示和等效运算.docx.txt`
- 工作源码目录：`experiments/lab01_data_representation/src/original_copy/`
- 可编辑工作副本：`experiments/lab01_data_representation/src/work/`
- 源码文件：`lab1.c`、`lab1.h`
- Visual Studio 项目文件：`lab1.sln`、`lab1.vcxproj`

## 2. 源码模板状态

当前 `lab1.c` 只是单个 `student_t student` 示例程序，执行流程为：

1. 清零 `student`。
2. 写入示例姓名 `wangwu`。
3. 写入示例年龄 `20`。
4. 写入示例分数 `90`。
5. 写入示例备注 `good!`。
6. 打印该结构体。

当前模板尚未实现任务书要求的：

- `beforecompress[N]` 和 `decompress[N]` 两个结构数组；
- `message` 紧凑压缩存储区；
- `pack_student_bytebybyte`；
- `pack_student_whole`；
- `restore_student`；
- `message` 前 40 字节十六进制输出；
- 浮点数编码分析输出或记录；
- 位运算函数和自动判定测试。

`lab1.h` 已定义与任务书一致的 `student_t` 结构。

## 3. 项目文件状态

`lab1.vcxproj` 当前包含：

- 配置：`Debug|Win32`、`Release|Win32`
- 输出类型：控制台应用程序
- Debug 优化：关闭
- Release 配置：启用常规 Release 编译选项
- 目标机：`MachineX86`
- 编译文件：`lab1.c`

任务书要求使用 Visual Studio 2019/2022/2023。当前项目文件来自较旧 VS 格式，正式执行前需要用实际可用 VS 打开或升级项目，并保存相关操作记录。

## 4. 执行步骤规划

1. 确认个人信息输入
   - 从 `config/report_metadata.yaml` 或用户明确确认中获取 `student_name` 和 `student_id`。
   - 仅用于实验输入时，仍需记录来源；不能使用源码示例值。

2. 确认工具链
   - 检查本机 Visual Studio 版本和 MSBuild 可用性。
   - 如果存在多个可用版本，执行前向用户确认使用哪一个。

3. 准备工作源码
   - 保留 `src/original_copy/` 不改。
   - 在 `src/` 下建立可编辑工作副本后再修改。
   - 记录复制动作和文件来源。

4. 实现任务 1
   - 定义 `beforecompress[N]`、`decompress[N]`、`message`。
   - 初始化 5 名学生数据，其中第 0 名学生的姓名和分数依赖已确认信息。
   - 实现逐字节压缩函数。
   - 实现整体字段写入压缩函数。
   - 实现只依赖接口参数的解压函数。
   - 输出压缩前、解压后、压缩长度和前 40 字节十六进制内容。

5. 调试与观察
   - 在 Visual Studio 调试器中观察 `message` 前 40 字节。
   - 保存截图或等效调试记录，并登记到 `evidence/screenshots_index.md`。
   - 对比程序输出的十六进制字节与调试器观察结果。

6. 分析数据表示
   - 根据已确认的第 0 名学生 `score` 值分析 IEEE 754 单精度编码。
   - 观察并解释字符串、`short`、`float`、结构数组元素的内存存放规律。

7. 实现任务 2
   - 逐个完成任务书列出的位运算函数。
   - 为每个函数编写标准实现或对照判断。
   - 保存自动测试输出，避免只凭人工判断。

8. 证据沉淀
   - 更新 `evidence/commands.md`。
   - 保存运行输出到 `outputs/`。
   - 更新 `evidence/errors_and_fixes.md`。
   - 更新 `evidence/evidence_manifest.md`。
   - 更新 `evidence/report_claims_checklist.md`。
   - 将可写入正文的素材沉淀到 `notes/report_material_bank.md`，但不直接写正式报告正文。

## 5. 当前阻塞点

以下事项不会阻塞本计划文件生成，但会阻塞源码实现或正式编译运行：

1. 任务书列出 VS2019/VS2022/VS2023，当前仅检测到 Visual Studio Community 2026，需要用户确认是否可用。
2. `student.name[8]` 中写入中文姓名“张家梁”时，需要确认采用 GBK/CP936 字节序列或其他写法。

这些事项已登记到 `evidence/human_questions.md`。
