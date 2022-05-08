#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Util.h"
#include"Aluno.h"
#include"Arquivo.h"

#define QTD_REGISTROS 10

int main(){
  // INCLUSÃO
  FILE *arq = arquivoAbrir(ARQ_NOME, "ab");
  
  boolean resultado;

  do{
    resultado = arquivoLerLinhaSalvar(arq);
  }while(resultado);
  // return 0;
  arquivoFechar(&arq);

  // LEITURA
  arq = arquivoAbrir(ARQ_NOME, "rb");

  int len = arquivoNumRegistros(arq);


  // arquivoSelecionarOperacao(arq, ARQ_SHOW_SECOND_HALF);
  arquivoLerFaixa(arq, len-9, len);

  arquivoFechar(&arq);

  return 0;
}