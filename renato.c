#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

/*
			ENUNCIADO
Fa�a um programa para gerenciar loja aluguel carros.
O sistema ir� cadastrar:
	� Carro: modelo, cor, ano, quantidade, valor di�ria, placa;
	� Cliente: nome, endere�o (rua, casa, bairro), telefone, n�mero CNH.
O Sistema ir� realizar o aluguel dos carros:
	� O cliente cadastrado escolhe o carro dispon�vel e aluga de acordo com o tempo desejado, valor total.
O sistema ter� devolu��o:
	O funcion�rio pesquisa a placa, o sistema lista os dados do carro
	e quando finalizar a devolu��o o carro volta a estar dispon�vel.
Observa��o: Limite de 5 (cinco) Carros e 5 (cinco) Clientes, estipulado pelo professor!.
*/

typedef struct{
	char Modelo[50];
	char Cor[50];
	int Ano;
	int Quantidade;
	float valorDiaria;
	char Placa[50];
	int Status;
}tCarros;

typedef struct{
	char rua[50];
	int nCasa;
	char bairro[50];
}tEndereco;

typedef struct{
	char Nome[50];
	tEndereco endereco;
	char Telefone[50];
	char CNH[50];
}tClientes;

tCarros Carro[5];
tClientes Cliente[5];

int main(void){
	setlocale(LC_ALL, "Portuguese_Brazil");
	
	int Sistema = 1, Cadastros, Alugueis;
	char eMenuPrincipal, eMenuCadastros;
	int nCarro = 0, nCliente = 0;
	int i, n = 0;
	int existe;
	
	do{
		printf(":::::|Aluguel de Carros|:::::\n\n"
			   "[1] - Cadastramentos\n"
			   "[2] - Aluguel\n"
			   "[3] - Devolu��o\n"
			   "[0] - Encerrar Sistema\n\n"
			   "Escolha: ");
		fflush(stdin);
		scanf("%c", & eMenuPrincipal);
		
		system("cls");
		
		switch(eMenuPrincipal){
			case '1':
				Cadastros = 1;
				
				do{
					printf(":::::|Cadastramentos|:::::\n\n"
						   "Carros cadastrados: %i\n"
						   "Clientes cadastrados: %i\n\n"
						   "[1] - Cadastrar Carro\n"
						   "[2] - Cadastrar Cliente\n"
						   "[0] - Voltar\n\n"
						   "Escolha: ", nCarro, nCliente);
					fflush(stdin);
					scanf("%c", & eMenuCadastros);
					
					system("cls");
					
					switch(eMenuCadastros){
						case '1':
							if(nCarro < 5){
								puts(":::::|Novo Carro|:::::");
								
								printf("Modelo: ");
								fflush(stdin);
								gets(Carro[nCarro].Modelo);
								
								printf("Cor: ");
								fflush(stdin);
								gets(Carro[nCarro].Cor);
								
								printf("Ano: ");
								fflush(stdin);
								scanf("%i", & Carro[nCarro].Ano);
								
								printf("Quantidade: ");
								fflush(stdin);
								scanf("%i", & Carro[nCarro].Quantidade);
								
								printf("Valor Di�ria: R$");
								fflush(stdin);
								scanf("%f", & Carro[nCarro].valorDiaria);
								
								printf("Placa: ");
								fflush(stdin);
								gets(Carro[nCarro].Placa);
								
								Carro[nCarro].Status = 1;
								
								nCarro += 1;
								system("cls");
							}else{
								printf(":::::|Error encontrado|:::::\n"
									   "ERROR 01: Capacidade max. j� cadastrada.\n\n");
								
								system("pause");
								system("cls");
							}
						break;
						
						case '2':
							if(nCliente < 5){
								puts(":::::|Novo Cliente|:::::");
								
								printf("Nome: ");
								fflush(stdin);
								gets(Cliente[nCliente].Nome);
								
								puts("\n:::::|Endere�o|:::::");
								
								printf("Rua: ");
								fflush(stdin);
								gets(Cliente[nCliente].endereco.rua);
								
								printf("N� da Casa: ");
								fflush(stdin);
								scanf("%i", & Cliente[nCliente].endereco.nCasa);
								
								printf("Bairro: ");
								fflush(stdin);
								gets(Cliente[nCliente].endereco.bairro);
								
								puts("\n:::::|Contato|:::::");
								
								printf("Telefone: ");
								fflush(stdin);
								gets(Cliente[nCliente].Telefone);
								
								puts("\n:::::|Identifica��o|:::::");
								
								printf("N� da CNH: ");
								fflush(stdin);
								gets(Cliente[nCliente].CNH);
								
								nCliente += 1;
								system("cls");
							}else{
								printf(":::::|Error encontrado|:::::\n"
									   "ERROR 01: Capacidade max. j� cadastrada.\n\n");
								
								system("pause");
								system("cls");
							}
						break;
						
						case '0':
							Cadastros = 0;
						break;
						
						default:
							printf(":::::|Error encontrado|:::::\n"
								   "ERROR 02: Op��o inv�lida\n\n");
							
							system("pause");
							system("cls");
					}
				}while(Cadastros != 0);
			break;
			
			case '2':
				Alugueis = 1;
				
				do{
					printf(":::::|Aluguel de Carros|:::::\n\n");
					
					existe = 0;
					
					for(i=0; i<5; i++){
						if(Carro[i].Status == 1){
							existe = 1;
						}
					}
					
					if(existe == 1){
						printf("Carros dipon�veis:\n");
						for(i=0; i<5; i++){
							if(Carro[i].Status == 1){
								n++;
								printf("[%i] - %s/%s/%i/%i/%.2f/%s\n", n,
																	   Carro[i].Modelo,
																	   Carro[i].Cor,
																	   Carro[i].Ano,
																	   Carro[i].Quantidade,
																	   Carro[i].valorDiaria,
																	   Carro[i].Placa);
						}
					}
					
					Alugueis = 0;
					}else{
						printf(":::::|Error encontrado|:::::\n"
							   "ERROR 03: N�o a carros dispon�veis\n\n");
						
						system("pause");
						system("cls");
						Alugueis = 0;
					}					
								
				}while(Alugueis != 0);
				
			break;
			
			case '3':
				printf("");
			break;
			
			case '0':
				Sistema = 0;
			break;
			
			default:
				printf(":::::|Error encontrado|:::::\n"
					   "ERROR 02: Op��o inv�lida\n\n");
				
				system("pause");
				system("cls");
		}				
	}while(Sistema != 0);
}
