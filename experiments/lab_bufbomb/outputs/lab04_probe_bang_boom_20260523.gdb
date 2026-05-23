set pagination off
set disassembly-flavor intel
set disable-randomization on
file bufbomb

break *getbuf+0x24
commands
silent
printf "--- getbuf stack probe ---\n"
printf "rbp="
p/x $rbp
printf "buf="
p/x $rbp-0x30
printf "saved_rbp_value="
x/gx $rbp
printf "ret_value="
x/gx $rbp+8
continue
end

run U202414558 ../../outputs/lab04_bang_hex_20260523.txt 2
run U202414558 ../../outputs/lab04_boom_hex_20260523.txt 3
quit
