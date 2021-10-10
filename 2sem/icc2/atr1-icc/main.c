#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* selecao(int* array,int tamanho){
  int i, j, min, aux;
  for (i = 0; i < (tamanho-1); i++) 
  {
     min = i;
     for (j = (i+1); j < tamanho; j++) {
       printf("C %d %d\n", min, j);
       if (array[j] < array[min])
         min = j;
     }
     if (i != min) {
       printf("T %d %d\n", i, min);
       aux = array[i];
       array[i] = array[min];
       array[min] = aux;
     }
  }
  return array;
}
int* bolha(int* array,int tamanho){
  int aux = 0, troca=1, sentinela = tamanho;
  while(troca == 1 && tamanho-1 >0) {
    troca = 0;
    tamanho = sentinela;
    for (int i = 0; i < tamanho; i++)
    {
      if(i+1 == tamanho) {
        break;
      }
      printf("C %d %d\n", i ,i + 1);
      if (array[i] > array[i + 1])
      {
        troca = 1;
        aux = array[i];
        array[i] = array[i + 1];
        array[i + 1] = aux;
        sentinela = i+1;
        printf("T %d %d\n", i, i + 1);
      }
    }
  }

  return array;
}
int main()
{
  int tamanho = 0;
  char metodo[20];
  scanf("%s", metodo);
  scanf("%d", &tamanho);
  int *array = (int *)malloc(sizeof(int) * tamanho);
  for (int i = 0; i < tamanho; i++)
  {
    scanf("%d", &array[i]);
  }
  if (strcmp(metodo, "selecao") == 0)
  {
    array = selecao(array, tamanho);
  }
  else
  {
    array = bolha(array, tamanho);
  }
  for (int i = 0; i < tamanho; i++)
  {
    printf("%d ", array[i]);
  }
  return 0;
}

