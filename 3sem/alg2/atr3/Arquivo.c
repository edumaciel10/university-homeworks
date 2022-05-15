#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Arquivo.h"

// Funções auxiliares
static ALUNO* separarCamposAluno(char *dados);

// Funções públicas
FILE* arquivoAbrir(char* nomeArq, char* modo){
  if(nomeArq == NULL){
    return NULL;
  }

  FILE *arq = fopen(nomeArq, modo);
  if(arq == NULL){
    printf("\nErro ao abrir o arquivo");
    exit(-1);
  }

  return arq;
}

boolean arquivoSalvarIndices(FILE* arqIndices, INDICE **indicesEmMemoria, int qtdIndices) {
  printf("\nSalvando indices em arquivo...");
  if(indicesEmMemoria == NULL){
    return FALSE;
  }

  for(int i = 0; i < qtdIndices; i++){
    // indiceImprimir(indicesEmMemoria[i]);

    boolean salvarIndex = fwrite(indicesEmMemoria[i], indiceTamanhoStruct(), 1, arqIndices);

    if(salvarIndex == FALSE) {
      return FALSE;
    }
  }

  return TRUE;

}


int arquivoDividirOpALuno(char *linha, ALUNO **aluno){
  if(linha == NULL){
    printf("\nLinha invalida!");
    exit(-1);
  }

  // Descobrindo nome da operação
  char* auxLinha = calloc(strlen(linha)+1, sizeof(char));
  strcpy(auxLinha, linha);
  char* nomeOperacao = strtok(auxLinha, " ");

  // String com os parâmetros da operação
  char* dados = strchr(linha, ' ');

  int NUSP, operacao;
  if( strcmp(nomeOperacao, "insert") == 0 ){
    operacao = ARQ_INSERT;

    (*aluno) = separarCamposAluno(dados);
  }
  else if( strcmp(nomeOperacao, "search") == 0 ){
    operacao = ARQ_SEARCH;

    NUSP = atoi(dados);
    (*aluno) = alunoCriarVazio();
    alunoSetNUSP(*aluno, NUSP);
  }
  else if( strcmp(nomeOperacao, "delete") == 0 ){
    operacao = ARQ_DELETE;

    NUSP = atoi(dados);
    (*aluno) = alunoCriarVazio();
    alunoSetNUSP(*aluno, NUSP);
  }
  else if( strcmp(nomeOperacao, "exit") == 0 ){
    operacao = ARQ_EXIT;
  }
  else{
    operacao = -1;
  }

  free(auxLinha);

  return operacao;
}

static ALUNO* separarCamposAluno(char *dados){
  if(dados == NULL || strlen(dados) < ALUNO_NUM_CAMPOS){
    return NULL;
  }

  // nUSP
  char* nUSP_ = strtok(dados, ARQ_SEPARADOR);
  int nUSP = atoi(nUSP_);

  // nome
  char* nome = strtok(NULL, ARQ_SEPARADOR);

  // sobrenome
  char* sobrenome = strtok(NULL, ARQ_SEPARADOR);

  // curso
  char* curso = strtok(NULL, ARQ_SEPARADOR);

  // nota
  char* nota_ = strtok(NULL, ARQ_SEPARADOR);
  float nota = atof(nota_);

  ALUNO *aluno = alunoCriar(nUSP, nome, sobrenome, curso, nota);

  return aluno;
}

boolean arquivoInsert(FILE *arqDados, INDICE ***indices, int *indicesLen, ALUNO *aluno){
  if(arqDados == NULL || aluno == NULL){
    printf("Erro ao inserir registro!");
    exit(1);
  }

  boolean resultadoSalvarDados = fwrite(aluno, alunoTamanhoStruct(), 1, arqDados);

  if(!resultadoSalvarDados){
    printf("\nErro ao salvar no arquivo de dados");
    exit(-1);
  }
  // salva o rrn sendo o último registro salvo no arquivo de dados
  int rrn = arquivoNumRegistros(arqDados, alunoTamanhoStruct());
  boolean resultadoSalvarIndex = indiceSalvar(indices, indicesLen, alunoGetNUSP(aluno), rrn);

  if(resultadoSalvarIndex == FALSE){
    printf("Erro ao salvar no arquivo de indices");
    exit(-1);
  }

  return TRUE;
}

ALUNO* arquivoSearch(FILE *arqDados, INDICE **indices, int indicesLen, int NUSP){
  printf("pesquisei! :D\n");
  return NULL;
}

boolean arquivoDelete(FILE *arqDados, INDICE **indices, int indicesLen, int NUSP){
  printf("deletei! :D\n");
  return TRUE;
}

// função dinâmica para obter o número de registros de qualquer arquivo para qualquer tamanho de registro
int arquivoNumRegistros(FILE* arq, long int tamanhoRegistro){
  if(arq == NULL){
    return -1;
  }

  fseek(arq, 0, SEEK_END);

  long int tamanho = ftell(arq);
  rewind(arq);

  fseek(arq, 0, SEEK_SET);

  int len = tamanho/tamanhoRegistro;

  return len;
}
// a ideia é carregar os indices já criados do arquivo para um vetor que será usado para buscar os alunos
// durante a execução do programa, e "descarregado" ao final do programa
long int arquivoCarregarArquivoIndice(FILE *arqIndices, INDICE ***indices){
  // printf("\nCarregando indices do arquivo...");
  if(arqIndices == NULL){
    return -1;
  }

  fseek(arqIndices, 0, SEEK_END);
  long int tamanhoArq = ftell(arqIndices);
  rewind(arqIndices);

  long int qtdIndices = tamanhoArq / indiceTamanhoStruct();
  if(qtdIndices == 0){
    (*indices) = NULL;
    return 0;
  }
  
  (*indices) = (INDICE**) malloc(indiceTamanhoStruct() * qtdIndices );

  if((*indices) == NULL){
    printf("Erro ao alocar memoria para os indices!");
    exit(1);
  }

  for(int i = 0; i < qtdIndices; i++){
    (*indices)[i] = (INDICE*) malloc(indiceTamanhoStruct());

    fread((*indices)[i], indiceTamanhoStruct(), 1, arqIndices);
    // indiceImprimir((*indices)[i]);
    if((*indices)[i] == NULL){
      printf("Erro ao alocar memoria para os indices!");
      exit(1);
    }
  }

  return qtdIndices;
}

boolean arquivoFechar(FILE **arq){
  boolean result = fclose(*arq);
  *arq = NULL;
  return result;
}
