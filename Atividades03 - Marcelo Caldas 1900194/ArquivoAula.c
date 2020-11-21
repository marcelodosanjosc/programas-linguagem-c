#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main (){
	setlocale(LC_ALL, "");
	FILE *parquivo;
	
	int a,numero2, numero3, resul; // variavel resul pegar do arquivo para exibir na tela 
	a = 100000; // alocado no arquivo
	numero2 = 20000;
	numero3 = 30000;
	parquivo = fopen("teste.doc","a");
	/*
	if(parquivo == NULL){
		printf("Arquivo não encontrado \n");
		system("pause");
		exit(0);
	}else{
		printf("Arquivo cria com sucesso \n");
		system("pause");
		system("cls"); 
	}
	fwrite(&a, sizeof(int),1,parquivo);// fwrite escrita binario no arquivo 
	fwrite(&numero2, sizeof(int),1,parquivo);
	fwrite(&numero3, sizeof(int),1,parquivo);
	fclose(parquivo);
	*/
	// imprimir dados do arquivo
	
	parquivo = fopen("teste.doc","r");
	rewind(parquivo);// comando utilizado para realocar ponteiro para inicio do arquivo
	while(!feof(parquivo)){
	fread(&resul, sizeof(int), 1, parquivo); //fread escrita binario retorna do arquivo 
		if(!feof(parquivo)) {
		printf("%i \n",resul);
        printf("O arquivo inteiro foi lido.");
    } else {
        printf("O indicador de fim de arquivo (EOF) não está marcado. Um erro ocorreu.");
    	}
	}
	
	
	fclose(parquivo);
	system("pause");
	return 0;
}// fim da main



