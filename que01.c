#include <stdio.h>

void func(int tam, int *vetor );
main(){
	int tam = 5;
	int vetor[5] = {5,1,7,3,2};
	func(tam,vetor);
	
	
}

void func(int tam, int *vetor ){
	int p, i, temp;
	for (p=1; p<tam; p++){
		for (i = 0; i< tam-p; i++){
			if(vetor[i] > vetor[i+1]){
				temp = vetor[i];
				vetor[i] = vetor[i + 1];
				vetor[i+1] = temp;
			
			}
		}
	}
	
	for (i = 0;i < tam;i++){
		printf("%i ",vetor[i]);		
	}
}
