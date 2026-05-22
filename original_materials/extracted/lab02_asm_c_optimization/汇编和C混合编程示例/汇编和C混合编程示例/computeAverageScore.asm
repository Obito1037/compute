.686P
.model flat, c
printf proto c :ptr sbyte, :vararg
; includelib  libcmt.lib
includelib  legacy_stdio_definitions.lib 

student  struct
    sname   db   8 dup(0)
    sid     db   11 dup(0)
    align   2    ; 指明对齐方式，汇编语言默认是紧凑存放
                 ; 可以实验一下，去掉对齐方式伪指令的结果
    scores  dw   8  dup(0)
    average dw   0
student   ends

.data
   lpfmt  db "%s %s %d %d",0dh,0ah,0
   lpfmt_string  db "%s  ",0
   lpfmt_num  db "%d  ",0
   lpfmt_size    db  "size of struct %d  ",0dh,0ah,0
   lpfmt_offset  db  0dh,0ah,"offset of scores %d  ",0dh,0ah,0

.code
;  显示学生信息
;  sptr 学生数组的首地址
;  num  学生人数
;  注意， printf 中会用到一些寄存器，也没有保护
;         即执行 printf前后，一个寄存器中的内容发生变化

display proc  sptr: dword, num:dword
        local  i:dword      ; 定义局部变量，等同 unsigned int

        mov  ebx, sptr
        invoke printf, offset lpfmt_string, ebx
        invoke printf, offset lpfmt_string, addr  [ebx].student.sid

        invoke printf , offset lpfmt_num,  [ebx].student.scores[0]   ; 第0个分数
        invoke printf , offset lpfmt_num,  [ebx].student.scores[2]   ; 第1个分数
        add   ebx, 24
        invoke printf , offset lpfmt_num,  word ptr [ebx]    ; 第2个分数

        mov    esi, offset student.scores  ; 取字段scores 在结构中的偏移量
        mov    edi, type student           ; 取结构的大小
        invoke printf , offset lpfmt_offset, esi
        invoke printf , offset lpfmt_size, edi

        mov    ebx,num         ; 局部变量、参数的用法示例
        mov    i,  ebx
        invoke printf, offset lpfmt_num, i   ; 显示学生人数

        ret
display endp


end