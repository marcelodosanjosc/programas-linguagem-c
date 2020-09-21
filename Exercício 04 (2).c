//SISTEMA DE CONTROLE DA BIBLIOTECA

//CHAMADA DE BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//DECLARA��O DE REGISTROS
typedef struct{
	char login[25];
	char senha[20];
}tLogin;

typedef struct{
	char nome[25];
	int matricula;
	tLogin Id;
}tFuncionario;

typedef struct{
	char nome[25];
	char area[20];
}tCurso;

typedef struct{
	char nome[25];
	char isbn[25];
	tCurso Curso;
	char status[10];
	int nPosicao;
}tLivro;

typedef struct{
	char nome[25];
	int matricula;
	char curso[25];
	int QtdEmp;
	char LivEmp[25][3];
}tAluno;

//DECLARA��O DE PROTOTIPOS
void SistemaIntegrado();
void ptBR();
void CadastrarFunc();
void CadastrarLiv();
void CadastrarCur();
void CadastrarAln();
void EmprestimoLiv();
void DevolucaoLiv();
int Login();

//DECLARA��O DE PROTOTIPOS DE ERROS
void Error01();
void Error02();
void Error03();
void Error04();
void Error05();
void Error06();
void Error07();
void Error08();
void Error09();

//DADOS DO ADIMINISTRADOR
tLogin ADM = {"adm", "123"};

//DECLARA��O DE VARI�VEIS GLOBAIS
int iFunc = 0, iMatF = 1, iMatA = 1, iLiv = 0, iCur = 0, iAln;//indicies
tFuncionario Func[5];//Vetor de estrutura de funcion�rio
tLivro Liv[5];//Vetor de estrutura de livros
tCurso Cur[5];//Vetor de estrutura de cursos
tAluno Aln[5];//Vetor de estrutura de alunos
int iEmps[5] = {0, 0, 0, 0, 0};

//FUN��O PRINCIPAL
int main(){//inicio main
	SistemaIntegrado();
}//fim main

//FUN��ES E PROCEDIMENTOS
void SistemaIntegrado(){//inicio da integra��o do sistema
	ptBR();//escolha do idioma
	
	int opLogin, opMenuInicial, opMenuADM;//Vari�veis de controle de sub-rotinas
	
	do{//inicio loop principal
		printf(":~:~:~:~:~|Menu Inicial|~:~:~:~:~:\n\n"
			   "[1] - Login\n"
			   "[0] - Sair\n\n"
			   "Escolha: ");
		scanf("%i", & opMenuInicial);
		
		system("cls");
		
		switch(opMenuInicial){//inicio controle op��es inicias
			case 1:
				opLogin = Login();
				
				switch(opLogin){//inicio valida��o de usu�rio
					case 1:
					break;
					
					case 2:
						do{//inicio loop menu ADM
							printf(":~:~:~:~:~|Op��es de Administrador|~:~:~:~:~:\n\n"
								   "[1] - Cadastrar Funcion�rio\n"
								   "[2] - Cadastrar Livro\n"
								   "[3] - Cadastrar Curso\n"
								   "[4] - Cadastrar Aluno\n"
								   "[5] - Empr�stimo de Livro\n"
								   "[6] - Devolu��o de Livro\n"
								   "[0] - Voltar\n\n"
								   "Escolha: ");
							scanf("%i", & opMenuADM);
							
							system("cls");
							
							switch(opMenuADM){//inicio controle op��es adm
								case 1:
									CadastrarFunc();
								break;
								
								case 2:
									CadastrarLiv();
								break;
								
								case 3:
									CadastrarCur();
								break;
								
								case 4:
									CadastrarAln();
								break;
								
								case 5:
									EmprestimoLiv();
								break;
								
								case 6:
									DevolucaoLiv();
								break;
								
								case 0:
								break;
								
								default:
									Error01();
							}//fim controle op��es adm
						}while(opMenuADM != 0);//fim loop menu ADM
					break;
					
					default:
						Error02();
				}//fim valida��o de usu�rio
			break;
			
			case 0:
				printf(":~:~:~:~:~|Sistema Encerrado|~:~:~:~:~:\n\n"
		   			   "  ~~~> Obrigado por utilizar nossos servi�os!\n");
		   		
		   		exit(0);
		   	break;
		   	
		   	default:
		   		Error01();
		}//fim controle op��es inicias
		
	}while(opMenuInicial != 0);//fim loop principal
}//fim da integra��o do sistema

