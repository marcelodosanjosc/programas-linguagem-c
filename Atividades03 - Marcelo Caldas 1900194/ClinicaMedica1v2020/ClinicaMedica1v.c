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
void CadastraPaciente();
void CadastraEspecialidade();
void CadastraMedico();
void ListarMedico();


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
	Funcionario fun;
	Paciente pac;
	Medico med;
	Arquivo_Usuario = fopen("Usuario.txt", "rb");
	Arquivo_Funcionario = fopen("Funcionario.txt", "rb");
	Arquivo_Paciente = fopen("Paciente.txt", "rb");
	Arquivo_Medico = fopen("Medico.txt", "rb");

	
	if(Arquivo_Usuario == NULL && Arquivo_Funcionario == NULL && Arquivo_Paciente == NULL && Arquivo_Medico == NULL){
		printf("Arquivo não encontrado \n");
		system("pause");
		exit(0);
	}else{
		printf("Arquivo lindo com sucesso \n");
	}

	//LoginIn();
	Usuario usu = LoginIn();
	int i, achei = 0;
	rewind(Arquivo_Usuario);
	rewind(Arquivo_Funcionario);
	rewind(Arquivo_Paciente);
	rewind(Arquivo_Medico);
	while(!feof(Arquivo_Usuario) || !feof(Arquivo_Funcionario) || !feof(Arquivo_Paciente) || !feof(Arquivo_Medico) ){
		fread(&aux,sizeof(Usuario),1,Arquivo_Usuario);
		fread(&fun, sizeof(Funcionario),1,Arquivo_Funcionario);
		fread(&pac, sizeof(Paciente),1,Arquivo_Paciente);
		fread(&med, sizeof(Medico),1,Arquivo_Medico);

	if (strcmp(usu.login, aux.login)== 0 &&  strcmp(usu.senha, aux.senha)== 0 ){
		MenuAdm();
		achei = 1;
	}
	

	if(strcmp(usu.login, fun.usuario.login)== 0 &&  strcmp(usu.senha, fun.usuario.senha)== 0 ){
			MenuFuncionario();
			achei = 1;
			}
		
		
	
	if(strcmp(usu.login, pac.usuario.login)== 0 &&  strcmp(usu.senha, pac.usuario.senha)== 0 ){
			MenuPaciente();
			achei = 1;
			}
		
	
	if(strcmp(usu.login, med.usuario.login)== 0 &&  strcmp(usu.senha, med.usuario.senha)== 0 ){
			printf("Quantidade de pacientes\n");
			LoginIn();
			achei = 1;
			}
			
	}// fim do while
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
		printf("5 - Pesquisar (lista medico) \n");
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
				CadastraPaciente();
				break;
			case 3:
				CadastraEspecialidade();
				break;
			case 4:
				CadastraMedico();
				break;
			case 5:
				ListarMedico();
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
				CadastraPaciente();
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

void CadastraPaciente(){
		Paciente paciente;
		Arquivo_Paciente = fopen("Paciente.txt", "ab+");
		//verificação do arquivo
		if(Arquivo_Paciente== NULL){
		printf("Arquivo não encontrado \n");
		system("pause");
		exit(0);
		}else{
		printf("Arquivo criado com sucesso \n");
		system("pause");
		system("cls"); 
		}
		
		printf("Digite a nome \n");
		fflush(stdin);
		gets(paciente.nome);
		printf("Digite CPF \n");
		fflush(stdin);
		gets(paciente.cpf);
		printf("Digite telefone \n");
		fflush(stdin);
		gets(paciente.telefone);
		printf("Digite login \n");
		fflush(stdin);
		gets(paciente.usuario.login);
		printf("Digite senha \n");
		fflush(stdin);
		gets(paciente.usuario.senha);
		fwrite(&paciente, sizeof(Paciente),1,Arquivo_Paciente);
		fclose(Arquivo_Paciente);
		system("cls");
		printf("\n\tCadastro concluido com sucesso !\n");
		Sleep(2000); // biblioteca windows.h para oausa um tempo
	
}// fim do cadastra paciente

