#ifndef TADGENERICO_ARVOREBINARIA_H
#define TADGENERICO_ARVOREBINARIA_H

#include "Util.h"
#include "Cliente.h"

#define FILHO_ESQ 0
#define FILHO_DIR 1

typedef struct arvore_binaria ARVORE_BINARIA;
typedef struct node_st NODE;

ARVORE_BINARIA *arvore_binaria_criar();
void arvore_binaria_pre_ordem(ARVORE_BINARIA *arvoreBinaria);
void arvore_binaria_em_ordem(ARVORE_BINARIA *arvoreBinaria);
void arvore_binaria_pos_ordem(ARVORE_BINARIA *arvoreBinaria);
NODE * ab_cria_no(CLIENTE *cliente);
boolean no_checa_duplicado(NODE *raiz, CLIENTE *cliente);
boolean ab_inserir(ARVORE_BINARIA *T, CLIENTE *cliente);
NODE * ab_inserir_no(NODE *raiz, CLIENTE *cliente);


#endif //TADGENERICO_ARVOREBINARIA_H
