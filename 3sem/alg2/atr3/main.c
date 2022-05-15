#include<stdio.h>
#include<stdlib.h>

#include"Util.h"
#include"Aluno.h"
#include"Arquivo.h"

int main(){
  INDICE **indicesEmMemoria;
  int qtdIndices = arquivoCarregarArquivoIndice(&indicesEmMemoria);

  char *input;
  ALUNO *aluno;
  int operacao;
  boolean resultado;
  do{
    input = readLine();

    aluno = NULL;

    operacao = arquivoDividirOpAluno(input, &aluno);
    resultado = arquivoExecutarOperacao(&indicesEmMemoria, 
                                        &qtdIndices, 
                                        aluno, 
                                        operacao);
    if(!resultado){
      printf("\nErro ao executar operacao de codigo %d", operacao);
      exit(1);
    }

    free(input);

    if(aluno != NULL){
      free(aluno);
    }

  }while( operacao != ARQ_EXIT );

  boolean salvarIndicesArquivo = arquivoSalvarIndices(indicesEmMemoria, qtdIndices);
  if(!salvarIndicesArquivo){
    printf("\nErro ao salvar indices no arquivo!");
    exit(1);
  }

  indiceApagarLista(&indicesEmMemoria, qtdIndices);

  return 0;
}