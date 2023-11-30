import sys
import re
import os.path



# Definition of constant variables

FILEREGEX = "([A-Za-z0-9]+[.]s$)|([A-Za-z0-9]+[.]asm$)|([A-Za-z0-9]+[.]mips$)|([A-Za-z0-9]+[.]spim$)"
RTYPEREGEX = "([a-z]+ [$][a-z0-9]+[,] [$][a-z0-9]+[,] [$][a-z0-9]+)"
JTYPEMATCH = "([j] 0x[0-9]{7})"
ITYPEMATCH = "([a-z]+ [$][a-z0-9]+[,] [$][a-z0-9]+[,] 0x[0-9]{4})"
MEMTYPEMATCH = "([a-z]+ [$][a-z0-9]+[,] 0x[0-9]{4}[(][$][a-z0-9]+[)])"
OPERATIONMATCH = "(sub)|(addi)|(lw)|(add)|(j)|(sw)|(slt)|(nor)|(nand)|(and)|(or)|(beq)"
REGMATCH = "[$][zeroatvskgfsp0-9]+"
IMMD16MATCH = "0x[0-9]{4}"
JADDRMATCH = "0x[0-9]{7}"



RegBank = {
    "$zero" : 0,
    "$at" : 1,
    "$v0" : 2,
    "$v1" : 3,
    "$a0" : 4,
    "$a1" : 5,
    "$a2" : 6,
    "$a3" : 7,
    "$t0" : 8,
    "$t1" : 9,
    "$t2" : 10,
    "$t3" : 11,
    "$t4" : 12,
    "$t5" : 13,
    "$t6" : 14,
    "$t7" : 15,
    "$s0" : 16,
    "$s1" : 17,
    "$s2" : 18,
    "$s3" : 19,
    "$s4" : 20,
    "$s5" : 21,
    "$s6" : 22,
    "$s7" : 23,
    "$t8" : 24,
    "$t9" : 25,
    "$k0" : 26,
    "$k1" : 27,
    "$gp" : 28,
    "$sp" : 29,
    "$fp" : 30,
    "$ra" : 31
 }

InstructionSet = {
    "lw" : [0x23],
    "sw" : [0x2b],
    "beq" : [0x4],
    "addi" : [0x8],
    "j" : [0x2],
    "add" : [0x0, 0x20],
    "and" : [0x0, 0x24],
    "sub" : [0x0, 0x22],
    "or" : [0x0, 0x25],
    "nand" : [0x0, 0x26],
    "nor" : [0x0, 0x27],
    "slt" : [0x0, 0x2a],
}

memoryList = []


def main():

    if len(sys.argv) < 3:
        print("Not enough arguments passed!")
        return 1

    if re.search(FILEREGEX, sys.argv[1]) == None:
        print("Wrong arguments passed to main!")
        return 1
    
    if not os.path.isfile(sys.argv[1]):
        print(f"File named '{sys.argv[1]}' does not exist")
        return 1
    
    asmFile = open(sys.argv[1], "r")

    for line in asmFile:
        print(line, end='')
        line = line.lower()
        
        if re.match(RTYPEREGEX, line) != None:
            treatRType(line)
            continue
        
        elif re.match(ITYPEMATCH, line) != None:
            treatIType(line)
            continue
        
        elif re.match(JTYPEMATCH, line) != None:
            treatJType(line)
            continue
        
        elif re.match(MEMTYPEMATCH, line) != None:
            treatMemType(line)
            continue

    print()
    
def treatRType(asmLine):

    inst = re.match(OPERATIONMATCH, asmLine)
    regs = re.compile(REGMATCH)
    regs = regs.findall(asmLine)
    opcode = InstructionSet.get(inst.group())[0]
    funct = InstructionSet.get(inst.group())[1]
    rd = RegBank.get(regs[0])
    rs = RegBank.get(regs[1])
    rt = RegBank.get(regs[2])
    shamt = 0x0
    immd16 = 0x0
    jumpAddr = 0x0

    opcode = opcode << 26
    rs = rs << 21
    rt = rt << 16
    rd = rd << 11
    
    instructionComplete = opcode + rs + rt + rd + shamt + funct + immd16 + jumpAddr

    strHex = "0x%0.8X" % instructionComplete

    memoryList.append(strHex)

    return 0

def treatIType(asmLine):

    inst = re.match(OPERATIONMATCH, asmLine)
    regs = re.compile(REGMATCH)
    regs = regs.findall(asmLine)
    opcode = InstructionSet.get(inst.group())[0]
    immd16 = re.search(IMMD16MATCH, asmLine).group()

    funct = 0x0
    if opcode == 4:
        rs = RegBank.get(regs[0])
        rt = RegBank.get(regs[1])
        rd = 0x0
    else:
        rt = RegBank.get(regs[0])
        rs = RegBank.get(regs[1])
        rd = 0x0
    shamt = 0x0
    immd16 = int(immd16, 0)
    jumpAddr = 0x0

    opcode = opcode << 26
    rs = rs << 21
    rt = rt << 16
    
    instructionComplete = opcode + rs + rt + rd + shamt + funct + immd16 + jumpAddr

    strHex = "0x%0.8X" % instructionComplete

    memoryList.append(strHex)

    return 0

def treatJType(asmLine):

    jumpAddr = re.search(JADDRMATCH, asmLine).group()
    opcode = 0x2
    funct = 0x0
    rs = 0x0
    rt = 0x0
    rd = 0x0
    shamt = 0x0
    immd16 = 0x0
    jumpAddr = int(jumpAddr, 0)

    opcode = opcode << 26
    
    instructionComplete = opcode + rs + rt + rd + shamt + funct + immd16 + jumpAddr

    strHex = "0x%0.8X" % instructionComplete
    
    memoryList.append(strHex)

    return 0

def treatMemType(asmLine):

    inst = re.match(OPERATIONMATCH, asmLine)
    regs = re.compile(REGMATCH)
    regs = regs.findall(asmLine)
    opcode = 0x2
    funct = 0x0
    rs = 0x0
    rt = 0x0
    rd = 0x0
    shamt = 0x0
    immd16 = 0x0
    jumpAddr = int(jumpAddr, 0)

    opcode = opcode << 26
    
    instructionComplete = opcode + rs + rt + rd + shamt + funct + immd16 + jumpAddr

    strHex = "0x%0.8X" % instructionComplete
    
    memoryList.append(strHex)

    return 0

if __name__ == "__main__":
    main()




