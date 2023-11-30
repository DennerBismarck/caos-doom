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

    textFile = input("Input text segment filename: ")

    if not os.path.exists(textFile):
        print("Text file does not exist")
        exit()

    dataFile = input("Input data segment filename: ")

    if not os.path.exists(dataFile):
        print("Data file does not exist")
        exit()

    programFile = input("Input a name for program file: ")

    




    

if __name__ == "__main__":
    main()




