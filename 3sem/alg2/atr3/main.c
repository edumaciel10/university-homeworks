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
  FILE *arqIndex = arquivoAbrir(ARQ_NOME, "ab");
  
  boolean resultado;
  do{
    char * acao;
    scanf("%s", acao);
    // char* acao = strtok(linha, " ");
    if(strcmp(acao, "insert") == 0) {
      printf("On insert");
      resultado = arquivoLerLinhaSalvarAndIndexar(arqDados, arqIndex);
    }

    if(strcmp(acao, "exit") == 0) {
      resultado = FALSE;
    }

  }while(resultado);

  arquivoSelecionarOperacao(arqDados, ARQ_SHOW_ALL);
  // return 0;
  arquivoFechar(&arqDados);
  arquivoFechar(&arqIndex);

  // LEITURA
  arqDados = arquivoAbrir(ARQ_NOME, "rb");

  int len = arquivoNumRegistros(arqDados);


  // arquivoSelecionarOperacao(arq, ARQ_SHOW_SECOND_HALF);
  arquivoLerFaixa(arqDados, len-9, len);

  arquivoFechar(&arqDados);

  return 0;
}