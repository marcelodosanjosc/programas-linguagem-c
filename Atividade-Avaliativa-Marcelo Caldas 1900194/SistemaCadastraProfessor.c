#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define TAM 2

//registros
typedef struct Endereco{
	char rua[20];
	char numero[10];
	char bairro[25];
}Endereco;

typedef struct Professor{
	char nome[25];
	char cpf[15];
	int matricula;
	char email[35];
	char telefone[15];
	Endereco endereco;
}Professor;


//declaraçoes 
void MenuProfessor(Professor prof[], int tam);
void MenuGerenciar(Professor prof[], int tam);
void MenuPrinciapal(Professor prof[], int tam);
void CadastraProfessor(Professor prof[], int tam);
void ListaTodos(Professor prof[], int tam);
void PesquisaProfessor(Professor prof[], int tam);
void ListaUm(Professor prof);
void AtualizaProfessor(Professor prof[], int tam);
Professor AlteraProfessor(Professor prof);
void DeletarProfessor(Professor prof[], int tam);

int main(void){
	setlocale(LC_ALL, "");
	Professor prof[TAM];
	int tam = TAM;
	MenuPrinciapal(prof,tam);
	return 0;
}

void MenuPrinciapal(Professor prof[], int tam){ // menu do funcionario
	int op;
	
	do {
		system("cls");
		printf("1 - Gerenciar \n");
		printf("2 - Pesquisar \n");
		printf("3 - Listar (todos) \n");	
		printf("0 - Sair \n");
		printf("Escolhar: ");
		scanf("%i",&op);
		switch(op){
			case 1:
				MenuGerenciar(prof, tam);
				break;
			case 2:
				PesquisaProfessor(prof, tam);
				break;
			case 3:
				ListaTodos(prof, tam);
				break;	
			case 0:
				exit(0);
				break;
			default:
				printf("Opção não existente \n");								
		}
		
	}while(op != 0);
}// fim do menu funcionario

void MenuGerenciar(Professor prof[], int tam){ // menu do funcionario
	int op;
	
	do {
		system("cls");
		printf("1 - Professor \n");
		printf("2 - Voltar \n");
		printf("Escolhar: ");
		scanf("%i",&op);
		switch(op){
			case 1:
				MenuProfessor(prof, tam);
				break;
			case 2:
				MenuPrinciapal(prof, tam);
				break;
			default:
				printf("Opção não existente \n");								
		}
		
	}while(op != 2);
}// fim do menu funcionario

void MenuProfessor(Professor prof[], int tam){// menu do adminstrato do sistema
	int op;
	
	do {
		system("cls");
		printf("1 - Cadastra \n");
		printf("2 - Alterar \n");
		printf("3 - Deletar \n");
		printf("4 - Sair \n");
		printf("Escolhar: ");
		scanf("%i",&op);
		switch(op){
			case 1:
				CadastraProfessor(prof, tam);
				break;
			case 2:
				AtualizaProfessor(prof, tam);
				break;
			case 3:
				DeletarProfessor(prof, tam);
				break;
			case 4:
				MenuGerenciar(prof, tam);
				break;
			default:
				printf("Opção não existente \n");								
		}
		
	}while(op != 4);
}// fim do menu adminstrativo

void CadastraProfessor(Professor prof[], int tam){
	int i;
	for (i = 0; i < tam; i++){
		printf("Digite a mátricula \n");
		fflush(stdin);
		scanf("%i",&prof[i].matricula);
		printf("Digite nome \n");
		fflush(stdin);
		gets(prof[i].nome);
		printf("Digite CPF \n");
		fflush(stdin);
		gets(prof[i].cpf);
		printf("Digite email \n");
		fflush(stdin);
		gets(prof[i].email);
		printf("Digite telefone \n");
		fflush(stdin);
		gets(prof[i].telefone);
		printf("Digite rua \n");
		fflush(stdin);
		gets(prof[i].endereco.rua);
		printf("Digite numero da casa \n");
		fflush(stdin);
		gets(prof[i].endereco.numero);
		printf("Digite bairro \n");
		fflush(stdin);
		gets(prof[i].endereco.bairro);	
	}
		system("pause");
}// fim do cadastra 

void ListaTodos(Professor prof[], int tam){
	int i;
	for (i = 0; i < tam; i++){
	
	printf("----------------------------\n");
	printf("Matricula: %i \n",prof[i].matricula);
	printf("Nome: %s \n",prof[i].nome);
	printf("CPF: %s \n",prof[i].cpf);
	printf("Email: %s \n",prof[i].email);
	printf("Telefone: %s \n",prof[i].telefone);
	printf("Endereço: ");
	printf("Rua: %s \n",prof[i].endereco.rua);
	printf("Numero: %s \n",prof[i].endereco.numero);
	printf("Rua: %s \n",prof[i].endereco.bairro);
	printf("----------------------------\n");

	}
	system("pause");
}// fim do lista toods 

void ListaUm(Professor prof){
	
	printf("----------------------------\n");
	printf("Matricula: %i \n",prof.matricula);
	printf("Nome: %s \n",prof.nome);
	printf("CPF: %s \n",prof.cpf);
	printf("Email: %s \n",prof.email);
	printf("Telefone: %s \n",prof.telefone);
	printf("Endereço: ");
	printf("Rua: %s \n",prof.endereco.rua);
	printf("Numero: %s \n",prof.endereco.numero);
	printf("Rua: %s \n",prof.endereco.bairro);
	printf("----------------------------\n");

	system("pause");
}// fim do lista toods 

