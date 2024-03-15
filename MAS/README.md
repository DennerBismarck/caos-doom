# MAS
Microprocessor Architecture Simulations

This repository is focused on develop:

Currently, these are the projects developed: 

1. MiniMIPS 16 bits single-cycle 
2. MIPS 32 bits multi-cycle without pipelining (in dev)


For future ideas, we look out to do:

3. MIPS 32 bits single-cycle
4. MIPS 32 bits multi-cycle with pipelining

Note that the fourth project has many stages of hazard detection and optimization implementations, we ought to develop those as well.

# Using the MIPS ASSEMBLER

To use the MIPS ASM Coder, you should first compile it to an executable using the command below:

```console
gcc -o main main.c
```
After compiling the code, run it with:

```console
./main <yourAsm>.s <nameForRAMFile>
```

After you finish the main program, your instructions should be programmed into your RAM image file.

Notes:

The program currently running with Seg Fault without a call to a printf at the beginning of the code. Still studying the reasons behind it.

References:

