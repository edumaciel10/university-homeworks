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

  // utilizamos int para operacao para ficar mais fácil dar um valor significativo as operações utilizando constantes

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

  // descarregando os indices em memoria para o disco
  boolean salvarIndicesArquivo = arquivoSalvarIndices(indicesEmMemoria, qtdIndices);
  if(!salvarIndicesArquivo){
    printf("\nErro ao salvar indices no arquivo!");
    exit(1);
  }

  indiceApagarLista(&indicesEmMemoria, qtdIndices);

  return 0;
}