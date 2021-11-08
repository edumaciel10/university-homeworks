#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"

void testeInserir();
int main()
{
    testeInserir();
    return 0;
}
void testeInserir()
{
    ARVORE_BINARIA *arvoreBinaria;
    arvoreBinaria = arvore_binaria_criar();
    CLIENTE *cliente;
    cliente= cliente_criar(18616114041,"Heitor Rafael   Fernandes",57,-5911.43);
    ab_inserir(arvoreBinaria,cliente);
    cliente= cliente_criar(83477225287,"Heitor Júlia    Fernandes",82,-8666.55);
    ab_inserir(arvoreBinaria,cliente);
    cliente= cliente_criar(97753525760,"Alice  Bernardo Carvalho",55, 1520.47);
    ab_inserir(arvoreBinaria,cliente);
    cliente= cliente_criar(15066443339,"Pedro  Mendes",38,-3435.54);
    ab_inserir(arvoreBinaria,cliente);
    cliente= cliente_criar(55098026180,"Pedro  Henrique Arthur Davi Gomes",32,-4320.64);
    ab_inserir(arvoreBinaria,cliente);
    arvore_binaria_pre_ordem(arvoreBinaria);
    printf("\n");
    arvore_binaria_em_ordem(arvoreBinaria);
    printf("\n");
    arvore_binaria_pos_ordem(arvoreBinaria);
    printf("\n");
}