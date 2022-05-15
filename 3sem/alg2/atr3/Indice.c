#include<stdio.h>
#include<stdlib.h>
#include"Indice.h"

struct indice_st{
  int chave;
  int RRN;
};


// Funções públicas
INDICE* indiceCriar(int chave, int RRN){
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
  return indice;
}

INDICE* indiceCriarVazio(){
  INDICE *indice = (INDICE*) malloc(sizeof(INDICE));

  if(indice == NULL){
    printf("Erro ao criar indice\n");
    return NULL;
  }
  indice->chave = -1;
  indice->RRN = -1;
  return indice;
}

// utilizamos o parametro indices e indicesLen como referência, para manter o restante do programa também atualizado
boolean indiceAdicionar(INDICE ***indices, int *indicesLen, int chave, int rrn){
  INDICE *novoIndice = indiceCriar(chave, rrn);
  if(novoIndice == NULL){
    return FALSE;
  }

  // contabilizando o novo indice
  (*indicesLen)++;

  // adicionando um espaço para o novo indice no final do array
  INDICE **indicesAux = (INDICE**) realloc(*indices, indiceTamanhoStruct() * ((*indicesLen) + 1));
  if(indicesAux == NULL){
    printf("Erro ao realocar memoria para os indices em memoria!");
    exit(-1);
  }

  (*indices) = indicesAux;

  // adicionando o novoIndice 
  (*indices)[(*indicesLen)-1] = novoIndice;

  // inserindo indice em sua posição (insertion sort)
  int index = (*indicesLen)-2;
  while (index >= 0 && ((*indices)[index])->chave > chave) {
    (*indices)[index + 1]->chave = (*indices)[index]->chave;
    (*indices)[index + 1]->RRN = (*indices)[index]->RRN;
    index--;
  }
  ((*indices)[index + 1])->chave = chave;
  ((*indices)[index + 1])->RRN = rrn;

  return TRUE;
}

boolean indiceRemoverPorIndex(INDICE ***indices, int *indicesLen, int index){
  if(indices == NULL || indicesLen <= 0 || index < 0){
    return -1;
  }

  indiceApagar(&(*indices)[index]);

  for(int i = index; i < (*indicesLen)-1; i++){
    (*indices)[i] = (*indices)[i+1];
  }

  (*indicesLen)--;

  if((*indicesLen) == 0){
    (*indices) = NULL;
    return TRUE;
  }

  INDICE **indicesAux = (INDICE**) realloc(*indices, indiceTamanhoStruct() * (*indicesLen));
  if(indicesAux == NULL){
    printf("Erro ao realocar memoria para os indices em memoria!");
    exit(-1);
  }

  (*indices) = indicesAux;

  return TRUE;
}

int indiceGetChave(INDICE *indice){
  if(indice == NULL){
    return -1;
  }

  return indice->chave;
}

int indiceGetRRN(INDICE *indice){
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

boolean indiceApagarLista(INDICE ***indices, int indicesLen){
  for(int i = 0; i < indicesLen; i++){
    indiceApagar( &((*indices)[i]) );
  }
  free(*indices);
  (*indices) = NULL;
  return TRUE;
}

boolean indiceApagar(INDICE **indice){
  free(*indice);
  (*indice) = NULL;
  return TRUE;
}
