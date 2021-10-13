#include <stdio.h>
#include <stdlib.h>

void compareMethods(int array[], int arraySize)
{
  int shellOperations = shellSort(array, arraySize);
  // shellSort(array, arraySize, shellOperations);
  int quickOperations = quickSort(array, arraySize + 1);

  // printf("\n quickOperations = %d ", quickOperations);
  if (quickOperations < shellOperations)
  {
    printf("Q ");
  }
  if (shellOperations < quickOperations)
  {
    printf("S ");
  }
  if (shellOperations == quickOperations)
  {
    printf("- ");
  }
}
int shellSort(int v[], int n)
{
  int count = 0;

  int gap = 1;
  while (gap <= n)
  {
    gap *= 2;
  }
  gap = gap / 2 - 1;

  while (gap > 0)
  {
    int j;

    for (int k = 0; k < gap; k++)
    {
      for (int i = k + gap; i < n; i += gap)
      {
        int x = v[i];
        count++;

        j = i - gap;
        while (j >= 0)
        {
          count++;
          if (v[j] > x)
          {
            v[j + gap] = v[j];
            count++;

            j = -gap;
          }
          else
          {
            break;
          }
        }
        v[j + gap] = x;
        count++;
      }
    }
    gap /= 2;
  }

  return count;
}

int _quick(int array[], int init, int final, int count)
{
  if (init >= final)
  {
    return;
  }
  int indexOfPivot = (init + final) / 2;
  int pivot = array[indexOfPivot];
  int indexOfInit = init;
  int indexOfFinal = final;
  int aux = 0;
  while (1)
  {
    while (array[indexOfInit] < pivot)
    {
      // *operations++;
      indexOfInit++;
    }
    while (array[indexOfFinal] > pivot)
    {
      // *operations++;
      indexOfFinal--;
    }
    if (indexOfFinal <= indexOfInit)
    {
      break;
    }
    aux = array[indexOfInit];
    array[indexOfInit] = array[indexOfFinal];
    array[indexOfFinal] = aux;
    *operations++;
    *operations++;
    indexOfInit++;
    indexOfFinal--;
  }
  _quick(array, init, indexOfFinal, operations);
  _quick(array, indexOfFinal + 1, final, operations);
}

int quickSort(int array[], int arraySize)
{
  int operations = _quick(array, 0, arraySize - 1);
  for (int i = 0; i < arraySize; i++)
  {
    printf("%d ", array[i]);
  }
  printf("\n");
}
int main()
{
  int arraySize = 0;
  scanf("%d", &arraySize);
  int array[arraySize];
  for (int i = 0; i < arraySize; i++)
  {
    scanf("%d", &array[i]);
  }
  int *tempArray = malloc(1 * sizeof(int));

  for (int i = 0; i < arraySize; i++)
  {
    tempArray[i] = array[i];
    compareMethods(tempArray, i + 1);
    if (i + 1 < arraySize)
    {
      tempArray = (int *)realloc(tempArray, (i + 1) * sizeof(int));
    }
    // continue;
    // compareMethods(tempArray, i + 1);
  }

  return 0;
}
// A ideia deste método é ver qual fez menos operações para printar.
// Ai você coloca a quantidade de operações dentro do programa
// a unica coisa que você vai alterar é o metodo ShellSort, ok?
// Faça um programa em C que leia o número N de elementos de um vetor V. Após isso, leia os N elementos de V. O programa deve ordenar todos os subvetores de V utilizando os métodos Shell Sort e Quick Sort. Para cada subvetor de V, deve-se imprimir qual método fez menos operações (comparação + cópias), imprimindo Q quando for o Quick Sort, S quando for o Shell Sort e o caractere hífen quando o número de contagens for igual. O Shell deve utilizar os gaps no formato 2^k - 1, e o Quick Sort deve utilizar o elemento do meio como pivô (como os códigos vistos em aula).

// Por exemplo, considere o seguinte vetor V: [3, 6, 5, 2]. Os subvetores de V são: V1: [3], V2: [3, 6], V3: [3, 6, 5], e V4 = [3, 6, 5, 2]. Para V1, o número de operações é o mesmo para os dois métodos. Para V2, V3 e V4, o Shell Sort realiza menos operações. Portanto, seu programa deve imprimir: - S S S