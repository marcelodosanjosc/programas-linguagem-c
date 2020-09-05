#include <stdio.h>
#include <stdlib.h>

int main (){
    int num;
    char nome[50];

    printf("Digite um numero");
    scanf("%d", &num);
    scanf("%*c");
    printf("Digite seu nome");
    scanf("%s",&nome[50]);

    return 0;
}
