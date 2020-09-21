// ponteiro e lista 
#include <stdio.h>
#include <stdlib.h>

/* a lista de notas */
#define lnota struct s_nota
struct s_nota {
	float v;
	lnota *prox;
};


/*
	Cria uma lista vazia. Retorna ponteiro para a cabeça da lista.
*/
lnota *criaLista() {
	return(NULL);
}


/*
	Cria um nó na lista. Retorna ponteiro para este nó, ou NULL em caso de erro.

	Param:
		nota - a nota a ser armazenada no nó
*/
lnota *criaNo(float nota) {
	lnota *aux; /* auxiliar */

	/* aloco espaço para o nó */
	if (!(aux = (lnota *)malloc(sizeof(lnota)))) {
		/* não pode alocar */
		return(NULL);
	}

	/* alocou, carrego os valores */
	aux->v = nota;
	aux->prox = NULL;

	/* retorno o ponteiro para o elemento criado */
	return(aux);
}


/*
	Inclui um elemento no início da lista. Retorna ponteiro para o novo nó cabeça da lista, ou NULL em caso de erro.

	Param:
		cab - cabeça da lista
		nota - valor da nota a ser incluída
*/
lnota *incluiEl(lnota *cab, float nota) {
	lnota *aux; /* auxiliar */

	/* crio o novo nó */
	if (!(aux = criaNo(nota))) {
		/* houve problemas na criação do nó */
		return(NULL);
	}

	/* criei o nó, faço a cabeça ser o elemento seguinte a ele */
	aux->prox = cab;

	/* retorno a nova cabeça da lista */
	return(aux);
}


/*
	Imprime a lista na tela.

	Param:
		cab - a cabeça da lista
*/
void imprimeL(lnota *cab) {
	lnota *p; /* auxiliar */

	/* aponto p para o início da lista */
	p = cab;

	/* imprimo cada elemento da lista */
	while (p) {
		printf("nota: %f\n",p->v);
		p = p->prox;
	}
}


int main() {
	lnota *cabeca; /* cabeça da lista */
	float nota;    /* uma nota */
	char resp;     /* indica se continua o laço */
	lnota *p;      /* auxiliar */
	float soma;    /* soma das notas */
	int n;         /* número de notas */

	/* inicio a lista */
	cabeca = criaLista();

	/* pego as notas */
	do {
		printf("Entre uma nota: ");
		scanf("%f",&nota);

		/* incluo a nota na lista */
		if (!(cabeca = incluiEl(cabeca, nota))) {
			printf("Erro na inclusão da nota na lista\n");
			exit(1);
		}

		/* pergunto se há mais notas */
		printf("Continua? (s/n) ");
		scanf(" %s",&resp);
	} while (resp == 's');

	/* imprimo a lista na tela */
	imprimeL(cabeca);

	/* calculo a média */
	soma = 0;
	n = 0;
	p = cabeca;
	while (p) {
		soma += p->v;
		n++;
		p = p->prox;
	}

	/* dou a resposta */
	printf("Média = %f\n", soma / n);
}
