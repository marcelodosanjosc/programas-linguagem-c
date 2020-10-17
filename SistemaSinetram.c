/* sistema SINETRAM
ATORES: MARCELO E RENATO
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// declaracao do registros
typedef struct Endereco{
	char rua[20];
	char numero[10];
	char bairro[25];
}Endereco;
typedef struct Instituicao{
	char nome[30];
	Endereco endereco;
	char telefone[15];
}Instituicao;
typedef struct Curso{
	char nome[25];
	char instituicao[30];
}Curso;
typedef struct Usuario{
	char login[20];
	char senha[20];
}Usuario;
typedef struct Estudante{
	char nome[20];
	int matricula;
	char instituicao[30];
	char curso[25];
	char telefone[15];
	float saldo;
	float quantidadeCredito;
	Endereco endereco;
	Usuario usuario;
	char status[10];
}Estudante;
typedef struct Funcionario{
	char nome[25];
	int matricula;
	Usuario usuario;
}Funcionario;
// variaves globas
Usuario admin = {"admin", "admin"};
int max = 5;
float valorPassagem = 1.50;
int indMatriculaEstudante = 1;
int indMatriculaFuncionario = 1;
int indFuncionario = 0;
int indEstudade = 0;
int indInstituicao = 0;
int indCurso = 0;
Instituicao instituicao[5];
Curso curso[5];
Estudante estudante[5];
Funcionario funcionario[5];


// declaracao dos prototipos
void fazerVenda();
void fazerValidacao();
void cadastraFuncionario();
void cadastraEstudante();
void cadastraInstituicao();
void cadastraCurso();
void fazerLogin();
void menuEstudante();
void menuFuncionario();
void MenuAdministrado();
int login();


main(){
	fazerLogin();
}// fim da main

// procedimentos e funçeos 
void fazerLogin(){
	int opcaoInicial, opcaoLogin;
	
	do{
		printf("|Menu Inicial|\n\n"
			   "[1] - Login\n"
			   "[0] - Sair\n\n"
			   "Escolha: ");
		scanf("%i", & opcaoInicial);
		
		system("cls");
		
		switch(opcaoInicial){
			case 1:
				opcaoLogin = login();
				
				switch(opcaoLogin){
					case 1:
					break;
					
					case 2:
						MenuAdministrado();
					break;
					case 3:
						menuFuncionario();
					break;
					
					case 4:
						menuEstudante();
					break;
					
					default:
					printf("Opcao nao existente \n");		
				}
			break;
			
			case 0:
				printf("|Sistema Encerrado|\n\n"
		   			   " Obrigado por utilizar nossos serviços!\n");
		   		
		   		exit(0);
		   	break;
		   	
		   	default:
		   	printf("Opcao nao existente \n");
		}
		
	}while(opcaoInicial != 0);
	
}// fim do procedimento fazer login

int login(){
		int opcao = 0, i;
	char auxLogin[25], auxSenha[20];
	
	printf("|Tela de Login\n"
		   "Digite 0 nos dois campos para sair\n\n");
	
	printf("Login: ");
	fflush(stdin);
	gets(auxLogin);
	
	printf("Senha: ");
	fflush(stdin);
	gets(auxSenha);
	
	system("cls");
	
	if((strcmp(auxLogin, "0") == 0) && (strcmp(auxSenha, "0") == 0)){
		opcao = 1;
	}
	
	if((strcmp(auxLogin, admin.login) == 0) && (strcmp(auxSenha, admin.senha) == 0)){
		opcao = 2;
	}
	
	for(i=0; i<max; i++){
		if((strcmp(auxLogin, funcionario[i].usuario.login) == 0) && (strcmp(auxSenha, funcionario[i].usuario.senha) == 0)){
			opcao = 3;
		}
	}
	
	for(i=0; i<max; i++){
		if((strcmp(auxLogin, estudante[i].usuario.login) == 0) && (strcmp(auxSenha, estudante[i].usuario.senha) == 0)){
			opcao = 4;
		}
	}
	
	return opcao;
}// fim do login

void MenuAdministrado(){
	int opcaoMenuADM;
	do{
		printf("|Opções de Administrador|\n\n"
			   "[1] - Cadastrar Instituição\n"
			   "[2] - Cadastrar Cursos\n"
			   "[3] - Cadastrar Estudantes\n"
			   "[4] - Validação de Estudantes\n"
			   "[5] - Venda de Passagem\n"
			   "[6] - Cadastrar Funcionário\n"
			   "[0] - Voltar\n\n"
			   "Escolha: ");
		scanf("%i", & opcaoMenuADM);
		
		system("cls");
		
		switch(opcaoMenuADM){
			case 1:
				cadastraInstituicao();
			break;
			
			case 2:
				cadastraCurso();
			break;
			
			case 3:
				cadastraEstudante();
			break;
			
			case 4:
				fazerValidacao();
			break;
			
			case 5:
				fazerVenda();
			break;
			
			case 6:
				cadastraFuncionario();
			break;
			
			case 0:
				fazerLogin();
			break;
			
			default:
				printf("Opcao nao existente \n");
		}
	}while(opcaoMenuADM != 0);
}// fim do menu administrado

void menuFuncionario(){
	int opcaoMenuFuncio;
	do{
		printf("|Opções de Funcionario|\n\n"
			   "[1] - Cadastra Estudantes\n"
			   "[2] - Venda de Passagem\n"
			   "[0] - Voltar\n\n"
			   "Escolha: ");
		scanf("%i", & opcaoMenuFuncio);
		
		system("cls");
		
		switch(opcaoMenuFuncio){
			case 1:
				cadastraEstudante();
			break;
			
			case 2:
				
			break;
			
			case 0:
				fazerLogin();
			break;
			
			default:
				printf("Opcao nao existente \n");
		}
	}while(opcaoMenuFuncio != 0);
}// fim do menu funcionario

void menuEstudante(){
	int opcaoMenuEstud;
	do{
		printf("|Opções de Funcionario|\n\n"
			   "[1] - Saldo e Creditos\n"
			   "[0] - Voltar\n\n"
			   "Escolha: ");
		scanf("%i", & opcaoMenuEstud);
		
		system("cls");
		
		switch(opcaoMenuEstud){
			case 1:
				
			break;
			
			case 0:
				fazerLogin();
			break;
			
			default:
				printf("Opcao nao existente \n");
		}
	}while(opcaoMenuEstud != 0);
}// fim do menu estudante

void cadastraInstituicao(){
	if (indInstituicao < max){
		printf("Nome da Institução: \n");
		fflush(stdin);
		gets(instituicao[indInstituicao].nome);
		
		printf("Rua: \n");
		fflush(stdin);
		gets(instituicao[indInstituicao].endereco.rua);
		
		printf("Número: \n");
		fflush(stdin);
		gets(instituicao[indInstituicao].endereco.numero);
		
		printf("Bairro: \n");
		fflush(stdin);
		gets(instituicao[indInstituicao].endereco.bairro);
		
		printf("Telefone para contato: \n");
		fflush(stdin);
		gets(instituicao[indInstituicao].telefone);
		
		printf("\nCadastrado Com Sucessso!\n");
	}
	indInstituicao++;
}// fim do cadastro de instituicao

void cadastraCurso(){
	int opcaoIntituicao, i;
	if (indCurso < max){
	
		printf("Nome do Curso: \n");
		fflush(stdin);
		gets(curso[indCurso].nome);
		
		
		printf("Instituicao: \n");
		fflush(stdin);
		for (i = 0;i < indInstituicao; i++){
			printf(" %i - %s \n", i, instituicao[i].nome);
		}
		scanf("%i",&opcaoIntituicao);
				for (i = 0; i < indInstituicao; i++){
				if (opcaoIntituicao == i ){
				strcpy(curso[indCurso].instituicao, instituicao[i].nome);
			}
		}
		printf("Curso: %s\n", curso[indCurso].nome);
		printf("Instituicao: %s\n", curso[indCurso].instituicao);
		printf("\nCadastrado Com Sucessso!\n");
 	}
 	indCurso++;
}// fim do cadastra curso

void cadastraEstudante(){
	int opcaoInstituicao, i;
	if (indEstudade < max){
		printf("Nome do Estudante: \n");
		fflush(stdin);
		gets(estudante[indEstudade].nome);
		
		estudante[indEstudade].matricula = indMatriculaEstudante;
		indMatriculaEstudante++;
		
		printf("Instituicao: \n");
		fflush(stdin);
		for (i = 0; i < indInstituicao; i++){
			printf(" %i - %s",i , instituicao[i].nome);
		}
		scanf("%i",&opcaoInstituicao);
			for(i = 0;i < indInstituicao; i++){
				if(opcaoInstituicao == i){
					strcpy(estudante[indEstudade].instituicao, instituicao[i].nome);
				}
			}
		printf("Curso: \n");
		fflush(stdin);
		gets(estudante[indEstudade].curso);
		printf("Telefone: \n");
		fflush(stdin);
		gets(estudante[indEstudade].telefone);
		printf("Endereco:\n");
		printf("Rua:");
		fflush(stdin);
		gets(estudante[indEstudade].endereco.rua);
		printf("Numero:");
		fflush(stdin);
		gets(estudante[indEstudade].endereco.numero);
		printf("Bairro:");
		fflush(stdin);
		gets(estudante[indEstudade].endereco.bairro);
		printf("Usuario: \n");
		printf("Login (e-mail):");
		fflush(stdin);
		gets(estudante[indEstudade].usuario.login);
		printf("Senha:");
		fflush(stdin);
		gets(estudante[indEstudade].usuario.senha);
		
		strcpy(estudante[indEstudade].status, "pendente");
		
		estudante[indEstudade].saldo = 0;
		printf(" ---------------------------------------------\n");
		printf("Nome: %s\n",estudante[indEstudade].nome);
		printf("Matricula: %i\n",estudante[indEstudade].matricula);
		printf("Instituicao: %s\n",estudante[indEstudade].instituicao);
		printf("Status: %s \n",estudante[indEstudade].status);
		printf("\nCadastrado Com Sucessso!\n");
		
	}
	indEstudade++;
}// fim do cadastra estudante

void cadastraFuncionario(){
	
	if (indFuncionario < max){
		printf("Nome do Funcionario: \n");
		fflush(stdin);
		gets(funcionario[indFuncionario].nome);
	
		funcionario[indFuncionario].matricula = indMatriculaFuncionario;
		indMatriculaFuncionario++;
		
		printf("Usuario: \n");
		printf("Login: ");
		fflush(stdin);
		gets(funcionario[indFuncionario].usuario.login);
		printf("Senha: ");
		fflush(stdin);
		gets(funcionario[indFuncionario].usuario.senha);
		
		printf("------------------------------------------\n");
		printf("Nome: %s \n",funcionario[indFuncionario].nome);
		printf("Matricula: %i \n", funcionario[indFuncionario].matricula);
		printf("\nCadastrado Com Sucessso!\n");
		
	}
	indFuncionario++;
}// fim do cadastro funcionario

void fazerValidacao(){
	int opcaoEstudante, i;
	printf("Estudantes: \n");
		fflush(stdin);
		for (i = 0; i < indEstudade; i++){
			printf(" %i - %s\n",i , estudante[i].nome);
			printf("Status: %s \n\n",estudante[i].status);
		}
		scanf("%i",&opcaoEstudante);
			for(i = 0;i < indEstudade; i++){
				if(opcaoEstudante == i){
					strcpy(estudante[i].status, "ativo");
				}
			}
		printf("Alterador com sucesso!\n");
			for (i = 0; i < indEstudade; i++){
			printf(" %i - %s\n",i , estudante[i].nome);
			printf("Status: %s \n\n",estudante[i].status);
		}
}// fim do validar estudante

void fazerVenda(){
	int pesquisarmatricula,i;
	float addSaldo, troco;
	printf("Pesquisar estudade pela matricula: \n");
	fflush(stdin);
	scanf("%i",&pesquisarmatricula);
		for (i = 0; i < indEstudade; i++){
			if (pesquisarmatricula == estudante[i].matricula){
				printf("Estudade: %s\n",estudante[i].nome);
				printf("Status: %s\n",estudante[i].status);
			}
		}
	printf("Venda de passagem:\n");	
	printf("Valor: ");
	fflush(stdin);
	scanf("%f",&addSaldo);
		for (i = 0; i < indEstudade; i++){
			if (pesquisarmatricula == estudante[i].matricula){
				estudante[i].saldo += addSaldo; 
				estudante[i].quantidadeCredito = estudante[i].saldo / valorPassagem;
				troco = fmod(estudante[i].saldo, valorPassagem);
				estudante[i].saldo = troco;
				printf("Saldo: %.2f \n",estudante[i].saldo);
				printf("Troco: %f \n",troco);
				
				printf("Quantidade de creditos: %.0f \n", estudante[i].quantidadeCredito);
				
			}
		}
	
		
	
}// fim do fazer venda


