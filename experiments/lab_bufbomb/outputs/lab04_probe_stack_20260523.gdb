set pagination off
set disassembly-flavor intel
set disable-randomization on
file bufbomb
break *getbuf+0x24
commands
silent
printf "--- getbuf stack probe ---\n"
printf "rbp = "
p/x $rbp
printf "rsp = "
p/x $rsp
printf "buf = rbp-0x30 = "
p/x $rbp-0x30
printf "saved rbp slot = rbp = "
p/x $rbp
printf "return address slot = rbp+8 = "
p/x $rbp+8
printf "saved rbp value = "
x/gx $rbp
printf "return address value = "
x/gx $rbp+8
continue
end
run U202414558 ../../outputs/lab04_probe_minimal_hex_20260523.txt 0
quit
