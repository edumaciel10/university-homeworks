#include<stdio.h>
#include<stdlib.h>
#include"Indice.h"

struct indice_st{
  int chave;
  long int RRN;
};


// Funções públicas
INDICE* indiceCriar(int chave, int RRN){
  if(RRN < 0){
    return NULL;
  }
  printf("chave: %d\n", chave);
  printf("RRN: %d\n", RRN);

  INDICE *indice = (INDICE*) malloc(sizeof(INDICE));

  if(indice == NULL){
    printf("Erro ao criar indice\n");
    return NULL;
  }
  indice->chave = chave;
  indice->RRN = RRN;

  printf("indice criado\n");
  return indice;
}

boolean indiceSalvar(INDICE **indice, int *indicesLen, int nusp){
  printf("nusp: %d\n", nusp);
  printf("indicesLen: %d\n", *indicesLen);
  printf("(*indicesLen)+1: %d\n", (*indicesLen)+1);
  INDICE *novoIndice = indiceCriar(nusp, (*indicesLen)+1);
  printf("AAAA");
  if(novoIndice == NULL){
    return FALSE;
  }
  (*indicesLen)++;

  indice = (INDICE**) realloc(indice, sizeof(INDICE)*(*indicesLen));

  indice[(*indicesLen)-1] = novoIndice;


  printf("indice salvo\n");
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
  return sizeof(INDICE);
}

boolean indiceApagar(INDICE **indice){
  free(*indice);
  (*indice) = NULL;
  return TRUE;
}
