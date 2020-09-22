#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

//Declaração de Registros
typedef struct tipoEndereco{
	char rua[30];
	char numeroCasa[10];
	char bairro[25];
}tipoEndereco;

typedef struct tipoInstituicao{
	char nome[30];
	tipoEndereco Endereco;
	char telefone[25];
}tipoInstituicao;

typedef struct tipoCurso{
	char nome[30];
	char instituicao[30];
}tipoCurso;

typedef struct tipoId{
	char login[25];
	char senha[20];
}tipoId;

typedef struct tipoEstudante{
	char nome[30];
	char instituicao[30];
	char curso[30];
	char telefone[25];
	tipoEndereco Endereco;
	int matricula;
	tipoId Id;
	char status[8];
}tipoEstudante;

typedef struct tipoFuncionario{
	char nome[30];
	int marticula;
	tipoId Id;
}tipoFuncionario;

//Declaração dos Prototipos
void SistemaIntegrado();
void ptBR();
void MenuADM();
void CadastrarInstituicao();
void CadastrarCurso();
int Login();

//DECLARAÇÃO DE PROTOTIPOS DE ERROS
void Error01();
void Error02();

//Dados ADM
tipoId ADM = {"admin", "admin"};

//Declaração de Variáveis Globais
int max = 5;
int indiceI = 0, indiceC = 0;
tipoInstituicao Instituicao[5];
tipoEstudante Estudante[5];
tipoCurso Curso[5];
tipoFuncionario Funcionario[5];

int main(){
	SistemaIntegrado();
}

//Procedimentos e Funções
void SistemaIntegrado(){
	ptBR();
	
	int opcaoInicial, opcaoLogin;
	
	do{
		printf(":~:~:~:~:~|Menu Inicial|~:~:~:~:~:\n\n"
			   "[1] - Login\n"
			   "[0] - Sair\n\n"
			   "Escolha: ");
		scanf("%i", & opcaoInicial);
		
		system("cls");
		
		switch(opcaoInicial){
			case 1:
				opcaoLogin = Login();
				
				switch(opcaoLogin){
					case 1:
					break;
					
					case 2:
						MenuADM();
					break;
					
					case 3:
					break;
					
					case 4:
					break;
					
					default:
						Error02();
				}
			break;
			
			case 0:
				printf(":~:~:~:~:~|Sistema Encerrado|~:~:~:~:~:\n\n"
		   			   "  ~~~> Obrigado por utilizar nossos serviços!\n");
		   		
		   		exit(0);
		   	break;
		   	
		   	default:
		   		Error01();
		}
		
	}while(opcaoInicial != 0);
}

void ptBR(){
	setlocale(LC_ALL, "Portuguese_Brazil");
}

int Login(){
	int opcao = 0, i;
	char auxLogin[25], auxSenha[20];
	
	printf(":~:~:~:~:~|Tela de Login|~:~:~:~:~:\n"
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
	
	if((strcmp(auxLogin, ADM.login) == 0) && (strcmp(auxSenha, ADM.senha) == 0)){
		opcao = 2;
	}
	
	for(i=0; i<max; i++){
		if((strcmp(auxLogin, Funcionario[i].Id.login) == 0) && (strcmp(auxSenha, Funcionario[i].Id.senha) == 0)){
			opcao = 3;
		}
	}
	
	for(i=0; i<max; i++){
		if((strcmp(auxLogin, Estudante[i].Id.login) == 0) && (strcmp(auxSenha, Estudante[i].Id.senha) == 0)){
			opcao = 4;
		}
	}
	
	return opcao;
}

void MenuADM(){
	int opcaoMenuADM;
	
	do{
		printf(":~:~:~:~:~|Opções de Administrador|~:~:~:~:~:\n\n"
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
				CadastrarInstituicao();
			break;
			
			case 2:
				CadastrarCurso();
			break;
			
			case 3:
				
			break;
			
			case 4:
				
			break;
			
			case 5:
				
			break;
			
			case 6:
				
			break;
			
			case 0:
			break;
			
			default:
				Error01();
		}
	}while(opcaoMenuADM != 0);
}

void CadastrarInstituicao(){
	if(indiceI < max){
		printf("Nome da Institução: ");
		fflush(stdin);
		gets(Instituicao[indiceI].nome);
		
		printf("Rua: ");
		fflush(stdin);
		gets(Instituicao[indiceI].Endereco.rua);
		
		printf("Número: ");
		fflush(stdin);
		gets(Instituicao[indiceI].Endereco.numeroCasa);
		
		printf("Bairro: ");
		fflush(stdin);
		gets(Instituicao[indiceI].Endereco.bairro);
		
		printf("Telefone para contato: ");
		fflush(stdin);
		gets(Instituicao[indiceI].telefone);
		
		printf("\nCadastrado Com Sucessso!\n");
		system("pause");
		system("cls");
	}
	
	indiceI++;
}

void CadastrarCurso(){
	int i, aux;
	
	if(indiceC<max){
		do{
			printf("Nome do curso: ");
			fflush(stdin);
			gets(Curso[indiceC].nome);
			
			puts("\nInstituição Assossiado:\n");
			for(i=0; i<5; i++){
				if(strcmp(Instituicao[i].nome, "NULL") == 1){
					printf("[%i] - %s\n", i+1, Instituicao[i].nome);
				}
			}
			
			printf("\nEscolha: ");
			scanf("%i", & aux);
			
			strcpy(Curso[indiceC].instituicao, (aux == 1) ? Instituicao[0].nome :
										 	   (aux == 2) ? Instituicao[1].nome :
										   	   (aux == 3) ? Instituicao[2].nome :
										 	   (aux == 4) ? Instituicao[3].nome :
										 	   (aux == 5) ? Instituicao[4].nome : "");
			
			printf("\n");
			if(strcmp(Curso[indiceC].instituicao, "") == 0){
				Error01();
			}
			
			system("cls");
		}while(strcmp(Curso[indiceC].instituicao, "") == 0);
	}
	
	indiceC++;
}

//TRATAMENTO DE ERROS
void Error01(){
	printf(":~:~:~:~:~|Error encontrado|~:~:~:~:~:\n"
		   "ERROR 01: Opção inválida.\n\n");
	
	fflush(stdin);
	system("pause");
	system("cls");
}

void Error02(){
	printf(":~:~:~:~:~|Error encontrado|~:~:~:~:~:\n"
		   "ERROR 02: Login ou senha estão incorretos.\n\n");
	
	system("pause");
	system("cls");
}
