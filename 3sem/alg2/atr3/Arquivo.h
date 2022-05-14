#ifndef ARQUIVO_H
#define ARQUIVO_H

#include"Aluno.h"
#include"Util.h"
#include"stdio.h" // para utilizar as assinaturas de FILE

#define ARQ_NOME "data.bin"
#define ARQ_INDEX "index.bin"

#define ARQ_SEPARADOR ","
#define ARQ_SHOW_ALL 1
#define ARQ_SHOW_FIRST_HALF 2
#define ARQ_SHOW_SECOND_HALF 3
#define ARQ_SHOW_SLICE 4
#define ARQ_SHOW_ONE 5

FILE* arquivoAbrir(char* nomeArq, char* modo);

boolean arquivoLerLinhaSalvarAndIndexar(FILE* arqDados, FILE* arqIndex);
boolean arquivoSalvarLinha(FILE* arq, char* linha);
boolean arquivoIndexarLinha(FILE* arqIndex, char* linha);
boolean arquivoSalvarAluno(FILE* arq, ALUNO* aluno);

int arquivoNumRegistros(FILE* arq);
boolean arquivoSelecionarOperacao(FILE *arq, int op);
boolean arquivoLerFaixa(FILE *arq, int comeco, int fim);

boolean arquivoFechar(FILE **arq);


#endif // ARQUIVO_H