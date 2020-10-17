// cadastra carro
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//registro
typedef struct Carro{
	char marca[15];
	char modelo[20];
	char cor[20];
	char placa[10];
	float valor;
}Carro;
//declarações
void cadastraCarro(Carro c);
void calcularIpva(float valor);
void exibir(Carro c);
void pesquisarCarro(Carro c);


main(){
	setlocale(LC_ALL, "Portuguese");
	Carro ca;
	cadastraCarro(ca);
}// fim da main

void cadastraCarro(Carro c){	
	printf("---- Dados do Carro --------\n");
	printf("Digite a marca \n");
	fflush(stdin);
	gets(c.marca);
	printf("Digite o modelo \n");
	fflush(stdin);
	gets(c.modelo);
	printf("Digite a cor \n");
	fflush(stdin);
	gets(c.cor);
	printf("Digite a placa \n");
	fflush(stdin);
	gets(c.placa);
	printf("Digite o valor \n");
	fflush(stdin);
	scanf("%f",&c.valor);
	printf("-----------------------------\n");
	
	pesquisarCarro(c);
}// fim do cadastra carro



void pesquisarCarro(Carro c){
	char pl[10];
	printf("Digite a placa para pesquisar \n");
	fflush(stdin);
	gets(pl);
	if(strcmp(pl, c.placa) == 0){
		printf("Aqui\n");
		exibir(c);
	}else{
		printf("Placa não cadastrada \n");
	}
}// fim do pesquisar carro

void calcularIpva(float valor){
	float ipva;
	ipva = valor * 3/100;
	printf("Valor IPVA: %.2f \n",ipva); 
}// fim do calcular ipva

void exibir(Carro c){
	printf(" --------------------------------\n");
	printf("Marca: %s\n",c.marca);
	printf("Modelo: %s \n",c.modelo);
	printf("Cor: %s \n",c.cor);
	printf("Placa: %s \n",c.placa);
	calcularIpva(c.valor);
	printf(" -------------------------------\n");
}// fim do exibir


