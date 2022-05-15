#ifndef ARQUIVO_H
#define ARQUIVO_H

#include"Aluno.h"
#include"Indice.h"
#include"stdio.h"
#include"Util.h"

#define ARQ_SEPARADOR ","

#define ARQ_EXIT 0
#define ARQ_INSERT 1
#define ARQ_SEARCH 2
#define ARQ_DELETE 3

FILE* arquivoAbrir(char *arq, char *modo);
boolean arquivoSalvarIndices(FILE* arqIndices, INDICE **indicesEmMemoria, int qtdIndices);
int arquivoDividirOpALuno(char *linha, ALUNO **aluno);
boolean arquivoInsert(FILE *arqDados, INDICE ***indices, int *indicesLen, ALUNO *aluno);
ALUNO* arquivoSearch(FILE *arqDados, INDICE **indices, int indicesLen, int NUSP);
boolean arquivoDelete(FILE *arqDados, INDICE **indices, int indicesLen, int NUSP);
long int arquivoCarregarArquivoIndice(FILE *arqIndices, INDICE ***indices);
boolean arquivoFechar(FILE **arq);
int arquivoNumRegistros(FILE* arq, long int tamanhoRegistro);


#endif // ARQUIVO_H