// cadastra pessoa
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

// registro
typedef struct Pessoa{
	char nome[25];
	char cpf[15];
	int ano_nascimento;
}Pessoa;

// declaração
void cadastraPessoa(Pessoa p[2]);
void pesquisaPessoa(Pessoa p[2]);
void calcularIdade(int ano);
void menuPrinciapal(Pessoa p[2]);


main(){
	setlocale(LC_ALL, "Portuguese");
	Pessoa p[2];
	menuPrinciapal(p);
	
}// fim da main

void cadastraPessoa(Pessoa p[2]){
	int i;
	for (i = 0; i < 2;i++){
	printf("____ Cadastra %i° Pessoa ____\n",i+1);	
	printf("Digite o nome \n");
	fflush(stdin);
	gets(p[i].nome);
	printf("Digite o CPF \n");
	fflush(stdin);
	gets(p[i].cpf);
	printf("Digite o ano de nascimento \n");
	scanf("%i",&p[i].ano_nascimento);
	printf("_____________________________________\n");
	}
	
}// fim do cadastra pessoa

void calcularIdade(int ano){
	int idade = 2020 - ano;
	printf("Idade: %i \n",idade);
}// fim do calcular idade



void pesquisaPessoa(Pessoa p[2]){
	int i = 0, achei = 0;
	char cpf[15];
	printf("Digite o CPF \n");
	fflush(stdin);
	gets(cpf);
		do{
		if(strcmp(cpf,p[i].cpf) == 0){
			
			printf(" ------------------------------------\n");
			printf("Nome: %s \n",p[i].nome);
			printf("CPF: %s \n",p[i].cpf);
			calcularIdade(p[i].ano_nascimento);
			printf("Ano de nascimento: %i\n",p[i].ano_nascimento);
			printf(" ---------------------------------------\n");
			achei = 1;
		}
		i++;
	}while(i < 2);
	 if(!achei){
	 	printf("CPF não cadastrado \n");
	 }
	
}// fim do pesquisa pessoa

void menuPrinciapal(Pessoa p[2]){
	int op;
	do {
	
	printf("1 - Cadastra pessoas \n");
	printf("2 - Pesquisa pessoa\n");
	printf("0 - Sair \n");
	printf("Escolha: ");
	scanf("%i",&op);
	switch (op){
		case 1:
			cadastraPessoa(p);
			break;
		case 2:
			pesquisaPessoa(p);
			break;
		case 0:
			exit(0);
			break;	
		default: 
			printf("Opção não existente \n");		
	}
	}while(op != 0);
}// fim do menu
