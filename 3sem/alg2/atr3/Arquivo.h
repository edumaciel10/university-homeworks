#ifndef ARQUIVO_H
#define ARQUIVO_H

#include"Aluno.h"
#include"Indice.h"
#include"stdio.h"
#include"Util.h"

#define NOME_ARQ_DADOS "dados.bin"
#define NOME_ARQ_INDICES "indices.bin"

#define ARQ_SEPARADOR ","

#define ARQ_EXIT 0
#define ARQ_INSERT 1
#define ARQ_SEARCH 2
#define ARQ_DELETE 3

FILE* arquivoAbrir(char *arq, char *modo);

int arquivoDividirOpAluno(char *linha, ALUNO **aluno);
boolean arquivoExecutarOperacao(INDICE ***indicesEmMemoria, int *qtdIndices, ALUNO *aluno, int operacao);

boolean arquivoInsert(FILE *arqDados, INDICE ***indices, int *indicesLen, ALUNO *aluno);
ALUNO* arquivoSearch(FILE *arqDados, INDICE **indices, int indicesLen, int NUSP);
boolean arquivoDelete(FILE *arqDados, INDICE ***indices, int *indicesLen, int NUSP);

ALUNO* arquivoGetDadosPorRRN(FILE *arqDados, int rrn);
int arquivoSetDadosPorRRN(FILE *arqDados, int rrn, ALUNO *aluno);
int arquivoNumRegistros(FILE* arq, long int tamanhoRegistro);

long int arquivoCarregarArquivoIndice(INDICE ***indices);
boolean arquivoSalvarIndices(INDICE **indicesEmMemoria, int qtdIndices);

boolean arquivoFechar(FILE **arq);


#endif // ARQUIVO_H