.data 0x0100

a: .word 5
b: .word 12

.text 0x0000
main:
	addi $t0, $zero, 0x0100
	lw $t1, 0($t0)
	addi $t2, $t1, 2
	lw $t3, 4($t0)
	add $t4, $t1, $t2
	and $t1, $zero, $t1
	and $t2, $zero, $t2
	beq $t4, $t3, end
	sub $t4, $t3, $t2
end:
	j store
	add $zero, $zero, $zero
	add $zero, $zero, $zero
	add $zero, $zero, $zero
	add $zero, $zero, $zero
	
store:
	sw $t4, 8($t0) 
