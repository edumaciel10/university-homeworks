#include<stdio.h>
#include<stdlib.h>

#include"Util.h"
#include"Aluno.h"
#include"Arquivo.h"

int main(){
  char* nomeArqDados = "dados.bin";
  char* nomeArqIndices = "indices.bin";

  FILE *arqDados = arquivoAbrir(nomeArqDados, "ab+");
  FILE *arqIndices = arquivoAbrir(nomeArqIndices, "ab+");

  INDICE **indicesEmMemoria;
  int qtdIndices = arquivoCarregarArquivoIndice(arqIndices, &indicesEmMemoria);

  char *input;
  ALUNO *alunoAuxiliar, *alunoEncontrado;
  int operacao;
  boolean resultado;
  do{
    input = readLine();
    alunoAuxiliar = NULL;
    alunoEncontrado = NULL;

    operacao = arquivoDividirOpALuno(input, &alunoAuxiliar);

    switch(operacao){
      case ARQ_INSERT:
        resultado = arquivoInsert(arqDados, indicesEmMemoria, &qtdIndices, alunoAuxiliar);
        break;

      case ARQ_SEARCH:
        alunoEncontrado = arquivoSearch( arqDados, indicesEmMemoria, qtdIndices, alunoGetNUSP(alunoAuxiliar) );
        if(alunoEncontrado != NULL){
          alunoImprimir(alunoEncontrado);
        }
        else{
          printf("Registro nao encontrado!\n");
        }
        break;

      case ARQ_DELETE:
        resultado = arquivoDelete( arqDados, indicesEmMemoria, qtdIndices, alunoGetNUSP(alunoAuxiliar) );
        break;

      case ARQ_EXIT:
        break;

      default:
        printf("\nOperacao nao encontrada!");
        exit(1);
        break;
    }
    printf("FREE INPUT\n");
    free(input);

    if(!resultado){
      printf("\nErro ao executar operacao!");
      exit(1);
    }

    if(alunoAuxiliar != NULL){
      free(alunoAuxiliar);
    }
    if(alunoEncontrado != NULL){
      free(alunoEncontrado);
    }

  }while( operacao != ARQ_EXIT );


  arquivoFechar(&arqDados);
  arquivoFechar(&arqIndices);

  return 0;
}