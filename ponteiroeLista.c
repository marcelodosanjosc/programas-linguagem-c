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
	Cria uma lista vazia. Retorna ponteiro para a cabe�a da lista.
*/
lnota *criaLista() {
	return(NULL);
}


/*
	Cria um n� na lista. Retorna ponteiro para este n�, ou NULL em caso de erro.

	Param:
		nota - a nota a ser armazenada no n�
*/
lnota *criaNo(float nota) {
	lnota *aux; /* auxiliar */

	/* aloco espa�o para o n� */
	if (!(aux = (lnota *)malloc(sizeof(lnota)))) {
		/* n�o pode alocar */
		return(NULL);
	}

	/* alocou, carrego os valores */
	aux->v = nota;
	aux->prox = NULL;

	/* retorno o ponteiro para o elemento criado */
	return(aux);
}


/*
	Inclui um elemento no in�cio da lista. Retorna ponteiro para o novo n� cabe�a da lista, ou NULL em caso de erro.

	Param:
		cab - cabe�a da lista
		nota - valor da nota a ser inclu�da
*/
lnota *incluiEl(lnota *cab, float nota) {
	lnota *aux; /* auxiliar */

	/* crio o novo n� */
	if (!(aux = criaNo(nota))) {
		/* houve problemas na cria��o do n� */
		return(NULL);
	}

	/* criei o n�, fa�o a cabe�a ser o elemento seguinte a ele */
	aux->prox = cab;

	/* retorno a nova cabe�a da lista */
	return(aux);
}


/*
	Imprime a lista na tela.

	Param:
		cab - a cabe�a da lista
*/
void imprimeL(lnota *cab) {
	lnota *p; /* auxiliar */

	/* aponto p para o in�cio da lista */
	p = cab;

	/* imprimo cada elemento da lista */
	while (p) {
		printf("nota: %f\n",p->v);
		p = p->prox;
	}
}


int main() {
	lnota *cabeca; /* cabe�a da lista */
	float nota;    /* uma nota */
	char resp;     /* indica se continua o la�o */
	lnota *p;      /* auxiliar */
	float soma;    /* soma das notas */
	int n;         /* n�mero de notas */

	/* inicio a lista */
	cabeca = criaLista();

	/* pego as notas */
	do {
		printf("Entre uma nota: ");
		scanf("%f",&nota);

		/* incluo a nota na lista */
		if (!(cabeca = incluiEl(cabeca, nota))) {
			printf("Erro na inclus�o da nota na lista\n");
			exit(1);
		}

		/* pergunto se h� mais notas */
		printf("Continua? (s/n) ");
		scanf(" %s",&resp);
	} while (resp == 's');

	/* imprimo a lista na tela */
	imprimeL(cabeca);

	/* calculo a m�dia */
	soma = 0;
	n = 0;
	p = cabeca;
	while (p) {
		soma += p->v;
		n++;
		p = p->prox;
	}

	/* dou a resposta */
	printf("M�dia = %f\n", soma / n);
}
