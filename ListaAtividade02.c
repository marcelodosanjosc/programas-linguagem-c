// maior 
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
// declaração 
void cadastra(int n1, int n2, int n3);
void maior(int n1, int n2, int n3);

main(){
	setlocale(LC_ALL, "Portuguese");
	int n1,n2,n3;
	cadastra(n1,n2,n3);
}// fim da main

void cadastra(int n1, int n2, int n3){
	printf("Digite 1° número \n");
	scanf("%i",&n1);
	printf("Digite 2° número \n");
	scanf("%i",&n2);
	printf("Digite 3° número \n");
	scanf("%i",&n3);
	
	maior(n1,n2,n3);
}// fim do cadastra número

void maior(int n1, int n2, int n3){
	if (n1 > n2 && n1 > n3){
		printf("%i é o número maior",n1);
	}else if(n2 > n1 && n2 > n3){
		printf("%i é o número maior", n2);
	}else{
		printf("%i é o número maior", n3);
	}
}// fim do maior
