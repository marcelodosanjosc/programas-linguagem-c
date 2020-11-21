/*
	Sistema Cadastra Professor V2 com Arquivo
	Author: Marcelo Caldas - 1900194
	Sistema de Informação Matutino 
*/
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

// declaraçao do poteiro file
FILE *Professor_Arquivo;

//declaraçoes 
void MenuProfessor();
void MenuGerenciar();
void MenuPrinciapal();
void CadastraProfessor();
void ListaTodos();
void PesquisaProfessor();
void ListaUm(Professor prof);
void AtualizaProfessor();
Professor AlteraProfessor(Professor prof);
void DeletarProfessor();
int TamnhoParaVetor();


int main(void){
	setlocale(LC_ALL, "");
	Professor prof[TAM];
	int tam = TAM;
	MenuPrinciapal(prof,tam);
	return 0;
}



void MenuPrinciapal(){ // menu do funcionario
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
				MenuGerenciar();
				break;
			case 2:
				PesquisaProfessor();
				break;
			case 3:
				ListaTodos();
				break;	
			case 0:
				exit(0);
				break;
			default:
				printf("Opção não existente \n");								
		}
		
	}while(op != 0);
}// fim do menu funcionario

void MenuGerenciar(){ // menu do funcionario
	int op;
	
	do {
		system("cls");
		printf("1 - Professor \n");
		printf("0 - Voltar \n");
		printf("Escolhar: ");
		scanf("%i",&op);
		switch(op){
			case 1:
				MenuProfessor();
				break;
			case 0:
				MenuPrinciapal();
				break;
			default:
				printf("Opção não existente \n");								
		}
		
	}while(op != 2);
}// fim do menu funcionario

void MenuProfessor(){// menu do adminstrato do sistema
	int op;
	
	do {
		system("cls");
		printf("1 - Cadastra \n");
		printf("2 - Alterar \n");
		printf("3 - Deletar \n");
		printf("0 - Sair \n");
		printf("Escolhar: ");
		scanf("%i",&op);
		switch(op){
			case 1:
				CadastraProfessor();
				break;
			case 2:
				AtualizaProfessor();
				break;
			case 3:
				DeletarProfessor();
				break;
			case 0:
				MenuGerenciar();
				break;
			default:
				printf("Opção não existente \n");								
		}
		
	}while(op != 0);
}// fim do menu adminstrativo

void CadastraProfessor(){
		Professor professor;
		Professor_Arquivo = fopen("Professor.txt","ab+");
		if (Professor_Arquivo == NULL){
			printf("Arquivo não encontrado \n");
		system("pause");
		exit(0);
		}else{
			printf("Arquivo criado com sucesso \n");
			system("pause");
			system("cls"); 
		}
			printf("Digite a mátricula \n");
			fflush(stdin);
			scanf("%i",&professor.matricula);
			printf("Digite nome \n");
			fflush(stdin);
			gets(professor.nome);
			printf("Digite CPF \n");
			fflush(stdin);
			gets(professor.cpf);
			printf("Digite email \n");
			fflush(stdin);
			gets(professor.email);
			printf("Digite telefone \n");
			fflush(stdin);
			gets(professor.telefone);
			printf("Digite rua \n");
			fflush(stdin);
			gets(professor.endereco.rua);
			printf("Digite numero da casa \n");
			fflush(stdin);
			gets(professor.endereco.numero);
			printf("Digite bairro \n");
			fflush(stdin);
			gets(professor.endereco.bairro);	
			fwrite(&professor, sizeof(Professor),1,Professor_Arquivo);
			fclose(Professor_Arquivo);
			system("cls");
			printf("\n\tCadastro concluido com sucesso !\n");
		
			system("pause");
}// fim do cadastra 

int TamnhoParaVetor(){
	Professor prof;
	int tamanho =0;
		Professor_Arquivo = fopen("Professor.txt","rb");
		if (Professor_Arquivo == NULL){
			printf("Arquivo não encontrado \n");
		system("pause");
		exit(0);
		}else{
			printf("Arquivo lindo com sucesso \n");
			system("pause");
			system("cls"); 
		}
	while(!feof(Professor_Arquivo)){
	 fread(&prof, sizeof(Professor),1,Professor_Arquivo);
	tamanho++;	
	}
	return tamanho -1;
	fclose(Professor_Arquivo);
}// tamnha do arquivo para vetor

