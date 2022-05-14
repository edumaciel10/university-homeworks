#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Aluno.h"

struct aluno_st{
  int nUSP;
  char nome[50];
  char sobrenome[50];
  char curso[50];
  float nota;
};


// Funções públicas
ALUNO* alunoCriar(int nUSP, char *nome_,char *sobrenome_, char *curso_, float nota){
  char nome[50];
  char sobrenome[50];
  char curso[50];
  strcpy(nome, nome_);
  strcpy(sobrenome, sobrenome_);
  strcpy(curso, curso_);

  boolean nUSPValido = nUSP > 0 ;
  boolean nomeValido = strlen(nome) > 0;
  boolean sobrenomeValido = strlen(sobrenome) > 0;
  boolean cursoValido = strlen(curso) > 0;
  boolean notaValida =  nota >= 0 && nota <= 10;

  if(nUSPValido && nomeValido && sobrenomeValido && cursoValido && notaValida){
    ALUNO* aluno = (ALUNO*) malloc(sizeof(ALUNO));
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

boolean alunoImprimir(ALUNO *aluno){
  if(aluno == NULL){
    return FALSE;
  }

  printf("nUSP: %d", aluno->nUSP);
  printf("\nNome: %s", aluno->nome);
  printf("\nSobrenome: %s", aluno->sobrenome);
  printf("\nCurso: %s", aluno->curso);
  printf("\nNota: %.2f\n", aluno->nota);

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
