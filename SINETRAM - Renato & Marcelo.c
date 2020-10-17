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
	int posicao;
	int creditos;
	float saldo;
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
void CadastrarEstudante();
void ValidarCadastro();
void VendaPassagem();
void CadastrarFuncionario();
void MenuFunc();
void MenuEstudante();
void InicializadorCreditos();
int Login();

//DECLARAÇÃO DE PROTOTIPOS DE ERROS
void Error01();
void Error02();
void Error03();

//Dados ADM
tipoId ADM = {"admin", "admin"};

//Declaração de Variáveis Globais
int max = 5, Est;
int indiceI = 0, indiceC = 0, indiceE = 0, indiceMe = 0, indiceMf = 0, indiceF = 0;
tipoInstituicao Instituicao[5];
tipoEstudante Estudante[5];
tipoCurso Curso[5];
tipoFuncionario Funcionario[5];

//Função Principal
int main(){
	SistemaIntegrado();
}

//Procedimentos e Funções
void SistemaIntegrado(){
	ptBR();
	InicializadorCreditos();
	
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
						MenuFunc();
					break;
					
					case 4:
						MenuEstudante();
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
			Est = i;
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
				CadastrarEstudante();
			break;
			
			case 4:
				ValidarCadastro();
			break;
			
			case 5:
				VendaPassagem();
			break;
			
			case 6:
				CadastrarFuncionario();
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
	int i, e = 0, aux;
	
	if(indiceC<max){
		do{
			printf("Nome do curso: ");
			fflush(stdin);
			gets(Curso[indiceC].nome);
			
			puts("\nInstituição Assossiado:\n");
			for(i=0; i<5; i++){
				if(strcmp(Instituicao[i].nome, "NULL") == 1){
					printf("[%i] - %s\n", i+1, Instituicao[i].nome);
					e++;
				}
			}
			
			printf("\nEscolha: ");
			scanf("%i", & aux);
			
			system("cls");
			
			strcpy(Curso[indiceC].instituicao, (aux == 1) ? Instituicao[0].nome :
										 	   (aux == 2) ? Instituicao[1].nome :
										   	   (aux == 3) ? Instituicao[2].nome :
										 	   (aux == 4) ? Instituicao[3].nome :
										 	   (aux == 5) ? Instituicao[4].nome : "");
			
			if((strcmp(Curso[indiceC].instituicao, "") == 0) && (aux > e)){
				Error01();
			}
		}while((strcmp(Curso[indiceC].instituicao, "") == 0) && (aux > e));
		
		printf("Cadastrado com sucessso!\n");
		system("pause");
		system("cls");
	}
	
	indiceC++;
}

void CadastrarEstudante(){
	if(indiceE < max){
		printf("Nome do Estudante: ");
		fflush(stdin);
		gets(Estudante[indiceE].nome);
		
		printf("Instituição: ");
		fflush(stdin);
		gets(Estudante[indiceE].instituicao);
		
		printf("Curso: ");
		fflush(stdin);
		gets(Estudante[indiceE].curso);
		
		printf("Telefone para contato: ");
		fflush(stdin);
		gets(Estudante[indiceE].telefone);
		
		printf("Rua: ");
		fflush(stdin);
		gets(Estudante[indiceE].Endereco.rua);
		
		printf("Número: ");
		fflush(stdin);
		gets(Estudante[indiceE].Endereco.numeroCasa);
		
		printf("Bairro: ");
		fflush(stdin);
		gets(Estudante[indiceE].Endereco.bairro);
		
		indiceMe++;
		Estudante[indiceE].matricula = indiceMe;
		
		printf("Login: ");
		fflush(stdin);
		gets(Estudante[indiceE].Id.login);
		
		printf("Senha: ");
		fflush(stdin);
		gets(Estudante[indiceE].Id.senha);
		
		printf("\nCadastrado Com Sucessso!\n");
		system("pause");
		system("cls");
		
		strcpy(Estudante[indiceE].status, "Pendente");
	}
	
	indiceE++;
}

void ValidarCadastro(){
	int achei = 0, i, e, n = 0, aux, auxEscolha, auxPosicao;
	char auxValidacao[25];
	
	for(i=0;i<5;i++){
		if(strcmp(Estudante[i].status, "Pendente") == 0){
			achei = 1;
		}
	}
	
	if(!achei){
		Error03();
	}else{
		do{
			puts(":~:~:~:~:~|Validação de Cadastros|~:~:~:~:~:\n");
			
			for(i=0; i<5; i++){
				if(strcmp(Estudante[i].status, "Pendente") == 0){
					n++;
					printf("[%i] - \tNome: %s\n"
								  "\tInstituição: %s\n"
								  "\tCurso: %s\n"
								  "\tTelefone: %s\n"
								  "\tRua: %s\n"
								  "\tNº da Casa: %s\n"
								  "\tBairro: %s\n"
								  "\tMatricula: %i\n"
								  "\tLogin: %s\n"
								  "\tSenha: %s\n\n", n,
								   Estudante[i].nome,
								   Estudante[i].instituicao,
								   Estudante[i].curso,
								   Estudante[i].telefone,
								   Estudante[i].Endereco.rua,
								   Estudante[i].Endereco.numeroCasa,
								   Estudante[i].Endereco.bairro,
								   Estudante[i].matricula,
								   Estudante[i].Id.login,
								   Estudante[i].Id.senha);
					
					Estudante[i].posicao = n;
					auxPosicao = n;
				}
			}
	
			printf("[0] - Voltar\n\n"
				   "Escolha: ");
			scanf("%i", & aux);
			
			system("cls");
			
			n = 0;
			
			for(i=0;i<5;i++){
				e = ((aux == 1) && (Estudante[i].posicao == 1)) ? 1:
					((aux == 2) && (Estudante[i].posicao == 2)) ? 2:
					((aux == 3) && (Estudante[i].posicao == 3)) ? 3:
					((aux == 4) && (Estudante[i].posicao == 4)) ? 4:
					((aux == 5) && (Estudante[i].posicao == 5)) ? 5: 0;
				
				if(e > 0){
					auxEscolha = e;
				}
			}
			
			if(!aux){
			}else{
				if((auxEscolha >= 1) && (auxEscolha <= auxPosicao)){
					puts(":~:~:~:~:~|Validação de Cadastros|~:~:~:~:~:\n");
					
					for(i=0;i<5;i++){
						if(Estudante[i].posicao == auxEscolha){
							strcpy(auxValidacao, Estudante[i].nome);
							strcpy(Estudante[i].status, "Ativo");
						}
					}
					
					printf("Aluno: %s\n\n"
						   "Validado com sucesso!\n", auxValidacao);
					
					system("pause");
					system("cls");
				}else if((aux != 0) && !((aux > 0 ) && (aux < auxPosicao))){
					Error01();
				}
			}
			
			auxEscolha = 0;
			auxPosicao = 0;
		}while(aux != 0);
	}
}

