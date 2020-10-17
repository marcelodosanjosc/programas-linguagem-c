// cadastra carro com ponteiros aqui foi usado ponteiro so no cadastra aonde 
// por que tem a facil para usar a variavel para tem autonomia do usuario escolher
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
void cadastraCarro(Carro *pc);
void calcularIpva(float valor);
void exibir(Carro c);
void pesquisarCarro(Carro c);
void menuCarro();

main(){
	setlocale(LC_ALL, "Portuguese");
	menuCarro();
}// fim da main

void cadastraCarro(Carro *pc){
	Carro c;
	
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
	*pc = c;
	printf("Cadastrado com sucessso ! \n");
	system("pause");
	
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
	system("pause");
}// fim do exibir

void menuCarro(){
	Carro c;
	int op;
	do{
		system("cls");
	printf(" ------- Menu ------- \n");
	printf("1 - Cadastra carro \n");
	printf("2 - Pesquisar  \n");
	printf("0 - Sair \n");
	printf("Escolha: ");
	scanf("%i",&op);
	switch (op){
		case 1:
			cadastraCarro(&c);
			break;
		case 2:
			pesquisarCarro(c);
			break;
		case 0:
			exit(0);
			break;
		default: 
			printf("Opção não existente \n");				
		}// fim do switch
	}while(op != 0);// fim do while
}// fim do menu carro
