add $t0, $t0, $t0
sub $t0, $t1, $t2
beq $t0, $t0, 0x0002
addi $t2, $t2, 0x0100
lw $t0, 0x0000($s0)
j 0x0000020