void VendaPassagem(){
	int pesquisa, achei = 0, i, credito, auxSaldo1, auxSaldo2;
	float auxPgto, saldo;
	
	do{
		printf("Digite a matricula do aluno (ou 0 pra voltar): ");
		scanf("%i", & pesquisa);
		
		system("cls");
		
		for(i=0;i<5;i++){
			if((Estudante[i].matricula == pesquisa) && (strcmp(Estudante[i].status, "Ativo") == 0)){
				achei = 1;
				
				printf("Valor a pagar: R$");
				scanf("%f", & auxPgto);
				
				puts("\nContabilizado com sucesso!");
				system("pause");
				system("cls");
				
				credito = auxPgto / 1.5;
				
				auxSaldo1 = auxPgto/1;
				auxSaldo2 = (int)auxPgto;
				saldo = (auxSaldo1 - auxSaldo2) * 100;
				
				Estudante[i].creditos += credito;
				Estudante[i].saldo += saldo;
			}
		}
		
		if(!achei){
			Error01();
		}
		
	}while(pesquisa != 0);
}

void CadastrarFuncionario(){
	if(indiceF < max){
		printf("Nome do Funcionário: ");
		fflush(stdin);
		gets(Funcionario[indiceF].nome);
		
		indiceMf++;
		Funcionario[indiceF].marticula = indiceMf;
		
		printf("Login: ");
		fflush(stdin);
		gets(Funcionario[indiceF].Id.login);
		
		printf("Senha: ");
		fflush(stdin);
		gets(Funcionario[indiceF].Id.senha);
		
		printf("\nCadastrado Com Sucessso!\n");
		system("pause");
		system("cls");
	}
	
	indiceF++;
}

void MenuFunc(){
	int opcaoMenuFunc;
	
	do{
		printf(":~:~:~:~:~|Opções de Funcionário|~:~:~:~:~:\n\n"
			   "[1] - Cadastrar Aluno\n"
			   "[2] - Venda de Passagem\n"
			   "[0] - Voltar\n\n"
			   "Escolha: ");
		scanf("%i", & opcaoMenuFunc);
		
		system("cls");
		
		switch(opcaoMenuFunc){
			case 1:
				CadastrarEstudante();
			break;
			
			case 2:
				VendaPassagem();
			break;
			
			case 0:
			break;
			
			default:
				Error01();
		}
	}while(opcaoMenuFunc != 0);
}

void MenuEstudante(){
	int opcaoMenuEstudante;
	
	do{
		printf(":~:~:~:~:~|Opções de Estudante|~:~:~:~:~:\n\n"
			   "[1] - Ver dados\n"
			   "[0] - Voltar\n\n"
			   "Escolha: ");
		scanf("%i", & opcaoMenuEstudante);
		
		system("cls");
		
		switch(opcaoMenuEstudante){
			case 1:
				printf("Nome: %s\n"
					   "Instituição: %s\n"
					   "Curso: %s\n"
					   "Telefone: %s\n"
					   "Rua: %s\n"
					   "Nº casa: %s\n"
					   "Bairro: %s\n"
					   "Matricula: %i\n"
					   "Status: %s\n"
					   "Créditos: %i\n"
					   "Saldo: R$%i\n\n",
					   Estudante[Est].nome,
					   Estudante[Est].instituicao,
					   Estudante[Est].curso,
					   Estudante[Est].telefone,
					   Estudante[Est].Endereco.rua,
					   Estudante[Est].Endereco.numeroCasa,
					   Estudante[Est].Endereco.bairro,
					   Estudante[Est].matricula,
					   Estudante[Est].status,
					   Estudante[Est].creditos,
					   Estudante[Est].saldo);
					   
					   system("pause");
					   system("cls");
			break;
			
			case 0:
			break;
			
			default:
				Error01();
		}
	}while(opcaoMenuEstudante != 0);
}

void InicializadorCreditos(){
	int i;
	
	for(i=0;i<5;i++){
		Estudante[i].creditos = 0;
		Estudante[i].saldo = 0;
	}
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

void Error03(){
	printf(":~:~:~:~:~|Error encontrado|~:~:~:~:~:\n"
		   "ERROR 03: Não cadastros a serem validados.\n\n");
	
	system("pause");
	system("cls");
}

