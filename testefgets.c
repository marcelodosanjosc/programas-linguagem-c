#include <stdio.h>
#include <stdlib.h>

main (){
    int num;
    char nome[50];

    printf("Digite um numero");
    scanf("%d", &num);
    scanf("%*c");
    printf("Digite seu nome");
    fgets(nome, 49, stdin);

}
