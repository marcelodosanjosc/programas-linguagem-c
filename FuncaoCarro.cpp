#include<stdio.h>
#include<stdlib.h>
#include<string.h>



typedef struct Carro{
	char placa[12];
	char marca[10];
	char cor[10];	
}Carro;

void Cadastra(Carro car[],int TA);
Carro Pesquisar(Carro vetcar[],int tm);
void Imprimir(Carro carro);
void Imprimirtodos(Carro vetcar[],int t);
main(){
int op;
Carro	carro[2],car;
	do{
	system("cls");	
	printf("1-Cadastrar\n");
	printf("2-Pesquisar\n");
	printf("3-Imprimir\n");
	printf("0-Sair\n");
	scanf("%i",&op);
	switch(op){
		case 1:
			Cadastra(carro,2);
			break;
		case 2:
			
			//car=Pesquisar(carro,2);
			//Imprimir(car);
			Imprimir(Pesquisar(carro,2));
			break;
		case 3:
			Imprimirtodos(carro,2);		
			break;
		case 0:
			exit(0);
			break;
		default:
		printf("Opcao invalida\n");	
	}
	system("pause");	
	}while(op!=0);
}//fim main


void Cadastra(Carro car[],int TA){
int i;	
	for(i=0;i<TA;i++){
		printf("Placa: ");
		fflush(stdin);
		gets(car[i].placa);
		printf("\nMarca: ");
		fflush(stdin);
		gets(car[i].marca);
		printf("\nCor: ");
		fflush(stdin);
		gets(car[i].cor);
	}
	
}//fim cadastrar

Carro Pesquisar(Carro vetcar[],int tm){
char placapesq[10];
int i;	
	printf("Digite placa pesquisa\n");
	fflush(stdin);
	gets(placapesq);
	
	for(i=0;i<tm;i++){
		if(strcmp(placapesq,vetcar[i].placa)==0){
			return vetcar[i];
		}
	}
	
}//fim pesquisar


void Imprimir(Carro carro){
	printf("Placa:%s ",carro.placa);
	printf("\nMarca:%s ",carro.marca);
	printf("\nCor:%s \n",carro.cor);
		
}


void Imprimirtodos(Carro vetcar[],int t){
int i;
 for(i=0;i<t;i++){
 	printf("Placa:%s",vetcar[i].placa);
 	printf("\nMarca:%s",vetcar[i].marca);
 	printf("\nCor:%s\n\n",vetcar[i].cor);
 		
 }
 	
}//fim 
