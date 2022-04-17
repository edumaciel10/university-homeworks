#include<stdio.h>
#include<stdlib.h>
#include"Arquivo.h"

// Funções auxiliares
static boolean arquivoLeFaixa(FILE *arq, int comeco, int fim, int len);
static ALUNO* arquivoLeRegistro(FILE *arq);

// Funções públicas
FILE* arquivoAbrir(char* nomeArq){
  if(nomeArq == NULL){
    return NULL;
  }

  FILE *arq = fopen(nomeArq, "rb");

  return arq;
}

boolean arquivoSelecionaOperacao(FILE *arq, int op){
  boolean result;
  int comeco, fim;

  fseek(arq, 0, SEEK_END);

  long int tamanho = ftell(arq);

  // quantidade de alunos no arquivo
  int len = tamanho/alunoTamanhoStruct();

  switch(op){
    case ARQ_SHOW_ALL:
      result = arquivoLeFaixa(arq, 1, len, len);
      break;

    case ARQ_SHOW_FIRST_HALF:
      result = arquivoLeFaixa(arq, 1, len/2, len);
      break;

    case ARQ_SHOW_SECOND_HALF:
      result = arquivoLeFaixa(arq, 1+(len/2), len, len);
      break;

    case ARQ_SHOW_SLICE:
      scanf("%d %d", &comeco, &fim);
      result = arquivoLeFaixa(arq, comeco, fim, len);
      break;

    case ARQ_SHOW_ONE:
      scanf("%d", &comeco);
      result = arquivoLeFaixa(arq, comeco, comeco, len);
      break;

    default:
      return FALSE;
  }

  return result;
}

// este é o método principal do programa, basicamente todas as operações são baseadas em ler uma faixa de registros
// então nós apenas manipulamos onde que vai começar e onde que vai terminar a leitura dentro do arquivo
static boolean arquivoLeFaixa(FILE *arq, int comeco, int fim, int len){
  if(arq == NULL){
    return FALSE;
  }

  ALUNO *aluno;
  fseek(arq, alunoTamanhoStruct()*(comeco-1), SEEK_SET);

  // de acordo com o projeto a ideia é apenas consultar o aluno no arquivo e exibir seus dados
  // como não será utilizado nada mais que isso, é possível liberar a memória após a leitura.
  for(int i = comeco; i <= fim && i <= len; i++){
    aluno = arquivoLeRegistro(arq);

    if(aluno != NULL){
      alunoImprimir(aluno);
    }

    alunoApagar(&aluno);

    if(i < fim && i < len){
      printf("\n");
    }
  }

  return TRUE;
}

static ALUNO* arquivoLeRegistro(FILE *arq){
  int nUSP;
  char nome[50];
  char curso[50];
  float nota;

  if(arq != NULL && !feof(arq)){
    fread(&nUSP, sizeof(int), 1, arq);
    fread(nome, sizeof(char[50]), 1, arq);
    fread(curso, sizeof(char[50]), 1, arq);
    fread(&nota, sizeof(float), 1, arq);

    ALUNO* aluno = alunoCriar(nUSP, nome, curso, nota);
    return aluno;
  }

  return NULL;
}

boolean arquivoFechar(FILE **arq){
  boolean result = fclose(*arq);
  *arq = NULL;
  return result;
}
