/*1. Faça um programa para gerenciar loja aluguel carros. O sistema irá cadastrar:
• Carro: modelo, cor, ano, quantidade, valor diária, placa;
• Cliente: nome, endereço, rua, casa, bairro, telefone, número CNH.
O Sistema irá realizar o aluguel dos carros: O cliente cadastrado escolhe o carro disponível e aluga de acordo com o tempo desejado, valor total.
O sistema terá devolução.
O funcionário pesquisa a placa, o sistema lista os dados do carro e quando finalizar a devolução o carro volta a estar disponível.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct {
    char modelo[50], cor[23], placa[8];
    double valorDiaria;
    int ano;
} Carro;

typedef struct {
    char nome[60], rua[42],casa[8], bairro[42], telefone[14];
    long numeroCNH;
} Cliente;

Carro ler(){
    Carro cr;
    scanf("%*c");
    printf("\n Digite o modelo do carro");
    fgets(cr.modelo, 49, stdin);
    scanf("%*c");
    printf("\n Digite a cor ");
    fgets(cr.cor, 22, stdin);
    printf("\nDigite o ano");
    scanf("%d", &cr.ano);
    printf("\nDigite o valor diário");
    scanf("%lf",&cr.valorDiaria);
    scanf("%*c");
    printf("\n Digite a placas do carro");
    fgets(cr.placa, 7, stdin);

    return cr;
}

void imprimeCarro ( Carro c){
    printf("\n Modelo: %s \n", c.modelo);
    printf("\n Cor: %s \n", c.cor);
    printf("\n Ano: %d \n", c.ano);
    printf("\n Valor diário: %lf \n", c.valorDiaria);
    printf("\n Placa do carro: %s \n", c.placa);

}

void main(){
    Carro carro1 = ler();
    imprimeCarro(carro1);
}
