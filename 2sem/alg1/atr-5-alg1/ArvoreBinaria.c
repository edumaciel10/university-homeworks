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
NODE * ab_inserir_no(NODE *raiz, ITEM *item)
{
    if (raiz == NULL) {
        raiz = ab_cria_no(item);
    } else {
        if(item_comparar(item, raiz->esquerda->item) ==0 ||
            item_comparar(item, raiz->direita->item) ==0){
                return NULL;
        }
        if (item_comparar(item, raiz->item) < 0) {
            raiz->esquerda = ab_inserir_no(raiz->esquerda, item);
        } else {
            raiz->direita = ab_inserir_no(raiz->direita, item);
        }
    }
    return raiz;
}
// NODE *ab_inserir_no(NODE *raiz, ITEM *item, int lado, int chave) {
//     if (raiz != NULL) {
//         raiz->esquerda = ab_inserir_no(raiz->esquerda, item, lado, chave);
//         raiz->direita = ab_inserir_no(raiz->direita, item, lado, chave);
//         if (chave == item_get_chave(raiz->item)){
//             if (lado == FILHO_ESQ)
//             {
//                 if(raiz->esquerda == NULL)
//                 {
//                     raiz->esquerda = ab_cria_no(item);
//                 }
//             }
//             else if (lado == FILHO_DIR)
//             {
//                 if(raiz->direita == NULL)
//                 {
//                     raiz->direita = ab_cria_no(item);
//                 }
//             }
//         }
//     }
//     return raiz;
// }

boolean ab_inserir(ARVORE_BINARIA *T, CLIENTE *cliente){
    if (T->raiz == NULL)
        return((T->raiz = ab_cria_no(cliente)) != NULL);
    else
        return((T->raiz = binary_tree_insert(T->raiz, cliente)) != NULL);
}



