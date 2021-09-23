#include<stdio.h>
// #include <stdlib.h>
//Ler uma matriz de 5x5 inteiros e imprimir o menor e o maior valor.
int main() {
  int array[5][5],maior=0,menor=0;
  // srand(100)
  for (int i = 0; i < 5; i++)  {
    for (int j = 0; j < 5; j++){
      scanf("%d",&array[i][j]);
    }
  }
  for (int i = 0; i < 5; i++)  {
    for (int j = 0; j < 5; j++){
      if(i==j && i==0) {
        menor = maior = array[i][j];
      }
      if(array[i][j] > maior) {
        maior = array[i][j];
      }
      if(array[i][j] < menor) {
        menor = array[i][j];
      }
    }
  }
  
  
  printf("%d %d", menor,maior);

  
  return 0;
}
