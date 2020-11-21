#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define Max_Clientes 4
#define Max_Animais 3

typedef struct{
	char nome[25];
	char telefone[25];
}tCliente;

typedef struct{
	char nome[25];
	char raca[25];
	float peso;
	char dono[25];
}tAnimal;

void Menu();
void CadastrarCliente(int *cont, tCliente C[]);
void CadastrarAnimais(int cont[], tAnimal A[][Max_Clientes], tCliente C[]);
void PesquisarCliente(int cont[], tAnimal A[][Max_Clientes], tCliente C[]);
void Exibir(int achei, int i, int n, tAnimal A[][Max_Clientes], tCliente C[]);
void MenuAlterar(int cont[], tAnimal A[][Max_Clientes], tCliente C[]);
void Alt_1(int cont[], int opAlt, tAnimal A[][Max_Clientes], tCliente C[], int i);
void Alt_2(int opAlt, tAnimal A[][Max_Clientes], int i, int n);
void MenuDeletar(int contA[], int *contC, tAnimal A[][Max_Clientes], tCliente C[]);
void Del_1(int contA[], int *contC, tAnimal A[][Max_Clientes], tCliente C[], int i);
void Del_2(int cont[], tAnimal A[][Max_Clientes], int i, int n);

void Error01();
void Error02();
void Error03();
void Error04();
void Error05();
void Error06();

int main(){
	system("title Pet Shop v1.0");
	unsigned int cp    = 1252;
	unsigned int cpIn  = GetConsoleCP();
    unsigned int cpOut = GetConsoleOutputCP();
    SetConsoleOutputCP(cp);
    SetConsoleCP(cp);
	
	Menu();
	
	SetConsoleCP(cpIn);
    SetConsoleOutputCP(cpOut);
}

void Menu(){
	int opMenu;
	int cClientes = 0, cAnimais[4] = {0, 0, 0, 0};
	tCliente Cliente[Max_Clientes];
	tAnimal Animal[Max_Animais][Max_Clientes];
	
	do{
		printf("Qual operação deseja realizar?\n\n"
			   "[1] - Cadastrar Cliente\n"
			   "[2] - Cadastrar Animais\n"
			   "[3] - Pesquisar Dados\n"
			   "[4] - Alterar Dados de Cliente\n"
			   "[5] - Deletar Cliente\n"
			   "[0] - Fechar Sistema\n\n"
			   "\\> ");
		scanf("%i", & opMenu);
		
		system("cls");
		
		switch(opMenu){
			case 1:
				CadastrarCliente(&cClientes, Cliente);
			break;
			
			case 2:
				CadastrarAnimais(cAnimais, Animal, Cliente);
			break;
			
			case 3:
				PesquisarCliente(cAnimais, Animal, Cliente);
			break;
			
			case 4:
				MenuAlterar(cAnimais, Animal, Cliente);
			break;
			
			case 5:
				MenuDeletar(cAnimais, &cClientes, Animal, Cliente);
			break;
			
			case 0:
				printf(":~:~:~:~:~|Sistema Encerrado|~:~:~:~:~:\n\n"
		   			   "  ~~~> Obrigado por utilizar nossos serviços!\n");
		   		
		   		exit(0);
			break;
			
			default:
				Error01();
		}
	}while(opMenu != 0);
}

void CadastrarCliente(int *cont, tCliente C[]){
	tCliente Aux;
	int i = *cont;
		
	if(i < Max_Clientes){
		printf("Nome: ");
		fflush(stdin);
		gets(Aux.nome);
		
		printf("Telefone: ");
		fflush(stdin);
		gets(Aux.telefone);
		
		strcpy(C[i].nome, Aux.nome);
		strcpy(C[i].telefone, Aux.telefone);
		
		i++;
		*cont = i;
		
		system("cls");
	}else{
		Error02();
	}
}

void CadastrarAnimais(int cont[], tAnimal A[][Max_Clientes], tCliente C[]){
	tAnimal Aux;
	int i, achei = 0;
	
	printf("Nome do Dono: ");
	fflush(stdin);
	gets(Aux.dono);
	
	system("cls");
	
	for(i=0; i<Max_Clientes; i++){
		if(strcmp(Aux.dono, C[i].nome) == 0){
			achei = 1;
			
			if(cont[i] < Max_Animais){
				printf("Nome do Pet: ");
				fflush(stdin);
				gets(Aux.nome);
				
				printf("Raça do Pet: ");
				fflush(stdin);
				gets(Aux.raca);
				
				printf("Peso do Pet: ");
				scanf("%f", & Aux.peso);
				
				system("cls");
				
				strcpy(A[cont[i]][i].dono, Aux.dono);
				strcpy(A[cont[i]][i].nome, Aux.nome);
				strcpy(A[cont[i]][i].raca, Aux.raca);
				A[cont[i]][i].peso = Aux.peso;
				
				cont[i]++;
			}else{
				Error03();
			}
		}
	}
	
	if(!achei){
		Error04();
	}
}

