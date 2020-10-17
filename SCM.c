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

//VARIÁVEIS GLOBAIS DO SISTEMA
int max = 5;
int opInicial;
int opLogin;
int opMenuADM;
int opMenuFunc;

int indFuncionario;
int indProduto;

//DADOS DO ADIMINISTRADOR
char loginADMIN[25] = "admin";
char senhaADMIN[25] = "123";

tFuncionario funcionario[5];
tProduto produto[5];

//PROTÓTIPOS DE FUNÇÕES
int menuInicial();
int fLogin();
int telaADMIN();
int telaFunc();
void msgFinal();
void cadastrarProduto();
void cadastrarFuncionario();
void fVenda();

//PROTÓTIPOS DE TRATAMENTO DE ERROS
void Error01();
void Error02();
void Error03();

//FUNÇÃO PRINCIPAL
int main(void){
	setlocale(LC_ALL, "Portuguese_Brazil");//Definição do idioma do programa em pt-br
	
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

//FUNÇÃO DE TELA DE LOGIN
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

//FUNÇÃO DE MENSAGEM FINAL
void msgFinal(){
	printf(":::::|Sistema Encerrado|:::::\n\n"
		   "  ~> Obrigado por utilizar nossos serviços!\n\n");
}

//FUNÇÃO DE LOGINS
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
		return op;
	}
	
//}


//FUNÇÃO DE TELA DO ADIMINISTRADOR
int telaADMIN(void){
	int op;
	
	do{
		printf(":::::|Menu Inicial|:::::\n\n"
			   "[1] - Cadastrar Produto\n"
			   "[2] - Cadastrar Funcionário\n"
			   "[3] - Gerar Relatório\n"
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

//FUNÇÃO DO CADASTRAMENTO DE PRODUTOS
void cadastrarProduto(){
	if(indProduto < max ){
		
	puts(":::::|Cadastramento de Produtos|:::::");
	
	printf("Nome: ");
	fflush(stdin);
	gets(produto[indProduto].nome);
	
	printf("Qtd: ");
	fflush(stdin);
	scanf("%i", &produto[indProduto].qtd);
	
	printf("Valor: R$");
	fflush(stdin);
	scanf("%f", &produto[indProduto].valor);

	system("cls");
	}
	indProduto++;
}

//FUNÇÃO DO CADASTRAMENTO DE FUNCIONÁRIOS
void cadastrarFuncionario(){
	if(indFuncionario < max){
	
	puts(":::::|Cadastramento de Funcionários|:::::");
	
	printf("Nome: ");
	fflush(stdin);
	gets(funcionario[indFuncionario].nome);
	
	printf("Matrícula: ");
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

//FUNÇÃO DE TELA DO FUNCIONÁRIO
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

//FUNÇÃO DE OPERAÇÃO DE VENDAS
void fVenda(){
	int i, opcaoProduto, qtdProduto, dQuantidade, maisProduto;
	float valorTotal = 0.0, valorProduto = 0.0, pagamento = 0.0, troco = 0.0;
	puts(":::::|Venda de Produtos|:::::\n");

		do {
		for(i= 0;i < indProduto; i++){
			printf("[%i] - Nome: %s / Qtd: %i / Valor R$%.2f\n",i, produto[i].nome, produto[i].qtd, produto[i].valor);
		}
		for (i = 0;i < indProduto;i++){
		printf("Produto: ");
		fflush(stdin);
		scanf("%i",&opcaoProduto);
		printf("Qunatidade: ");
		fflush(stdin);
		scanf("%i",&qtdProduto);
			//for (i = 0;i < indProduto;i++){
				if(opcaoProduto == i){	
					if (qtdProduto <= produto[i].qtd){
					produto[i].qtd -= qtdProduto;
					valorProduto = produto[i].valor * qtdProduto;
					}else{
					printf("Alem da quantidade \n ");
					}
				}else{
					printf("Produto não existente! \n");
				}
			}
		valorTotal += valorProduto;	
		printf("Outro produto (1) finaliza (0): \n ");
		scanf("%i",&maisProduto);	
		}while(maisProduto != 0);
		printf("Total: %.2f \n",valorTotal); 
		printf("Pagamento: \n");
		fflush(stdin);
		scanf("%f",&pagamento);
		if(pagamento < valorTotal){
			printf("Valor abaxio: \n");
		}else {
			troco =pagamento - valorTotal;
		}
		printf("O troco: %.2f \n",troco);
		system("pause");
		
}

//FUNÇÕES DE TRATAMENTO DE ERROS
void Error01(){
	printf(":::::|Error encontrado|:::::\n"
		   "ERROR 01: Opção inválida.\n\n");
	
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
