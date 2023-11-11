#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

char * toBinaryString(int decimal, int bitsNumber);
int fromBinary(char * binaryString);
int saveResult(int result, char * filename, int * counter);
int arg1IsASM(char * filename);

// Definition of instruction set constants
#define ADD "add"
#define AND "and"
#define OR "or"
#define SUB "sub"
#define SLT "slt"
#define NAND "nand"
#define NOR "nor"
#define BEQ "beq"
#define LW "lw"
#define SW "sw"
#define JUMP "j"
#define ADDI "addi"
#define REGSIZE 5
#define FUNCTSIZE 7
#define IMMDSIZE 16


// To use compiler, ran it with args (file.s ramfilename)
int main(int argc, char * argv[]){

    if(!(argc == 2)){
        printf("Too few arguments passed to main");
        return 1;
    }

    if(!arg1IsASM()){
        printf("No assembly file was passed as argument 1")
    }

}

char * toBinaryString(int decimal, int bitsNumber){

    char * binaryOut = malloc(bitsNumber + 1);

    int remainder;

    for(int i = 1; i <= bitsNumber + 1; i++){

        remainder = decimal % 2;
        if(remainder == 0){
            binaryOut[bitsNumber - i] = '0';
        }
        else
        {
            binaryOut[bitsNumber - i] = '1';
        }
        decimal = decimal / 2;
    }
    binaryOut[bitsNumber] = '\0';

    return binaryOut;

}

int fromBinary(char * binaryString){
    int result = 0;
    for (int i = 0; binaryString[i] != '\0'; i++) {
        result <<= 1;  // Left shift by 1 bit
        if (binaryString[i] == '1') {
            result |= 1;  // Set the least significant bit
        }
    }
    return result;
    
}

int saveResult(int result, char * filename, int * counter){

    FILE * filePointer;

    filePointer = fopen(filename, "a");

    if(filePointer == NULL){
        filePointer = fopen(filename, "w");
        fprintf(filePointer, "v2.0 raw \n");
    }

    fprintf(filePointer, "%08x ", result);
    *counter = *counter + 1;

    if(*counter % 8 == 0){
        fprintf(filePointer, "\n");
    }

    fclose(filePointer);
}

int setupFile(char * filename){
    FILE * filePointer;

    FILE * filePointer;

    filePointer = fopen(filename, "r");

    if(filePointer == NULL){
        filePointer = fopen(filename, "w");
        fprintf(filePointer, "v3.0 raw \n");
    }
    
}