void CadastraEspecialidade(){
		Especialidade espe;
		Arquivo_Especialidade = fopen("Especialidade.txt", "ab+");
		//verificação do arquivo
		if(Arquivo_Especialidade== NULL){
		printf("Arquivo não encontrado \n");
		system("pause");
		exit(0);
		}else{
		printf("Arquivo criado com sucesso \n");
		system("pause");
		system("cls"); 
		}
	
		printf("Digite código \n");
		fflush(stdin);
		scanf("%i",&espe.codigo);
		printf("Digite o nome \n");
		fflush(stdin);
		gets(espe.nome);
		fwrite(&espe, sizeof(Especialidade),1,Arquivo_Especialidade);
		fclose(Arquivo_Especialidade);
		system("cls");
		printf("\n\tCadastro concluido com sucesso !\n");
		Sleep(2000); // biblioteca windows.h para oausa um tempo
	
}// fim do cadastra especialidade

void CadastraMedico(){
	Medico medico;
	Especialidade espe;
	int i, op,tamanho;
		Arquivo_Medico = fopen("Medico.txt", "ab+");
		Arquivo_Especialidade = fopen("Especialidade.txt", "rb");
		//verificação do arquivo
		if(Arquivo_Especialidade== NULL && Arquivo_Medico == NULL){
		printf("Arquivo não encontrado \n");
		system("pause");
		exit(0);
		}else{
		printf("Arquivo criado com sucesso \n");
		system("pause");
		system("cls"); 
		}
		
		printf("Digite nome \n");
		fflush(stdin);
		gets(medico.nome);
		printf("Selecione a especialidade: \n");
		i = 0;
		while(!feof(Arquivo_Especialidade)){
			fread(&espe,sizeof(Especialidade),1,Arquivo_Especialidade);//ler o arquivo
			if (!feof(Arquivo_Especialidade)){
			printf("[%i] - %s \n",i,espe.nome);
			i++;
			tamanho = i;
			}
		}
		printf("Digite a opção: ");
		fflush(stdin);
		scanf("%i",&op);
		i = 0;
		Especialidade es[tamanho];
		while(!feof(Arquivo_Especialidade)){
			fread(&espe,sizeof(Especialidade),1,Arquivo_Especialidade);//ler o arquivo
			if (!feof(Arquivo_Especialidade)){
			fscanf(Arquivo_Especialidade, "%s %i",&es[i].nome, &es[i].codigo);
			printf(" nome: %s - \n",es[i].nome);
			i++;
				}
			}
		for(i = 0; i < tamanho; i++){
			printf("Nome: %s \n", es[i].nome);
		}
			
		printf("Digite o CRM \n");
		fflush(stdin);
		gets(medico.crm);
		printf("Digite login \n");
		fflush(stdin);
		gets(medico.usuario.login);
		printf("Digite senha \n");
		fflush(stdin);
		gets(medico.usuario.senha);
		fwrite(&medico, sizeof(Medico),1,Arquivo_Medico);
		fclose(Arquivo_Especialidade);
		fclose(Arquivo_Medico);
		system("cls");
		printf("\n\tCadastro concluido com sucesso !\n");
		Sleep(2000); // biblioteca windows.h para oausa um tempo
}// fim do cadastra medico


void ListarMedico(){
	Medico med;
	Arquivo_Medico = fopen("Medico.txt", "rb");
	if(Arquivo_Medico == NULL){
		printf("Arquivo não encontrado \n");
		system("pause");
		exit(0);
		}else{
		printf("Arquivo lindo com sucesso \n");
		system("pause");
		system("cls"); 
		}
	while(!feof(Arquivo_Medico)){
	fread(&med,sizeof(Medico),1,Arquivo_Medico);//ler o arquivo
		if (!feof(Arquivo_Medico)){	
		printf("----------------------------\n");
		printf("Nome: %s \n",med.nome);
		printf("Especialidade: %s \n",med.especialidade.nome);
		printf("CRM: %s \n",med.crm);
		printf("Login: %s \n Senha: %s \n",med.usuario.login, med.usuario.senha);
		printf("----------------------------\n");
		system("pause");
		}
	}
		fclose(Arquivo_Medico);
		system("cls");
		Sleep(2000); // biblioteca windows.h para oausa um tempo
}// fim do exibir medico
