#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct Funcionario{
	char nome[12];
	char matricula[12];
	
}Funcionario;

typedef struct Produto{
	char nome[12];
	int quantidade;
	float valor;
}Produto;

int opInicial;
int opLogin;
int opMenuADM;
int opMenuFunc;

Funcionario func;
Produto prod;

FILE *arqu_funcionario;
FILE *arqu_produto;

void cadastraFuncionario();
void cadastraProdutos();
int venda();
int menu();

main(){
	setlocale(LC_ALL, "portuguese");
	do {
			opInicial = menuInicial();
		
		if(opInicial == 1){
			opLogin = login();
			
			switch(opLogin){
				case 1:
					do{
						opMenuADM = menu();
						switch(opMenuADM){
							case 1:
								cadastraFuncionario();
							break;
							case 2:
								cadastraProdutos();
							break;
							case 3:	
							break;
						}
					}while(opMenuADM != 0);
				break;
				case 2:
					do{
						opMenuFunc = venda();
						
						if(opMenuFunc == 1){
							venda();
						}
					}while(opMenuFunc != 0);
				break;
			}
		}				
	}while(opInicial != 0);


	
}//fim da main

int login(void){
		char loginop[12];	
		int op = 0;
		arqu_funcionario = fopen("funcionario.bin", "rb");
		
	printf("Login:\n");
	fflush(stdin);
	gets(loginop);
	if (stricmp(loginop, "admin") == 0){
		op = 1;
	}else{
			Funcionario func;
			int existeFunc = 0;
			
			while(fread(&func, sizeof(Funcionario), 1, arqu_funcionario)){
				if(strcmp(loginop, func.matricula) == 0){
					op = 2;
					existeFunc = 1;
				}
			}	
			if(!existeFunc){
				printf("Não encontrado!!\n");
			}
			fclose(arqu_funcionario);		
		}
		
/*	}else{
		printf("Ususario não cadastrador!:\n");
	
	}*/
	
	return op;
	system("pause");
}

void cadastraFuncionario(){
	arqu_funcionario = fopen("funcionario.bin", "a+b");
	if(arqu_funcionario == NULL)
	{
		printf("\nFalha ao abrir arquivo(s)!\n");
		exit(1); // aborta o programa
	}
	
	printf("Cadastrar funcionario\n");
	printf("Digite o nome do funiconario: \n");
	fflush(stdin);
	gets(func.nome);
	printf("Digite o a matricula: \n");
	fflush(stdin);
	gets(func.matricula);
	printf("Funcionario cadastrado com sucesso!\n");
	fwrite(&func,sizeof(Funcionario),1,arqu_funcionario);//escrever no arquivo
	fclose(arqu_funcionario);// fecha o ponteiro do arquivo 
	//return func;
	system("pause");
}

void cadastraProdutos(){
	arqu_produto = fopen("produto.bin", "a+b");
	if(arqu_produto == NULL)
	{
		printf("\nFalha ao abrir arquivo(s)!\n");
		exit(1); // aborta o programa
	}
	
	printf("Cadastra produtos\n");
	printf("Digite o nome do produto: \n");
	fflush(stdin);
	gets(prod.nome);
	printf("Digite a quantidade: \n");
	fflush(stdin);
	scanf("%d",&prod.quantidade);
	printf("Digite o valor: \n");
	fflush(stdin);
	scanf("%f",&prod.valor);
	printf("Produto cadastrado com sucesso!\n");
	fwrite(&prod,sizeof(Produto),1,arqu_produto);//escrever no arquivo
	fclose(arqu_produto);// fecha o ponteiro do arquivo
	system("pause");
}

void listaProdutos(){
	Produto aux;
	arqu_produto=fopen("produto.bin","rb"); // r = de leitura, b = binario 
	rewind(arqu_produto);// comando utilizado para realocar ponteiro para inicio do arquivo
	while(!feof(arqu_produto)){
		fread(&aux,sizeof(Produto),1,arqu_produto);//ler o arquivo
		if (!feof(arqu_produto)){
			printf("\n-----------------------------------------------\n");
			printf("Nome do produto: %s",aux.nome);
			printf("\nquantidade: %d",aux.quantidade);
			printf("\nvalor: %.2f",aux.valor);
			printf("\n------------------------------------------------\n");
			
		}// if do validar para nao haver repetição
	}// fim do while
}


int venda(void){
	int op = 1;
	printf("fazer vendas\n");
	return op;
}

int menu(void){
	int op = 0;
	
	do {
		system("cls");
		printf("1-Cadastra Funcionario\n");
		printf("2-Cadastra Produto\n");
		printf("3-Gerar relatorio \n");
		printf("0-Sair\n");
		scanf("%d",&op);
		
	} while(op != 0);
	return op;
	system("pause");
}
int menuInicial(void){
	int op;
	
	do{
		printf("Menu Inicial\n"
			   "1 - Login\n"
			   "0 - Sair\n\n"
			   "Escolha: ");
		fflush(stdin);
		scanf("%i", &op);
		
		system("cls");
		
		if((op < 0) || (op > 1)){
		printf("Não exite");
		}
	}while((op < 0) || (op > 1));
	
	return op;
}
