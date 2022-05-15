#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Aluno.h"

struct aluno_st{
  int nUSP;
  char nome[ALUNO_NAME_LEN];
  char sobrenome[ALUNO_SURNAME_LEN];
  char curso[ALUNO_COURSE_LEN];
  float nota;
};


// Funções públicas
ALUNO* alunoCriar(int nUSP, char *nome_, char *sobrenome_, char *curso_, float nota){
  char nome[ALUNO_NAME_LEN];
  char sobrenome[ALUNO_SURNAME_LEN];
  char curso[ALUNO_COURSE_LEN];

  strcpy(nome, nome_);
  strcpy(sobrenome, sobrenome_);
  strcpy(curso, curso_);

  if(nUSP > 0 && nome != NULL && sobrenome != NULL && curso != NULL && nota >= 0 && nota <= 10){
    ALUNO* aluno = malloc(sizeof(ALUNO));
    if(aluno == NULL){
      return NULL;
    }

    aluno->nUSP = nUSP;
    strcpy(aluno->nome, nome);
    strcpy(aluno->sobrenome, sobrenome);
    strcpy(aluno->curso, curso);
    aluno->nota = nota;

    return aluno;
  }

  return NULL;
}

ALUNO* alunoCriarVazio(){
  ALUNO *aluno = malloc(sizeof(ALUNO));
  if(aluno == NULL){
    return NULL;
  }

  aluno->nUSP = -1;
  strcpy(aluno->nome,"");
  strcpy(aluno->sobrenome,"");
  strcpy(aluno->curso,"");
  aluno->nota = -1;

  return aluno;
}

boolean alunoImprimir(ALUNO *aluno){
  if(aluno == NULL){
    return FALSE;
  }

  printf("-------------------------------");
  printf("\nUSP number: %d", aluno->nUSP);
  printf("\nName: %s", aluno->nome);
  printf("\nSurname: %s", aluno->sobrenome);
  printf("\nCourse: %s", aluno->curso);
  printf("\nTest grade: %.2f", aluno->nota);
  printf("\n-------------------------------\n");

  return TRUE;
}

int alunoGetNUSP(ALUNO *aluno){
  if(aluno == NULL){
    return FALSE;
  }

  return aluno->nUSP;
}

int alunoSetNUSP(ALUNO *aluno, int NUSP){
  if(aluno == NULL){
    return FALSE;
  }

  aluno->nUSP = NUSP;
  return TRUE;
}

long int alunoTamanhoStruct(){
  return sizeof(ALUNO);
}

boolean alunoApagar(ALUNO **aluno){
  if((*aluno) == NULL){
    return TRUE;
  }

  free((*aluno));
  (*aluno) = NULL;
  return TRUE;
}
