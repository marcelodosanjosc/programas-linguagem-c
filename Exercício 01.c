#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

/*
			ENUNCIADO
Faça um programa para gerenciar loja aluguel carros.
O sistema irá cadastrar:
	• Carro: modelo, cor, ano, quantidade, valor diária, placa;
	• Cliente: nome, endereço (rua, casa, bairro), telefone, número CNH.
O Sistema irá realizar o aluguel dos carros:
	• O cliente cadastrado escolhe o carro disponível e aluga de acordo com o tempo desejado, valor total.
O sistema terá devolução:
	O funcionário pesquisa a placa, o sistema lista os dados do carro
	e quando finalizar a devolução o carro volta a estar disponível.
	
Observação: Limite de 5 (cinco) Carros e 5 (cinco) Clientes, estipulado pelo professor!.

Notas: 	• Como não especificado pelo o enunciado, na seção "Cadastramentos",
	somente ha a função de cadastrar. Demais ações como excluir ou alterar,
	não foram inseridas no sistema.
		• Como não especificado pelo o enunciado, na seção "Alugueis",
	somente ha a função de aluguel. Demais ações como descontos ou
	impostos, não foram inseridas no sistema.
*/

typedef struct{//Estrutura que define o 'tipo Carro'.
	char Modelo[50];
	char Cor[50];
	int Ano;
	int Quantidade;
	float valorDiaria;
	char Placa[50];
	int Status;
	int Posicao;
	int diasAlugado;
	float qtdPaga;
	int Locatario;
}tCarros;

typedef struct{//Estrutura que define o 'tipo Endereço'.
	char rua[50];
	int nCasa;
	char bairro[50];
}tEndereco;

typedef struct{//Estrutura que define o 'tipo Cliente'.
	char Nome[50];
	tEndereco endereco;
	char Telefone[50];
	char CNH[50];
}tClientes;

//Instanciamento de 5 objetos de suas respecitivas estruturas.
tCarros Carro[5];
tClientes Cliente[5];

//Criação de funções que tem o papel de informar determinado erro.
int Error01(){
	printf(":~:~:~:~:~|Error encontrado|~:~:~:~:~:\n"
		   "ERROR 01: Capacidade max. já cadastrada.\n\n");
	
	system("pause");
	system("cls");
}

int Error02(){
	printf(":~:~:~:~:~|Error encontrado|~:~:~:~:~:\n"
		   "ERROR 02: Opção inválida.\n\n");
	
	system("pause");
	system("cls");
}

int Error03(){
	printf(":~:~:~:~:~|Error encontrado|~:~:~:~:~:\n"
		   "ERROR 03: Não a carros disponíveis.\n\n");
	
	system("pause");
	system("cls");
}

int Error04(){
	printf(":~:~:~:~:~|Error encontrado|~:~:~:~:~:\n"
		   "ERROR 04: Cliente não cadastrado.\n\n");
	
	system("pause");
	system("cls");
}

int Error05(){
	printf(":~:~:~:~:~|Error encontrado|~:~:~:~:~:\n"
		   "ERROR 05: Valor pago insuficiente.\n\n");
	
	system("pause");
	system("cls");
}

int Error06(){
	printf(":~:~:~:~:~|Error encontrado|~:~:~:~:~:\n"
		   "ERROR 06: Não há carros que foram alugados.\n\n");
	
	system("pause");
	system("cls");
}

int Error07(){
	printf(":~:~:~:~:~|Error encontrado|~:~:~:~:~:\n"
		   "ERROR 07: Carro não encontrado.\n\n");
	
	system("pause");
	system("cls");
}

