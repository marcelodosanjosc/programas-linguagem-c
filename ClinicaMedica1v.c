/*
Clinica medica
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define HORA 7  // incicio da contagem da horas 
#define TAM_HORA 8 // quantidade de horas disponifel no dia
// Registro 
typedef struct Especialidade{
	char nome[25];
	int codigo;
} Especialidade;

typedef struct Usuario{
	char login[20];
	char senha[20];
}Usuario;

typedef struct Medico{
	char crm[8];
	char nome[30];
	Especialidade especialidade;
	Usuario usuario;
}Medico;

typedef struct Funcionario{
	int matricula;
	char nome[30];
	Usuario usuario;
}Funcionario;

typedef struct Paciente{
	char cpf[15];
	char nome[30];
	char telefone[15];
	Usuario usuario;
}Paciente;

typedef struct Consulta{
	char profissional[25];
	int hora;
}Consulta;

typedef struct DataHora{
	int hora;
	char status[15];
}DataHora;

// cria os arquivo global 
FILE *Arquivo_Especialidade;
FILE *Arquivo_Usuario;
FILE *Arquivo_Medico;
FILE *Arquivo_Funcionario;
FILE *Arquivo_Paciente;
FILE *Arquivo_Consulta;
FILE *Arquivo_DataHora;

//Declarações 
void CriarAdmin(Usuario us);
Usuario LoginIn();
void LoginSistema();
void MenuAdm();
void MenuPaciente();
void MenuFuncionario();
void CadastraFuncionario();


int main (void){
	setlocale(LC_ALL, "portuguese");
	Usuario us;
	LoginSistema();
	
	return 0;
}// fim da main

void CriarArquivo(){
	
}// fim do cria arquivos

void CriarAdmin(Usuario us){
	Arquivo_Usuario = fopen("Usuario.txt", "ab+");
	strcpy(us.login, "admin");
	strcpy(us.senha, "admin");
	
	if(Arquivo_Usuario == NULL){
		printf("Arquivo não encontrado \n");
		system("pause");
		exit(0);
	}else{
		printf("Arquivo criado com sucesso \n");
		system("pause");
		system("cls"); 
	}
	fwrite(&us, sizeof(Usuario),1,Arquivo_Usuario);
	fclose(Arquivo_Usuario);
	
}// cria o usuario administrado
Usuario LoginIn(){// funçao para login 
	Usuario us;
	printf("Digite Login \n");
	fflush(stdin);
	gets(us.login);
	printf("Digite Senha \n");
	fflush(stdin);
	gets(us.senha);
	
	return us;
}//fim da função login entrar

void LoginSistema(){ // aqui entra no sistema com login 
	Usuario aux;
	Arquivo_Usuario = fopen("Usuario.txt", "rb");
	if(Arquivo_Usuario == NULL){
		printf("Arquivo não encontrado \n");
		system("pause");
		exit(0);
	}else{
		printf("Arquivo lindo com sucesso \n");
	}
	char login[20];
	char senha[20];
	//LoginIn();
	Usuario usu = LoginIn();
	int i, achei = 0;
	rewind(Arquivo_Usuario);
	while(!feof(Arquivo_Usuario)){
		fread(&aux,sizeof(Usuario),1,Arquivo_Usuario);

	if (strcmp(usu.login, aux.login)== 0 &&  strcmp(usu.senha, aux.senha)== 0 ){
		MenuAdm();
		achei = 1;
	}
	/*
	for (i = 0; i < tam;i++){
	if(strcmp(usu.login, fun[i].usuario.login)== 0 &&  strcmp(usu.senha, fun[i].usuario.senha)== 0 ){
			MenuFuncionario(fun, pac, espe, med,con, tam);
			achei = 1;
			}
		}
	for (i = 0; i < tam;i++){
	if(strcmp(usu.login, pac[i].usuario.login)== 0 &&  strcmp(usu.senha, pac[i].usuario.senha)== 0 ){
			MenuPaciente(fun, pac, espe, med,con, tam);
			achei = 1;
			}
		}
	for (i = 0; i < tam;i++){
	if(strcmp(usu.login, med[i].usuario.login)== 0 &&  strcmp(usu.senha, med[i].usuario.senha)== 0 ){
			printf("Quantidade de pacientes\n");
			LoginIn();
			achei = 1;
			}
		}	*/
	}
	if(!achei){
		printf("Login ou Senha invalidar ! \n");
	}

}// fim do login no sistema 

