/* faç programa que gerencie petshop, cadastre 4 cliente: nome, telefone, cada cliente pode ter
ate 3 animais cadastre os anismais: nome, raça, peso. O sistema terá a opção pesquisar por nome
cliente, caso exista exiba todos os dados do cliente e os anismais dele. o sistema terá crud para cliente
obs: controle o número de cadastro
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define MAX_CLIENTE 4
#define MAX_ANIMAL 3

// registro
typedef struct Animal{
    char nome[20];
    char raca[20];
    float peso;
}Animal;

typedef struct Cliente{
    char nome[25];
    char telefone[15];
    Animal animal[MAX_ANIMAL];
}Cliente;
// declaraçoes
void CadastraCliente(int *contiC, Cliente c[MAX_CLIENTE]);
void Menu();
void ExibirCliente(Cliente c);
void CadastraAnimal(int contiA[], int *contiC, Animal a[],  Cliente c[]);
void ExibirA(Cliente c[]);
void PesquisarCliente(int contiA[],Cliente c[]);


main(){
    setlocale(LC_ALL, "portuguese");
    Menu();
} // fim do main

void Menu(){
int ct_c = 0, ct_a[MAX_ANIMAL] = {0,0,0}, i, op;
Cliente c[MAX_CLIENTE];
Animal a[MAX_ANIMAL];
do {
	printf("1 - Cadastrar cliente \n");
	printf("2 - Cadastrar Animal \n");
	printf("3 - Pesquisar cliente \n");
	printf("4 - Alterar cliente \n");
	printf("5 - Excluir cliente \n");
	printf("0 - Sair \n");
	printf("Escolhar: ");
	scanf("%i",&op);
	switch(op){
	
		case 1:
			CadastraCliente(&ct_c, c);
			break;
		case 2:
			CadastraAnimal(ct_a,&ct_c, a, c);
			break;
		case 3:
			PesquisarCliente(ct_a,c);
			break;
		case 4:
			break;
		case 5:
			break;
		case 0:
			exit(0);
			break;		
		default:
			printf("Opção não existente \n");	
		}
	}while(op != 0);	
}// fim do menu

void CadastraCliente(int *contiC, Cliente c[]){
	Cliente aux;
	int i = *contiC;
	
	if(i < MAX_CLIENTE){
		printf("Digite o nome do cliente \n");
		fflush(stdin);
		gets(c[i].nome);
		printf("Digite o telefone \n");
		fflush(stdin);
		gets(c[i].telefone);
		
		strcpy(aux.nome, c[i].nome);
		strcpy(aux.telefone, c[i].telefone);	
		
		i++;
		*contiC = i;
		
	}
	printf("Cadastrado com sucesso \n");
	ExibirCliente(aux);
	}
		
void CadastraAnimal(int contiA[], int *contiC, Animal a[],  Cliente c[]){
		Animal auxA;
		int j ,i = *contiC, achei = 0;		
		char aux[20];
		
		
		printf("Digite o nome do cliente");
		fflush(stdin);
		gets(aux);
		
				for ( i = 0 ; i< MAX_CLIENTE; i++){
				
					
				if(strcmp(aux, c[i].nome) == 0){
				achei = 1;
				
				if(contiA[i] < MAX_ANIMAL){
				for(j= 0;j < MAX_ANIMAL;j++){

				printf("Digite nome do animal\n");
				fflush(stdin);
				gets(auxA.nome);
				printf("Digite a raça \n");
				fflush(stdin);
				gets(auxA.raca);
				printf("Digite o peso \n");
				fflush(stdin);
				scanf("%f",&auxA.peso);
				
				strcpy(c[i].animal[j].nome, auxA.nome);
				strcpy(c[i].animal[j].raca, auxA.raca);
				c[i].animal[j].peso = auxA.peso;
				
							
				contiA[j]++;
				}
				i++;
	
				*contiC = i;
				ExibirA(c);
				}
				
			}
		}
		if(!achei){
			printf("Cliente não encontrado \n\a");
		}
				
}// fim do cadastra animal

void ExibirCliente(Cliente c){
	
	printf(" ---------------------------------- \n");
	printf("Nome do cliente: %s \n",c.nome);
	printf("Telefone: %s \n",c.telefone);
	
	printf("------------------------------------ \n");
	
}// fim do exibir 

void ExibirA(Cliente c[]){
	int i, j;
	for(i = 0; i < MAX_CLIENTE; i++){
	printf(" ---------------------------------- \n");
	printf("Nome do cliente: %s \n",c[i].nome);
	printf("Telefone: %s \n",c[i].telefone);
	for(j = 0; j < MAX_ANIMAL; j++){
	printf("Nome: %s", c[i].animal[j].nome);
	printf("Raça: %s", c[i].animal[j].raca);
	printf("Peso: %.2f", c[i].animal[j].peso);
	printf("------------------------------------ \n");
   	}
	}
	
}// 

void PesquisarCliente(int contiA[], Cliente c[]){
	char aux[20];
	int i,j;
	printf("Digite nome do cliente \n");
	fflush(stdin);
	gets(aux);
	
	for(i = 0;i < MAX_CLIENTE; i++){
		if(strcmp(aux, c[i].nome)==0){
			printf("Nome: %s \n",c[i].nome);
			
			printf("Telefone: %s \n",c[i].telefone);
				if(contiA[i] > 0){
				for (j = 0; j < MAX_ANIMAL;j++){
							printf("Nome: %s", c[i].animal[j].nome);
							printf("Raça: %s", c[i].animal[j].raca);
							printf("Peso: %.2f", c[i].animal[j].peso);
						
					}
					
				}
			break;	
		}else{
			printf("Não cadastrado \n");
		}
	}
}// 
