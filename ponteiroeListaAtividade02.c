// maior com ponteiro aqui n�o nessecida de ponteiro pos so paramentro por valor resolveria
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
// declara��o 
void cadastra(int *pn1, int *pn2, int *pn3);
void maior(int n1, int n2, int n3);

main(){
	setlocale(LC_ALL, "Portuguese");
	int n1,n2,n3;
	cadastra(&n1,&n2,&n3);
}// fim da main

void cadastra(int *pn1, int *pn2, int *pn3){
	printf("Digite 1� n�mero \n");
	scanf("%i",&*pn1);
	printf("Digite 2� n�mero \n");
	scanf("%i",&*pn2);
	printf("Digite 3� n�mero \n");
	scanf("%i",&*pn3);
	
	maior(*pn1,*pn2,*pn3);
}// fim do cadastra n�mero

void maior(int n1, int n2, int n3){
	if (n1 > n2 && n1 > n3){
		printf("%i � o n�mero maior",n1);
	}else if(n2 > n1 && n2 > n3){
		printf("%i � o n�mero maior", n2);
	}else{
		printf("%i � o n�mero maior", n3);
	}
}// fim do maior
