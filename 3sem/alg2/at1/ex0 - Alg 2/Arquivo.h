#ifndef ARQUIVO_H
#define ARQUIVO_H

#include"Aluno.h"
#include"Util.h"

#define ARQ_SHOW_ALL 1
#define ARQ_SHOW_FIRST_HALF 2
#define ARQ_SHOW_SECOND_HALF 3
#define ARQ_SHOW_SLICE 4
#define ARQ_SHOW_ONE 5

FILE* arquivoAbrir(char* arq);
boolean arquivoSelecionaOperacao(FILE *arq, int op);
boolean arquivoFechar(FILE **arq);


#endif // ARQUIVO_H