void ListaTodos(){
	
	Professor professor;
	int i, tamanho;
		Professor_Arquivo = fopen("Professor.txt","rb");
		if (Professor_Arquivo == NULL){
			printf("Arquivo não encontrado \n");
		system("pause");
		exit(0);
		}else{
			printf("Arquivo lindo com sucesso \n");
			system("pause");
			system("cls"); 
		}

//	tamanho = TamnhoParaVetor();
//	printf("[%i] \n",tamanho);
	while(!feof(Professor_Arquivo)){
		fread(&professor, sizeof(Professor),1,Professor_Arquivo);
		if(!feof(Professor_Arquivo)){
	
	printf("----------------------------\n");
	printf("Matricula: %i \n",professor.matricula);
	printf("Nome: %s \n",professor.nome);
	printf("CPF: %s \n",professor.cpf);
	printf("Email: %s \n",professor.email);
	printf("Telefone: %s \n",professor.telefone);
	printf("Endereço: ");
	printf("Rua: %s \n",professor.endereco.rua);
	printf("Numero: %s \n",professor.endereco.numero);
	printf("Rua: %s \n",professor.endereco.bairro);
	printf("----------------------------\n");
	
		}
	}
	

	fclose(Professor_Arquivo);
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

void PesquisaProfessor(){
	int i,op,achei = 1, matricula;
	Professor aux_prof;
	char  aux_cpf[15];
	
	Professor professor;
	int  tamanho;
		Professor_Arquivo = fopen("Professor.txt","rb");
		if (Professor_Arquivo == NULL){
			printf("Arquivo não encontrado \n");
		system("pause");
		exit(0);
		}else{
			printf("Arquivo lindo com sucesso \n");
			system("pause");
			system("cls"); 
		}
	
	printf("Pesquisar \n CPF(1) ou \n Matricula(2): ");
	scanf("%i",&op);
	switch (op){
		case 1:
			printf("\nDigite o CPF \n");
			fflush(stdin);
			gets(aux_cpf);
			while(!feof(Professor_Arquivo)){
				fread(&professor, sizeof(Professor),1,Professor_Arquivo);
				if(!feof(Professor_Arquivo)){
					if(strcmp(aux_cpf, professor.cpf)==0 ){
						aux_prof = professor;
						ListaUm(aux_prof);
						achei = 1;
						}
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
				while(!feof(Professor_Arquivo)){
				fread(&professor, sizeof(Professor),1,Professor_Arquivo);
				if(!feof(Professor_Arquivo)){
					if(matricula == professor.matricula ){
						aux_prof = professor;
						ListaUm(aux_prof);
						achei = 1;
						}
				}	
		}
				if(!achei){
						printf("Não cadastrado \n");
					}
			break;
		default:
			printf("Opção não existente \n");
					
		}
	fclose(Professor_Arquivo);
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

void AtualizaProfessor(){
	int i,op,achei = 1, matricula;
	Professor aux_prof;
	
	char  aux_cpf[15];
	
	Professor professor;
	int  tamanho = TamnhoParaVetor();
	Professor vetor_Prof[tamanho];
		Professor_Arquivo = fopen("Professor.txt","rb+");
	
		if (Professor_Arquivo == NULL){
			printf("Arquivo não encontrado \n");
		system("pause");
		exit(0);
		}else{
			printf("Arquivo lindo com sucesso \n");
			system("pause");
			system("cls"); 
		}
	
	
	printf("Pesquisar \n CPF(1) ou \n Matricula(2): ");
	scanf("%i",&op);
	switch (op){
		case 1:
			printf("\nDigite o CPF \n");
			fflush(stdin);
			gets(aux_cpf);
			rewind(Professor_Arquivo);
			i = 0;
			while(!feof(Professor_Arquivo)){
			fread(&professor, sizeof(Professor),1,Professor_Arquivo);
				if(!feof(Professor_Arquivo)){
					// aqui salva o que esta sendo lindo e salva nesse vetor
					vetor_Prof[i] = professor;
					
					if( strcmp(aux_cpf, vetor_Prof[i].cpf)==0 ){
						aux_prof = vetor_Prof[i];
						printf("\nNome:[%s] Será alterador \n",vetor_Prof[i].nome);
						vetor_Prof[i] = AlteraProfessor(aux_prof);
						printf("Nome:[%s] Foi alteraco com sucesso \n",vetor_Prof[i].nome);
						achei = 1;
						
							break; // sai do loop
						}
					
				}
				i++;
				
		}
				
						// fechamendo do arquivo
					fclose(Professor_Arquivo);
					//abri o arquivo para esvazia e escrever 
					Professor_Arquivo = fopen("Professor.txt","wb+");
					if (Professor_Arquivo == NULL){
					printf("Arquivo não encontrado \n");
					system("pause");
					exit(0);
					}
					// aqui reecrever noarquivo que esta vazio com tamanho do vetor 
				for(i = 0; i < tamanho; i++){
				fwrite(&vetor_Prof[i], sizeof(Professor), 1, Professor_Arquivo);
				}
				printf("Alteraçoes salvas com sucesso!\n");
				system("pause");
				if(!achei){
						printf("Não cadastrado \n");
					}
					
			break;
		case 2:
			printf("\nDigite a matricula \n");
			fflush(stdin);
			scanf("%i", &matricula);
		
			i = 0;
			while(!feof(Professor_Arquivo)){
			fread(&professor, sizeof(Professor),1,Professor_Arquivo);
				if(!feof(Professor_Arquivo)){
					// aqui salva o que esta sendo lindo e salva nesse vetor
					vetor_Prof[i] = professor;
					
					if( matricula == vetor_Prof[i].matricula ){
						aux_prof = vetor_Prof[i];
						printf("\nNome:[%s] Será alterador\n",vetor_Prof[i].nome);
						vetor_Prof[i] = AlteraProfessor(aux_prof);
						printf("Nome:[%s] Foi alteraco com sucesso \n",vetor_Prof[i].nome);
						achei = 1;
						
							break; // sai do loop
						}
					
				}
				i++;
				
		}
				
						// fechamendo do arquivo
					fclose(Professor_Arquivo);
					//abri o arquivo para esvazia e escrever 
					Professor_Arquivo = fopen("Professor.txt","wb+");
					if (Professor_Arquivo == NULL){
					printf("Arquivo não encontrado \n");
					system("pause");
					exit(0);
					}
					// aqui reecrever noarquivo que esta vazio com tamanho do vetor 
				for(i = 0; i < tamanho; i++){
				fwrite(&vetor_Prof[i], sizeof(Professor), 1, Professor_Arquivo);
				}
				printf("Alteraçoes salvas com sucesso!\n");
				system("pause");
				if(!achei){
						printf("Não cadastrado \n");
					}
			break;
		default:
			printf("Opção não existente \n");
					
	}
	
	fclose(Professor_Arquivo);
	system("pause");
}// fim do atualizar

void DeletarProfessor(){
	int i,op,achei = 1, matricula;
	Professor aux_prof = {"","", 0,"","","","",""};
	
	char  aux_cpf[15];
	
	Professor professor;
	int  tamanho = TamnhoParaVetor();
	Professor vetor_Prof[tamanho];
		Professor_Arquivo = fopen("Professor.txt","rb+");
	
		if (Professor_Arquivo == NULL){
			printf("Arquivo não encontrado \n");
		system("pause");
		exit(0);
		}else{
			printf("Arquivo lindo com sucesso \n");
			system("pause");
			system("cls"); 
		}
	
	
	printf("Pesquisar \n CPF(1) ou \n Matricula(2): ");
	scanf("%i",&op);
	switch (op){
		case 1:
			printf("\nDigite o CPF \n");
			fflush(stdin);
			gets(aux_cpf);
			rewind(Professor_Arquivo);
			i = 0;
			while(!feof(Professor_Arquivo)){
			fread(&professor, sizeof(Professor),1,Professor_Arquivo);
				if(!feof(Professor_Arquivo)){
					// aqui salva o que esta sendo lindo e salva nesse vetor
					vetor_Prof[i] = professor;
					
					if( strcmp(aux_cpf, vetor_Prof[i].cpf)==0 ){
						
						printf("\nNome:[%s] Será Deletado \n",vetor_Prof[i].nome);
						vetor_Prof[i] = aux_prof;
						
						achei = 1;
						
							break; // sai do loop
						}
					
				}
				i++;
				
		}
					
						// fechamendo do arquivo
					fclose(Professor_Arquivo);
					//abri o arquivo para esvazia e escrever 
					Professor_Arquivo = fopen("Professor.txt","wb+");
					if (Professor_Arquivo == NULL){
					printf("Arquivo não encontrado \n");
					system("pause");
					exit(0);
					}
					// aqui reecrever noarquivo que esta vazio com tamanho do vetor 
				for(i = 0; i < tamanho; i++){
					if( vetor_Prof[i].matricula != 0){
				fwrite(&vetor_Prof[i], sizeof(Professor), 1, Professor_Arquivo);
						}
				}
				printf("Deletado com sucesso !\n");
				system("pause");
				if(!achei){
						printf("Não cadastrado \n");
					}
					
			break;
		case 2:
			printf("\nDigite a matricula \n");
			fflush(stdin);
			scanf("%i", &matricula);
		
			i = 0;
			while(!feof(Professor_Arquivo)){
			fread(&professor, sizeof(Professor),1,Professor_Arquivo);
				if(!feof(Professor_Arquivo)){
					// aqui salva o que esta sendo lindo e salva nesse vetor
					vetor_Prof[i] = professor;
					
					if( matricula == vetor_Prof[i].matricula ){
						printf("\nNome:[%s] Será Deletado\n",vetor_Prof[i].nome);
						vetor_Prof[i] = aux_prof;
					
						achei = 1;
						
							break; // sai do loop
						}
					
				}
				i++;
				
		}
					
						// fechamendo do arquivo
					fclose(Professor_Arquivo);
					//abri o arquivo para esvazia e escrever 
					Professor_Arquivo = fopen("Professor.txt","wb+");
					if (Professor_Arquivo == NULL){
					printf("Arquivo não encontrado \n");
					system("pause");
					exit(0);
					}
					// aqui reecrever noarquivo que esta vazio com tamanho do vetor 
				for(i = 0; i < tamanho; i++){
						if( vetor_Prof[i].matricula != 0){
						fwrite(&vetor_Prof[i], sizeof(Professor), 1, Professor_Arquivo);
						}
				}
				printf("Deletado com sucesso !\n");
				system("pause");
				if(!achei){
						printf("Não cadastrado \n");
					}
			break;
		default:
			printf("Opção não existente \n");
					
	}
	fclose(Professor_Arquivo);
	system("pause");
}
