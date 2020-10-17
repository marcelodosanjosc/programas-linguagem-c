// ponteiro questao 01
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//declaraçoes 
void menu();
void CadastraNumero(int *pn1, int *pn2, int *pn3);
void PesquisarNumero(int n1, int n2, int n3);
void AlterarNumero(int *pn1, int *pn2, int *pn3);
void ExcluirNumero(int *pn1, int *pn2, int *pn3);

main(){
	setlocale(LC_ALL, "Portuguese");
	menu();
}// fim da main

// procedimentos
void CadastraNumero(int *pn1, int *pn2, int *pn3){
	int aux1 = NULL, aux2 = NULL, aux3 = NULL;
	printf("Digite 1° número \n");
	scanf("%i",&aux1);
	printf("Digite 2° número \n");
	scanf("%i",&aux2);
	printf("Digite 3° número \n");
	scanf("%i",&aux3);
	*pn1 = aux1;
	*pn2 = aux2;
	*pn3 = aux3;
	
}// fim do cadastra numero

void PesquisarNumero(int n1, int n2, int n3){
	int aux;
	printf("Digite o numero para buscar \n");
	scanf("%i",&aux);
	if(aux == n1 && aux != 0){
		system("color 27");
		printf("%i encontrado !\n",n1);
	}else if(aux == n2 && aux != 0){
		system("color 27");
		printf("%i encontrado !\n",n2);
	}else if(aux == n3 && aux != 0){
		system("color 27");
		printf("%i encontrado !\n",n3);
	}else{
		system("color 47");
		printf("número não cadastrado !\n");
	}
	system("pause");
		
}// fim do pesquisar numero

void AlterarNumero(int *pn1, int *pn2, int *pn3){
	int aux,aux1 ;
	printf("Digite o numero para buscar \n");
	scanf("%i",&aux);
	if(aux == *pn1 && aux != 0){
		system("color 27");
		printf("%i encontrado !\n",*pn1);
		printf("Digite um novo número \n");
		scanf("%i",&aux1);
		*pn1 = aux1;
		printf("O novo é: %i !\n",*pn1);
	}else if(aux == *pn2 && aux != 0){
		system("color 27");
		printf("%i encontrado !\n",*pn2);
		printf("Digite um novo número \n");
		scanf("%i",&aux1);
		*pn2 = aux1;
		printf("O novo é: %i !\n",*pn2);
	}else if(aux == *pn3 && aux != 0){
		system("color 27");
		printf("%i encontrado !\n",*pn3);
		printf("Digite um novo número \n");
		scanf("%i",&aux1);
		*pn3 = aux1;
		printf("O novo é: %i !\n",*pn3);
	}else{
		system("color 47");
		printf("número não cadastrado !\n");
	}
	system("pause");
		
}// fim do pesquisar numero

void ExcluirNumero(int *pn1, int *pn2, int *pn3){
	int aux,aux1 = NULL, sim;
	printf("Digite o numero para buscar \n");
	scanf("%i",&aux);
	if(aux == *pn1 && aux != 0){
		system("color 27");
		printf("%i encontrado !\n",*pn1);
		printf("Realmente deseja excluir ? sim (1) não (0) ");
		scanf("%i",&sim);
		if (sim == 1){
			*pn1 = aux1;
			printf("Excluido com sucesso !");
		}
	}else if(aux == *pn2 && aux != 0){
		system("color 27");
		printf("%i encontrado !\n",*pn2);
		printf("Realmente deseja excluir ? sim (1) não (0) ");
		scanf("%i",&sim);
		if (sim == 1){
			*pn2 = aux1;
			printf("Excluido com sucesso !");
		}
	}else if(aux == *pn3 && aux != 0){
		system("color 27");
		printf("%i encontrado !\n",*pn3);
	printf("Realmente deseja excluir ? sim (1) não (0) ");
		scanf("%i",&sim);
		if (sim == 1){
			*pn3 = aux1;
			printf("Excluido com sucesso !");
		}
	}else{
		system("color 47");
		printf("número não cadastrado !\n");
	}
	system("pause");
		
}// fim do pesquisar nume

void menu(){
	int n1 = NULL,n2 = NULL,n3 = NULL, op;
	
	do{
		system("cls");
		system("color 00");
		printf("1 - Cadastrar \n");
		printf("2 - Pesquisar \n");
		printf("3 - Alterar \n");
		printf("4 - Excluir \n");
		printf("0 - Sair \n");
		printf("Escolhar: ");
		scanf("%i",&op);
		switch(op){
			case 1:
				CadastraNumero(&n1, &n2, &n3);
				break;
			case 2:
				PesquisarNumero(n1,n2,n3);
				break;
			case 3:
				AlterarNumero(&n1,&n2,&n3);
				break;
			case 4:
				ExcluirNumero(&n1,&n2,&n3);
				break;
			case 0:
				exit(0);
				break;
			default:
				printf("Opção não existente \n");					
		}
	}while(op != 0);

}// fim do menu
