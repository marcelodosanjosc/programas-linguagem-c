// imc com ponteiros aqui o ponteiro não é necessario pos so o parametro por valor resolver 
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// registro
typedef struct Pessoa{
	char nome[20];
	float peso;
	float altura;
}Pessoa;
// declaração
void cadastra(Pessoa p1);
void imc(float p, float a);
void classificacao(float r);

main(){
	setlocale(LC_ALL, "Portuguese");
	Pessoa p;
	cadastra(p);
}// fim da main

void cadastra(Pessoa p1){
	printf("Digite o nome \n");
	fflush(stdin);
	gets(p1.nome);
	printf("Digite o peso: ");
	scanf("%f",&p1.peso);
	printf("Digite a altura: ");
	scanf("%f",&p1.altura);
	printf("\n");
	imc(p1.peso,p1.altura);
}// fim do cadastro

void imc(float p, float a){
	float imc;
	imc = p / (a * a);
	
	classificacao(imc);
}// fim do imc

void classificacao(float r){
	printf("Resultado: \n");
	printf("O seu Indice de Massa Corporal é:  %.2f \n",r);
	printf("Você está com: ");
	if (r < 18.5){
		printf("Abaixo do normal \n");
	}else if(r > 18.5 && r < 25.0){
		printf("Normal \n");
	}else if(r > 25.0 && r < 30.0){
		printf("Acima do peso \n");
	}else if(r > 30.0 && r < 35.0){
		printf("Obesidade de 1° grau \n");
	}else if(r > 35.0 && r < 40.0){
		printf("Obesidade de 2° grau \n");
	}else{
		printf("Obesidade de 3° grau ou mórbida");
	}
}// fim da classificação
