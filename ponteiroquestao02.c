// ponteiro questão 02
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// registro
typedef struct Pessoa{
	char nome[20];
	char cpf[15];
	int ano_nascimento;
}Pessoa;

//declarações
void ExcluirPessoa(Pessoa *pp1, Pessoa *pp2, Pessoa *pp3);
void AlterarPessoa(Pessoa *pp1, Pessoa *pp2, Pessoa *pp3);
void Menu();
void CadastraPessoa(Pessoa *pp1, Pessoa *pp2, Pessoa *pp3);
void CalcularIdadePessoa(int ano);
void ExibirPessoa(Pessoa p);
void PesquisarPessoa(Pessoa p1, Pessoa p2, Pessoa p3);


main(){
	setlocale(LC_ALL, "portuguese");
	Menu();
}// fim da main 

void CadastraPessoa(Pessoa *pp1, Pessoa *pp2, Pessoa *pp3){
	Pessoa paux;
	int i;
	for (i = 0; i < 3;i++){
		printf("Dados da pessoa %i \n",i + 1);
		printf("Digite o nome \n");
		fflush(stdin);
		gets(paux.nome);
		printf("Digite o CPF \n");
		fflush(stdin);
		gets(paux.cpf);
		printf("Digite o ano de nascimento \n");
		fflush(stdin);
		scanf("%i",&paux.ano_nascimento);
		if (i == 0){
			*pp1 = paux;
		}else if(i == 1){
			*pp2 = paux;
		}else if(i == 2){
			*pp3 = paux;
		}
		printf("Cadastrado com sucesso ! \n");
	}
	
}// fim do cadastra pessoa

void CalcularIdadePessoa(int ano){
	int idade = 2020 - ano;
	printf("Idade: %i \n",idade);
}// fim do calcular idade

void ExibirPessoa(Pessoa p){
	printf(" --------------------------- \n");
	printf("Nome: %s \n",p.nome);
	printf("CPF: %s \n",p.cpf);
	printf("Ano de nascimento: %i ",p.ano_nascimento);
	CalcularIdadePessoa(p.ano_nascimento);
	printf("------------------------------ \n");
	
}// fim do exibir pessoa

void PesquisarPessoa(Pessoa p1, Pessoa p2, Pessoa p3){
	Pessoa aux;
	char cpf[15];
	int i;
	printf("Digite o CPF para busca \n");
	fflush(stdin);
	gets(cpf);
	if(strcmp(cpf,p1.cpf)== 0 || strcmp(cpf,p2.cpf)== 0 || strcmp(cpf,p3.cpf)== 0 ){
	for (i = 0; i < 3;i++){
		if(i == 0 && strcmp(cpf, p1.cpf) == 0){
			ExibirPessoa(p1);
			break;
		}else if(i == 1 && strcmp(cpf, p2.cpf) == 0){
			ExibirPessoa(p2);
			break;
		}else if(i == 1 && strcmp(cpf, p3.cpf) == 0){
			ExibirPessoa(p3);
			break;
			}
		}
	}else{
		printf("CPF não cadastrado ! \n");
	}
}// fim do pesquisar pessoa


