# ELF 分析指南

常用命令：

```bash
gcc -S -fverbose-asm -D U* main.c -o main.s
gcc -c -g -D U* main.c -o main.o
readelf -S -W main.o | tee outputs/readelf_sections_main_o.txt
readelf -s main.o | tee outputs/readelf_symbols_main_o.txt
readelf -r main.o | tee outputs/readelf_relocations_main_o.txt
objdump -d main.o | tee outputs/objdump_disasm_main_o.txt
readelf -x .data main.o | tee outputs/readelf_data_main_o.txt
readelf -x .rodata main.o | tee outputs/readelf_rodata_main_o.txt
```

分析重点：节头表、符号表、重定位、静态链接、动态链接。