int main(void){//função principal do sistema.
	setlocale(LC_ALL, "Portuguese_Brazil");//Definição do idioma do sistema.
	
	int Sistema = 1, Cadastros, Alugueis, Pagamento, Devolucoes;//Variáveis base do sistema.
	int opAluguel, opPagamento, opDevolucao;//Variáveis de controle de operações.
	char eMenuPrincipal, eMenuCadastros, eAluguelCarros, ePagamento;//Váriáveis de controle de menus.
	int nCarro = 0, nCliente = 0, nLocatario, nAlugado;//Variáveis de controle de numerações.
	int i, n, e, x;//Variáveis de controle de indicies.
	int existeCarro, existeCliente, existeAlugado, existePlaca;//Variáveis para verificações de existência.
	char idCliente[50], idCarro[50], idAlugado[50];//Variáveis para leitura de identificações.
	int qtdDias;//Variável de apoio a seção de aluguel, onde define a qtd. de dias que um carro será alugado.
	float valorTotal, valorPago, Troco;//Variáveis de controle do pagamento.
	
	//Estruturas de anulação inicial de valores em variáveis de validação.
	for(i=0; i<5; i++){
		Carro[i].Posicao = -1;
	}
	
	for(i=0; i<5; i++){
		Carro[i].Status = -1;
	}

	do{//Seção funcional do sistema.
		printf(":~:~:~:~:~|Aluguel de Carros|~:~:~:~:~:\n\n"
			   "[1] - Cadastramentos\n"
			   "[2] - Aluguel\n"
			   "[3] - Devolução\n"
			   "[0] - Encerrar Sistema\n\n"
			   "Escolha: ");
		fflush(stdin);
		scanf("%c", & eMenuPrincipal);
		
		system("cls");
		
		switch(eMenuPrincipal){//Contole de Menu Principal do sistema.
			case '1':
				Cadastros = 1;
				
				do{//Seção de cadastros.
					printf(":~:~:~:~:~|Cadastramentos|~:~:~:~:~:\n\n"
						   "Carros cadastrados: %i\n"
						   "Clientes cadastrados: %i\n\n"
						   "[1] - Cadastrar Carro\n"
						   "[2] - Cadastrar Cliente\n"
						   "[0] - Voltar\n\n"
						   "Escolha: ", nCarro, nCliente);
					fflush(stdin);
					scanf("%c", & eMenuCadastros);
					
					system("cls");
					
					switch(eMenuCadastros){//Contole de Menu do Cadastramento.
						case '1':
							if(nCarro < 5){//Entrada de Dados no cadastro de carro.
								puts(":~:~:~:~:~|Novo Carro|~:~:~:~:~:");
								
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
								
								printf("Valor Diária: R$");
								fflush(stdin);
								scanf("%f", & Carro[nCarro].valorDiaria);
								
								printf("Placa: ");
								fflush(stdin);
								gets(Carro[nCarro].Placa);
								
								Carro[nCarro].Status = 1;
								
								nCarro += 1;
								system("cls");
							}else{
								Error01();
							}
						break;
						
						case '2':
							if(nCliente < 5){//Entrada de Dados no cadastro de cliente.
								puts(":~:~:~:~:~|Novo Cliente|~:~:~:~:~:");
								
								printf("Nome: ");
								fflush(stdin);
								gets(Cliente[nCliente].Nome);
								
								puts("\n:~:~:~:~:~|Endereço|~:~:~:~:~:");
								
								printf("Rua: ");
								fflush(stdin);
								gets(Cliente[nCliente].endereco.rua);
								
								printf("Nº da Casa: ");
								fflush(stdin);
								scanf("%i", & Cliente[nCliente].endereco.nCasa);
								
								printf("Bairro: ");
								fflush(stdin);
								gets(Cliente[nCliente].endereco.bairro);
								
								puts("\n:~:~:~:~:~|Contato|~:~:~:~:~:");
								
								printf("Telefone: ");
								fflush(stdin);
								gets(Cliente[nCliente].Telefone);
								
								puts("\n:~:~:~:~:~|Identificação|~:~:~:~:~:");
								
								printf("Nº da CNH: ");
								fflush(stdin);
								gets(Cliente[nCliente].CNH);
								
								nCliente += 1;
								system("cls");
							}else{
								Error01();
							}
						break;
						
						case '0':
							Cadastros = 0;
						break;
						
						default:
							Error02();
					}
				}while(Cadastros != 0);
			break;
			
			case '2':
				Alugueis = 1;
				
				do{//Seção de Alugueis.
					puts(":~:~:~:~:~|Aluguel de Carros|~:~:~:~:~:\n");
					
					existeCarro = 0;
					n = 0;
					
					for(i=0; i<5; i++){//Estrutura de verificação de existencia.
						if(Carro[i].Status == 1){
							existeCarro = 1;
						}
					}
					
					if(existeCarro == 1){
						e = 0;
						
						puts("Carros diponíveis:\n");
						for(i=0; i<5; i++){
							if(Carro[i].Status == 1){
								n++;
								printf("[%i] - \tModelo: %s\n"
											  "\tCor: %s\n"
											  "\tAno: %i\n"
											  "\tQuantidade: %i\n"
											  "\tValor Diária: R$%.2f\n"
											  "\tPlaca: %s\n\n", n,
											   Carro[i].Modelo,
											   Carro[i].Cor,
											   Carro[i].Ano,
											   Carro[i].Quantidade,
											   Carro[i].valorDiaria,
											   Carro[i].Placa);
								
								Carro[i].Posicao = n;	
							}
						}
						printf("[0] - Voltar\n\n"
							   "Escolha: ");
						fflush(stdin);
						scanf("%c", & eAluguelCarros);
						
						system("cls");
						
						switch(eAluguelCarros){//Contole de Menu de Aluguel.
							case '1':
								for(i=0; i<5; i++){
									if(Carro[i].Posicao == 1){
										e = 1;
									}
								}
								
								if(e == 1){
								}else{
									Error02();
								}
							break;
							
							case '2':
								for(i=0; i<5; i++){
									if(Carro[i].Posicao == 2){
										e = 2;
									}
								}
								
								if(e == 2){
								}else{
									Error02();
								}
							break;
							
							case '3':
								for(i=0; i<5; i++){
									if(Carro[i].Posicao == 3){
										e = 3;
									}
								}
								
								if(e == 3){
								}else{
									Error02();
								}
							break;
							
							case '4':
								for(i=0; i<5; i++){
									if(Carro[i].Posicao == 4){
										e = 4;
									}
								}
								
								if(e == 4){
								}else{
									Error02();
								}
							break;
							
							case '5':
								for(i=0; i<5; i++){
									if(Carro[i].Posicao == 5){
										e = 5;
									}
								}
								
								if(e == 5){
								}else{
									Error02();
								}
							break;
							
							case '0':
								Alugueis = 0;
							break;
							
							default:
								Error02();
						}
						
						if(eAluguelCarros == '0'){
						}else{
							for(i=0; i<5; i++){
								if((Carro[i].Posicao == e) && (e > 0)){
									do{//Estrutura de operação de aluguel.
										opAluguel = 1;										
										puts(":~:~:~:~:~|Aluguel de Carros|~:~:~:~:~:");
										
										printf("\t{Digite '-1' para voltar}\n\n"
											   "CNH do cliente: ");
										fflush(stdin);
										gets(idCliente);
										
										system("cls");
										
										existeCliente = 0;
										
										if(strcmp(idCliente, "-1") == 0){
											opAluguel = 0;
										}else{
											for(x=0; x<5; x++){//Estrutura de verificação de existência.
												if(strcmp(idCliente, Cliente[x].CNH) == 0){
													existeCliente = 1;
													nLocatario = x;
												}
											}
											
											if(existeCliente == 1){
												puts(":~:~:~:~:~|Cliente Encontrado|~:~:~:~:~:");
												
												system("pause");
												system("cls");
												
												puts(":~:~:~:~:~|Aluguel de Carros|~:~:~:~:~:");
												
												printf("Qtd. de dias será alugado: ");
												fflush(stdin);
												scanf("%i", & qtdDias);
												
												valorTotal = Carro[i].valorDiaria * qtdDias;
												
												system("cls");
												
												do{//Seção de Pagamento
													printf(":~:~:~:~:~|Aluguel de Carros|~:~:~:~:~:\n\n"
														   "[1] - Pagamento\n"
														   "[0] - Abotar Operação\n\n"
														   "Escolha: ");
													fflush(stdin);
													scanf("%c", & ePagamento);
													
													system("cls");
													
													switch(ePagamento){//Contole de Menu de Pagamento.
														case '1':
															do{//Estrutura de operação de pagamento.
																puts(":~:~:~:~:~|Aluguel de Carros|~:~:~:~:~:\n");
																
																printf("Valor total a pagar: R$%.2f\n\n"
																	   "Valor Pago: R$", valorTotal);
																fflush(stdin);
																scanf("%f", & valorPago);
																
																if(valorPago == -1){
																	opPagamento = 1;
																	Pagamento = 0;
																	opAluguel = 0;
																	
																	system("cls");
																}else if(valorPago >= valorTotal){
																	Troco = valorPago - valorTotal;
																	printf("\nTroco: R$%.2f\n\n", Troco);
																	
																	system("pause");
																	system("cls");
																	
																	//Informações
																	puts(":~:~:~:~:~|Aluguel de Carros|~:~:~:~:~:\n");
																	
																	puts(":~:~:~:~:~|Dados do Carro|~:~:~:~:~:\n");
																	printf("\tModelo: %s\n"
																		   "\tCor: %s\n"
																		   "\tAno: %i\n"
																		   "\tQuantidade: %i\n"
																		   "\tValor Diária: R$%.2f\n"
																		   "\tPlaca: %s\n\n",
																		   Carro[i].Modelo,
																		   Carro[i].Cor,
																		   Carro[i].Ano,
																		   Carro[i].Quantidade,
																		   Carro[i].valorDiaria,
																		   Carro[i].Placa);
																	
																	Carro[i].Status = 0;
																	Carro[i].Posicao = -1;
																	
																	puts(":~:~:~:~:~|Dados do Cliente|~:~:~:~:~:\n");
																	printf("\tNome: %s\n\n"
																		   "\tEndereço: "
																		   "Rua - %s\n"
																		   "\t\t  Nº da Casa - %i\n"
																		   "\t\t  Bairro - %s\n\n"
																		   "\tTelefone: %s\n"
																		   "\tNº da CNH: %s\n\n",
																		   Cliente[nLocatario].Nome,
																		   Cliente[nLocatario].endereco.rua,
																		   Cliente[nLocatario].endereco.nCasa,
																		   Cliente[nLocatario].endereco.bairro,
																		   Cliente[nLocatario].Telefone,
																		   Cliente[nLocatario].CNH);
																	
																	Carro[i].Locatario = nLocatario;
																	
																	puts(":~:~:~:~:~|Demais informações|~:~:~:~:~:\n");
																	printf("\tQtd. de dias alugados: %i\n"
																		   "\tValor do pagamento: R$%.2f\n\n",
																		   qtdDias,
																		   valorTotal);
																	
																	Carro[i].diasAlugado = qtdDias;
																	Carro[i].qtdPaga = valorTotal;
																	
																	puts(":~:~:~:~:~|Operação finalizada|~:~:~:~:~:\n");
																	opPagamento = 1;
																	
																	system("pause");
																	system("cls");
																}else{
																	system("cls");
																	Error05();
																}
															}while(opPagamento != 1);
															
															Pagamento = 0;
														break;
														
														case '0':
															Pagamento = 0;
															opAluguel = 0;
														break;
														
														default:
															Error02();
													}
												}while(Pagamento != 0);
												
												opAluguel = 0;
											}else{
												Error04();
											}
										}
									}while(opAluguel != 0);
								}
							}
						}						
					}else{
						system("cls");
						Error03();
						Alugueis = 0;
					}
				}while(Alugueis != 0);
			break;
			
			case '3':
				Devolucoes = 1;
				
				do{//Seção de Devoluções
					existeAlugado = 0;
					
					for(i=0; i<5; i++){//Estrutura de verificação de existência.
						if(Carro[i].Status == 0){
							existeAlugado = 1;
						}
					}
					
					if(existeAlugado == 1){
						do{//Estrutura de operação de Devolução
							opDevolucao = 1;										
							puts(":~:~:~:~:~|Devolução de Carros|~:~:~:~:~:");
							
							printf("\t{Digite '-1' para voltar}\n\n"
								   "Placa do carro: ");
							fflush(stdin);
							gets(idAlugado);
							
							system("cls");
							
							existePlaca = 0;
							
							if(strcmp(idAlugado, "-1") == 0){
								opDevolucao = 0;
							}else{
								for(i=0; i<5; i++){//Estrutura de verificação de existência.
									if(strcmp(idAlugado, Carro[i].Placa) == 0){
										existePlaca = 1;
										nAlugado = i;
									}
								}
								
								if(existePlaca == 1){
									puts(":~:~:~:~:~|Carro Encontrado|~:~:~:~:~:");
									
									system("pause");
									system("cls");
									
									//Informações
									puts(":~:~:~:~:~|Devolução Realizada|~:~:~:~:~:\n");
									
									puts(":~:~:~:~:~|Carro Recuperado|~:~:~:~:~:\n");
									printf("\tModelo: %s\n"
										   "\tCor: %s\n"
										   "\tAno: %i\n"
										   "\tQuantidade: %i\n"
										   "\tValor Diária: R$%.2f\n"
										   "\tPlaca: %s\n\n",
										   Carro[nAlugado].Modelo,
										   Carro[nAlugado].Cor,
										   Carro[nAlugado].Ano,
										   Carro[nAlugado].Quantidade,
										   Carro[nAlugado].valorDiaria,
										   Carro[nAlugado].Placa);
									
									Carro[nAlugado].Status = 1;
									
									puts(":~:~:~:~:~|Dados do Cliente|~:~:~:~:~:\n");
									printf("\tNome: %s\n\n"
										   "\tEndereço: "
										   "Rua - %s\n"
										   "\t\t  Nº da Casa - %i\n"
										   "\t\t  Bairro - %s\n\n"
										   "\tTelefone: %s\n"
										   "\tNº da CNH: %s\n\n",
										   Cliente[Carro[nAlugado].Locatario].Nome,
										   Cliente[Carro[nAlugado].Locatario].endereco.rua,
										   Cliente[Carro[nAlugado].Locatario].endereco.nCasa,
										   Cliente[Carro[nAlugado].Locatario].endereco.bairro,
										   Cliente[Carro[nAlugado].Locatario].Telefone,
										   Cliente[Carro[nAlugado].Locatario].CNH);
									
									puts(":~:~:~:~:~|Demais informações|~:~:~:~:~:\n");
									printf("\tQtd. de dias alugados: %i\n"
										   "\tValor pago: R$%.2f\n\n",
										   Carro[nAlugado].diasAlugado,
										   Carro[nAlugado].qtdPaga);
									
									puts(":~:~:~:~:~|Operação finalizada|~:~:~:~:~:\n");
									
									system("pause");
									system("cls");
									
									opDevolucao = 0;
									Devolucoes = 0;
								}else{
									Error07();
								}
							}
						}while(opDevolucao != 0);				
					}else{
						system("cls");
						Error06();
						Devolucoes = 0;
					}
				}while(Devolucoes != 0);
			break;
			
			case '0':
				Sistema = 0;
			break;
			
			default:
				Error02();
		}				
	}while(Sistema != 0);
	
	//Mensagem final.
	printf(":~:~:~:~:~|Sistema Encerrado|~:~:~:~:~:\n\n"
		   "  ~~~> Obrigado por utilizar nossos serviços!\n\n");
}
