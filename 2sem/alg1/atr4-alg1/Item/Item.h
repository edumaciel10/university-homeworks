#ifndef ITEM_H
#define ITEM_H

#include "../Util/Util.h"

#define ERRO (-32000)

typedef struct item_st ITEM;

ITEM *item_criar(int chave, int valor, int tamanho, int isBool);
boolean item_apagar(ITEM **item);
void item_imprimir(const ITEM *item);
void item_imprimir_valor(const ITEM *item);
int item_get_chave(const ITEM *item);
boolean item_set_chave(ITEM *item, int chave);
int item_somar(const ITEM *item1, const ITEM *item2);

#endif //ITEM_H
