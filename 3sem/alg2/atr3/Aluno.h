#ifndef ALUNO_H
#define ALUNO_H

#include"Util.h"

#define ALUNO_NUM_CAMPOS 5

#define ALUNO_NAME_LEN 20
#define ALUNO_SURNAME_LEN 50
#define ALUNO_COURSE_LEN 50

typedef struct aluno_st ALUNO;

ALUNO* alunoCriar(int nUSP, char* nome, char* sobrenome, char* curso, float nota);
ALUNO* alunoCriarVazio();
int alunoGetNUSP(ALUNO *aluno);
int alunoSetNUSP(ALUNO *aluno, int NUSP);
boolean alunoImprimir(ALUNO *aluno);
long int alunoTamanhoStruct();
boolean alunoApagar(ALUNO **aluno);

#endif // ALUNO_H