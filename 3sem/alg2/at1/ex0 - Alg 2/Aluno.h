#ifndef ALUNO_H
#define ALUNO_H

#include"Util.h"

typedef struct aluno_st ALUNO;

ALUNO* alunoCriar(int nUSP, char* nome, char* curso, float nota);
boolean alunoImprimir(ALUNO *aluno);
long int alunoTamanhoStruct();
boolean alunoApagar(ALUNO **aluno);

#endif // ALUNO_H