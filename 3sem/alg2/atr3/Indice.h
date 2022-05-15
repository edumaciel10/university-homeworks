#ifndef INDICE_H
#define INDICE_H

#include"Util.h"

typedef struct indice_st INDICE;

INDICE* indiceCriar(int chave, int rrn);
boolean indiceSalvar(INDICE **indice, int *indicesLen, int nusp);

int indiceGetChave(INDICE *indice);

long int indiceGetRRN(INDICE *indice);
long int indiceTamanhoStruct();
boolean indiceApagar(INDICE **indice);

#endif // INDICE_H