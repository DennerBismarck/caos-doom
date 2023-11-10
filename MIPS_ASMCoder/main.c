#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

char * toBinaryString(int decimal, int bitsNumber);
int fromBinary(char * binaryString);
int saveResult(int result, char * filename);

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
    char instOpcode[] = "000000";
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
    printf("Digite um nome para o arquivo de seu programa: ");
    scanf("%100s", filename);
    system("cls || clear");
    do{
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

            instCode = malloc(sizeof(char) * 33);
            instruction = malloc(sizeof(char) * 5);
            reg1 = malloc(sizeof(char) * REGSIZE);
            reg2 = malloc(sizeof(char) * REGSIZE);
            reg3 = malloc(sizeof(char) * REGSIZE);

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
            saveResult(result, filename);
            printf("Your instruction in hexa is: %08x \n \n \n", result);

            free(instCode);
            free(instruction);


            break;
        
        case 2:

            instCode = malloc(sizeof(char) * 33);
            instruction = malloc(sizeof(char) * 5);
            reg1 = malloc(sizeof(char) * REGSIZE);
            reg2 = malloc(sizeof(char) * REGSIZE);
            immd16C = malloc(sizeof(char) * 16);

            printf("Digite a instrução: ");
            scanf("%5s", instruction);
            printf("Digite o rs(em decimal): ");
            scanf("%hu", &rs);
            printf("Digite o rt(em decimal): ");
            scanf("%hu", &rt);
            printf("\n");
            printf("Digite o imediato de 16bits(endereço de palavra)(em hexa): ");
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
            }

            strcat(instCode, instOpcode);
            strcat(instCode, reg1);
            strcat(instCode, reg2);
            strcat(instCode, immd16C);

            instCode[32] = '\0';

            result = fromBinary(instCode);
            saveResult(result, filename);
            printf("Your instruction in hexa is: %08x \n \n \n", result);

            free(instCode);
            free(instruction);
            free(immd16C);

            break;

        case 3:

            instCode = malloc(sizeof(char) * 33);
            jumpAddressC = malloc(sizeof(char) * 26);
            printf("Digite o endereço para o jump(Endereço de palavra)(em hexa): ");
            scanf("%x", &jumpAddress);
            printf("\n");
            system("cls || clear");

            immd16C = toBinaryString(jumpAddress, 26);

            strcat(instCode, "000010");
            strcat(instCode, immd16C);

            instCode[32] = '\0';

            result = fromBinary(instCode);
            saveResult(result, filename);
            printf("Your instruction in hexa is: %08x \n \n \n", result);

            free(instCode);
            free(jumpAddressC);

            break;
        
        default:
            break;
        }

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

int saveResult(int result, char * filename){

    FILE * filePointer;

    filePointer = fopen(filename, "a");

    if(filePointer == NULL){
        filePointer = fopen(filename, "w");
    }

    fprintf(filePointer, "%08x ", result);

    fclose(filePointer);
}