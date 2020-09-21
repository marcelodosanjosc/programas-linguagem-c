// Sistema de controle de Biblioteca
// Autor Marcelo Caldas 
// Sistema de Informacao sede Matutino 4 periodo
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//declaracao do registros
typedef struct Funcionario{
	char nomeFuncionario[20];
	char login[12];
	char senha[12];
	int matricula;
}Funcionario; // registro funcionario

typedef struct Curso{
	char nomeCurso[20];
	char area[15];
}Curso; // registro curso

typedef struct Livro{
	char nomeLivro[20];
	char ISBN[15];
	char curso[20];
	char status[20];
}Livro; // registro livro

typedef struct Aluno{
	char nomeAluno[20];
	int matricula;
	char curso[20];
	char livroEmpestado[20][3];
}Aluno; // registro aluno

// declaracao das variaveis globas
Funcionario funcionario[2];
Curso curso[2];
Livro livro[2];
Aluno aluno[2];

// declaracao dos procedimento e funcoes
void menuAdm();
void menuFunc();
void CadastraFuncionario();
void CadastraCurso();
void CadastraLivro();
void cadastraAluno();
void fazerLogin();
void pesquisarAluno();
void pesquisarLivro();
void exibirAluno();
void exibirLivro();
void exibirFuncionario();
void realizarEmprestimo();


main(){
	fazerLogin();
	system("pause");
}// fim da main

// criacao 

void menuAdm(){
	int op;
	
	do {
		printf("\t1 - Cadastra Funcionario \n");
		printf("\t2 - Cadastra Livro \n");
		printf("\t3 - Cadastra Curso \n");
		printf("\t4 - Cadastra Aluno \n");
		printf("\t5 - Pesquisar Livro \n");
		printf("\t6 - Pesquisar Aluno \n ");
		printf("\t7 - Emprestimo de Livro \n ");
		printf("\t8 - Devolucao de Livro \n ");
		printf("\t9 - Relatorio \n ");
		printf("\t0 - Sair \n");
		printf("\tEscolhar opcao :\n");
		scanf("%i",&op);
		switch (op){
				case 1:
					CadastraFuncionario();
					break;
				case 2:
					CadastraLivro();
					break;
				case 3:
					CadastraCurso();
					break;
				case 4:
					cadastraAluno();
					break;
				case 5:
					pesquisarLivro();
					break;
				case 6:
					pesquisarAluno();
					break;
				case 7:
					realizarEmprestimo();
					break;
				case 8:
					break;	
				case 9:
					break;		
				case 0:
					fazerLogin();
					break;
				default:
					printf("Opcao nao exitente!\n");							
		}// fim do switch

		
	}while(op != 0);
	
}// fim do procedimento menuAdm

void menuFunc(){
	int op;
	
	do {

		printf("\t1 - Cadastra Aluno \n");
		printf("\t2 - Pesquisar Livro \n");
		printf("\t3 - Pesquisar Aluno \n ");
		printf("\t4 - Emprestimo de Livro \n ");
		printf("\t5 - Devolucao de Livro \n ");
		printf("\t0 - Sair \n");
		printf("\tEscolhar opcao :\n");
		scanf("%i",&op);
		switch (op){
				case 1:
					cadastraAluno();
					break;
				case 2:
					pesquisarLivro();
					break;
				case 3:
					pesquisarAluno();
					break;
				case 4:
					realizarEmprestimo();
					break;
				case 5:
					break;
				case 0:
					fazerLogin();
					break;
				default:
					printf("Opcao nao exitente!\n");							
		}// fim do switch


	}while(op != 0);
}// fim do procedimento menuFunc

void CadastraFuncionario(){
	int f;
	for (f = 0; f < 2; f++ ){
	printf("Digite o nome do funcionario %i: \n",f);
	fflush(stdin);
	gets(funcionario[f].nomeFuncionario);
	printf("forneca a matricula: \n");
	fflush(stdin);
	scanf("%i",&funcionario[f].matricula);
	printf("Digite Login: \n");
	fflush(stdin);
	gets(funcionario[f].login);
	printf("Digite a senha: \n");
	fflush(stdin);
	gets(funcionario[f].senha);
    }
    exibirFuncionario();
}// fim do cadastra funcionario

void CadastraCurso(){
	int c;
	for (c = 0; c< 2;c++){
	printf("Digite o nome do curso %i: \n",c);
	fflush(stdin);
	gets(curso[c].nomeCurso);
	printf("Digite a area: \n");
	fflush(stdin);
	gets(curso[c].area);
		}
}// fim do procedimento cadastra curso

void CadastraLivro(){
	int l, a, i,aux;
	for (l = 0; l < 2;l++){
	printf("Digite o nome do Livro %i: \n",l);
	fflush(stdin);
	gets(livro[l].nomeLivro);
	printf("Digite o ISBN: \n");
	fflush(stdin);
	gets(livro[l].ISBN);
	printf("Associe um Curso: \n");
	for(a = 0; a < 2;a++){
		printf(" %i: %s \n",a, curso[a].nomeCurso);
	}
	printf("Digite o numero do curso: \n");
						fflush(stdin);
						scanf("%i",&aux);
						for (i = 0; i < 2; i++){
						if (aux == i ){
						strcpy(livro[l].curso, curso[i].nomeCurso);
						}
					}
	
	}
	exibirLivro();
}// fim do cadastra livro

