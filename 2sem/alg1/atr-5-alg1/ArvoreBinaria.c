#include <stdlib.h>
#include "ArvoreBinaria.h"


struct node_st
{
    CLIENTE *cliente;
    NODE *direita;
    NODE *esquerda;
};

struct arvore_binaria
{
    NODE* raiz;
    int profundidade;
};

ARVORE_BINARIA *arvore_binaria_criar()
{
    ARVORE_BINARIA *arvore;
    arvore = (ARVORE_BINARIA *) malloc(sizeof(ARVORE_BINARIA));
    if (arvore != NULL) {
        arvore->raiz = NULL;
        arvore->profundidade = -1;
    }
    return arvore;
}

static void pre_ordem_recursao(NODE *raiz) {
    if (raiz != NULL) {
        cliente_imprimir(raiz->cliente);
        pre_ordem_recursao(raiz->esquerda);
        pre_ordem_recursao(raiz->direita);
    }
}

static void em_ordem_recursao(NODE *raiz) {
    if (raiz != NULL) {
        pre_ordem_recursao(raiz->esquerda);
        cliente_imprimir(raiz->cliente);
        pre_ordem_recursao(raiz->direita);
    }
}

static void pos_ordem_recursao(NODE *raiz) {
    if (raiz != NULL) {
        pre_ordem_recursao(raiz->esquerda);
        pre_ordem_recursao(raiz->direita);
        cliente_imprimir(raiz->cliente);
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

NODE * ab_cria_no(CLIENTE *cliente)
{
    NODE * novo_no;
    novo_no = (NODE *) malloc(sizeof(NODE));
    if (novo_no != NULL) {
        novo_no->cliente = cliente;
        novo_no->direita = NULL;
        novo_no->esquerda = NULL;
    }
    return novo_no;
}
boolean no_checa_duplicado(NODE *raiz, CLIENTE *cliente)
{
    if (cliente_comparar(raiz->cliente, cliente) == 0) {
        return TRUE;
    }
    if(raiz->esquerda != NULL) {
        if (cliente_comparar(raiz->esquerda->cliente, cliente) == 0) {
            return TRUE;
        }
    }
    if(raiz->direita != NULL) {
        if (cliente_comparar(raiz->direita->cliente, cliente) == 0) {
            return TRUE;
        }
    }
    return FALSE;
}

NODE * binary_tree_insert(NODE *raiz, CLIENTE *cliente)
{
    if(raiz == NULL) {
        raiz = ab_cria_no(cliente);
    } else {
        if(cliente_comparar(raiz->cliente, cliente) < 0) {
            raiz->esquerda = binary_tree_insert(raiz->esquerda, cliente);
        } else if(cliente_comparar(raiz->cliente, cliente) > 0) {
            raiz->direita = binary_tree_insert(raiz->direita, cliente);
        }
        else {
            return raiz;
        }
    }
    return raiz;
}


boolean ab_inserir(ARVORE_BINARIA *T, CLIENTE *cliente){
    if (T->raiz == NULL)
        return((T->raiz = ab_cria_no(cliente)) != NULL);
    else
        return((T->raiz = binary_tree_insert(T->raiz, cliente)) != NULL);
}



