#include<stdio.h>
#include<stdlib.h>
#include"Indice.h"

struct indice_st{
  int chave;
  int RRN;
};


// Funções públicas
INDICE* indiceCriar(int chave, int RRN){
  printf("indiceCriar(%d, %d)\n", chave, RRN);
  if(RRN < 0){
    return NULL;
  }

  INDICE *indice = (INDICE*) malloc(sizeof(INDICE));

  if(indice == NULL){
    printf("Erro ao criar indice\n");
    return NULL;
  }
  indice->chave = chave;
  indice->RRN = RRN;
  // indiceImprimir(indice);
  return indice;
}
// utilizamos o parametro indices e indicesLen como referência, para manter o restante do programa também atualizado
boolean indiceSalvar(INDICE ***indices, int *indicesLen, int nusp, int rrn){
  INDICE *novoIndice = indiceCriar(nusp, rrn);
  if(novoIndice == NULL){
    return FALSE;
  }

  // contabilizando o novo indice
  (*indicesLen)++;

  // adicionando um espaço para o novo indice no final do array
  *indices = (INDICE**) realloc(*indices, indiceTamanhoStruct() * ((*indicesLen) + 1));

  // adicionando o novoIndice 
  (*indices)[(*indicesLen)-1] = novoIndice;

  return TRUE;
}

int indiceGetChave(INDICE *indice){
  if(indice == NULL){
    return -1;
  }

  return indice->chave;
}

long int indiceGetRRN(INDICE *indice){
  if(indice == NULL){
    return -1;
  }

  return indice->RRN;
}

long int indiceTamanhoStruct(){
  return sizeof(INDICE*);
}

void indiceImprimir(INDICE *indice){
  printf("----------------------------------------------------\n");
  printf("chave: %d\n", indice->chave);
  printf("RRN: %d\n", indice->RRN);
  printf("----------------------------------------------------\n");

}

boolean indiceApagar(INDICE **indice){
  free(*indice);
  (*indice) = NULL;
  return TRUE;
}