// menus 
void MenuAdm(){// menu do adminstrato do sistema
	int op;
	
	do {
		printf("1 - Cadastra Funcionario \n");
		printf("2 - Cadastra Paciente \n");
		printf("3 - Cadastra Especialidade \n");
		printf("4 - Cadastra Médico \n");
		printf("5 - Pesquisar \n");
		printf("6 - Alterar \n");
		printf("7 - Deletar \n");
		printf("8 - Voltar \n");
		printf("0 - Sair \n");
		printf("Escolhar: ");
		scanf("%i",&op);
		switch(op){
			case 1:
				CadastraFuncionario();
				break;
			case 2:
			
				break;
			case 3:
			
				break;
			case 4:
			
				break;
			case 5:
			
				break;
			case 6:
				
				break;
			case 7:
				
				break;
			case 8:
				LoginSistema();
				break;	
			case 0:
				exit(0);
				break;
			default:
				printf("Opção não existente \n");								
		}
		
	}while(op != 0);
}// fim do menu adminstrativo

void MenuFuncionario(){ // menu do funcionario
	int op;
	
	do {
	
		printf("1 - Cadastra Paciente \n");
		printf("2 - Voltar \n");	
		printf("0 - Sair \n");
		printf("Escolhar: ");
		scanf("%i",&op);
		switch(op){
			case 1:
			
				break;
			case 2:
				LoginSistema();
				break;
			case 0:
				exit(0);
				break;
			default:
				printf("Opção não existente \n");								
		}
		
	}while(op != 0);
}// fim do menu funcionario

void MenuPaciente(){
	int op;
	
	//DataHora dt[TAM_HORA]; // aqui chamado o registro e tanto o tamanho 
	//CadastraDataHora(dt); // aqui cadastrado os horarios 
	do {
	
		printf("1 - Agendar consulta \n");
		printf("2 - Voltar \n");	
		printf("0 - Sair \n");
		printf("Escolhar: ");
		scanf("%i",&op);
		switch(op){
			case 1:
				
				break;
			case 2:
				LoginSistema();
				break;
			case 0:
				exit(0);
				break;
			default:
				printf("Opção não existente \n");								
		}
		
	}while(op != 0);
}// fim do menu paciente

void CadastraFuncionario(){
		Funcionario funcionario;
		Arquivo_Funcionario = fopen("Funcionario.txt", "ab+");
		//verificação do arquivo
		if(Arquivo_Funcionario== NULL){
		printf("Arquivo não encontrado \n");
		system("pause");
		exit(0);
		}else{
		printf("Arquivo criado com sucesso \n");
		system("pause");
		system("cls"); 
		}
		// aqui começa atribui valores para funcionario
		printf("Digite a mátricula \n");
		fflush(stdin);
		scanf("%i",&funcionario.matricula);
		printf("Digite nome \n");
		fflush(stdin);
		gets(funcionario.nome);
		printf("Digite login \n");
		fflush(stdin);
		gets(funcionario.usuario.login);
		printf("Digite senha \n");
		fflush(stdin);
		gets(funcionario.usuario.senha);
		fwrite(&funcionario, sizeof(Funcionario),1,Arquivo_Funcionario);
		fclose(Arquivo_Funcionario);
		system("cls");
		printf("\n\tCadastro concluido com sucesso !\n");
		Sleep(2000); // biblioteca windows.h para oausa um tempo
	
}// fim do cadastra funcionario



