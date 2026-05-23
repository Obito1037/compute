set pagination off
set disassembly-flavor intel
set confirm off

file bomb

break phase_1
commands
silent
printf "\n--- breakpoint: phase_1 ---\n"
printf "input string: "
x/s $rdi
printf "expected string for last digit 8: "
x/s ((char *)&special)+400
info registers rdi rbp rsp
continue
end

break *phase_2+0x32
commands
silent
printf "\n--- checkpoint: phase_2 after read_six_numbers ---\n"
x/6dw $rbp-0x20
continue
end

break *phase_3+0x50
commands
silent
printf "\n--- checkpoint: phase_3 after sscanf ---\n"
printf "first integer: "
x/dw $rbp-0x18
printf "second integer: "
x/dw $rbp-0x14
continue
end

break *phase_4+0x77
commands
silent
printf "\n--- checkpoint: phase_4 after func4 ---\n"
printf "func4 return eax = "
p/d $eax
printf "first integer: "
x/dw $rbp-0x1c
printf "second integer: "
x/dw $rbp-0x18
continue
end

break *phase_5+0x7c
commands
silent
printf "\n--- checkpoint: phase_5 transformed string ---\n"
x/s $rbp-0xf
continue
end

break *phase_6+0x46
commands
silent
printf "\n--- checkpoint: phase_6 after read_six_numbers ---\n"
x/6dw $rbp-0x60
continue
end

break *phase_6+0x146
commands
silent
printf "\n--- checkpoint: phase_6 reordered list head ---\n"
set $p = *(void **)($rbp-0x68)
printf "node 1: "
x/2dw $p
set $p = *(void **)($p+8)
printf "node 2: "
x/2dw $p
set $p = *(void **)($p+8)
printf "node 3: "
x/2dw $p
set $p = *(void **)($p+8)
printf "node 4: "
x/2dw $p
set $p = *(void **)($p+8)
printf "node 5: "
x/2dw $p
set $p = *(void **)($p+8)
printf "node 6: "
x/2dw $p
continue
end

run ../../outputs/lab03_answers_20260523.txt
quit