void PesquisarCliente(int cont[], tAnimal A[][Max_Clientes], tCliente C[]){
	char aux_Pesq[25];
	int i, n, x, achei = 0;
	
	printf("Digite o nome do cliente: ");
	fflush(stdin);
	gets(aux_Pesq);
	
	system("cls");
	
	for(i=0; i<Max_Clientes; i++){
		if(strcmp(aux_Pesq, C[i].nome) == 0){
			achei = 1;
			n = i;
			x = cont[i];
		}
	}
	
	Exibir(achei, n, x, A, C);
}

void Exibir(int achei, int i, int n, tAnimal A[][Max_Clientes], tCliente C[]){
	if(achei == 1){
		int x;
		printf("DADOS DO CLIENTE\n"
				   "Nome: %s\n"
				   "Telefone: %s\n\n"
				   "PETS\n", C[i].nome, C[i].telefone);
			if(n > 0){
				for(x=0; x<n; x++){
					printf("Pet %iº: %s\n"
						   "Raça: %s\n"
						   "Peso: %.2f\n\n", x+1
						   				   , A[x][i].nome
										   , A[x][i].raca
										   , A[x][i].peso);
				}
			}else{
				printf("Não possui pets cadastrados!\n\n");
			}
			
			system("pause");
			system("cls");
	}else{
		Error04();
	}
}

void MenuAlterar(int cont[], tAnimal A[][Max_Clientes], tCliente C[]){
	char aux_Pesq[25];
	int i, n, achei = 0, aux_Alt;
	
	printf("Digite o nome do cliente: ");
	fflush(stdin);
	gets(aux_Pesq);
	
	system("cls");
	
	for(i=0; i<Max_Clientes; i++){
		if(strcmp(aux_Pesq, C[i].nome) == 0){
			achei = 1;
			n = i;
		}
	}
	
	if(achei == 1){
		do{
			printf("Qual dado deseja alterar?\n\n"
				   "[1] - Nome (%s)\n"
				   "[2] - Telefone (%s)\n"
				   "[3] - Alterar dados de seus pets\n"
				   "[4] - Deletar algum pet\n"
				   "[0] - Voltar\n\n"
				   "\\> ",
				   C[n].nome,
				   C[n].telefone);
			scanf("%i", &aux_Alt);
			
			system("cls");
			
			Alt_1(cont, aux_Alt, A, C, n);
		}while(aux_Alt != 0);
	}else{
		Error04();
	}
}

