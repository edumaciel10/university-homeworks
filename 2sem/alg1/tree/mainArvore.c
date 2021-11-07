#include <stdio.h>
#include "ArvoreBinaria.h"

int main()
{
    ARVORE_BINARIA *arvoreBinaria;
    arvoreBinaria = arvore_binaria_criar();
    ITEM *item;
    item = item_criar(0, "Magia","Desc",10,20);
    ab_inserir(arvoreBinaria,item);
    item = item_criar(3, "Magia","Desc",10,20);
    ab_inserir(arvoreBinaria,item);
    item = item_criar(1, "Magia","Desc",10,20);
    ab_inserir(arvoreBinaria,item);
    item = item_criar(2, "Magia","Desc",10,20);
    ab_inserir(arvoreBinaria,item);
    arvore_binaria_pre_ordem(arvoreBinaria);
    arvore_binaria_em_ordem(arvoreBinaria);
    arvore_binaria_pos_ordem(arvoreBinaria);
    return 0;
}