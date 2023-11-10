# MAS
Microprocessor and Architecture Simulation

This repository is focused on developing Microprocessor architecture simulations using Logisim Evolution.

Currently, these are the projects developed: 

1. MiniMIPS 16 bits single-cycle 
2. MIPS 32 bits multi-cycle without pipelining (in dev)


For future ideas, we look out to do:

3. MIPS 32 bits single-cycle
4. MIPS 32 bits multi-cycle with pipelining

Note that the fourth project has many stages of hazard detection and optimization implementations, we ought to develop those as well.

# Using the MIPS ASM Coder

To use the MIPS ASM Coder, you should first compile it to an executable using the command below:

```console
gcc -o main main.c -lm
```
After compiling the code, run it and follow the instructions:

1. Give your program a filename (Do not input any extensions, only raw filename).
2. Select the instruction type.
3. Input the instruction (The instruction set implemented can be found in ALUControl Instructions.txt)
4. Input registers, immediate or address.
5. Repeat until you finish coding.

After you finish the main program, your instructions should be programmed into a file named with the filename given.


References:

