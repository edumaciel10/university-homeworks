#include <stdio.h>
#include <stdlib.h>

// M é o método (I para inserção e M para merge),
// N é o tamanho do vetor,
// T é o número de trocas e
// C é o número de comparações.

void insertionSort(int *array, int sizeOfArray);
void mergeSort(int *array, int sizeOfArray);
void printArray(int *array, int sizeOfArray);
int main()
{
  int arrayLength = 0;

  scanf("%d", &arrayLength);

  int arraySize[arrayLength];

  int *array[arrayLength];

  for (int i = 0; i < arrayLength; i++)
  {
    scanf("%d", &arraySize[i]);
    array[i] = (int *)malloc(arraySize[i] * sizeof(int));
  }

  for (int i = 0; i < arrayLength; i++)
  {
    for (int j = 0; j < arraySize[i]; j++)
    {
      scanf("%d", &array[i][j]);
    }
  }

  for (int i = 0; i < arrayLength; i++)
  {
    insertionSort(array[i], arraySize[i]);
    // mergeSort(array[i], arraySize[i]);
  }
}

void insertionSort(int *array, int sizeOfArray)
{
  int swap = 0;
  int comparison = 0;
  int aux = 0;
  for (int i = 0; i < sizeOfArray - 1; i++)
  {
    comparison++;
    // printf("\n compare %d > %d", array[i], array[i + 1]);
    if (array[i] > array[i + 1])
    {
      swap++;
      // printf("\n swap %d -> %d", array[i], array[i + 1]);
      aux = array[i + 1];
      array[i + 1] = array[i];
      array[i] = aux;
      for (int j = i; j > 0; j--)
      {
        // printf("\n compare %d > %d", array[i], array[i + 1]);
        comparison++;
        if (array[j] < array[j - 1])
        {
          // printArray(array, sizeOfArray);
          // printf("\n swap %d -> %d", array[j], array[j + 1]);
          swap++;
          aux = array[j];
          array[j] = array[j - 1];
          array[j - 1] = aux;
          // printArray(array, sizeOfArray);
        }
        else
        {
          break;
        }
      }
    }
  }
  printf("\n I %d %d %d", sizeOfArray, swap, comparison);
}

void printArray(int *array, int sizeOfArray)
{
  printf("\n <PRINT ARRAY> \n");
  for (int i = 0; i < sizeOfArray; i++)
  {
    printf("%d ", array[i]);
  }
  printf("\n <\\PRINT ARRAY> \n");
}