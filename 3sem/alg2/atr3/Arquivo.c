#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Arquivo.h"

// Funções auxiliares
static ALUNO* separarCamposAluno(char *dados);
static int salvarAlunoDados(FILE *arqDados, ALUNO *aluno);
static long int procurarChaveEmIndices(INDICE **indices, int indicesLen, int chave);
static int getIndexBuscaBinaria(int chave, INDICE **indices, int esquerda, int direita);

// Funções públicas
FILE* arquivoAbrir(char* nomeArq, char* modo){
  if(nomeArq == NULL){
    return NULL;
  }

  FILE *arq = fopen(nomeArq, modo);

  return arq;
}

int arquivoDividirOpAluno(char *linha, ALUNO **aluno){
  if(linha == NULL){
    printf("\nLinha invalida!");
    exit(-1);
  }

  // Descobrindo nome da operação
  char* auxLinha = (char*) calloc(strlen(linha)+1, sizeof(char));
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

boolean arquivoExecutarOperacao(INDICE ***indicesEmMemoria, int *qtdIndices, ALUNO *aluno, int operacao){
  boolean resultado;
  ALUNO *alunoEncontrado;
  FILE *arqDados;

  switch(operacao){
    case ARQ_INSERT:{
      arqDados = arquivoAbrir(NOME_ARQ_DADOS, "ab+");
      resultado = arquivoInsert(arqDados, indicesEmMemoria, qtdIndices, aluno);
      arquivoFechar(&arqDados);
      if(!resultado){
        printf("O Registro ja existe!\n");
      }
      break;
    }

    case ARQ_SEARCH:{
      arqDados = arquivoAbrir(NOME_ARQ_DADOS, "rb");
      alunoEncontrado = arquivoSearch( arqDados, *indicesEmMemoria, *qtdIndices, alunoGetNUSP(aluno) );
      arquivoFechar(&arqDados);
      if(alunoEncontrado != NULL){
        alunoImprimir(alunoEncontrado);
        alunoApagar(&alunoEncontrado);
      }
      else{
        printf("Registro nao encontrado!\n");
      }
      break;
    }

    case ARQ_DELETE:{
      arqDados = arquivoAbrir(NOME_ARQ_DADOS, "rb+");
      arquivoDelete( arqDados, indicesEmMemoria, qtdIndices, alunoGetNUSP(aluno) );
      arquivoFechar(&arqDados);
      break;
    }

    case ARQ_EXIT:{
      break;
    }

    default:{
      // operação inválida
      return FALSE;
      break;
    }
  }

  return TRUE;
}

boolean arquivoInsert(FILE *arqDados, INDICE ***indices, int *indicesLen, ALUNO *aluno){
  if(arqDados == NULL || aluno == NULL){
    printf("Erro ao inserir registro!");
    exit(-1);
  }

  int rrnEncontrado = procurarChaveEmIndices(*indices, *indicesLen, alunoGetNUSP(aluno));
  if(rrnEncontrado >= 0){
    // registro já existe
    return FALSE;
  }

  int rrnAtual = salvarAlunoDados(arqDados, aluno);
  if(rrnAtual < 0){
    printf("Erro ao salvar no arquivo de dados!");
    exit(-1);
  }

  boolean resultadoSalvarIndice = indiceAdicionar(indices, indicesLen, alunoGetNUSP(aluno), rrnAtual);

  if(resultadoSalvarIndice == FALSE){
    printf("Erro ao salvar no arquivo de indices!");
    exit(-1);
  }

  return TRUE;
}

ALUNO* arquivoSearch(FILE *arqDados, INDICE **indices, int indicesLen, int NUSP){
  if(arqDados == NULL || indices == NULL || indicesLen <= 0){
    return NULL;
  }

  int index = getIndexBuscaBinaria(NUSP, indices, 0, indicesLen-1);
  if(index < 0){
    return NULL;
  }

  int rrn = indiceGetRRN(indices[index]);

  ALUNO *aluno = arquivoGetDadosPorRRN(arqDados, rrn);
  return aluno;
}

boolean arquivoDelete(FILE *arqDados, INDICE ***indices, int *indicesLen, int NUSP){
  if(arqDados == NULL || (*indices) == NULL || (*indicesLen) <= 0){
    return FALSE;
  }

  int index = getIndexBuscaBinaria(NUSP, (*indices), 0, (*indicesLen)-1);
  if(index < 0){
    return FALSE;
  }
  int rrn = indiceGetRRN((*indices)[index]);

  ALUNO *aluno = arquivoGetDadosPorRRN(arqDados, rrn);
  if(aluno == NULL){
    return FALSE;
  }

  alunoSetNUSP(aluno, -1);
  int resultado = arquivoSetDadosPorRRN(arqDados, rrn, aluno);
  if(resultado <= 0){
    return FALSE;
  }

  resultado = indiceRemoverPorIndex(indices, indicesLen, index);
  if(!resultado){
    return FALSE;
  }

  alunoApagar(&aluno);

  return TRUE;
}

ALUNO* arquivoGetDadosPorRRN(FILE *arqDados, int rrn){
  if(arqDados == NULL || rrn < 0){
    return NULL;
  }

  fseek(arqDados, alunoTamanhoStruct()*rrn, SEEK_SET);

  ALUNO *aluno = alunoCriarVazio();
  int resultado = fread(aluno, alunoTamanhoStruct(), 1, arqDados);
  if(resultado <= 0){
    return NULL;
  }

  return aluno;
}

int arquivoSetDadosPorRRN(FILE *arqDados, int rrn, ALUNO *aluno){
  if(arqDados == NULL || rrn < 0 || aluno == NULL){
    return -1;
  }

  fseek(arqDados, alunoTamanhoStruct()*rrn, SEEK_SET);

  int resultado = fwrite(aluno, alunoTamanhoStruct(), 1, arqDados);

  return resultado;
}

// função dinâmica para obter o número de registros de qualquer arquivo para qualquer tamanho de registro
int arquivoNumRegistros(FILE* arq, long int tamanhoRegistro){
  if(arq == NULL){
    return -1;
  }

  fseek(arq, 0, SEEK_END);
  long int tamanho = ftell(arq);
  rewind(arq);

  int len = tamanho/tamanhoRegistro;

  return len;
}

// a ideia é carregar os indices já criados do arquivo para um vetor que será usado para buscar os alunos
// durante a execução do programa, e "descarregado" ao final do programa
long int arquivoCarregarArquivoIndice(INDICE ***indices){
  FILE *arqIndices = arquivoAbrir(NOME_ARQ_INDICES, "rb");
  if(arqIndices == NULL){
    (*indices) = NULL;
    return 0;
  }

  int qtdIndices = arquivoNumRegistros(arqIndices, indiceTamanhoStruct());
  if(qtdIndices <= 0){
    (*indices) = NULL;
    return 0;
  }
  
  (*indices) = (INDICE**) malloc(indiceTamanhoStruct() * qtdIndices );

  if((*indices) == NULL){
    printf("Erro ao alocar memoria para os indices!");
    exit(1);
  }

  for(int i = 0; i < qtdIndices; i++){
    (*indices)[i] = indiceCriarVazio();

    if((*indices)[i] == NULL){
      printf("Erro ao alocar memoria para o indice!");
      exit(1);
    }

    int resultado = fread((*indices)[i], indiceTamanhoStruct(), 1, arqIndices);
    if(resultado <= 0){
      printf("Erro ao ler arquivo de indices!");
      exit(1);
    }
  }

  arquivoFechar(&arqIndices);

  return qtdIndices;
}

boolean arquivoSalvarIndices(INDICE **indicesEmMemoria, int qtdIndices) {
  FILE *arqIndices = arquivoAbrir(NOME_ARQ_INDICES, "wb");
  if(arqIndices == NULL){
    printf("\nErro ao abrir arquivo de indices!");
    exit(1);
  }

  if(indicesEmMemoria == NULL || qtdIndices <= 0){
    return TRUE;
  }

  rewind(arqIndices);
  for(int i = 0; i < qtdIndices; i++){
    boolean salvarIndex = fwrite(indicesEmMemoria[i], indiceTamanhoStruct(), 1, arqIndices);

    if(salvarIndex == FALSE) {
      return FALSE;
    }
  }

  arquivoFechar(&arqIndices);

  return TRUE;
}

boolean arquivoFechar(FILE **arq){
  if((*arq) == NULL){
    return FALSE;
  }
  boolean result = fclose(*arq);
  *arq = NULL;
  return result;
}


// Funções auxiliares
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

static int salvarAlunoDados(FILE *arqDados, ALUNO *aluno){
  if(arqDados == NULL || aluno == NULL){
    return -1;
  }

  int resultado = fwrite(aluno, alunoTamanhoStruct(), 1, arqDados);
  if(resultado <= 0){
    return -1;
  }

  // o rrn de um novo registro é o número de registros no arquivo de dados
  int rrn = arquivoNumRegistros(arqDados, alunoTamanhoStruct()) - 1;

  return rrn;
}

static long int procurarChaveEmIndices(INDICE **indices, int indicesLen, int chave){
  if(indices == NULL || indicesLen <= 0 || chave < 0){
    return -1;
  }

  int index = getIndexBuscaBinaria(chave, indices, 0, indicesLen-1);
  if(index < 0){
    return -1;
  }
  int rrn = indiceGetRRN(indices[index]);

  return rrn;
}

static int getIndexBuscaBinaria(int chave, INDICE **indices, int esquerda, int direita){
  if(direita < esquerda){
    return -1;
  }

  int index = (esquerda + direita)/2;

  int chaveAtual = indiceGetChave(indices[index]);

  if(chaveAtual == chave){
    return index;
  }
  else if(chaveAtual < chave){
    return getIndexBuscaBinaria(chave, indices, index+1, direita);
  }
  else{
    return getIndexBuscaBinaria(chave, indices, esquerda, index-1);
  }
}