void ptBR(){//inicio defini��o de idioma
	setlocale(LC_ALL, "Portuguese_Brazil");//Defini��o do idioma do sistema.
}//fim defini��o de idioma

int Login(){//inicio login
	int op = 0;//Vari�veis de controle de sub-rotinas
	char auxLogin[25], auxSenha[20];//Vari�veis auxiliares
	
	printf(":~:~:~:~:~|Tela de Login|~:~:~:~:~:\n"
		   "Digite 0 nos dois campos para sair\n\n");
	
	printf("Login: ");
	fflush(stdin);
	gets(auxLogin);
	
	printf("Senha: ");
	fflush(stdin);
	gets(auxSenha);
	
	system("cls");
	
	if((strcmp(auxLogin, "0") == 0) && (strcmp(auxSenha, "0") == 0)){//define logout
		op = 1;
	}
	
	if((strcmp(auxLogin, ADM.login) == 0) && (strcmp(auxSenha, ADM.senha) == 0)){//define log de adm
		op = 2;
	}
	
	return op;//retornando valida��o
}//fim login

void CadastrarFunc(){//inicio cadastrar funcionario
	int idVal = 0, val = 0;
	int i;
	
	if(iFunc < 5){//limitador de qtd. funcionarios
		puts(":~:~:~:~:~|Cadastramento de Funcin�rio|~:~:~:~:~:\n");
		
		printf("Nome: ");
		fflush(stdin);
		gets(Func[iFunc].nome);
		
		system("cls");
		
		Func[iFunc].matricula = iMatF;
		iMatF++;
		
		do{
			puts(":~:~:~:~:~|Cadastro de Id do Funcion�rio|~:~:~:~:~:\n");
			
			printf("Login: ");
			fflush(stdin);
			gets(Func[iFunc].Id.login);
			
			printf("Senha: ");
			fflush(stdin);
			gets(Func[iFunc].Id.senha);
			
			system("cls");
			
			for(i=0; i<5; i++){
				if(i != iFunc){
					if(strcmp(Func[iFunc].Id.login, ADM.login) == 1){
						if(strcmp(Func[iFunc].Id.login, Func[i].Id.login) == 1){
							idVal = 1;
							val = 1;
						}
					}
				}
			}
			
			if(!val){
				Error04();
			}
		}while(idVal != 1);
		
		printf(":~:~:~:~:~|Cadastrado com sucesso!|~:~:~:~:~:\n\n"//exibi��o de dados cadastrados
			   "Nome: %s\n"
			   "Matricula: %i\n"
			   "Login: %s\n"
			   "Senha: %s\n\n",
			   Func[iFunc].nome,
			   Func[iFunc].matricula,
			   Func[iFunc].Id.login,
			   Func[iFunc].Id.senha);
		
		system("pause");
		system("cls");
	}else{
		Error03();
	}
	
	iFunc++;
}//fim cadastrar funcionario

