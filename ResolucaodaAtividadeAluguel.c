#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Endereco{
	char bairro[10];
	char rua[10];
	char casa[10];
}Endereco;
typedef struct Carro{
	char modelo[12];
	char cor[12];
	char placa[10];
	int ano;
	float vd;
	char status[10];
}Carro;
typedef struct Cliente{
	char nome[10];
	int cnh;
	Endereco end;
}Cliente;



main(){
	int op;
	
	do {
		printf("1-Cadastra carro\n");
		printf("2-Cadastra cliente\n");
		printf("3-Realizar aluguel\n");
		printf("4-Finalizar aluguel\n");
		printf("0-Sair\n");
		scanf("%i",&op);
		switch(op != 0){
			case 1:
				break;
			case 2:
				break;	
			case 3:
				break;
			case 4:
				break;
			case 0:
				exit(0);
				break;
			default:
			printf("Opcao invalida\n");			
		}
	} while(op != 0);
	system("pause");
}//fim main
