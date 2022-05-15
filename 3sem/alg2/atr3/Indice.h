#ifndef INDICE_H
#define INDICE_H

#include"Util.h"

typedef struct indice_st INDICE;

INDICE* indiceCriar(int chave, int rrn);
INDICE* indiceCriarVazio();

boolean indiceAdicionar(INDICE ***indices, int *indicesLen, int chave, int rrn);
boolean indiceRemoverPorIndex(INDICE ***indices, int *indicesLen, int index);

void indiceImprimir(INDICE *indice);
int indiceGetChave(INDICE *indice);
int indiceGetRRN(INDICE *indice);
long int indiceTamanhoStruct();

boolean indiceApagarLista(INDICE ***indices, int indicesLen);
boolean indiceApagar(INDICE **indice);

#endif // INDICE_H