void AlterarPessoa(Pessoa *pp1, Pessoa *pp2, Pessoa *pp3){ // falta terminar 
	Pessoa aux, p1 = *pp1,p2 = *pp2,p3 = *pp3;
	char cpf[15];
	int i;
	printf("Digite o CPF para busca \n");
	fflush(stdin);
	gets(cpf);
	if(strcmp(cpf, p1.cpf)==0 || strcmp(cpf, p2.cpf)==0 || strcmp(cpf, p3.cpf)==0 ){
	for (i = 0; i < 3;i++){
		if(i == 0 && strcmp(cpf, p1.cpf) == 0){
			ExibirPessoa(p1);
			printf("Digite alteração do nome \n");
			fflush(stdin);
			gets(aux.nome);
			printf("Digite alteração do CPF \n");
			fflush(stdin);
			gets(aux.cpf);
			printf("Digite alteração do ano de nascimento \n");
			fflush(stdin);
			scanf("%i",&aux.ano_nascimento);
			*pp1 = aux;
			printf("Alterado com sucesso ! \n");
			break;
		}else if(i == 1 && strcmp(cpf, p2.cpf) == 0){
			ExibirPessoa(p2);
		printf("Digite alteração do nome \n");
			fflush(stdin);
			gets(aux.nome);
			printf("Digite alteração do CPF \n");
			fflush(stdin);
			gets(aux.cpf);
			printf("Digite alteração do ano de nascimento \n");
			fflush(stdin);
			scanf("%i",&aux.ano_nascimento);
			*pp2 = aux;
			printf("Alterado com sucesso ! \n");
			break;
		}else if(i == 1 && strcmp(cpf, p3.cpf) == 0){
			ExibirPessoa(p3);
			printf("Digite alteração do nome \n");
			fflush(stdin);
			gets(aux.nome);
			printf("Digite alteração do CPF \n");
			fflush(stdin);
			gets(aux.cpf);
			printf("Digite alteração do ano de nascimento \n");
			fflush(stdin);
			scanf("%i",&aux.ano_nascimento);
			*pp3 = aux;
			printf("Alterado com sucesso ! \n");
			break;
			}
		}
	}else{
		printf("CPF não cadastrado ! \n");
	}
}// fim do alterar pessoa

void ExcluirPessoa(Pessoa *pp1, Pessoa *pp2, Pessoa *pp3){ // falta terminar 
	Pessoa aux, p1 = *pp1,p2 = *pp2,p3 = *pp3;
	char cpf[15];
	int i, op;
	printf("Digite o CPF para busca \n");
	fflush(stdin);
	gets(cpf);
	if(strcmp(cpf, p1.cpf)==0 || strcmp(cpf, p2.cpf)==0 || strcmp(cpf, p3.cpf)==0 ){
	for (i = 0; i < 3;i++){
		if(i == 0 && strcmp(cpf, p1.cpf) == 0){
			ExibirPessoa(p1);
			printf("Deseja realmente excluir ? sim (1) e não (0) \n");
			fflush(stdin);
			scanf("%i",&op);
			if(op != 0 ){
			*pp1 = aux;
			printf("Excluido com sucesso ! \n");
			}
			break;
		}else if(i == 1 && strcmp(cpf, p2.cpf) == 0){
			ExibirPessoa(p2);
		printf("Deseja realmente excluir ? sim (1) e não (0) \n");
			fflush(stdin);
			scanf("%i",&op);
			if(op != 0 ){
			*pp2 = aux;
			printf("Excluido com sucesso ! \n");
			}
			break;
		}else if(i == 1 && strcmp(cpf, p3.cpf) == 0){
			ExibirPessoa(p3);
			printf("Deseja realmente excluir ? sim (1) e não (0) \n");
			fflush(stdin);
			scanf("%i",&op);
			if(op != 0 ){
			*pp3 = aux;
			printf("Excluido com sucesso ! \n");
			}
			break;
			}
		}
	}else{
		printf("CPF não cadastrado ! \n");
	}
}// fim do excluir pessoa

void Menu(){
	Pessoa p1,p2,p3;
	int op;
	do{
		printf("----- Menu ------\n");
		printf("1 - Cadastrar \n");
		printf("2 - Pesquisar \n");
		printf("3 - Alterar \n");
		printf("4 - Excluir \n");
		printf("0 - Sair \n");
		printf("Escolhar: ");
		scanf("%i",&op);
		switch(op){
			case 1:
				CadastraPessoa(&p1,&p2,&p3);
				break;
			case 2:
				PesquisarPessoa(p1,p2,p3);
				break;
			case 3:
				AlterarPessoa(&p1,&p2,&p3);
				break;
			case 4:
				ExcluirPessoa(&p1,&p2,&p3);
				break;
			case 0:
				exit(0);
				break;
			default:
				printf("Opção não existente");					
		}
	}while(op != 0);
}// fim do menu 
