// calculadora 
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


// declaracao procecimentos
void menu(float n1, float n2);
void cadastraNumeros(float x, float y);
void messagem( float r);
void adicao(float n1, float n2);
void subtracao(float n1, float n2);
void multiplicacao(float n1, float n2);
void divisao(float n1, float n2);
void potencia(float n1, float n2);

main(){
	setlocale(LC_ALL, "Portuguese");
	float x, y;
	cadastraNumeros(x,y);
}// fim da main

// procedimentos
void menu(float n1, float n2){
	int op;
	printf("1 - Adição \n");
	printf("2 - Subtração\n");
	printf("3 - Multiplicação\n");
	printf("4 - Divisão\n");
	printf("5 - Potência\n");
	printf("Escolha: ");
	scanf("%i",&op);
	switch(op) {
		case 1:
			adicao(n1,n2);
			break;
		case 2:
			subtracao(n1,n2);
			break;
		case 3:
			multiplicacao(n1,n2);
			break;
		case 4:
			divisao(n1,n2);
			break;
		case 5:
			potencia(n1,n2);
			break;
		default:
			printf("Opção não exitente");					
	}
	
		
}// fim do menu

void cadastraNumeros(float x, float y){
	printf("Digite 1° número\n");
	scanf("%f",&x);
	printf("Digite 2° número\n");
	scanf("%f",&y);
	
	menu(x,y);
}// fim do cadastra

void messagem(float r){
	printf("Resultado da operação é: %.2f",r);
}//fim da messagem

void adicao(float n1, float n2){
	float resul;
	resul = n1 + n2;
	messagem(resul);
}// fim da adição

void subtracao(float n1, float n2){
	float resul;
	resul = n1 - n2;
	messagem(resul);
}// fim da subtração

void multiplicacao(float n1, float n2){
	float resul;
	resul = n1 * n2;
	messagem(resul);
}// fim da multiplicação

void divisao(float n1, float n2){
	float resul;
	resul = n1 / n2;
	messagem(resul);
}// fim da divisão

void potencia(float n1, float n2){
	float resul = 0.0;
	int i;
	printf("Digite a base \n");
	scanf("%f",&n1);
	printf("Digite o exponte\n");
	scanf("%f",&n2);
	for (i = 0; i < n2; i++){
		resul = n1* (n1 * i); 
	}
		if(n2 == 0){
			resul = 1.0; 
		}
	messagem(resul);
}// fim da potência