void PesquisaProfessor(Professor prof[], int tam){
	int i,op,achei = 1, matricula;
	Professor aux_prof;
	char  aux_cpf[15];
	printf("Pesquisar \n CPF(1) ou \n Matricula(2): ");
	scanf("%i",&op);
	switch (op){
		case 1:
			printf("\nDigite o CPF \n");
			fflush(stdin);
			gets(aux_cpf);
				for (i = 0; i < tam;i++){
					if(strcmp(aux_cpf, prof[i].cpf)==0 ){
						aux_prof = prof[i];
						ListaUm(aux_prof);
				 achei = 1;
					}
				}			
				if(!achei){
						printf("Não cadastrado \n");
					}
					
			break;
		case 2:
			printf("\nDigite a matricula \n");
			fflush(stdin);
			scanf("%i", &matricula);
				for (i = 0; i < tam;i++){
					if(matricula == prof[i].matricula){
						aux_prof = prof[i];
						ListaUm(aux_prof);
				 achei = 1;
					}
				}			
				if(!achei){
						printf("Não cadastrado \n");
					}
					
		
			break;
		default:
			printf("Opção não existente \n");
					
	}
	system("pause");
}// fim do pesquisar 

Professor AlteraProfessor(Professor prof){
	char aux[25];
	int op;
	printf("1 - Alterar nome \n");
	printf("2 - Alterar CPF \n");
	printf("3 - Alterar telefonne \n");
	printf("4 - Alterar email\n");
	printf("5 - Alterar Endereco rua\n");
	printf("6 - Alterar Endereco numero\n");
	printf("7 - Alterar Endereco bairro\n");
	printf("Escolhar: ");
	scanf("%i",&op);
	switch(op){
		case 1:
			printf("Digite nome: ");
			fflush(stdin);
			gets(aux);
			strcpy(prof.nome, aux);
			return prof;
			break;
		case 2:
			printf("Digite CPF: ");
			fflush(stdin);
			gets(aux);
			strcpy(prof.cpf, aux);
			return prof;
			break;
		case 3:
			printf("Digite telefone: ");
			fflush(stdin);
			gets(aux);
			strcpy(prof.telefone, aux);
			return prof;
			break;		
		case 4:
			printf("Digite email: ");
			fflush(stdin);
			gets(aux);
			strcpy(prof.email, aux);
			return prof;
			break;
		case 5:
			printf("Digite rua: ");
			fflush(stdin);
			gets(aux);
			strcpy(prof.endereco.rua, aux);
			return prof;
			break;
		case 6:
			printf("Digite numero: ");
			fflush(stdin);
			gets(aux);
			strcpy(prof.endereco.numero, aux);
			return prof;
			break;
		case 7:
			printf("Digite bairro: ");
			fflush(stdin);
			gets(aux);
			strcpy(prof.endereco.bairro, aux);
			return prof;
			break;		
		default:
			printf("Opção nã existente \n");			
	}
}// fim da funcao altera professor

void AtualizaProfessor(Professor prof[], int tam){
	int i,op,achei = 1, matricula;
	Professor aux_prof;
	char  aux_cpf[15];
	printf("Pesquisar \n CPF(1) ou \n Matricula(2): ");
	scanf("%i",&op);
	switch (op){
		case 1:
			printf("\nDigite o CPF \n");
			fflush(stdin);
			gets(aux_cpf);
				for (i = 0; i < tam;i++){
					if(strcmp(aux_cpf, prof[i].cpf)==0 ){
						aux_prof = prof[i];
						prof[i] = 	AlteraProfessor(aux_prof);
				 achei = 1;
					}
				}			
				if(!achei){
						printf("Não cadastrado \n");
					}
					
			break;
		case 2:
			printf("\nDigite a matricula \n");
			fflush(stdin);
			scanf("%i", &matricula);
				for (i = 0; i < tam;i++){
					if(matricula == prof[i].matricula){
						aux_prof = prof[i];
						prof[i]	= AlteraProfessor(aux_prof);
				 achei = 1;
					}
				}			
				if(!achei){
						printf("Não cadastrado \n");
					}
					
		
			break;
		default:
			printf("Opção não existente \n");
					
	}
	system("pause");
}// fim do atualizar

void DeletarProfessor(Professor prof[], int tam){
	int i,op,achei = 1, matricula;
	Professor aux_prof = {"","", 0,"","","","",""};
	char  aux_cpf[15];
	printf("Pesquisar \n CPF(1) ou \n Matricula(2): ");
	scanf("%i",&op);
	switch (op){
		case 1:
			printf("\nDigite o CPF \n");
			fflush(stdin);
			gets(aux_cpf);
				for (i = 0; i < tam;i++){
					if(strcmp(aux_cpf, prof[i].cpf)==0 ){
	
						prof[i] = aux_prof;
						printf("Deletado com sucesso \n");
				 achei = 1;
					}
				}			
				if(!achei){
						printf("Não cadastrado \n");
					}
					
			break;
		case 2:
			printf("\nDigite a matricula \n");
			fflush(stdin);
			scanf("%i", &matricula);
				for (i = 0; i < tam;i++){
					if(matricula == prof[i].matricula){
					
						prof[i]	= aux_prof;
						printf("Deletado com sucesso \n");
				 achei = 1;
					}
				}			
				if(!achei){
						printf("Não cadastrado \n");
					}
					
		
			break;
		default:
			printf("Opção não existente \n");
					
	}
	system("pause");
}// 