void CadastrarLiv(){//inicio cadastrar livro
	int idVal = 0, val = 0, temCurso = 0;
	int i;
	
	for(i=0; i<5; i++){//verificador de existencia de curso
		if(strcmp(Cur[i].nome, "NULL") == 1){
			temCurso = 1;
		}
	}
	
	if(temCurso == 1){
		int aux;
		
		if(iLiv < 5){//limitador de qtd. livros
			puts(":~:~:~:~:~|Cadastramento de Livro|~:~:~:~:~:\n");
		
			printf("Nome: ");
			fflush(stdin);
			gets(Liv[iLiv].nome);
			
			system("cls");
			
			do{
				puts(":~:~:~:~:~|Cadastro de ISBN do Livro|~:~:~:~:~:\n");
				
				printf("C�digo: ");
				fflush(stdin);
				gets(Liv[iLiv].isbn);
				
				system("cls");
				
				for(i=0; i<5; i++){//verifica se j� tem algum livro com o cod, para n�o se repetir
					if(i != iLiv){
						if(strcmp(Liv[iLiv].isbn, Liv[i].isbn) == 1){
							idVal = 1;
							val = 1;
						}
					}
				}
				
				if(!val){
					Error04();
				}
			}while(idVal != 1);
			
			do{
				puts(":~:~:~:~:~|Cadastramento de Livro|~:~:~:~:~:\n");
				
				puts("Curso Assossiado:\n");
				for(i=0; i<5; i++){
					if(strcmp(Cur[i].nome, "NULL") == 1){
						printf("[%i] - %s\n", i+1, Cur[i].nome);
					}
				}
				
				printf("\nEscolha: ");
				scanf("%i", & aux);
				
				strcpy(Liv[iLiv].Curso.nome, (aux == 1) ? Cur[0].nome :
											 (aux == 2) ? Cur[1].nome :
											 (aux == 3) ? Cur[2].nome :
											 (aux == 4) ? Cur[3].nome :
											 (aux == 5) ? Cur[4].nome : "");
				
				strcpy(Liv[iLiv].Curso.area, (aux == 1) ? Cur[0].area :
											 (aux == 2) ? Cur[1].area :
											 (aux == 3) ? Cur[2].area :
											 (aux == 4) ? Cur[3].area :
											 (aux == 5) ? Cur[4].area : "");
				
				system("cls");
				
				if((strcmp(Liv[iLiv].Curso.nome, "") == 0) || (strcmp(Liv[iLiv].Curso.area, "") == 0)){
					Error01();
				}
			}while((strcmp(Liv[iLiv].Curso.nome, "") == 0) || (strcmp(Liv[iLiv].Curso.area, "") == 0));
			
			system("cls");
			
			printf(":~:~:~:~:~|Cadastrado com sucesso!|~:~:~:~:~:\n\n"//exibi��o dps dados cadastrados
				   "Nome: %s\n"
				   "ISBN: %s\n"
				   "Curso: %s\n"
				   "�rea: %s\n\n",
				   Liv[iLiv].nome,
				   Liv[iLiv].isbn,
				   Liv[iLiv].Curso.nome,
				   Liv[iLiv].Curso.area);
			
			strcpy(Liv[iLiv].status, "dispon�vel");
			
			system("pause");
			system("cls");
		}else{
			Error03();
		}
	}else{
		Error05();
	}
	
	iLiv++;
}//fim cadastrar livro

void CadastrarCur(){//inicio cadastrar curso
	if(iCur < 5){//limitador de qtd. cursos
		puts(":~:~:~:~:~|Cadastramento de Curso|~:~:~:~:~:\n");
		
		printf("Nome: ");
		fflush(stdin);
		gets(Cur[iCur].nome);
		
		printf("�rea: ");
		fflush(stdin);
		gets(Cur[iCur].area);
		
		system("cls");
		
		printf(":~:~:~:~:~|Cadastrado com sucesso!|~:~:~:~:~:\n\n"
			   "Nome: %s\n"
			   "�rea: %s\n\n",
			   Cur[iCur].nome,
			   Cur[iCur].area);
		
		system("pause");
		system("cls");
	}else{
		Error03();
	}
	
	iCur++;
}//fim cadastrar curso

void CadastrarAln(){//inicio cadastar aluno
	int idVal = 0, val = 0;
	int i;
	
	if(iAln < 5){//limitador de qtd. alunos
		puts(":~:~:~:~:~|Cadastramento de Aluno|~:~:~:~:~:\n");
		
		printf("Nome: ");
		fflush(stdin);
		gets(Aln[iAln].nome);
		
		Aln[iAln].matricula = iMatA;
		iMatA++;
		
		printf("Curso: ");
		fflush(stdin);
		gets(Aln[iAln].curso);
		
		system("cls");
		
		printf(":~:~:~:~:~|Cadastrado com sucesso!|~:~:~:~:~:\n\n"
			   "Nome: %s\n"
			   "Matricula: %i\n"
			   "Curso: %s\n\n",
			   Aln[iAln].nome,
			   Aln[iAln].matricula,
			   Aln[iAln].curso);
		
		Aln[iAln].QtdEmp = 0;
		system("pause");
		system("cls");
	}else{
		Error03();
	}
	
	iAln++;
}//fim cadastrar aluno

