/*
Clinica medica
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define HORA 7  // incicio da contagem da horas 
#define TAM_HORA 8 // quantidade de horas disponifel no dia
// Registro 
typedef struct Especialidade{
	char nome[25];
	int codigo;
} Especialidade;

typedef struct Usuario{
	char login[20];
	char senha[20];
}Usuario;

typedef struct Medico{
	char crm[8];
	char nome[30];
	Especialidade especialidade;
	Usuario usuario;
}Medico;

typedef struct Funcionario{
	int matricula;
	char nome[30];
	Usuario usuario;
}Funcionario;

typedef struct Paciente{
	char cpf[15];
	char nome[30];
	char telefone[15];
	Usuario usuario;
}Paciente;

typedef struct Consulta{
	char profissional[25];
	int hora;
}Consulta;

typedef struct DataHora{
	int hora;
	char status[15];
}DataHora;

//Declarações 
void LoginSistema(Funcionario fun[],Paciente pac[], Especialidade espe[], Medico med[],Consulta con[], int tam);
void MenuAdm(Funcionario func[], Paciente paci[], Especialidade espe[], Medico med[],Consulta con[], int tam);
Funcionario PesquisarFuncionario(Funcionario func[], int tam);
void CadastraFuncionario(Funcionario funcionario[], int tam);
void MenuFuncionario(Funcionario func[], Paciente paci[], Especialidade espe[], Medico med[],Consulta con[], int tam);
void CadastraPaciente(Paciente paciente[], int tam);
Usuario LoginIn();
void CadastraMedico(Medico medico[],Especialidade espe[], int tam);
void CadastraEspecialidade(Especialidade espe[], int tam);
void PesquisarTodos(Funcionario fun[],Paciente pac[], Especialidade espe[], Medico med[],Consulta con[], int tam);
void ExibirPaciente(Paciente paci);
void ExibirMedico(Medico med);
void ExibirEspecialidade(Especialidade espe);
void AlterarTodos(Funcionario fun[],Paciente pac[], Especialidade espe[], Medico med[],Consulta con[], int tam);
Funcionario AlterarF(Funcionario fun);
Paciente AlterarP(Paciente pac);
Medico AlterarM(Medico med, Especialidade espe[], int tam);
void DeletarTodos(Funcionario fun[],Paciente pac[], Especialidade espe[], Medico med[],Consulta con[], int tam);
void MenuPaciente(Funcionario func[], Paciente paci[], Especialidade espe[], Medico med[],Consulta con[], int tam);
void AgendarConsulta(Paciente pac[], Medico med[],Especialidade espe[], Consulta con[], DataHora *pdt, int tam);
void CadastraDataHora(DataHora dthora[]);



int main (void){
	setlocale(LC_ALL, "portuguese");
	int tam = 2;
	
	Funcionario fun[tam];
	Paciente pac[tam];
	Especialidade espe[tam];
	Medico med[tam];
	Consulta con[tam];
	
	LoginSistema(fun,pac,espe,med,con, tam);
	return 0;
}// fim da main

// funcões e procedimentos 
void MenuAdm(Funcionario func[], Paciente paci[], Especialidade espe[], Medico med[],Consulta con[], int tam ){// menu do adminstrato do sistema
	int op;
	
	do {
		printf("1 - Cadastra Funcionario \n");
		printf("2 - Cadastra Paciente \n");
		printf("3 - Cadastra Especialidade \n");
		printf("4 - Cadastra Médico \n");
		printf("5 - Pesquisar \n");
		printf("6 - Alterar \n");
		printf("7 - Deletar \n");
		printf("8 - Voltar \n");
		printf("0 - Sair \n");
		printf("Escolhar: ");
		scanf("%i",&op);
		switch(op){
			case 1:
				CadastraFuncionario(func, tam);
				break;
			case 2:
				CadastraPaciente(paci, tam);
				break;
			case 3:
				CadastraEspecialidade(espe, tam);
				break;
			case 4:
				CadastraMedico(med, espe, tam);
				break;
			case 5:
				PesquisarTodos(func, paci,espe,med,con, tam);
				break;
			case 6:
				AlterarTodos(func, paci,espe,med,con, tam);
				break;
			case 7:
				DeletarTodos(func, paci,espe,med,con, tam);
				break;
			case 8:
				LoginSistema(func, paci,espe,med,con, tam);
				break;	
			case 0:
				exit(0);
				break;
			default:
				printf("Opção não existente \n");								
		}
		
	}while(op != 0);
}// fim do menu adminstrativo

void MenuFuncionario(Funcionario func[], Paciente paci[], Especialidade espe[], Medico med[],Consulta con[], int tam){ // menu do funcionario
	int op;
	
	do {
	
		printf("1 - Cadastra Paciente \n");
		printf("2 - Voltar \n");	
		printf("0 - Sair \n");
		printf("Escolhar: ");
		scanf("%i",&op);
		switch(op){
			case 1:
				CadastraPaciente(paci, tam);
				break;
			case 2:
				LoginSistema(func, paci,espe, med,con, tam);
				break;
			case 0:
				exit(0);
				break;
			default:
				printf("Opção não existente \n");								
		}
		
	}while(op != 0);
}// fim do menu funcionario

void MenuPaciente(Funcionario func[], Paciente paci[], Especialidade espe[], Medico med[],Consulta con[], int tam){
	int op;
	
	DataHora dt[TAM_HORA]; // aqui chamado o registro e tanto o tamanho 
	CadastraDataHora(dt); // aqui cadastrado os horarios 
	do {
	
		printf("1 - Agendar consulta \n");
		printf("2 - Voltar \n");	
		printf("0 - Sair \n");
		printf("Escolhar: ");
		scanf("%i",&op);
		switch(op){
			case 1:
				AgendarConsulta(paci,med,espe, con,dt ,tam);
				break;
			case 2:
				LoginSistema(func, paci,espe, med,con, tam);
				break;
			case 0:
				exit(0);
				break;
			default:
				printf("Opção não existente \n");								
		}
		
	}while(op != 0);
}// fim do menu paciente

Usuario LoginIn(){// funçao para login 
	Usuario us;
	printf("Digite Login \n");
	fflush(stdin);
	gets(us.login);
	printf("Digite Senha \n");
	fflush(stdin);
	gets(us.senha);
	
	return us;
}//fim da função login entrar

void LoginSistema(Funcionario fun[],Paciente pac[], Especialidade espe[], Medico med[],Consulta con[], int tam){ // aqui entra no sistema com login 
	
	char login[20];
	char senha[20];
	//LoginIn();
	Usuario usu = LoginIn();
	int i, achei = 0;
	Usuario us = {"admin", "admin"};

	if (strcmp(usu.login, us.login)== 0 &&  strcmp(usu.senha, us.senha)== 0 ){
		MenuAdm(fun, pac, espe, med,con, tam);
		achei = 1;
	}
	for (i = 0; i < tam;i++){
	if(strcmp(usu.login, fun[i].usuario.login)== 0 &&  strcmp(usu.senha, fun[i].usuario.senha)== 0 ){
			MenuFuncionario(fun, pac, espe, med,con, tam);
			achei = 1;
			}
		}
	for (i = 0; i < tam;i++){
	if(strcmp(usu.login, pac[i].usuario.login)== 0 &&  strcmp(usu.senha, pac[i].usuario.senha)== 0 ){
			MenuPaciente(fun, pac, espe, med,con, tam);
			achei = 1;
			}
		}
	for (i = 0; i < tam;i++){
	if(strcmp(usu.login, med[i].usuario.login)== 0 &&  strcmp(usu.senha, med[i].usuario.senha)== 0 ){
			printf("Quantidade de pacientes\n");
			LoginIn();
			achei = 1;
			}
		}	
	if(!achei){
		printf("Login ou Senha invalidar ! \n");
	}
}// fim do login no sistema 

void CadastraFuncionario(Funcionario funcionario[], int tam){
	int i;
	for(i = 0; i < tam;i++){
		printf("Digite a mátricula \n");
		fflush(stdin);
		scanf("%i",&funcionario[i].matricula);
		printf("Digite nome \n");
		fflush(stdin);
		gets(funcionario[i].nome);
		printf("Digite login \n");
		fflush(stdin);
		gets(funcionario[i].usuario.login);
		printf("Digite senha \n");
		fflush(stdin);
		gets(funcionario[i].usuario.senha);
	}
	
}// fim do cadastra funcionario

void CadastraPaciente(Paciente paciente[], int tam){
	int i;
	for(i = 0; i < tam;i++){
		printf("Digite a nome \n");
		fflush(stdin);
		gets(paciente[i].nome);
		printf("Digite CPF \n");
		fflush(stdin);
		gets(paciente[i].cpf);
		printf("Digite telefone \n");
		fflush(stdin);
		gets(paciente[i].telefone);
		printf("Digite login \n");
		fflush(stdin);
		gets(paciente[i].usuario.login);
		printf("Digite senha \n");
		fflush(stdin);
		gets(paciente[i].usuario.senha);
	}
	
}// fim do cadastra paciente

void CadastraEspecialidade(Especialidade espe[], int tam){
	int i;
	for (i = 0; i < tam;i++){
		printf("Digite código \n");
		fflush(stdin);
		scanf("%i",&espe[i].codigo);
		printf("Digite o nome \n");
		fflush(stdin);
		gets(espe[i].nome);
	}
	
}// fim do cadastra especialidade 

void CadastraMedico(Medico medico[],Especialidade espe[], int tam){
	int i,j, op;
	for(i = 0;i < tam;i++){
		printf("Digite nome \n");
		fflush(stdin);
		gets(medico[i].nome);
		printf("Selecione a especialidade: \n");
		for(j = 0; j < tam;j++){
			printf("[%i] - %s",j,espe[j].nome);
		}
		printf("Digite a opção: ");
		fflush(stdin);
		scanf("%i",&op);
		for(j = 0;j < tam;j++){ // lista as especialidades
			if(op == j){
				medico[i].especialidade.codigo = espe[j].codigo;
				strcpy(medico[i].especialidade.nome, espe[j].nome);
			}
		}
		printf("Digite o CRM \n");
		fflush(stdin);
		gets(medico[i].crm);
		printf("Digite login \n");
		fflush(stdin);
		gets(medico[i].usuario.login);
		printf("Digite senha \n");
		fflush(stdin);
		gets(medico[i].usuario.senha);
	}
}// fim do cadastra medico

void CadastraDataHora(DataHora dthora[]){ // aqui cadastra o horarios para lista por paciente 
int i, hora = HORA, tam = TAM_HORA; // definido no inicio os  HORA e TAM_HORA 
	 for (i = 0; i <= tam; i++){
        hora++;
        if(hora != 12){
            dthora[i].hora = hora; // atribuido com conforme a if 
            strcpy(dthora[i].status, "vargo");// atribuido vom vargo
        }else{
            dthora[i].hora = hora;
            strcpy(dthora[i].status, "Almoço");
        }

    }
	
}// fim do cadastra data e hora

void ExibirFuncionario(Funcionario func){
	printf("----------------------------\n");
	printf("Nome: %s \n",func.nome);
	printf("matricula: %i \n",func.matricula);
	printf("Login: %s \n Senha: %s \n",func.usuario.login, func.usuario.senha);
	printf("----------------------------\n");
}//fim do exibir funcionario

void ExibirPaciente(Paciente paci){
	printf("----------------------------\n");
	printf("Nome: %s \n",paci.nome);
	printf("CPF: %s \n",paci.cpf);
	printf("telefone: %s \n",paci.telefone);
	printf("Login: %s \n Senha: %s \n",paci.usuario.login, paci.usuario.senha);
	printf("----------------------------\n");

	
}// fim do exibir paciente

void ExibirMedico(Medico med){
	printf("----------------------------\n");
	printf("Nome: %s \n",med.nome);
	printf("Especialidade: %s \n",med.especialidade.nome);
	printf("CRM: %s \n",med.crm);
	printf("Login: %s \n Senha: %s \n",med.usuario.login, med.usuario.senha);
	printf("----------------------------\n");

}// fim do exibir medico

void ExibirEspecialidade(Especialidade espe){
	printf("-----------------------------------\n");
	printf("Código: %i \n",espe.codigo);
	printf("Nome: %s \n",espe.nome);
	printf("-----------------------------------\n");
}// fim do exibir especialidade

Funcionario PesquisarFuncionario(Funcionario func[], int tam){
	int i,codigo;
	printf("Digite a mátricula \n");
	fflush(stdin);
	scanf("%i",&codigo);
		for (i = 0;i < tam;i++){
		if(codigo == func[i].matricula){
			return func[i];
			}
		}
		
}// fim do pesquisar funcionario


void PesquisarTodos(Funcionario fun[],Paciente pac[], Especialidade espe[], Medico med[],Consulta con[], int tam){
	int i,op, auxM, achei = 0 ;
	Funcionario aux_F;
	Paciente aux_P;
	Medico aux_M;
	Especialidade aux_E;
	char auxN[25];
	
	do{
	printf("1 - Funcionario \n");
	printf("2 - Paciente \n");
	printf("3 - Médico \n");
	printf("4 - Especialidade \n");
	printf("5 - Voltar \n");
	printf("0 - Sair \n");
	printf("Escolhar: ");
	scanf("%i",&op);
	switch(op){
		case 1:
			printf("Digite matricula funcionário \n");
			fflush(stdin);
			scanf("%i",&auxM);
				for(i = 0; i < tam; i++){
					if(auxM == fun[i].matricula){
					
					 aux_F = fun[i];
					 ExibirFuncionario(aux_F);
					 achei = 1;
					}
				}			
				if(!achei){
						printf("Não cadastrado \n");
					}
			break;
		case 2:
			printf("Digite o nome ou CPF do paciente \n");
			fflush(stdin);
			gets(auxN);
				for (i = 0; i < tam;i++){
					if(strcmp(auxN, pac[i].nome)==0 || strcmp(auxN, pac[i].cpf)==0){
						aux_P = pac[i];
						ExibirPaciente(aux_P);
				 achei = 1;
					}
				}			
				if(!achei){
						printf("Não cadastrado \n");
					}
			break;
		case 3:
			printf("Digite o nome ou CRM do médico \n");
			fflush(stdin);
			gets(auxN);
				for (i = 0; i < tam;i++){
					if(strcmp(auxN, med[i].nome)==0 || strcmp(auxN, med[i].crm)==0){
						aux_M = med[i];
						ExibirMedico(aux_M);
				 achei = 1;
					}
				}			
				if(!achei){
						printf("Não cadastrado \n");
					}
				
			break;
		case 4:
			printf("Digite o código da especialidade \n");
			fflush(stdin);
			scanf("%i",&auxM);
				for(i = 0;i < tam;i++){
					if(auxM == espe[i].codigo){
					aux_E = espe[i];
					ExibirEspecialidade(aux_E);
					 achei = 1;
					}
				}			
				if(!achei){
						printf("Não cadastrado \n");
					}
				
			break;
		case 5:
			LoginSistema(fun, pac,espe, med,con, tam);
			break;	
		case 0:
			exit(0);
			break;
		default:
			printf("Opção não existente \n");			
	}	
	}while(op != 0);
}// fim do pesquisar 

Funcionario AlterarF(Funcionario fun){
	char aux[25];
	int op;
	printf("1 - Alterar nome: \n");
	printf("2 - Alterar login\n");
	printf("3 - Alterar senha\n");
	printf("Escolhar: ");
	scanf("%i",&op);
	switch(op){
		case 1:
			printf("Digite nome: ");
			fflush(stdin);
			gets(aux);
			strcpy(fun.nome, aux);
			return fun;
			break;
		case 2:
			printf("Digite login: ");
			fflush(stdin);
			gets(aux);
			strcpy(fun.usuario.login, aux);
			return fun;
			break;
		case 3:
			printf("Digite senha: ");
			fflush(stdin);
			gets(aux);
			strcpy(fun.usuario.senha, aux);
			return fun;
			break;
		default:
			printf("Opção nã existente \n");			
	}
	
}// alterar funcionario

Paciente AlterarP(Paciente pac){
	char aux[25];
	int op;
	printf("1 - Alterar nome \n");
	printf("2 - Alterar CPF \n");
	printf("3 - Alterar telefone \n");
	printf("4 - Alterar login\n");
	printf("5 - Alterar senha\n");
	printf("Escolhar: ");
	scanf("%i",&op);
	switch(op){
		case 1:
			printf("Digite nome: ");
			fflush(stdin);
			gets(aux);
			strcpy(pac.nome, aux);
			return pac;
			break;
		case 2:
			printf("Digite CPF: ");
			fflush(stdin);
			gets(aux);
			strcpy(pac.cpf, aux);
			return pac;
			break;
		case 3:
			printf("Digite telefone: ");
			fflush(stdin);
			gets(aux);
			strcpy(pac.telefone, aux);
			return pac;
			break;		
		case 4:
			printf("Digite login: ");
			fflush(stdin);
			gets(aux);
			strcpy(pac.usuario.login, aux);
			return pac;
			break;
		case 5:
			printf("Digite senha: ");
			fflush(stdin);
			gets(aux);
			strcpy(pac.usuario.senha, aux);
			return pac;
			break;
		default:
			printf("Opção nã existente \n");			
	}
	
}// fim do altera paciente

Medico AlterarM(Medico med, Especialidade espe[], int tam){
	char aux[25];
	int op,aux_espe,j;
	printf("1 - Alterar nome \n");
	printf("2 - Alterar CRM \n");
	printf("3 - Alterar Especialidade \n");
	printf("4 - Alterar login\n");
	printf("5 - Alterar senha\n");
	printf("Escolhar: ");
	scanf("%i",&op);
	switch(op){
		case 1:
			printf("Digite nome: ");
			fflush(stdin);
			gets(aux);
			strcpy(med.nome, aux);
			return med;
			break;
		case 2:
			printf("Digite CRM: ");
			fflush(stdin);
			gets(aux);
			strcpy(med.crm, aux);
			return med;
			break;
		case 3:
				printf("Selecione a especialidade: \n");
				for(j = 0; j < tam;j++){
				printf("[%i] - %s \n",j,espe[j].nome);
					}
				printf("Digite a opção: ");
				fflush(stdin);
					scanf("%i",&aux_espe);
					for(j = 0;j < tam;j++){ // lista as especialidades
						if(aux_espe == j){
				med.especialidade.codigo = espe[j].codigo;
				strcpy(med.especialidade.nome, espe[j].nome);
				}
					}
			
			return med;
			break;		
		case 4:
			printf("Digite login: ");
			fflush(stdin);
			gets(aux);
			strcpy(med.usuario.login, aux);
			return med;
			break;
		case 5:
			printf("Digite senha: ");
			fflush(stdin);
			gets(aux);
			strcpy(med.usuario.senha, aux);
			return med;
			break;
		default:
			printf("Opção nã existente \n");			
	}
}// fim do alterar medico

Especialidade AlterarE(Especialidade espe){
		char aux[25];
	int op, aux_cod;
	printf("1 - Alterar nome \n");
	printf("2 - Alterar código \n");
	printf("Escolhar: ");
	scanf("%i",&op);
	switch(op){
		case 1:
			printf("Digite nome: ");
			fflush(stdin);
			gets(aux);
			strcpy(espe.nome, aux);
			return espe;
			break;
		case 2:
			printf("Digite código: ");
			fflush(stdin);
			scanf("%i",&aux_cod);
			espe.codigo = aux_cod;
			return espe;
			break;
		default:
			printf("Opção nã existente \n");			
	}
}// fim do altera especialidade 

void AlterarTodos(Funcionario fun[],Paciente pac[], Especialidade espe[], Medico med[],Consulta con[], int tam){
	int i,op, auxM = 0, achei = 0;
	Funcionario aux_F;
	Paciente aux_P;
	Medico aux_M;
	Especialidade aux_E;
	char auxN[25];
	
	do{
	printf("1 - Funcionario \n");
	printf("2 - Paciente \n");
	printf("3 - Médico \n");
	printf("4 - Especialidade \n");
	printf("5 - Voltar \n");
	printf("0 - Sair \n");
	printf("Escolhar: ");
	scanf("%i",&op);
	switch(op){
		case 1:
			printf("Digite matricula funcionário \n");
			fflush(stdin);
			scanf("%i",&auxM);
				for(i = 0; i < tam; i++){
					if(auxM == fun[i].matricula){
						 aux_F = fun[i];
					 
					 fun[i] = AlterarF(aux_F);
					 printf("Alterador com sucesso \n");
					 achei = 1;
					}
				}			
				if(!achei){
						printf("Não cadastrado \n");
					}			
				
			break;
		case 2:
			printf("Digite o nome ou CPF do paciente \n");
			fflush(stdin);
			gets(auxN);
				for (i = 0; i < tam;i++){
					if(strcmp(auxN, pac[i].nome)==0 || strcmp(auxN, pac[i].cpf)==0){
						aux_P = pac[i];
					
						pac[i] = AlterarP(aux_P); // aqui retorno da funçao 
						printf("Alterador com sucesso \n");
					 achei = 1;
					}
				}			
				if(!achei){
						printf("Não cadastrado \n");
					}
				
			break;
		case 3:
			printf("Digite o nome ou CRM do médico \n");
			fflush(stdin);
			gets(auxN);
				for (i = 0; i < tam;i++){
					if(strcmp(auxN, med[i].nome)==0 || strcmp(auxN, med[i].crm)==0){
						aux_M = med[i];
						
						med[i] = AlterarM(aux_M,espe,tam); // aqui retorno da funçao 
						printf("Alterador com sucesso \n");
					 achei = 1;
					}
				}			
				if(!achei){
						printf("Não cadastrado \n");
					}
			
			break;
		case 4:
			printf("Digite o código da especialidade \n");
			fflush(stdin);
			scanf("%i",&auxM);
				for(i = 0;i < tam;i++){
					if(auxM == espe[i].codigo){
						aux_E = espe[i];
					
					espe[i] = AlterarE(aux_E);  // aqui retorno da funçao 
					printf("Alterador com sucesso \n");
					 achei = 1;
					}
				}			
				if(!achei){
						printf("Não cadastrado \n");
					}
			break;
		case 5:
			LoginSistema(fun, pac,espe, med,con, tam);
			break;	
		case 0:
			exit(0);
			break;
		default:
			printf("Opção não existente \n");			
	}	
	}while(op != 0);
}// fim do alterar

void DeletarTodos(Funcionario fun[],Paciente pac[], Especialidade espe[], Medico med[],Consulta con[], int tam){
		int i,op, auxM = 0, achei = 0;
	Funcionario aux_F = {0,"","",""};
	Paciente aux_P = {"","","","",""};
	Medico aux_M = {"","","",0,"",""};
	Especialidade aux_E = {"",0};
	char auxN[25];
	
	do{
	printf("1 - Funcionario \n");
	printf("2 - Paciente \n");
	printf("3 - Médico \n");
	printf("4 - Especialidade \n");
	printf("5 - Voltar \n");
	printf("0 - Sair \n");
	printf("Escolhar: ");
	scanf("%i",&op);
	switch(op){
		case 1:
			printf("Digite matricula funcionário \n");
			fflush(stdin);
			scanf("%i",&auxM);
				for(i = 0; i < tam; i++){
					if(auxM == fun[i].matricula){
						fun[i] = aux_F;
					 	printf("Deletado com sucesso \n");
					 	achei = 1;
					}
				}			
				if(!achei){
						printf("Não cadastrado \n");
					}			
				
			break;
		case 2:
			printf("Digite o nome ou CPF do paciente \n");
			fflush(stdin);
			gets(auxN);
				for (i = 0; i < tam;i++){
					if(strcmp(auxN, pac[i].nome)==0 || strcmp(auxN, pac[i].cpf)==0){
						
						pac[i] = aux_P; 
						printf("Deletado com sucesso \n");
					 achei = 1;
					}
				}			
				if(!achei){
						printf("Não cadastrado \n");
					}
				
			break;
		case 3:
			printf("Digite o nome ou CRM do médico \n");
			fflush(stdin);
			gets(auxN);
				for (i = 0; i < tam;i++){
					if(strcmp(auxN, med[i].nome)==0 || strcmp(auxN, med[i].crm)==0){
						
						med[i] = aux_M; 
						printf("Deletado com sucesso \n");
					 achei = 1;
					}
				}			
				if(!achei){
						printf("Não cadastrado \n");
					}
			
			break;
		case 4:
			printf("Digite o código da especialidade \n");
			fflush(stdin);
			scanf("%i",&auxM);
				for(i = 0;i < tam;i++){
					if(auxM == espe[i].codigo){
							espe[i] = aux_E; 
							printf("Deletado com sucesso \n");
					 achei = 1;
					}
				}			
				if(!achei){
						printf("Não cadastrado \n");
					}
			break;
		case 5:
			LoginSistema(fun, pac,espe, med,con, tam);
			break;	
		case 0:
			exit(0);
			break;
		default:
			printf("Opção não existente \n");			
	}	
	}while(op != 0);
}// fim do deletar todos



void AgendarConsulta(Paciente pac[], Medico med[],Especialidade espe[], Consulta con[], DataHora *pdt, int tam){
	char auxN[25];
	int achei = 0, i,j, op,aux_prof;
	int op_dt,tam_hora = TAM_HORA, hora = HORA;
	Paciente aux_P;
	
	printf("Digite o nome ou CPF do paciente \n"); 
			fflush(stdin);
			gets(auxN); // pegado o cpf que o paciente digito  
				for (i = 0; i < tam;i++){
					if(strcmp(auxN, pac[i].nome)==0 || strcmp(auxN, pac[i].cpf)==0){ // comparação do cpf com ja cadastrado no sistema
						aux_P = pac[i]; // auxlia pegar esse paciente 
						ExibirPaciente(aux_P); // aqui exibir informaçoes dele 
						printf("Opção de lista: \n ");
						printf("1 - Medico \n");
						printf("2 - Especialidade \n");
						printf("Escolhar: ");
						scanf("%i",&op);
						switch(op){
							case 1:
								
								// aqui lista os medico e atribui a escolha do paciente
								for (j = 0; j < tam; j++){
									printf("[%i] - %s \n",j, med[j].nome);// lista medicos
								}
								printf("Digite opção \n");
								fflush(stdin);
								scanf("%i",&aux_prof); // escolha do paciente
								for (j = 0; j < tam; j++){
									if(aux_prof == j){ 
									strcpy(con[i].profissional, med[j].nome);// armazenando a opcção	
									}
								}
								// aqui lista e escolher o horario da consulta
								    for (j = 0; j <= tam_hora; j++){
								        if(pdt->hora != 12 ){
								            printf("[%i]: %ihr Status: %s  \n",j,pdt[j].hora,pdt[j].status); // aqui exibir os horarios
								        
								             }
								    }
								    printf("\nEscolha: ");
								    scanf("%i",&op_dt);//opção escolhida
								    if(op_dt != 12){ // comparação para que não seja o horario do almoço 
								        for(j = 0; j <= tam_hora; j++){ // pecoredo 
								            if(op_dt == j){ // comparação da opçao escolhida se e igual que for listo
								                if(strcmp(pdt[j].status, "ocupado") != 0){ // comparado se não esta ocupado
								                    strcpy(pdt[j].status, "ocupado"); // alterado o status do horario para ocupado
								                    con[i].hora = pdt[j].hora; // atribuido para a consulta o horario 
								                    break;
								                }else{
								                    printf("Ja ocupado\n");
								
								                }
								            }else{
								                printf("Opcao invalido\n");
								            }
								        }
								    }else{
								      printf("Esse horario não esta disponivel \n");
								    }
							
								break;
							case 2:
								for (j = 0;j < tam; j++){
									printf("[%i] - %s \n",j, espe[j].nome);
								}
								printf("Digite opção \n");
								fflush(stdin);
								scanf("%i",&aux_prof);
								for (j = 0; j < tam; j++){
									if(aux_prof == j){
									strcpy(con[i].profissional, espe[j].nome);	
									}
								}
								// aqui lista e escolher o horario da consulta
								    for (j = 0; j <= tam_hora; j++){
								        if(pdt->hora != 12 ){
								            printf("[%i]: %ihr Status: %s  \n",j,pdt[j].hora,pdt[j].status);
								        
								             }
								    }
								    printf("\nEscolha: ");
								    scanf("%i",&op_dt);
								    if(op_dt != 12){
								        for(j = 0; j <= tam_hora; j++){
								            if(op_dt == j){
								                if(strcmp(pdt[j].status, "ocupado") != 0){
								                    strcpy(pdt[j].status, "ocupado");
								                    con[i].hora = pdt[j].hora;
								                    break;
								                }else{
								                    printf("Ja ocupado\n");
								
								                }
								            }else{
								                printf("Opcao invalido\n");
								            }
								        }
								    }else{
								      printf("Esse horario não esta disponivel \n");
								    }
								
								
								break;
							default:
								printf("Opção não existente \n");		
						}
				 		achei = 1;
					}
				}			
				if(!achei){
						printf("Não cadastrado \n");
					}
					
}// fim do agenda consulta
