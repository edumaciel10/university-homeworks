#include<stdio.h>
#include <stdlib.h>

int quantidadeDeRegistros(int vet[5][5], int numero) {
  int quantidade = 0;
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5;j++) {
      if(vet[i][j] == numero ) {
        quantidade++;
      }
    }
  }
  return quantidade;
}
int jaFoiEncontrado(int *vet,int numero) {
  for (int i = 0; i < 8;i++) {
    if(numero == vet[i]) {
      return 1;
    }
  }
  return 0;
}
int encontrarRepetidos(int vetor[5][5],int *encontrados) {
  int posicao = 0;
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5;j++) {
      if(quantidadeDeRegistros(vetor, vetor[i][j]) >= 3) {
        if (jaFoiEncontrado(encontrados, vetor[i][j]) == 0) {
          encontrados = (int *)realloc(encontrados,posicao+1 * sizeof(int)); // aloco dinamicamente o array
          encontrados[posicao] = vetor[i][j];
          posicao++;
        }
      }
    }
  }
  return posicao;
}
void mostrarRegistros(int tamanho, int *encontrados) {
  for (int i = 0; i < tamanho; i++) {
    printf("%d\n", encontrados[i]);
  }
}
int main () {
  int vetor[5][5];
  int *encontrados = (int *)malloc(sizeof(int)); // aloco apenas 1 int
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5;j++) {
      scanf("%d",&vetor[i][j]);
    }
  }
  int quantidadeDeRegistros = encontrarRepetidos(vetor,encontrados);

  mostrarRegistros(quantidadeDeRegistros,encontrados);

  return 0;
}
