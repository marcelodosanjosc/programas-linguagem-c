// atividade 01 censo no brasil
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Estado{
	char nomeEstado[20];
	char unidadeFederativa[3];
	float quantPopulacional;
}Estado; // fim do registro Estado

Estado es[3];// vetor de estado

void cadastraEstado(); // declaracao da procedimento cadastra estado
void pesquisarEstado(); // declaracao do procedimento pesquisar estado
void menu(); // declaracao do procedimento menu

main (){
	menu();
	system("pause");
}//fim da main

void cadastraEstado(){
	int i;
	for(i = 0; i < 3; i++){
		printf("Digite nome do estado %i: \n", i+1);
		fflush(stdin);
		gets(es[i].nomeEstado);
		printf("Digite a unidade federativa: \n");
		fflush(stdin);
		gets(es[i].unidadeFederativa);
		printf("Digite a quantidade populacional: \n");
		fflush(stdin);
		scanf("%f", &es[i].quantPopulacional);
	}//fim for 
}// fim do cadastro de estados

void pesquisarEstado(){
	char aux[20];
	int i, achei = 0;
	printf("Digite o Estado ou Unidade Federativa de busca: \n");
	fflush(stdin);
	gets(aux);
	for(i = 0; i < 3; i++){
		if(strcmp(aux, es[i].unidadeFederativa)==0 || strcmp(aux, es[i].nomeEstado)==0){
			printf("Nome do estado: %s\n",es[i].nomeEstado);
			printf("Unidade federativa: %s\n",es[i].unidadeFederativa);
			printf("Quantidade populacional: %0.f\n\n", es[i].quantPopulacional);
			system("pause");
			achei = 1;
		}else{
			achei = 0;
		}
	}
	 if (!achei)
	 	printf("Nao encontrado \n");
	 	system("pause");
}// fim da pesquisar

void menu(){
	int op = 0;
	
	do {
	system("cls");
	printf("1 - Cadastra Estado \n");
	printf("2 - Pesquisar Estado \n");
	printf("0 - Sair \n");
	printf("Digite a opcao: \n");
	scanf("%i", &op);
	switch (op){
		case 1:
			cadastraEstado();
			break;
		case 2:
			pesquisarEstado();
			break;
		case 0:
			exit(0);
			break;
		default:
			printf("Opcao nao exitente \n");	
			break;		
		}
	}while (op != 0);
	
}// fim do menu
