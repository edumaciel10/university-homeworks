#include <stdlib.h>
#include "ArvoreBinaria.h"


struct node_st
{
    ITEM *item;
    NODE *direita;
    NODE *esquerda;
};

struct arvore_binaria
{
    NODE* raiz;
};

ARVORE_BINARIA *arvore_binaria_criar()
{
    ARVORE_BINARIA *arvore;
    arvore = (ARVORE_BINARIA *) malloc(sizeof(ARVORE_BINARIA));
    if (arvore != NULL) {
        arvore->raiz = NULL;
    }
    return arvore;
}

static void pre_ordem_recursao(NODE *raiz) {
    if (raiz != NULL) {
        item_imprimir(raiz->item);
        pre_ordem_recursao(raiz->esquerda);
        pre_ordem_recursao(raiz->direita);
    }
}

static void em_ordem_recursao(NODE *raiz) {
    if (raiz != NULL) {
        pre_ordem_recursao(raiz->esquerda);
        item_imprimir(raiz->item);
        pre_ordem_recursao(raiz->direita);
    }
}

static void pos_ordem_recursao(NODE *raiz) {
    if (raiz != NULL) {
        pre_ordem_recursao(raiz->esquerda);
        pre_ordem_recursao(raiz->direita);
        item_imprimir(raiz->item);
    }
}

void arvore_binaria_pre_ordem(ARVORE_BINARIA *arvoreBinaria)
{
    pre_ordem_recursao(arvoreBinaria->raiz);
}

void arvore_binaria_em_ordem(ARVORE_BINARIA *arvoreBinaria)
{
    em_ordem_recursao(arvoreBinaria->raiz);
}

void arvore_binaria_pos_ordem(ARVORE_BINARIA *arvoreBinaria)
{
    pos_ordem_recursao(arvoreBinaria->raiz);
}

NODE * ab_cria_no(ITEM *item)
{
    NODE * novo_no;
    novo_no = (NODE *) malloc(sizeof(NODE));
    if (novo_no != NULL) {
        novo_no->item = item;
        novo_no->direita = NULL;
        novo_no->esquerda = NULL;
    }
    return novo_no;
}
NODE * ab_inserir_no(NODE *raiz, ITEM *item)
{
    if (raiz == NULL) {
        raiz = ab_cria_no(item);
        return raiz;
    } 
    cliente_imprimir_verboso(raiz->item);
    cliente_imprimir_verboso(item);
    if (item_comparar(raiz->item,item ) < 0) {
        raiz->esquerda = ab_inserir_no(raiz->esquerda, item);
    } else {
        raiz->direita = ab_inserir_no(raiz->direita, item);
    }
    return raiz;
}

boolean ab_inserir(ARVORE_BINARIA *T, ITEM *item){
    if (T->raiz == NULL)
        return((T->raiz = ab_cria_no(item)) != NULL);
    else
        return((T->raiz = ab_inserir_no(T->raiz, item)) != NULL);
}