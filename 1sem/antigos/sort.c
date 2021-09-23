#include <stdio.h>
//Crie um programa que lê um vetor de 10 inteiros e imprime esses valores em ordem crescente.
//Obs: Os valores da resposta devem separados por espaços, na mesma linha. Ex: 1 2 3 4...

// {9,4,6,78,5,3,2,6,9,0}
//  4 6 9 5 3 2 6 9 0 78
int main()
{
  int input[10];
  for (int i = 0; i < 10; i++) // get all inputs
  {
    scanf("%d",&input[i]);
  }
  int aux = 0, troca = 1;
  while (troca == 1)
  {
    troca = 0;
    for (int i = 0; i < 10; i++)
    {
      if(i+1 == 10) continue;
      if (input[i] > input[i + 1])
      {
        troca = 1;
        aux = input[i];
        input[i] = input[i + 1];
        input[i + 1] = aux;
      }
    }
  }

  for (int i = 0; i < 10; i++)
  {
    printf("%d ",input[i]);
  }

  return 0;
}
