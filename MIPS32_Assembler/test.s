add $t0, $t0, $t0
add $zero, $zero, $zero
sub $t0, $t1, $t2
beq $t0, $t1, 0x0003 // funciona com word address
addi $t2, $t2, 0x0100
lw $t0, 0x0000($s0)
j 0x0000004 // funciona com word address