void EmprestimoLiv(){//inicio emprestimo
	int auxMat, i, p, auxEmp;
	int val = 0, e = 1, idVal = 0, LivsDisp = 0;
	
	for(i=0; i<5; i++){//verifica se a livros livres
		if(strcmp(Liv[i].status, "dispon�vel") == 0){
			LivsDisp = 1;
		}
	}
	
	if(LivsDisp > 0){
		puts(":~:~:~:~:~|Empr�stismo de Livros|~:~:~:~:~:\n");
		
		printf("Matricula do aluno: ");
		scanf("%i", & auxMat);
		
		system("cls");
		
		for(i=0; i<5; i++){
			if(Aln[i].matricula == auxMat){
				val = 1;
				p = i;
			}
		}
		
		if(!val){
			Error06();
		}else{
			if(Aln[p].QtdEmp <= 3){
				do{
					puts(":~:~:~:~:~|Empr�stismo de Livros|~:~:~:~:~:\n");
					
					puts("Livros dispon�veis:\n");
					for(i=0; i<5; i++){//lista livros disponiveis
						if((strcmp(Liv[i].status, "dispon�vel") == 0) && (strcmp(Liv[i].status, "NULL") == 1)){
							printf("[%i] - %s\n", e, Liv[i].nome);
							Liv[i].nPosicao = e;
							e++;
						}
					}
					
					e = 1;
					
					printf("\nEscolha: ");
					scanf("%i", & auxEmp);
					
					system("cls");
					
					for(i=0; i<5; i++){// verifica se op de livro existe e, se sim, empresta o respectivo
						if(Liv[i].nPosicao == auxEmp){
							strcpy(Liv[i].status, "emprestado");
							Aln[p].LivEmp[iEmps[p]] == Liv[i].nome;
							iEmps[p]++;
							
							idVal = 1;
							
							printf(":~:~:~:~:~|Empr�stismo realizado com sucesso!|~:~:~:~:~:\n\n"
								   "Emprestado pelo(a) aluno(a): %s\n"
								   "Matricula: %i\n"
								   "Curso: %s\n"
								   "Livro emprestado: %s\n"
								   "ISBN: %s\n"
								   "Curso: %s\n"
								   "�rea: %s\n\n",
								   Aln[p].nome,
								   Aln[p].matricula,
								   Aln[p].curso,
								   Liv[i].nome,
								   Liv[i].isbn,
								   Liv[i].Curso.nome,
								   Liv[i].Curso.area);
							
							system("pause");
							system("cls");
						}
					}
					
					if(!idVal){
						Error01();
					}
					
					system("cls");
				}while(idVal != 1);
			}else{
				Error07();
			}
		}
	}else{
		Error08();
	}
}//fim emprestimo

