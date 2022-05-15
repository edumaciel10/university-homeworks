#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Util.h"
#include"Aluno.h"
#include"Arquivo.h"

#define QTD_REGISTROS 10

int main(){
  // INCLUSÃO
  FILE *arqDados = arquivoAbrir(ARQ_NOME, "ab");
  FILE *arqIndex = arquivoAbrir(ARQ_INDEX, "ab");
  
  boolean resultado;
  do{
    char * acao;
    scanf("%s", acao);
    // printf("acao: %s\n", acao);
    // char* acao = strtok(linha, " ");
    if(strcmp(acao, "insert") == 0) {
      // printf("On insert");
      resultado = arquivoLerLinhaSalvarAndIndexar(arqDados, arqIndex);
    }

    if(strcmp(acao, "exit") == 0) {
      resultado = FALSE;
    }

  }while(resultado);

  // return 0;
  arquivoFechar(&arqDados);
  arquivoFechar(&arqIndex);

  // LEITURA
  arqDados = arquivoAbrir(ARQ_NOME, "rb");
  printf("\n\n");
  arquivoSelecionarOperacao(arqDados, ARQ_SHOW_ALL);

  arquivoFechar(&arqDados);

  return 0;
}