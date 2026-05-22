.686P
.model flat, c

student struct
    sname   db 8 dup(0)
    sid     db 11 dup(0)
    align   2
    scores  dw 8 dup(0)
    average dw 0
student ends

.code

computeAverageScore_asm proc uses esi ebx, sptr:dword, num:dword
    mov esi, sptr
    mov ecx, num
    test ecx, ecx
    jle average_done

average_loop:
    push ecx
    xor eax, eax
    movsx edx, word ptr [esi].student.scores[0]
    add eax, edx
    movsx edx, word ptr [esi].student.scores[2]
    add eax, edx
    movsx edx, word ptr [esi].student.scores[4]
    add eax, edx
    movsx edx, word ptr [esi].student.scores[6]
    add eax, edx
    movsx edx, word ptr [esi].student.scores[8]
    add eax, edx
    movsx edx, word ptr [esi].student.scores[10]
    add eax, edx
    movsx edx, word ptr [esi].student.scores[12]
    add eax, edx
    movsx edx, word ptr [esi].student.scores[14]
    add eax, edx
    mov ebx, 8
    cdq
    idiv ebx
    mov word ptr [esi].student.average, ax
    add esi, type student
    pop ecx
    loop average_loop

average_done:
    ret
computeAverageScore_asm endp

computeAverageScore_asm_opt proc uses esi, sptr:dword, num:dword
    mov esi, sptr
    mov ecx, num
    test ecx, ecx
    jle average_opt_done

average_opt_loop:
    xor eax, eax
    movsx edx, word ptr [esi].student.scores[0]
    add eax, edx
    movsx edx, word ptr [esi].student.scores[2]
    add eax, edx
    movsx edx, word ptr [esi].student.scores[4]
    add eax, edx
    movsx edx, word ptr [esi].student.scores[6]
    add eax, edx
    movsx edx, word ptr [esi].student.scores[8]
    add eax, edx
    movsx edx, word ptr [esi].student.scores[10]
    add eax, edx
    movsx edx, word ptr [esi].student.scores[12]
    add eax, edx
    movsx edx, word ptr [esi].student.scores[14]
    add eax, edx
    sar eax, 3
    mov word ptr [esi].student.average, ax
    add esi, type student
    dec ecx
    jnz average_opt_loop

average_opt_done:
    ret
computeAverageScore_asm_opt endp

end
