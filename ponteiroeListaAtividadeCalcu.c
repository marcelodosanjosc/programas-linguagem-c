// calculadora com ponteiro 
// sem necessidade de usar parametros por referecia
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


// declaracao procecimentos
void menu();
void cadastraNumeros(float *px, float *py);
void messagem( float r);
void adicao(float n1, float n2);
void subtracao(float n1, float n2);
void multiplicacao(float n1, float n2);
void divisao(float n1, float n2);
void potencia(float n1, float n2);

main(){
	setlocale(LC_ALL, "Portuguese");
	menu();
}// fim da main

// procedimentos
void menu(){
	float n1,n2;
	int op;
	cadastraNumeros(&n1,&n2);
	do{
		
	printf("1 - Adi��o \n");
	printf("2 - Subtra��o\n");
	printf("3 - Multiplica��o\n");
	printf("4 - Divis�o\n");
	printf("5 - Pot�ncia\n");
	printf("0 - Sair \n");
	printf("Escolha: ");
	scanf("%i",&op);
	switch(op) {
		case 1:
			adicao(&n1,&n2);
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
		case 0:
			exit(0);
			break;	
		default:
			printf("Op��o n�o exitente\n");					
	}
	}while(op != 0);
		
}// fim do menu

void cadastraNumeros(float *px, float *py){
	float x, y;
	printf("Digite 1� n�mero\n");
	scanf("%f",&x);
	printf("Digite 2� n�mero\n");
	scanf("%f",&y);
	*px = x;
	*py = y;

}// fim do cadastra

void messagem(float r){
	printf("Resultado da opera��o �: %.2f \n",r);
}//fim da messagem

void adicao(float n1, float n2){
	float resul;
	resul = n1 + n2;
	messagem(resul);
}// fim da adi��o

void subtracao(float n1, float n2){
	float resul;
	resul = n1 - n2;
	messagem(resul);
}// fim da subtra��o

void multiplicacao(float n1, float n2){
	float resul;
	resul = n1 * n2;
	messagem(resul);
}// fim da multiplica��o

void divisao(float n1, float n2){
	float resul;
	resul = n1 / n2;
	messagem(resul);
}// fim da divis�o

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
}// fim da pot�ncia
