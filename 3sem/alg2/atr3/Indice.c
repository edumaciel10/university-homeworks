#include<stdio.h>
#include<stdlib.h>
#include"Indice.h"

struct indice_st{
  int chave;
  long int RRN;
};


// Funções públicas
INDICE* indiceCriar(int chave, long int RRN){
  if(RRN < 0){
    return NULL;
  }

  INDICE *indice = malloc(sizeof(INDICE));
  return indice;
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
