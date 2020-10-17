// ponteiro procedimento pro referencia
#include <stdio.h>
#include <stdlib.h>

// procedimento
void Exibir(int a, int b);
void Cadastra(int *p1, int *p2);
void menu ();

main(){
	menu();
}// fim da main

void menu (){
	int a, b, op; 
	do{
		system("title Ponteiro");
		system("color 17");
		system("cls");
		printf("1 - Cadastra \n");
		printf("2 - Exibir \n");
		printf("0 - Sair \n");
		printf("Escolhar: ");
		scanf("%i",&op);
		switch(op){
			case 1:
				Cadastra(&a,&b);
				break;
			case 2:
				Exibir(a,b);
				break;
			case 0:
				exit(0);
				break;
			default:
				printf("Opcao nao existente \n");			
		}
	}while(op != 0);
	
}// fim do menu

void Cadastra(int *p1, int *p2){
	int aux1, aux2;
	printf("Digite 1 numero \n");
	scanf("%i",&aux1);
	printf("Digite 2 numero \n");
	scanf("%i",&aux2);
	*p1 = aux1;
	*p2 = aux2;
	
}// fim do cadastra

void Exibir(int a, int b){
	printf("Numero 1: %i\n",a);
	printf("Numero 2: %i\n",b);
	system("pause");
}// fim do exibir
