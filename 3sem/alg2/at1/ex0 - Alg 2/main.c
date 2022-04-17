#include<stdio.h>
#include<stdlib.h>
#include"Util.h"
#include"Aluno.h"
#include"Arquivo.h"

int main(){
  char* nomeArq;
  int operacao;

  nomeArq = readLine();
  scanf("%d", &operacao);

  FILE* arq = arquivoAbrir(nomeArq);

  if(arq == NULL){
    printf("\nErro ao abrir o arquivo");
    exit(-1);
  }

  boolean result = arquivoSelecionaOperacao(arq, operacao);
  
  if(!result){
    printf("\nErro ao selecionar a operacao");
    exit(-1);
  }

  free(nomeArq);

  arquivoFechar(&arq);

  return 0;
}