void Alt_1(int cont[], int opAlt , tAnimal A[][Max_Clientes], tCliente C[], int i){
	tCliente auxC;
	int n, x;
	int acheiPet = 0, contAux = 0;
	int opAltAnim, opAltAnimAux;
	int opDelAnim, opDelAnimAux;
	
	switch(opAlt){
		case 1:
			printf("Digite um novo nome para alteração: ");
			fflush(stdin);
			gets(auxC.nome);
			
			for(n=0; n<Max_Clientes; n++){
				for(x=0; x<Max_Animais; x++){
					if(strcmp(A[x][n].dono, C[i].nome) == 0){
						strcpy(A[x][n].dono, auxC.nome);
					}
				}
			}
			
			strcpy(C[i].nome, auxC.nome);
			
			system("pause");
			system("cls");
		break;
		
		case 2:
			printf("Digite um novo telefone para alteração: ");
			fflush(stdin);
			gets(auxC.telefone);
			
			strcpy(C[i].telefone, auxC.telefone);
			
			system("pause");
			system("cls");
		break;
		
		case 3:
			do{
				puts("Qual pet deseja alterar dados?\n");
				for(n=0; n<Max_Clientes; n++){
					for(x=0; x<Max_Animais; x++){
						if(strcmp(A[x][n].dono, C[i].nome) == 0){
							acheiPet = 1;
							printf("[%i] - %s\n", x+1, A[x][n].nome);
							contAux++;
						}
					}
				}
				if(!acheiPet){
					system("cls");
					Error05();
					
					opAltAnim = 0;
				}else{
					printf("[0] - Voltar\n\n"
						   "\\> ");
					scanf("%i", & opAltAnim);
					
					system("cls");
					
					if(!opAltAnim){
					}else if(opAltAnim <= contAux){
						do{
							printf("Qual dado deseja alterar?\n\n"
								   "[1] - Nome (%s)\n"
								   "[2] - Raça (%s)\n"
								   "[3] - Peso (%.2fKg)\n"
								   "[0] - Voltar\n\n"
								   "\\> ",
								   A[opAltAnim-1][i].nome,
								   A[opAltAnim-1][i].raca,
								   A[opAltAnim-1][i].peso);
							scanf("%i", &opAltAnimAux);
							
							system("cls");
							
							Alt_2(opAltAnimAux, A, i, opAltAnim-1);
						}while(opAltAnimAux != 0);
					}else{
						Error01();
					}
				}
				
				contAux = 0;
			}while(opAltAnim != 0);
		break;
		
		case 4:
			do{
				puts("Qual pet deseja deletar do sistema?\n");
				for(n=0; n<Max_Clientes; n++){
					for(x=0; x<Max_Animais; x++){
						if(strcmp(A[x][n].dono, C[i].nome) == 0){
							acheiPet = 1;
							printf("[%i] - %s\n", x+1, A[x][n].nome);
							contAux++;
						}
					}
				}
				if(!acheiPet){
					system("cls");
					Error05();
					
					opDelAnim = 0;
				}else{
					printf("[0] - Voltar\n\n"
						   "\\> ");
					scanf("%i", & opDelAnim);
					
					system("cls");
					
					if(!opDelAnim){
					}else if(opDelAnim <= contAux){
						printf("Deseja deletar realmente o seguinte pet?\n\n"
							   "Nome: %s\n"
							   "Raça: %s\n"
							   "Peso: %.2fKg\n\n"
							   "[1] - Prosseguir\n"
							   "[0] - Abortar\n\n"
							   "\\> ",
							   A[opDelAnim-1][i].nome,
							   A[opDelAnim-1][i].raca,
							   A[opDelAnim-1][i].peso);
						scanf("%i", &opDelAnimAux);
						
						system("cls");
						
						switch(opDelAnimAux){
							case 1:
								Del_2(cont, A, i, opDelAnim-1);
							break;
							
							case 0:
							break;
							
							default:
								Error01();
						}
					}else{
						Error01();
					}
				}
				
				contAux = 0;
			}while(opDelAnim != 0);
		break;
		
		case 0:
		break;
		
		default:
			Error01();
	}
}

void Alt_2(int opAlt, tAnimal A[][Max_Clientes], int i, int n){
	tAnimal auxA;
	
	switch(opAlt){
		case 1:
			printf("Digite um novo nome do pet para alteração: ");
			fflush(stdin);
			gets(auxA.nome);
			
			strcpy(A[n][i].nome, auxA.nome);
			
			system("pause");
			system("cls");
		break;
		
		case 2:
			printf("Digite uma nova raça ao pet para alteração: ");
			fflush(stdin);
			gets(auxA.raca);
			
			strcpy(A[n][i].raca, auxA.raca);
			
			system("pause");
			system("cls");
		break;
		
		case 3:
			printf("Digite o novo peso do pet para alteração: ");
			scanf("%f", & auxA.peso);
			
			A[n][i].peso = auxA.peso;
			
			system("pause");
			system("cls");
		break;
		
		case 0:
		break;
		
		default:
			Error01();
	}
}

void MenuDeletar(int contA[], int *contC, tAnimal A[][Max_Clientes], tCliente C[]){
	int i;
	int achei = 0, contAux = 0;
	int opDelClien, opDelClienAux;
	
	do{
		puts("Qual cliente deseja deletar do sistema?\n");
		for(i=0; i<Max_Clientes; i++){
			if(strcmp(C[i].nome, "NULL") == 1){
				achei = 1;
				
				printf("[%i] - %s\n", i+1, C[i].nome);
				contAux++;
			}
		}
		if(!achei){
			system("cls");
			Error06();
			
			opDelClien = 0;
		}else{
			printf("[0] - Voltar\n\n"
				   "\\> ");
			scanf("%i", & opDelClien);
			
			system("cls");
			
			if(!opDelClien){
			}else if(opDelClien <= contAux){
				printf("Deseja deletar realmente o seguinte cliente?\n\n"
					   "Nome: %s\n"
					   "Telefone: %s\n\n"
					   "OBS: todos os pet associados a este, serão deletados também!\n\n"
					   "[1] - Prosseguir\n"
					   "[0] - Abortar\n\n"
					   "\\> ",
					   C[opDelClien-1].nome,
					   C[opDelClien-1].telefone);
				scanf("%i", &opDelClienAux);
				
				system("cls");
				
				switch(opDelClienAux){
					case 1:
						Del_1(contA, contC, A, C, opDelClien-1);
					break;
					
					case 0:
					break;
					
					default:
						Error01();
				}
			}else{
				Error01();
			}
		}
		
		contAux = 0;
	}while(opDelClien != 0);
}

