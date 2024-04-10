.data 0x400

a: .word 5
b: .word 3
c: .word 

.text 

nor $t5, $t5, $t5
addi $t0, $zero, 0x400 # 20080400 -> 0010 0000 0000 1000 0000 0100 0000 0000 / FORMATO I -> 001000 00000 01000 00000100000000000 -> Opcode 8(hex) ; RgSrc1 0 ; RgDest 8 ; Immd 0x400
lw $t1, 0($t0) # 8D090000 -> 1000 1101 0000 1001 0000 0000 0000 0000 / FORMATO I ->  100011 01000 01001 0000 0000 0000 0000 -> Opcode 23(hex) ; RgSrc1 8 ; RgDest 9; Immd 0x0000
lw $t2, 4($t0) # 8D0A0004 -> 1000 1101 0000 1010 0000 0000 0000 0000 / FORMATO I ->  100011 01000 01010 0000 0000 0000 0000 -> Opcode 23(hex) ; RgSrc1 8; RgDest 10; Immd 0x0004

loop:
	beq $t2, $zero, end
	add $t3, $t3, $t1
	add $t2, $t2, $t5
	j loop

end:
	sw $t3, c







