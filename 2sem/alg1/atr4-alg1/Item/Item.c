#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Item.h"

struct item_st
{
    int chave;   // like a primary key
    int valor;   // real value on int
    int tamanho; // length of valor
    int isBool;  // length of valor
};

ITEM *item_criar(int chave, int valor, int tamanho, int isBool)
{
    ITEM *item;

    item = (ITEM *)malloc(sizeof(ITEM));

    if (item != NULL)
    {
        item->chave = chave;
        item->valor = valor;
        item->tamanho = tamanho;
        item->isBool = isBool;
        return item;
    }
    return NULL;
}

boolean item_apagar(ITEM **item)
{
    if (*item != NULL)
    {
        (*item)->chave = ERRO; /*apaga o item simbolicamente*/
        free(*item);
        *item = NULL;
        return TRUE;
    }
    return FALSE;
}

int item_get_chave(const ITEM *item)
{
    if (item != NULL)
    {
        return item->chave;
    }
    return ERRO;
}

int item_somar(const ITEM *item1, const ITEM *item2)
{
    return item1->valor + item2->valor;
}

boolean item_set_chave(ITEM *item, int chave)
{
    if (item != NULL)
    {
        item->chave = chave;
        return TRUE;
    }
    return FALSE;
}

void item_imprimir(const ITEM *item)
{
    if (item != NULL)
    {
        printf("\n-->chave: %d", item->chave);
        printf("\n-->valor: %d", item->valor);
        printf("\n-->tamanho: %d", item->tamanho);
    }
}
void item_imprimir_valor(const ITEM *item)
{
    if (item != NULL)
    {
        printf("%d", item->valor);
    }
}
// LISTA *lista;
// lista = lista_criar();
// ITEM *item = item_ler_std_in();
// lista_inserir(lista, item);
// item = item_ler_std_in();
// lista_inserir(lista, item);
// item_imprimir(lista_busca_sequencial(lista, 0));
// item_imprimir(lista_busca_sequencial(lista, 1));
// boolean_print(lista_vazia(lista));
// lista_apagar(&lista);