void cadastraAluno(){
	int a, c, aux,i, achei = 0;
	for (a = 0;a < 2;a++){
	printf("Digite o nome do aluno %i:  \n",a);
	fflush(stdin);
	gets(aluno[a].nomeAluno);
	printf("Digite a matricula: \n");
	fflush(stdin);
	scanf("%i",&aluno[a].matricula);
	if (curso != NULL ){
	
		for (c = 0; c < 2; c++){
						printf("Cursos: \n");
						printf("%i - %s \n",c,curso[c].nomeCurso);
							
					}
						printf("Digite o numero do curso: \n");
						fflush(stdin);
						scanf("%i",&aux);
						for (i = 0; i < 2; i++){
						if (aux == i ){
						strcpy(aluno[a].curso, curso[i].nomeCurso);
						}
					}
		achei = 1;		
		}
		if (!achei){
			printf("Nao a cursos \n");
		}

	}
	exibirAluno();
}// fim do cadastro de aluno

void fazerLogin(){
	char admin[8] = "admin";
	char passe[8] = "admin";
	char login[8];
	char senha[8];
	int op,i = 0, achei = 0;
	// teste 
	char funcilogin[10] = "Marcelo";
	char funcisenha[10] = "228855";
	do {
			system("cls");
			printf("\t1 - Fazer Login \n");
			printf("\t0 - Sair \n");
			fflush(stdin);
			scanf("%i",&op);	
			switch(op){
			case 1:
			printf("\tLogin: ");
			fflush(stdin);
			gets(login);
			printf("\tSenha: ");
			fflush(stdin);
			gets(senha);
			
			if (!strcmp(login, admin )&& !strcmp(senha, passe)){
				printf("Acesso administrador com sucesso !\n");
				menuAdm();	
			}else{
				
				while( sizeof(funcionario[i]) ){
					if (!strcmp(login, funcionario[i].login)&&!strcmp(senha, funcionario[i].senha)){	
						printf("Acesso funcionario com sucesso !\n");
							
						menuFunc();	
						achei = 1;
					}
					i++;	
				}
				achei = 0;	
			}
			if(!achei) {
				printf("Acesso negado !\n");
				system("pause");
			}
		
			break;
			case 0:
			 exit(0);
			 break;
			 default:
			 printf("Opcao nao exitente!\n");
			 system("pause");	
			}// fim do switch
			
	}while(op!= 0);
	
}// fim do login

void pesquisarAluno(){
	char aux[20];
	int i, achei = 0;
	printf("Digite o nome da busca: \n");
	fflush(stdin);
	gets(aux);
	for (i = 0; i < 2;i++){
		if(!strcmp(aux, aluno[i].nomeAluno)){
			printf("Nome: %s\n", aluno[i].nomeAluno);
			printf("Matriluca: %i\n", aluno[i].matricula);
			printf("Curso: %s\n", aluno[i].curso);
			achei = 1;
			}
		
	} 
		if(!achei){
				printf("Aluno nao cadastrado! \n");
				system("pause");
			}
}// fim pesquisar aluno

void pesquisarLivro(){
	char aux[20];
	int i, achei = 0;
	printf("Digite o nome da busca: \n");
	fflush(stdin);
	gets(aux);
	for (i = 0; i < 2;i++){
		if(!strcmp(aux, livro[i].nomeLivro)){
			printf("Nome: %s\n", livro[i].nomeLivro);
			printf("Codigo ISBN: %s\n", livro[i].ISBN);
			printf("Curso: %s\n", livro[i].curso);
			achei = 1;
			}
	}
		if(!achei){
				printf("Livro não cadastrado! \n");
				system("pause");
			}
}// fim pesquisar livro

void realizarEmprestimo(){
	int i, livroDisponivel = 0;

	for (i = 0; i < 2;i++){
		if (strcmp(livro[i].status, "disponivel")==0){
			livroDisponivel = 1;
			}
		}
	if(livroDisponivel > 0 ){
	
	printf("\t________Realizar Emprestimo________\n");	
	}
	exibirLivro();	
}// fim do realizar emprestimo


void exibirAluno(){
	int i;
	for (i = 0; i < 2;i++){
	
	printf("\t ___________ Exibir Aluno #%i___________\n ",i+1);
	printf("\t Nome: %s \n", aluno[i].nomeAluno);
	printf("\t Matricula: %d \n", aluno[i].matricula);
	printf("\t Curso: %s \n", aluno[i].curso);
	printf("\t________________________________________\n");
	}
	
}// fim do exibir aluno

void exibirLivro(){
	int i;
	for (i = 0; i < 2;i++){
	
	printf("\t ___________ Exibir Livro #%i___________\n ",i+1);
	printf("\t Nome: %s \n", livro[i].nomeLivro);
	printf("\t Codigo ISBM: %s \n", livro[i].ISBN);
	printf("\t Curso: %s \n", livro[i].curso);
	printf("\t________________________________________\n");
	}
	
}// fim do exibir livro

void exibirFuncionario(){
		int i;
	for (i = 0; i < 2;i++){
	printf("\t ___________ Exibir Livro #%i___________\n ",i+1);
	printf("\t Nome: %s \n", funcionario[i].nomeFuncionario);
	printf("\t Matricula: %i \n", funcionario[i].matricula);
	printf("\t________________________________________\n");
	}
}// fim do exibir funcionario
