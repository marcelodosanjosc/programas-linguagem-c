/*(1)Faça um programa que cadastre 2 números,
pesquise número se existir exiba,
senão exiba mensagem número não cadastrado */
// agora com ponteiros aqui o codigo fico facil com ponteiro 
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// declaracao
void cadastraNumero(int *px, int *py);
void pesquisaNumero(int n1, int n2);
void menu();

main(){
	setlocale(LC_ALL, "portuguese");
	menu();
	
}// fim do main

// procedimentos

void cadastraNumero(int *px, int *py){
	int x, y;
	printf("Digite um numero \n");
	scanf("%i",&x);
	printf("Digite um numero \n");
	scanf("%i",&y);
	*px = x;
	*py = y;
}// fim do cadastra

void pesquisaNumero( int n1, int n2){
	int n;
	printf("Digite um numero para pesquisa? \n");
	scanf("%i",&n);
	if (n == n1){
		printf("Existe %i\n",n1);
	} else if (n == n2){
		printf("Existe %i\n",n2);
	}else{
		printf("Nao existente!! \n");
	}
	
}// fim da pesquisa

void menu(){
	int op, n1,n2;
	do{
	
	printf("1 - Cadastrar \n");
	printf("2 - Pesquisar \n");
	printf("0 - Sair \n");
	printf("Escolhar: ");
	scanf("%i",&op);
	switch(op){
		case 1:
			cadastraNumero(&n1,&n2);
			break;
		case 2:
			pesquisaNumero(n1,n2);
			break;
		case 0:
			exit(0);
			break;
		default:
			printf("Opção não existente ! \n");			
	}
  }while(op != 0);
}// fim do menu 
