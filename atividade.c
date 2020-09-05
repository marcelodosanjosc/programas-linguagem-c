/*1. Fa√ßa um programa para gerenciar loja aluguel carros. O sistema ir√° cadastrar:
‚Ä¢ Carro: modelo, cor, ano, quantidade, valor di√°ria, placa;
‚Ä¢ Cliente: nome, endere√ßo, rua, casa, bairro, telefone, n√∫mero CNH.
O Sistema ir√° realizar o aluguel dos carros: O cliente cadastrado escolhe o carro dispon√≠vel e aluga de acordo com o tempo desejado, valor total.
O sistema ter√° devolu√ß√£o.
O funcion√°rio pesquisa a placa, o sistema lista os dados do carro e quando finalizar a devolu√ß√£o o carro volta a estar dispon√≠vel.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
 
char sim[13] = "Disponivel";
char nao[13] = "Indisponivel";

typedef struct Cliente{ // registro de cliete
    char nome[60], rua[60],casa[8], bairro[42], telefone[14];
    long int numeroCNH;
}Cliente;

typedef struct Carro { // registro de carro
    char modelo[50], cor[23], placa[8];
    float valorDiaria;
    int ano;
   	char status[13];
   	Cliente cliente;
} Carro;

FILE *arqu_carro;
FILE *arqu_cliente;

Carro cadastraCarro(){// funcao cadastra carro
    Carro cr;
    
    arqu_carro = fopen("carro.bin", "a+b");
    	if(arqu_carro == NULL)
	{
		printf("\nFalha ao abrir arquivo(s)!\n");
		exit(1); // aborta o programa
	}
 
    printf("\n Digite o modelo do carro: ");
    fflush (stdin);
    fgets(cr.modelo, 49, stdin); //usado essa funcao para pegar do teclado 
    printf("\n Digite a cor: ");
    fflush (stdin);
    fgets(cr.cor, 22, stdin);
    printf("\nDigite o ano: ");
    fflush (stdin);
    scanf("%d", &cr.ano);
    printf("\nDigite o valor diario: ");
    scanf("%f",&cr.valorDiaria);
	fflush (stdin);
    printf("\n Digite a placas do carro: ");
    fgets(cr.placa, 8, stdin);
    fflush (stdin);
   	sscanf(sim, "%s" ,&cr.status);

	fwrite(&cr, sizeof(Carro), 1, arqu_carro);
	// fecha o arquivo
	fclose(arqu_carro);
    return cr;
    
}

Cliente cadastraCliente(){ //funcao de cadastrado cliente
	 arqu_cliente = fopen("cliente.bin", "a+b");
	    	if(arqu_cliente == NULL)
		{
			printf("\nFalha ao abrir arquivo(s)!\n");
			exit(1); // aborta o programa
		} 
	Cliente cl;
	printf("\nDigite nome: ");
	fflush (stdin);
	fgets(cl.nome, 59, stdin);
	printf("\nEndereco\n");
	printf("\nLogradouro: ");
	fflush (stdin);
	fgets(cl.rua, 59, stdin);
	printf("\nNumero da casa: ");
	fflush (stdin);
	fgets(cl.casa, 7, stdin);
	printf("\nBairro: ");
	fflush (stdin);
	fgets(cl.bairro, 41, stdin);
	printf("\nContatos\n");
	printf("\nTelefone: ");
	fflush (stdin);
	fgets(cl.telefone, 13, stdin);
	printf("\nDocumentos\n");
	printf("\nNumero da CNH: ");
	fflush (stdin);
	scanf("%li", &cl.numeroCNH);
	
	fwrite(&cl, sizeof(Cliente), 1, arqu_cliente);
	// fecha o arquivo
	fclose(arqu_cliente);
	
	return cl;
}


void imprimeCarro ( ){ // funcao imprime carro
	Carro c;
	arqu_carro = fopen("carro.bin","rb");
	rewind(arqu_carro);
		while(!feof(arqu_carro)){
		fread(&c,sizeof(Carro),1,arqu_carro);//ler o arquivo
		if (!feof(arqu_carro)){
	
	    printf("\n Modelo: %s", c.modelo);
	    printf("\n Cor: %s", c.cor);
	    printf("\n Ano: %d", c.ano);	
	    printf("\n Valor diario: %.2f", c.valorDiaria);
	    printf("\n Placa do carro: %s", c.placa);
	    printf("\n Status: %s ", c.status);
		}
	}
}

void imprimeCliente () { // funcao imprime cliente
	Cliente c;
	arqu_cliente = fopen("cliente.bin","rb");
	rewind(arqu_cliente);
		while(!feof(arqu_cliente)){
		fread(&c,sizeof(Cliente),1,arqu_cliente);//ler o arquivo
		if (!feof(arqu_cliente)){
		printf("\nNome do Cliente: %s", c.nome);
		printf("\nEndereco: Logradouro %s N∞ %s Bairro %s ", c.rua, c.casa, c.bairro);
		printf("\nContato: Tel. %s", c.telefone);
		printf("\nDocumento: CNH %li",c.numeroCNH);
		}
	}
}

void buscaPlaca (){
	char p[8];
	int encontrou_placa = 0;
	Carro c;
	
			printf("\n A placa: ");
			 scanf("%s%*c", &p);		
			arqu_carro = fopen("carro.bin","rb");
			rewind(arqu_carro);
				while(!feof(arqu_carro)){
				size_t total = fread(&c,sizeof(Carro),1,arqu_carro);//ler o arquivo
				
						if(total == 0)
							break;
		// verifica se È igual
		if(strcmp(strupr(c.placa), strupr(p)) == 0)
		{
			// mostra os dados do cliente
			printf("Placa encontrada: %s\n", c.placa);
			printf("\n Modelo: %s", c.modelo);
		    printf("\n Cor: %s", c.cor);
		    printf("\n Ano: %d", c.ano);	
		    printf("\n Valor diario: %.2f\n", c.valorDiaria);
		    printf("\n Status: %s", c.status);
		    
			encontrou_placa = 1;
			} 
		}
			if(encontrou_placa == 0)
				printf("Nenhum placa encontrada.\n\n");
				// fecha o arquivo
				fclose(arqu_carro);
}
void buscaCnh(){
		int long cnh;
		int encontrou_cnh = 0;
		Cliente cl;
	
			printf("\n A CNH: ");
			 scanf("%li", &cnh);		
			arqu_cliente = fopen("cliente.bin","rb");
			rewind(arqu_cliente);
				while(!feof(arqu_cliente)){
				size_t total = fread(&cl,sizeof(Cliente),1,arqu_cliente);//ler o arquivo
				
						if(total == 0)
							break;
		// verifica se È igual
		if(cl.numeroCNH == cnh)
		{
			// mostra os dados do cliente
			printf("CNH encontrada: %li\n", cl.numeroCNH);
			printf("\nNome do Cliente: %s", cl.nome);
			printf("\nEndereco: Logradouro %s N∞ %s Bairro %s ", cl.rua, cl.casa, cl.bairro);
			printf("\nContato: Tel. %s \n", cl.telefone);
			encontrou_cnh = 1;
			}
		}
			if(encontrou_cnh == 0)
				printf("Nenhum CNH encontrada.\n\n");
				// fecha o arquivo
				fclose(arqu_cliente);
}

// recebe o ponteiro para o arquivo
void atualizarCarro(){
	FILE *arqu_carro = fopen("carro.bin", "r+b");
	if (arqu_carro == NULL){
	printf("Arquivo inexistente!");
	return;
	}
	//rewind(arqu_carro);
	Carro c;
	char cod[9];
	int achei = 0;
	printf ("\nDigite o placa que deseja alterar: \n");
	fflush(stdin);
	gets(cod);

	while (fread (&c, sizeof(Carro), 1, arqu_carro)){
	if (strcmp (strupr(cod), strupr(c.placa)) == 0){
				printf("Placa encontrada: %s\n", c.placa);
				printf("\n Modelo: %s", c.modelo);
			    printf("\n Cor: %s", c.cor);
			    printf("\n Ano: %d", c.ano);	
			    printf("\n Valor diario: %.2f", c.valorDiaria);
			    printf("\n Status; %s\n", c.status);
	achei = 1;
	fseek(arqu_carro,sizeof(Carro)*-1, SEEK_CUR);
	printf("\nDigite a nova status: \n");
	if (strcmp(strupr(c.status), strupr(sim)) == 0){
		fflush(stdin);
		sscanf(nao, "%s" ,&c.status);
		printf("\nAlugado");
	}else{
		fflush(stdin);
		sscanf(sim, "%s" ,&c.status);
			printf("\nDevolvido");
	}
	fwrite(&c, sizeof(c), 1, arqu_carro);
	fseek(arqu_carro, sizeof(Carro)* 0, SEEK_END);
	return;
}
}
	if (!achei)
	printf ("\nNao cadastrado!!\n");
	
	fclose(arqu_carro);
		
}



void alugar(){
	int op = 0;
	int op2 = 0;
	int op3 = 0;

 	printf("\n-- ALUGUEL DE CARRO! --z\n");
 	printf("\nDigite (1) Alugar  ou (2) Devolver:  ");
 	fflush(stdin);
 	scanf("%d", &op);
 	if ( op == 1){
 		printf("\nBusca pela CNH:");
 		buscaCnh();
 		printf("\nBusca deu sucesso? se sim digite (1) se n„o (2): ");
 		fflush(stdin);
 		scanf("%d%*c",&op2);
 		if (op2 != 1){
 		  		printf("\nN„o encontrado !!");
 		 		menu();
 		 		
		   }
		   
		printf("\nBusca pela PLACA:");   
 		buscaPlaca();
 		printf("\nBusca deu sucesso? se sim digite (1) se n„o (2): ");
 		fflush(stdin);
 		scanf("%d%*c",&op3);
 		if (op3 != 1){
		 		printf("\nN„o encontrado !!");
		   		menu();
		   }
 		atualizarCarro();
	 }else{
	 	atualizarCarro();
	 }
}


void menu(){ // funcao menu 
	int o;
	int opcao, i, j, contCR = 0, contCL = 0;
	char p[8];
	long int cnh;
	do {
		printf("\nOpÁıes\n");
		printf("\n1 - Cadastra Carro ");
		printf("\n2 - Cadastra Cliente ");
		printf("\n3 - Lista Carros ");
		printf("\n4 - Lista Clientes ");
		printf("\n5 - Busca Carro por placa ");
		printf("\n6 - Busca Cliente pela CNH ");
		printf("\n7 - Aluguel de Carro");
		printf("\n0 - Sair.\n");
		printf(" \n Digite a opÁ„o desejada: ");
		scanf("%d%*c", &opcao);
        switch(opcao){
        	case 1: // opcao de cadastra carro
        		cadastraCarro();
        		contCR ++;
        	break;
        	case 2: // opcao de cadastra cliente
        		cadastraCliente();
        		contCL ++;
        	break;
			case 3:// opcao de lista carros
					imprimeCarro();
			break;
			case 4:// opcao de lista cliente
				
					imprimeCliente();
				
			break;
			case 5: // busca pela placa
				buscaPlaca();
			break;
			case 6: // busca pela cnh
				buscaCnh();
			break;	
			case 7: // fazer aluguel
				//atualizarCarro();
				alugar();
			break;
			default:
                 printf(" \n OpÁ„o n„o existente. ");
            break;			
		}
	}while (opcao != 0);
}

main(){ // main 
	
		setlocale(LC_ALL, "portuguese");
		menu();		
		
}
