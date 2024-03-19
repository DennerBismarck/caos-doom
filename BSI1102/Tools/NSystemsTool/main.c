//	Number Systems Tool
//
//	Authors: Iago Gouveia Gurgel and Luiz Paulo de Assis Barbosa
//
//	--help for help with options
//
//
//
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int, char **);
int options(int, char **);
int help();
int set_tex();
int menu();
int clear();
int str_index(char *, char);
int add();
int sub();
int add_padding(int, char *);

int cfg_tex = 0;
const char def_base[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(int argc, char ** argv){

	int op;
	options(argc, argv);

	while(1){
		menu();

		scanf("%d", &op);
		clear();
	
		switch(op){
		
			case 0:
				exit(0);
			break;
			case 1:
				add();
			break;
			case 2:
				sub();
			break;
			case 3:
	//			mult();
			break;
			case 4:
	//			div();
			break;
			case 5:
	//			n_add();
			break;
			default:
				exit(0);
		}

	}	

	return 0;
}

int options(int argc, char ** argv){
	
	for(int i = 0; i < argc; i++){
		if(strncmp(argv[i], "--help", 7) == 0){
			help();
		}
		else if(strncmp(argv[i], "-tex", 7) == 0){
			set_tex();
		}
	}
	return 0;
}

int help(){

	printf("./main [OPTIONS]...\n\n");
	printf("Produces 'as-in school' calculations using TeX align.\nAlso may be used for base conversions and overall learning\ndifferent basis arithmetic.\n\n");
	printf("-tex [FILENAME]\n		Produces LaTeX and writes it into a FILE. If non-specified, by default does\n		not produce LaTeX. If filename is not specified, creates a file with name based on current date and time.\n\n");
	printf("--help\n		display this help and exit\n\n");
	printf("Exit status:\n	0	if OK,\n\n 	1	if minor problems (wrong inputs),\n\n	2 	if serious trouble\n\n");
	exit(0);

}

int set_tex(){
	
	cfg_tex = 1;
	return 0;

}

int menu(){

	printf("0 - Exit\n");
	printf("1 - Addition\n");
	printf("2 - Subtract\n");
	printf("3 - Multiplication\n");
	printf("4 - Division\n");
	printf("5 - N-Operands Addition\n\n");
	printf("Choose: ");
	return 0;
}

int add(){

	char * n1 = (char *) malloc(sizeof(char) * 65);
	char * n2 = (char *) malloc(sizeof(char) * 65);
	int base;
	char * b_digits;
	int limit = 0;

	printf("Input 1st number: ");
	scanf("%65s", n1);
	printf("Input 2nd number: ");
	scanf("%65s", n2);
	printf("Input the numbers base: ");
	scanf("%d", &base);
	
	b_digits = (char *) malloc(sizeof(char) * (base + 1));
	b_digits[base] = '\0';
	if(strlen(n1) > strlen(n2)){
		limit = strlen(n1);
		add_padding(limit - strlen(n2), n2);
		
	}
	else if(strlen(n1) < strlen(n2)){
		limit = strlen(n2);
		add_padding(limit - strlen(n1), n1);
	}
	else{
		limit = strlen(n1);
	}
	strncpy(b_digits, def_base, (size_t) base);
	for(int i = (limit - 1); i >= 0 ; i--){
		printf("Result %d- %d\n", i, (str_index(b_digits, n1[i]) + str_index(b_digits, n2[i])) % base );
		printf("Carry  %d- %d\n", i, (str_index(b_digits, n1[i]) + str_index(b_digits, n2[i])) / base );
	}

	free(b_digits);
	free(n1);
	free(n2);

	return 0;
}

int sub(){

        char * n1 = (char *) malloc(sizeof(char) * 65);
        char * n2 = (char *) malloc(sizeof(char) * 65);
        int base;
        char * b_digits;
	int limit = 0;

        printf("Input 1st number: ");
        scanf("%65s", n1);
        printf("Input 2nd number: ");
        scanf("%65s", n2);
        printf("Input the numbers base: ");
        scanf("%d", &base);
        
        b_digits = (char *) malloc(sizeof(char) * (base + 1));
        b_digits[base] = '\0';
        if(strlen(n1) > strlen(n2)){
                limit = strlen(n1);
                add_padding(limit - strlen(n2), n2);

        }
        else if(strlen(n1) < strlen(n2)){
                limit = strlen(n2);
                add_padding(limit - strlen(n1), n1);
        }
        else{
                limit = strlen(n1);
        }
        strncpy(b_digits, def_base, (size_t) base);
	
	free(b_digits);
	free(n1);
	free(n2);

        return 0;
}

int add_padding(int n_paddings, char * number){
	
	printf("%s\n", number);

	for(int i = 0; i < n_paddings; i++){
		for(int j = (strlen(number) - 1); j >= 1 ; j--){
			number[j] = number[j - 1];
		}
		number[0] = '0';
	}

	printf("%s\n", number);
	exit(0);
	return 0;
}


int str_index(char * b_digits, char symbol){

	for(int i = 0; i < strlen(b_digits); i++){
		printf("%c == %c ?\n", b_digits[i], symbol);
		if(b_digits[i] == symbol) return i;
	}
	printf("Unrecognized symbol!");

	exit(2);

}

int clear(){
	system("clear || cls");
	return 0;
}
