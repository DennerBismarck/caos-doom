#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

char * toBinaryString(int decimal, int bitsNumber);
int fromBinary(char * binaryString);
int saveResult(int result, char * filename, int * counter);

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



int main(int argc, char * argv[]){

    int instType;
    char filename[100];
    char * instruction;
    char instOpcode[7] = "000000";
    char * instCode;
    char funct[FUNCTSIZE];
    __uint16_t rd, rs, rt;
    char * reg1;
    char * reg2;
    char * reg3;
    __uint16_t immd16;
    int jumpAddress;
    char * jumpAddressC;
    char * immd16C;
    int result = 0;
    int instructionCounter = 0;
    system("cls || clear");
    printf("Digite um nome para o arquivo de seu programa: ");
    scanf("%100s", filename);
    system("cls || clear");
    do{
        instCode = malloc(sizeof(char) * 33);
        printf("Selecione o tipo de instrução\n");
        printf("1. R-Type\n");
        printf("2. I-Type\n");
        printf("3. J-Type\n");
        printf("0. Sair\n");
        printf("Digite o tipo de instrução: ");
        scanf("%d", &instType);
        system("cls || clear");

        switch (instType)
        {
        case 1:
            rs, rt, rd = 0;
            instruction = malloc(sizeof(char) * 5);
            reg1 = malloc(sizeof(char) * REGSIZE);
            reg2 = malloc(sizeof(char) * REGSIZE);
            reg3 = malloc(sizeof(char) * REGSIZE);
            result = 0;

            printf("Digite a instrução: ");
            scanf("%5s", instruction);
            printf("Digite o rs(em decimal): ");
            scanf("%hu", &rs);
            printf("Digite o rt(em decimal): ");
            scanf("%hu", &rt);
            printf("Digite o rd(em decimal): ");
            scanf("%hu", &rd);
            printf("\n");
            system("cls || clear");

            if(!strcmp(instruction, ADD)){
                strncpy(funct, "100000", FUNCTSIZE);
            }
            else if(!strcmp(instruction, SUB)){
                strncpy(funct, "100010", FUNCTSIZE);
            }
            else if(!strcmp(instruction, SLT)){
                strncpy(funct, "101010", FUNCTSIZE);
            }
            else if(!strcmp(instruction, AND)){
                strncpy(funct, "100100", FUNCTSIZE);
            }
            else if(!strcmp(instruction, OR)){
                strncpy(funct, "100101", FUNCTSIZE);
            }
            else if(!strcmp(instruction, NAND)){
                strncpy(funct, "100110", FUNCTSIZE);
            }
            else if(!strcmp(instruction, NOR)){
                strncpy(funct, "100111", FUNCTSIZE);
            }

            reg3 = toBinaryString(rd, REGSIZE);
            reg1 = toBinaryString(rs, REGSIZE);
            reg2 = toBinaryString(rt, REGSIZE);

            strcat(instCode, instOpcode);
            strcat(instCode, reg1);
            strcat(instCode, reg2);
            strcat(instCode, reg3);
            strcat(instCode, "00000"); // Shamt
            strcat(instCode, funct);

            instCode[32] = '\0';
            
            result = fromBinary(instCode);
            saveResult(result, filename, &instructionCounter);
            printf("Your instruction in hexa is: %08x \n \n \n", result);

            free(instruction);
            


            break;
        
        case 2:

            rs, rt, rd = 0;
            instruction = malloc(sizeof(char) * 5);
            reg1 = malloc(sizeof(char) * REGSIZE);
            reg2 = malloc(sizeof(char) * REGSIZE);
            immd16C = malloc(sizeof(char) * 16);
            result = 0;

            printf("Digite a instrução: ");
            scanf("%5s", instruction);
            printf("Digite o rs(em decimal): ");
            scanf("%hu", &rs);
            printf("Digite o rt(em decimal): ");
            scanf("%hu", &rt);
            printf("\n");
            printf("Digite o imediato de 16 bits(endereço de palavra)(em hexa): ");
            scanf("%hx", &immd16);
            printf("\n");
            system("cls || clear");

            immd16 = immd16 << 2;

            immd16C = toBinaryString(immd16, 16);

            reg2 = toBinaryString(rt, REGSIZE);
            reg1 = toBinaryString(rs, REGSIZE);

            if(!strcmp(instruction, ADDI)){
                strncpy(instOpcode, "001000", 7);
            }
            else if(!strcmp(instruction, BEQ)){
                strncpy(instOpcode, "000100", 7);
            }
            else if(!strcmp(instruction, SW)){
                strncpy(instOpcode, "101011", 7);
            }
            else if(!strcmp(instruction, LW)){
                strncpy(instOpcode, "100011", 7);
                printf("HEY!");
            }

            strcat(instCode, instOpcode);
            printf("%s \n", instCode);
            strcat(instCode, reg1);
            printf("%s \n", instCode);
            strcat(instCode, reg2);
            printf("%s \n", instCode);
            strcat(instCode, immd16C);
            printf("%s \n", instCode);

            instCode[32] = '\0';

            result = fromBinary(instCode);
            saveResult(result, filename, &instructionCounter);
            printf("Your instruction in hexa is: %08x \n \n \n", result);

            free(instruction);

            break;

        case 3:

            jumpAddressC = malloc(sizeof(char) * 26);
            result = 0;
            printf("Digite o endereço para o jump(Endereço de palavra)(em hexa): ");
            scanf("%x", &jumpAddress);
            printf("\n");
            system("cls || clear");

            immd16C = toBinaryString(jumpAddress, 26);

            strcat(instCode, "000010");
            strcat(instCode, immd16C);

            instCode[32] = '\0';

            result = fromBinary(instCode);
            saveResult(result, filename, &instructionCounter);
            printf("Your instruction in hexa is: %08x \n \n \n", result);

            break;
        
        default:
            break;
        }

        free(instCode);

    }while(instType != 0);

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