#ifndef ALUNO_H
#define ALUNO_H

#include"Util.h"

#define ALUNO_NUM_CAMPOS 4

typedef struct aluno_st ALUNO;

ALUNO* alunoCriar(int nUSP, char *nome_,char *sobrenome_, char *curso_, float nota);
boolean alunoImprimir(ALUNO *aluno);
long int alunoTamanhoStruct();
boolean alunoApagar(ALUNO **aluno);

#endif // ALUNO_H