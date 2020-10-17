/*(1)Faça um programa que cadastre 2 números,
pesquise número se existir exiba,
senão exiba mensagem número não cadastrado*/
#include <stdio.h>
#include <stdlib.h>

// declaracao
void cadastraNumero(int x, int y);
void pesquisaNumero(int n1, int n2);
void menu();

main(){
int n1,n2;
cadastraNumero(n1,n2);
	
}

// procedimentos

void cadastraNumero(int x, int y){
	printf("Digite um numero \n");
	scanf("%i",&x);
	printf("Digite um numero \n");
	scanf("%i",&y);
	pesquisaNumero(x,y);
}// fim do cadastra

void pesquisaNumero( int n1, int n2){
	int n;
	do{
	printf("Digite um numero para pesquisa? ou (0) para sair \n");
	scanf("%i",&n);
	if (n == n1){
		printf("Existe %i\n",n1);
	} else if (n == n2){
		printf("Existe %i\n",n2);
	}else{
		printf("Nao existente!! \n");
	}
	}while(n != 0);
	
}// fim da pesquisa