void DevolucaoLiv(){
	int i, p, auxDev, n;
	int LivsEmp = 0, val = 0, e = 1, idVal = 0;
	char nPesq[25];
	
	for(i=0; i<5; i++){//verifica se a livros emprestados
		if(strcmp(Liv[i].status, "emprestado") == 0){
			LivsEmp = 1;
		}
	}
	
	if(LivsEmp > 0){
		puts(":~:~:~:~:~|Devolu��o de Livros|~:~:~:~:~:\n");
		
		printf("Nome do aluno: ");
		fflush(stdin);
		gets(nPesq);
		
		system("cls");
		
		for(i=0; i<5; i++){
			if(strcmp(Aln[i].nome, nPesq) == 0){
				val = 1;
				p = i;
			}
		}
		
		if(!val){
			Error06();
		}else{
			do{
				puts(":~:~:~:~:~|Devolu��o de Livros|~:~:~:~:~:\n");
				
				printf("Livros emprestados por %s:\n\n", Aln[p].nome);
				for(i=0; i<5; i++){//lista livros emprestados
					if(strcmp(Liv[i].status, "emprestado") == 0){
						for(n=0; n<3; n++){
							if(strcmp(Liv[i].nome, Aln[p].LivEmp[n]) == 0){
								printf("[%i] - %s\n", e, Liv[i].nome);
								Liv[i].nPosicao = e;
								e++;
								iEmps[p]++;
							}
						}
					}
				}
				
				e = 1;
				
				printf("\nEscolha: ");
				scanf("%i", & auxDev);
				
				system("cls");
				
				for(i=0; i<5; i++){// verifica se op de livro foi emprestado, se sim, devolve o respectivo
					if(Liv[i].nPosicao == auxDev){
						strcpy(Liv[i].status, "dispon�vel");
						iEmps[p]--;
						idVal = 1;
						
						printf(":~:~:~:~:~|Devolu��o realizada com sucesso!|~:~:~:~:~:\n\n"
							   "Devolvido por: %s\n"
							   "Matricula: %i\n"
							   "Curso: %s\n"
							   "Livro devolvido: %s\n"
							   "ISBN: %s\n"
							   "Curso: %s\n"
							   "�rea: %s\n\n",
							   Aln[p].nome,
							   Aln[p].matricula,
							   Aln[p].curso,
							   Liv[i].nome,
							   Liv[i].isbn,
							   Liv[i].Curso.nome,
							   Liv[i].Curso.area);
						
						system("pause");
						system("cls");
					}
				}
				
				if(!idVal){
					Error01();
				}
				
				system("cls");
			}while(idVal != 1);
		}
	}else{
		Error09();
	}
}

//TRATAMENTO DE ERROS
void Error01(){//inicio error 01
	printf(":~:~:~:~:~|Error encontrado|~:~:~:~:~:\n"
		   "ERROR 01: Op��o inv�lida.\n\n");
	
	fflush(stdin);
	system("pause");
	system("cls");
}//fim error 01

void Error02(){//inicio error 02
	printf(":~:~:~:~:~|Error encontrado|~:~:~:~:~:\n"
		   "ERROR 02: Login ou senha est�o incorretos.\n\n");
	
	system("pause");
	system("cls");
}//fim error 02

void Error03(){//inicio error 03
	printf(":~:~:~:~:~|Error encontrado|~:~:~:~:~:\n"
		   "ERROR 03: Capacidade max. j� cadastrada.\n\n");
	
	system("pause");
	system("cls");
}//fim error 03

void Error04(){//inicio error 04
	printf(":~:~:~:~:~|Error encontrado|~:~:~:~:~:\n"
		   "ERROR 04: Indentifica��o inv�lida.\n"
		   "Poss�vel causa: id j� sendo usado.\n"
		   "\t\tou id n�o � permitido.\n\n");
	
	fflush(stdin);
	system("pause");
	system("cls");
}//fim error 04

void Error05(){//inicio error 05
	printf(":~:~:~:~:~|Error encontrado|~:~:~:~:~:\n"
		   "ERROR 05: indispon�vel cadastro de livros.\n"
		   "Poss�vel solu��o: Cadastre no min. 1 curso.\n\n");
	
	system("pause");
	system("cls");
}//fim error 05

void Error06(){//inicio error 06
	printf(":~:~:~:~:~|Error encontrado|~:~:~:~:~:\n"
		   "ERROR 06: Aluno n�o matriculado.\n"
		   "Poss�vel solu��o: Tente matr�cula-lo.\n\n");
	
	system("pause");
	system("cls");
}//fim error 06

void Error07(){//inicio error 07
	printf(":~:~:~:~:~|Error encontrado|~:~:~:~:~:\n"
		   "ERROR 07: Capacidade max. j� emprestada p/aluno.\n\n");
	
	system("pause");
	system("cls");
}//fim error 07

void Error08(){//inicio error 08
	printf(":~:~:~:~:~|Error encontrado|~:~:~:~:~:\n"
		   "ERROR 08: N�o h� livros dispon�veis para empr�stimo.\n\n");
	
	system("pause");
	system("cls");
}//fim error 08

void Error09(){//inicio error 09
	printf(":~:~:~:~:~|Error encontrado|~:~:~:~:~:\n"
		   "ERROR 09: N�o h� livros que foram emprestados.\n\n");
	
	system("pause");
	system("cls");
}//fim error 09

