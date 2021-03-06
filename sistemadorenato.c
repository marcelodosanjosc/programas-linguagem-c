#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//REGISTROS
typedef struct{
	char login[25];
	char senha[25];
}tLogin;

typedef struct{
	char nome[25];
	char matricula[25];
	tLogin Id;
}tFuncionario;

typedef struct{
	char nome[25];
	int qtd;
	float valor;
}tProduto;

//VARI�VEIS GLOBAIS DO SISTEMA
int max = 5;
int opInicial;
int opLogin;
int opMenuADM;
int opMenuFunc;

int indFuncionario;
int IndProduto;

//DADOS DO ADIMINISTRADOR
char loginADMIN[25] = "admin";
char senhaADMIN[25] = "123";

tFuncionario funcionario[5];
tProduto produto[5];

//PROT�TIPOS DE FUN��ES
int menuInicial();
int fLogin();
int telaADMIN();
int telaFunc();
void msgFinal();
void cadastrarProduto();
void cadastrarFuncionario();
void fVenda();

//PROT�TIPOS DE TRATAMENTO DE ERROS
void Error01();
void Error02();
void Error03();

//FUN��O PRINCIPAL
int main(void){
	setlocale(LC_ALL, "Portuguese_Brazil");//Defini��o do idioma do programa em pt-br
	
	do{
		opInicial = menuInicial();
		
		if(opInicial == 1){
			opLogin = fLogin();
			
			switch(opLogin){
				case 1:
					do{
						opMenuADM = telaADMIN();
						
						switch(opMenuADM){
							case 1:
								cadastrarProduto();
							break;
							
							case 2:
								cadastrarFuncionario();
							break;
							
							case 3:
								fVenda();
							break;
						}
					}while(opMenuADM != 0);
				break;
				
				case 2:
					do{
						opMenuFunc = telaFunc();
						
						if(opMenuFunc == 1){
							fVenda();
						}
					}while(opMenuFunc != 0);
				break;
			}
		}				
	}while(opInicial != 0);
	
	msgFinal();
}

//FUN��O DE TELA DE LOGIN
int menuInicial(void){
	int op;
	
	do{
		printf(":::::|Menu Inicial|:::::\n\n"
			   "[1] - Login\n"
			   "[0] - Sair\n\n"
			   "Escolha: ");
		fflush(stdin);
		scanf("%i", &op);
		
		system("cls");
		
		if((op < 0) || (op > 1)){
			Error01();
		}
	}while((op < 0) || (op > 1));
	
	return op;
}

//FUN��O DE MENSAGEM FINAL
void msgFinal(){
	printf(":::::|Sistema Encerrado|:::::\n\n"
		   "  ~> Obrigado por utilizar nossos servi�os!\n\n");
}

//FUN��O DE LOGINS
int fLogin(void){
	char login[25];
	char senha[25];
	int op = 0, i;
	
	
	puts(":::::|Tela de Login|:::::");
	
	printf("Login: ");
	fflush(stdin);
	gets(login);
	
	printf("Senha: ");
	fflush(stdin);
	gets(senha);
	
	system("cls");
	
	if((strcmp(login, loginADMIN) == 0) && (strcmp(senha, senhaADMIN) == 0)){
	   	op = 1;
	
		}else{
		
			int existeFunc = 0;
			
			for(i = 0; i < indFuncionario; i++){
				if((strcmp(login, funcionario[i].Id.login) == 0) && (strcmp(senha, funcionario[i].Id.senha) == 0)){
					op = 2;
					existeFunc = 1;
				}
			}
			
			if(!existeFunc){
				Error03();
			}
		
		}	
	}
	return op;
}

//FUN��O DE TELA DO ADIMINISTRADOR
int telaADMIN(void){
	int op;
	
	do{
		printf(":::::|Menu Inicial|:::::\n\n"
			   "[1] - Cadastrar Produto\n"
			   "[2] - Cadastrar Funcion�rio\n"
			   "[3] - Gerar Relat�rio\n"
			   "[0] - Sair\n\n"
			   "Escolha: ");
		fflush(stdin);
		scanf("%i", &op);
		
		system("cls");
		
		if((op < 0) || (op > 3)){
			Error01();
		}
	}while((op < 0) || (op > 3));
	
	return op;
}

//FUN��O DO CADASTRAMENTO DE PRODUTOS
void cadastrarProduto(){
	
	if(IndProduto < max ){
		
	puts(":::::|Cadastramento de Produtos|:::::");
	
	printf("Nome: ");
	fflush(stdin);
	gets(produto[IndProduto].nome);
	
	printf("Qtd: ");
	fflush(stdin);
	scanf("%i", &produto[IndProduto].qtd);
	
	printf("Valor: R$");
	fflush(stdin);
	scanf("%f", &produto[IndProduto].valor);

	system("cls");
	}
	IndProduto++;
}

//FUN��O DO CADASTRAMENTO DE FUNCION�RIOS
void cadastrarFuncionario(){
	if(indFuncionario < max){
	
	puts(":::::|Cadastramento de Funcion�rios|:::::");
	
	printf("Nome: ");
	fflush(stdin);
	gets(funcionario[indFuncionario].nome);
	
	printf("Matr�cula: ");
	fflush(stdin);
	gets(funcionario[indFuncionario].matricula);
	
	printf("Login: ");
	fflush(stdin);
	gets(funcionario[indFuncionario].Id.login);
	
	printf("Senha: ");
	fflush(stdin);
	gets(funcionario[indFuncionario].Id.senha);
	
	system("cls");
	}
	indFuncionario++;
}

//FUN��O DE TELA DO FUNCION�RIO
int telaFunc(void){
	int op;
	
	do{
		printf(":::::|Menu Inicial|:::::\n\n"
			   "[1] - Realizar Venda\n"
			   "[0] - Sair\n\n"
			   "Escolha: ");
		fflush(stdin);
		scanf("%i", &op);
		
		system("cls");
		
		if((op < 0) || (op > 1)){
			Error01();
		}
	}while((op < 0) || (op > 1));
	
	return op;
}

//FUN��O DE OPERA��O DE VENDAS
void fVenda(){
	int i;
	puts(":::::|Venda de Produtos|:::::\n");


		for(i= 0;i < IndProduto; i++){
			printf("Nome: %s / Qtd: %i / Valor R$%.2f\n", produto[i].nome, produto[i].qtd, produto[i].valor);
		}
	}

	
}

//FUN��ES DE TRATAMENTO DE ERROS
void Error01(){
	printf(":::::|Error encontrado|:::::\n"
		   "ERROR 01: Op��o inv�lida.\n\n");
	
	system("pause");
	system("cls");
}

void Error02(){
	printf(":::::|Error encontrado|:::::\n"
		   "ERROR 02: Error na leitura de arquivo.\n\n");
	
	system("pause");
	system("cls");
}

void Error03(){
	printf(":::::|Error encontrado|:::::\n"
		   "ERROR 03: Error ao efetuar login.\n\n");
	
	system("pause");
	system("cls");
}