void Del_1(int contA[], int *contC, tAnimal A[][Max_Clientes], tCliente C[], int i){
	tCliente auxC[Max_Clientes];
	tAnimal auxA[Max_Animais];
	int n;
	int aux_cont = 0;
	
	strcpy(C[i].nome, "NULL");
	strcpy(C[i].telefone, "NULL");
	
	for(n=0; n<Max_Clientes; n++){
		if(strcmp(C[n].nome, "NULL") == 1){
			strcpy(auxC[aux_cont].nome, C[n].nome);
			strcpy(auxC[aux_cont].telefone, C[n].telefone);
			
			aux_cont++;
		}
	}
	
	for(n=0; n<Max_Clientes; n++){
		strcpy(C[n].nome, auxC[n].nome);
		strcpy(C[n].telefone, auxC[n].telefone);
	}
	
	*contC -= 1;
	//*contC--; Deu erro!
	
	for(n=0; n<Max_Animais; n++){
		Del_2(contA, A, i, n);
	}
}

void Del_2(int cont[], tAnimal A[][Max_Clientes], int i, int n){
	tAnimal auxA[Max_Animais];
	int x, aux_cont = 0;
	
	strcpy(A[n][i].dono, "NULL");
	strcpy(A[n][i].nome, "NULL");
	strcpy(A[n][i].raca, "NULL");
	A[n][i].peso = 0;
	
	for(x=0; x<Max_Animais; x++){
		if(strcmp(A[x][i].dono, "NULL") == 1){
			strcpy(auxA[aux_cont].dono, A[x][i].dono);
			strcpy(auxA[aux_cont].nome, A[x][i].nome);
			strcpy(auxA[aux_cont].raca, A[x][i].raca);
			auxA[aux_cont].peso = A[x][i].peso;
			
			aux_cont++;
		}
	}
	
	for(x=0; x<Max_Animais; x++){
		strcpy(A[x][i].dono, auxA[x].dono);
		strcpy(A[x][i].nome, auxA[x].nome);
		strcpy(A[x][i].raca, auxA[x].raca);
		A[x][i].peso = auxA[x].peso;
	}
	
	cont[i]--;
}

void Error01(){
	printf(":~:~:~:~:~|Error encontrado|~:~:~:~:~:\n"
		   "ERROR 01: Opção inválida.\n\n");
	
	fflush(stdin);
	system("pause");
	system("cls");
}

void Error02(){
	printf(":~:~:~:~:~|Error encontrado|~:~:~:~:~:\n"
		   "ERROR 02: Quantidade max. de clientes já cadastrada.\n\n");
	
	fflush(stdin);
	system("pause");
	system("cls");
}

void Error03(){
	printf(":~:~:~:~:~|Error encontrado|~:~:~:~:~:\n"
		   "ERROR 03: Quantidade max. de animais p/cliente já cadastrada.\n\n");
	
	fflush(stdin);
	system("pause");
	system("cls");
}

void Error04(){
	printf(":~:~:~:~:~|Error encontrado|~:~:~:~:~:\n"
		   "ERROR 04: Cliente não cadastrado no sistema.\n\n");
	
	fflush(stdin);
	system("pause");
	system("cls");
}

void Error05(){
	printf(":~:~:~:~:~|Error encontrado|~:~:~:~:~:\n"
		   "ERROR 05: Cliente não possui animais cadastrados no sistema.\n\n");
	
	fflush(stdin);
	system("pause");
	system("cls");
}

void Error06(){
	printf(":~:~:~:~:~|Error encontrado|~:~:~:~:~:\n"
		   "ERROR 06: Não  há clientes cadastrados no sistema.\n\n");
	
	fflush(stdin);
	system("pause");
	system("cls");
}

