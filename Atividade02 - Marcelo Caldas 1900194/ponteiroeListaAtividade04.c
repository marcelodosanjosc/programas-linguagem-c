// cadastra pessoa com ponteiros foi usado ponteiro condigo fico facil de ler
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
void Exibir(Pessoa p);
void cadastraPessoa(Pessoa *pp1, Pessoa *pp2);
void pesquisaPessoa(Pessoa p1, Pessoa p2);
void calcularIdade(int ano);
void menuPrinciapal();


main(){
	setlocale(LC_ALL, "Portuguese");
	menuPrinciapal();
	
}// fim da main

void cadastraPessoa(Pessoa *pp1, Pessoa *pp2){
	Pessoa aux;
	int i;
	for (i = 0; i < 2;i++){
	printf("____ Cadastra %i° Pessoa ____\n",i+1);	
	printf("Digite o nome \n");
	fflush(stdin);
	gets(aux.nome);
	printf("Digite o CPF \n");
	fflush(stdin);
	gets(aux.cpf);
	printf("Digite o ano de nascimento \n");
	scanf("%i",&aux.ano_nascimento);
	printf("_____________________________________\n");
	if(i == 0){
		*pp1 = aux;
	}else if(i == 1){
		*pp2 = aux;
	}
	 printf("Cadastrado com sucesso !\n");
	}
	
}// fim do cadastra pessoa

void calcularIdade(int ano){
	int idade = 2020 - ano;
	printf("Idade: %i \n",idade);
}// fim do calcular idade

void Exibir(Pessoa p){
			printf(" ------------------------------------\n");
			printf("Nome: %s \n",p.nome);
			printf("CPF: %s \n",p.cpf);
			calcularIdade(p.ano_nascimento);
			printf("Ano de nascimento: %i\n",p.ano_nascimento);
			printf(" ---------------------------------------\n");
}// fim do exibir

void pesquisaPessoa(Pessoa p1, Pessoa p2){
	int i = 0, achei = 0;
	char cpf[15];
	printf("Digite o CPF \n");
	fflush(stdin);
	gets(cpf);
		do{
		if(strcmp(cpf,p1.cpf) == 0){
			Exibir(p1);
			achei = 1;
			break;
		} else if(strcmp(cpf,p2.cpf) == 0){
			Exibir(p2);
			achei = 1;
			break;
		}
		i++;
	}while(i < 2);
	 if(!achei){
	 	printf("CPF não cadastrado \n");
	 }
	
}// fim do pesquisa pessoa

void menuPrinciapal(){
	Pessoa p1,p2;
	int op;
	do {
	
	printf("1 - Cadastra pessoas \n");
	printf("2 - Pesquisa pessoa\n");
	printf("0 - Sair \n");
	printf("Escolha: ");
	scanf("%i",&op);
	switch (op){
		case 1:
			cadastraPessoa(&p1,&p2);
			break;
		case 2:
			pesquisaPessoa(p1,p2);
			break;
		case 0:
			exit(0);
			break;	
		default: 
			printf("Opção não existente \n");		
	}
	}while(op != 0);
}// fim do menu
