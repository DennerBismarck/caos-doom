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
int add();

int cfg_tex = 0;

int main(int argc, char ** argv){

	int op;
	options(argc, argv);
	menu();

	scanf("%d", &op);
	
	switch(op){
		
		case 0:
			exit(0);
		break;
		case 1:
			add();
		break;
		case 2:
	//		sub();
		break;
		case 3:
	//		mult();
		break;
		case 4:
	//		div();
		break;
		case 5:
	//		n_add();
		break;
		default:
			exit(0);
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

	char * n1 = (char *) malloc(sizeof(char) * 64);
	char * n2 = (char *) malloc(sizeof(char) * 64);

	printf("Input 1st number: ");
	scanf("%64s", n1);
	printf("Input 2nd number: ");
	scanf("%64s", n2);

	return 0;

}
