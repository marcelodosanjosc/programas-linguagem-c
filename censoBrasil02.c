// atividade 02 censo no brasil
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Municipios{
	char nomeMunicipio[20];
	float quantidadePop;
} Municipios;//fim do registro municipio

typedef struct Estado{
	char nomeEstado[20];
	char unidadeFederativa[3];
	float quantPopulacional;
	Municipios mu[3]; // vetor de municipio
}Estado; // fim do registro Estado

Estado es[3];// vetor de estado

void cadastraEstado(); // declaracao da procedimento cadastra estado
void pesquisarEstado(); // declaracao do procedimento pesquisar estado
void pesquisarMunicipio(); // declaracao do procedimento pesquisar municipio
void menu(); // declaracao do procedimento menu

main (){
	menu();
	system("pause");
}//fim da main

void cadastraEstado(){
	int i;
	int j;
	for(i = 0; i < 3; i++){
		printf("Digite nome do estado %i: \n", i+1);
		fflush(stdin);
		gets(es[i].nomeEstado);
		printf("Digite a unidade federativa: \n");
		fflush(stdin);
		gets(es[i].unidadeFederativa);
			for (j = 0; j < 3; j++){
				printf("Digite o nome do municipio %d: \n", j +1);
				fflush(stdin);
				gets(es[i].mu[j].nomeMunicipio);
				printf("Digite a quantidade populacional: \n");
				fflush(stdin);
				scanf("%f", &es[i].mu[j].quantidadePop);
				es[i].quantPopulacional += es[i].mu[j].quantidadePop;
			}
		
	}//fim for 
}// fim do cadastro de estados

void pesquisarEstado(){
	char aux[20];
	int i, j, achei =0;
	printf("Digite o Estado ou Unidade Federativa de busca: \n");
	fflush(stdin);
	gets(aux);
	for(i = 0; i < 3; i++){
		if(strcmp(aux, es[i].unidadeFederativa)==0 || strcmp(aux, es[i].nomeEstado)==0){
			printf("Nome do estado: %s\n",es[i].nomeEstado);
			printf("Unidade federativa: %s\n",es[i].unidadeFederativa);
			printf("Municipio: \n");
				for(j = 0; j < 3; j++){
					printf(" %s\n",es[i].mu[j].nomeMunicipio);
				}
			printf("Quantidade populacional: %0.f\n\n", es[i].quantPopulacional);
			
			achei = 1;
			system("pause");
		}else{
			achei = 0;
		}
	}
	 if (!achei)
	 	printf("Nao encontrado \n");
	 	system("pause");
}// fim da pesquisar

void pesquisarMunicipio(){
	char aux[20];
	int i, j, achei  = 0;
	printf("Digite o municipio de busca: \n");
	fflush(stdin);
	gets(aux);
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
		if(strcmp(aux, es[i].mu[j].nomeMunicipio)==0 ){
			printf("Nome do estado: %s\n",es[i].nomeEstado);
			printf("Unidade federativa: %s\n",es[i].unidadeFederativa);
			printf("Municipio: %s \n",es[i].mu[j].nomeMunicipio);
		
			printf("Quantidade populacional: %0.f\n\n", es[i].mu[j].quantidadePop);
			
			achei = 1;
			system("pause");
		}else{
			achei = 0;
		}
	}
	}
	 if (!achei)
	 	printf("Nao encontrado \n");
	 	system("pause");	
}// fim da pesquisa municipios

void menu(){
	int op = 0;
	
	do {
	system("cls");
	printf("1 - Cadastra Estado \n");
	printf("2 - Pesquisar Estado \n");
	printf("3 - Pesquisar Municipio \n");
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
		case 3:
			pesquisarMunicipio();
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
