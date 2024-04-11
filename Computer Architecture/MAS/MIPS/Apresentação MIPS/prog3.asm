.data 0x400  # Define o ponteiro de dados para a região 0x400 da memória no modo MARS MEMORY 16 BIT COMPACTED DATA AT 0X0000

a: .word 5   # Adiciona 5 na memória na posição 0x400 
b: .word 3   # Adiciona 3 na memória na posição 0x404
c: .word     # Adiciona um label para a região 0x408 / Após execução, receberá o valor 5 + 7 = 0xc

.text 

nor $t5, $t5, $t5 	# 01AD6827 -> 0000 0001 1010 1101 0110 1000 0010 0111 / FORMATO R -> 000000 01101 01101 01101 00000 100111 -> Opcode 0(hex); RgSrc1 13; RgSrc2 13; RgDest 13; Shamt 0; Funct 27(hex)
addi $t0, $zero, 0x400 	# 20080400 -> 0010 0000 0000 1000 0000 0100 0000 0000 / FORMATO I -> 001000 00000 01000 00000100000000000 -> Opcode 8(hex) ; RgSrc1 0 ; RgDest 8 ; Immd 0x400h
lw $t1, 0($t0) 		# 8D090000 -> 1000 1101 0000 1001 0000 0000 0000 0000 / FORMATO I ->  100011 01000 01001 0000 0000 0000 0000 -> Opcode 23(hex) ; RgSrc1 8 ; RgDest 9; Immd 0x0000
lw $t2, 4($t0) 		# 8D0A0004 -> 1000 1101 0000 1010 0000 0000 0000 0000 / FORMATO I ->  100011 01000 01010 0000 0000 0000 0000 -> Opcode 23(hex) ; RgSrc1 8; RgDest 10; Immd 0x0004

loop:
beq $t2, $zero, end 	# 11400003 -> 0001 0001 0100 0000 0000 0000 0000 0011 / FORMATO I -> 000100 01010 00000 0000000000000011 -> Opcode 4(hex) ; RgSrc1 10; RgSrc2 zero; Immd 0x0003
add $t3, $t3, $t1   	# 01695820 -> 0000 0001 0110 1001 0101 1000 0010 0000 / FORMATO R -> 000000 01011 01001 01011 00000 100000 -> Opcode 0(hex); RgSrc 11; RgSrc2 9; RgDest 11; Shamt 0; Funct 20(hex)
add $t2, $t2, $t5  	# 014D5020 -> 0000 0001 0100 1101 0101 0000 0010 0000 / FORMATO R -> 000000 01010 01101 01010 00000 100000 -> Opcode 0(hex); RgSrc 10; RgSrc 13; RgDest 10; Shamt 0; Funct 20(hex)
j loop 			# 08000004 -> 0000 1000 0000 0000 0000 0000 0000 0100 / FORMATO J -> 000010 00000000000000000000000100 -> Opcode 2(hex); JAddr 0x4

end:
sw $t3, c 		# AC0B0408 -> 1010 1100 0000 1011 0000 0100 0000 1000 / FORMATO I -> 101011 00000 01011 0000010000001000 -> Opcode 2b(hex); RgSrc zero; RgSrc 11; Immd 0x408
