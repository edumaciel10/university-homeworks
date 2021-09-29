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

void insertionSort(int array[], int sizeOfArray)
{
  int swap = 0;
  int actualValue = 0;
  int comparison = 0;
  int j = 0;
  for (int i = 1; i < sizeOfArray; i++)
  {
    actualValue = array[i];
    j = i - 1;
    swap++;
    comparison++;
    while (j >= 0 && array[j] > actualValue)
    {
      array[j + 1] = array[j];
      j--;
      if (j >= 0)
        comparison++;
      swap++;
    }

    array[j + 1] = actualValue;
    swap++;
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