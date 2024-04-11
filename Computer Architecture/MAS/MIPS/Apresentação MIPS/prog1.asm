.data 0x400 # Define o ponteiro de dados para a região 0x400 da memória no modo MARS MEMORY 16 BIT COMPACTED DATA AT 0X0000

a: .word 5 # Adiciona 5 na memória na posição 0x400 
b: .word 7 # Adiciona 7 na memória na posição 0x404
c: .word # Adiciona um label para a região 0x408 / Após execução, receberá o valor 5 + 7 = 0xc

.text

addi $t0, $zero, 0x400    # 20080400 -> 0010 0000 0000 1000 0000 0100 0000 0000 / FORMATO I -> 001000 00000 01000 00000100000000000 -> Opcode 8(hex) ; RgSrc1 0 ; RgDest 8 ; Immd 0x400
lw $t1, 0($t0)            # 8D090000 -> 1000 1101 0000 1001 0000 0000 0000 0000 / FORMATO I ->  100011 01000 01001 0000 0000 0000 0000 -> Opcode 23(hex) ; RgSrc1 8 ; RgDest 9; Immd 0x0000
lw $t2, 4($t0)            # 8D0A0004 -> 1000 1101 0000 1010 0000 0000 0000 0000 / FORMATO I ->  100011 01000 01010 0000 0000 0000 0000 -> Opcode 23(hex) ; RgSrc1 8; RgDest 10; Immd 0x0004
add $t3, $t1, $t2         # 012A5820 ->  0000 0001 0010 1010 0101 1000 0010 0000 / FORMATO R -> 000000 01001 01010 01011 00000 100000  -> Opcode 0(hex) ; RgSrc 9; RgSrc 10; RgDest 11; Shamt 0 ; Funct 20(hex)
sw $t3, 8($t0)            # AD0B0008 -> 1010 1101 0000 1011 0000 0000 0000 1000 / FORMATO I -> 101011 01000 01011 0000000000001000 -> Opcode 2b(hex) ; RgSrc1 8; RgSrc2 11; Immd 0x0008
