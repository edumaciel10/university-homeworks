#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"

int main()
{
    int quantidade;
    ARVORE_BINARIA *arvoreBinaria;
    arvoreBinaria = arvore_binaria_criar();
    CLIENTE *cliente;
    scanf("%d",&quantidade);
    getchar();
    for(int i = 0; i < quantidade; i++)
    {
        cliente = cliente_ler_stdin();
        ab_inserir(arvoreBinaria, cliente);
    }
    arvore_binaria_em_ordem(arvoreBinaria);
    arvore_binaria_pre_ordem(arvoreBinaria);
    arvore_binaria_pos_ordem(arvoreBinaria);
    printf("\n");
    ab_apagar(&arvoreBinaria);
    return 0;
}