#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define TAM 2

// registro
typedef struct Carro{
	char placa[8];
	char cor[20];
	char modelo[20];
}Carro;

// declarações
void CadastraCarro(Carro c[] );
void ImprimirC(Carro c);
int PesquisarCarro(Carro c[]);


int main (void){
	setlocale(LC_ALL, "portuguese");
	int op;
	Carro c[TAM], ca;
	do{
		printf("1 - Cadastrar \n");
		printf("2 -  Pesquisar \n");
		printf("0 -  Sair \n");
		printf("Escolhar: ");
		scanf("%i",&op);
		switch(op){
			case 1:
				CadastraCarro(c);
				break;
			case 2:
				ca = PesquisarCarro(c);
				ImprimirC(ca);
				break;
			case 0:
				exit(0);
				break;
			default:
				printf("OPÇÃO INVALIDAR \n\a");			
		}
		
	}while(op != 0);

	return 0;
}// fim da main

void CadastraCarro(Carro c[] ){
	int i;
	for (i = 0; i < TAM; i++){
		printf("Digite a placa \n");
		fflush(stdin);
		gets(c[i].placa);
		printf("Digite a cor \n");
		fflush(stdin);
		gets(c[i].cor);
		printf("Digite o modelo \n");
		fflush(stdin);
		gets(c[i].modelo);
	}
	
}// fim do proedimento

void ImprimirC( Carro c){
	printf("Placa: %s \n",c.placa);
	printf("Cor: %s \n", c.cor);
	printf("Modelo: %s \n", c.modelo);
}// fim do imprimir

Carro PesquisarCarro(Carro c[]){
	int i;
	char aux[8];
	printf("Digite a placa \n");
	fflush(stdin);
	gets(aux);
	
	for (i = 0; i < TAM; i++){
		if(strcmp(aux, c[i].placa)==0){
			return c[i];	
		}	
	}
}// fim do pesquisar 
