#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Arquivo.h"

// Funções auxiliares
static ALUNO* arquivoLerRegistro(FILE *arq);

// Funções públicas
FILE* arquivoAbrir(char* nomeArq, char* modo){
  if(nomeArq == NULL){
    printf("\nErro ao abrir o arquivo");
    exit(-1);
  }

  FILE *arq = fopen(nomeArq, modo);

  return arq;
}

boolean arquivoLerLinhaSalvar(FILE* arq){
  if(arq == NULL){
    return FALSE;
  }

  char* linha = readLine();
  boolean resultado;

  if(strlen(linha) < ALUNO_NUM_CAMPOS){
    // linha vazia
    // printf("Linha vazia");
    resultado = FALSE;
  }
  else{
    // printf("\n%s", linha);
    resultado = arquivoSalvarLinha(arq, linha);
  }

  free(linha);

  return resultado;
}

boolean arquivoSalvarLinha(FILE* arq, char* linha){
  if(arq == NULL || linha == NULL || strlen(linha) < ALUNO_NUM_CAMPOS){
    return FALSE;
  }

  // nUSP
  char* nUSP_ = strtok(linha, ARQ_SEPARADOR);
  int nUSP = atoi(nUSP_);

  // nome
  char* nome = strtok(NULL, ARQ_SEPARADOR);

  // curso
  char* curso = strtok(NULL, ARQ_SEPARADOR);

  // nota
  char* nota_ = strtok(NULL, ARQ_SEPARADOR);
  int nota = atof(nota_);

  ALUNO *aluno = alunoCriar(nUSP, nome, curso, nota);
  if(aluno == NULL){
    return FALSE;
  }

  boolean resultado = arquivoSalvarAluno(arq, aluno);

  alunoApagar(&aluno);

  return resultado;
}

boolean arquivoSalvarAluno(FILE* arq, ALUNO* aluno){
  if(arq == NULL || aluno == NULL){
    return FALSE;
  }

  boolean resultado = fwrite(aluno, alunoTamanhoStruct(), 1, arq);

  if(!resultado){
    printf("\nErro ao salvar no arquivo");
    exit(-1);
  }

  return resultado;
}

int arquivoNumRegistros(FILE* arq){
  if(arq == NULL){
    return -1;
  }

  fseek(arq, 0, SEEK_END);

  long int tamanho = ftell(arq);

  // quantidade de alunos no arquivo
  fseek(arq, 0, SEEK_SET);
  // printf("tamnho: %ld\n", tamanho);
  // printf("alinoTamanhoStruct: %ld\n", alunoTamanhoStruct());
  int len = tamanho/alunoTamanhoStruct();
  return len;
}

boolean arquivoSelecionarOperacao(FILE *arq, int op){
  boolean result;
  int comeco, fim, len;

  len = arquivoNumRegistros(arq);
  // printf("len = arquivoNumRegistros(arq); === %d",len)
  switch(op){
    case ARQ_SHOW_ALL:
      result = arquivoLerFaixa(arq, 1, len);
      break;

    case ARQ_SHOW_FIRST_HALF:
      result = arquivoLerFaixa(arq, 1, len/2);
      break;

    case ARQ_SHOW_SECOND_HALF:
      result = arquivoLerFaixa(arq, 1+(len/2), len);
      break;

    case ARQ_SHOW_SLICE:
      scanf("%d %d", &comeco, &fim);
      result = arquivoLerFaixa(arq, comeco, fim);
      break;

    case ARQ_SHOW_ONE:
      scanf("%d", &comeco);
      result = arquivoLerFaixa(arq, comeco, comeco);
      break;

    default:
      return FALSE;
  }

  return result;
}

// este é o método principal do programa, basicamente todas as operações são baseadas em ler uma faixa de registros
// então nós apenas manipulamos onde que vai começar e onde que vai terminar a leitura dentro do arquivo
boolean arquivoLerFaixa(FILE *arq, int comeco, int fim){
  if(arq == NULL){
    printf("\nErro ao ler faixa do arquivo");
    exit(-1);
  }
  ALUNO *aluno;
  int len = arquivoNumRegistros(arq);
  
  fseek(arq, alunoTamanhoStruct()*(comeco-1), SEEK_SET);


  // de acordo com o projeto a ideia é apenas consultar o aluno no arquivo e exibir seus dados
  // como não será utilizado nada mais que isso, é possível liberar a memória após a leitura.
  for(int i = comeco; i <= fim && i <= len; i++){
    aluno = arquivoLerRegistro(arq);

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

static ALUNO* arquivoLerRegistro(FILE *arq){
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
