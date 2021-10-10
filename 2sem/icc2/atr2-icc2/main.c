#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *array, int sizeOfArray);
void mergeSort(int *array, int sizeOfArray);
void printArray(int *array, int sizeOfArray);
void _mergeVectors(int array[], int first1, int last1, int first2, int last2, int aux[], int *swapMerge, int *comparisonMerge);
void _merge(int array[], int first, int last, int aux[], int *swapMerge, int *comparisonMerge);
void mergeSort(int array[], int sizeOfArray);
void destroyVector(int *array);
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
    mergeSort(array[i], arraySize[i]);
  }
  destroyVector(*array);
  return 0;
}
void insertionSort(int originalArray[], int sizeOfArray)
{
  int swap = 0;
  int actualValue = 0;
  int comparison = 0;
  int j = 0;
  int array[sizeOfArray];
  for (int i = 0; i < sizeOfArray; i++)
  {
    array[i] = originalArray[i];
  }

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
  printf("I %d %d %d\n", sizeOfArray, swap, comparison);
}
void _mergeVectors(int array[], int first1, int last1, int first2, int last2, int aux[], int *swapMerge, int *comparisonMerge)
{
  int initial1 = first1;
  int initial2 = first2;
  int j = 0;
  while (initial1 <= last1 && initial2 <= last2)
  {
    (*comparisonMerge)++;
    (*swapMerge)++;
    if (array[initial1] <= array[initial2])
    {
      aux[j] = array[initial1];
      j++;
      initial1++;
    }
    else
    {
      aux[j] = array[initial2];
      j++;
      initial2++;
    }
  }

  if (initial1 <= last1)
  {
    // (*comparisonMerge)++;
    while (initial1 <= last1)
    {
      (*swapMerge)++;
      aux[j] = array[initial1];
      j++;
      initial1++;
      if (initial1 <= last1)
      {
        // (*comparisonMerge)++;
      }
    }
  }
  if (initial2 <= last2)
  {
    // (*comparisonMerge)++;
    while (initial2 <= last2)
    {
      (*swapMerge)++;
      aux[j] = array[initial2];
      j++;
      initial2++;
      if (initial2 <= last2)
      {
        // (*comparisonMerge)++;
      }
    }
  }

  j = 0;
  for (int i = first1; i <= last2; i++, j++)
  {
    array[i] = aux[j];
    (*swapMerge)++;
  }
}
void _merge(int array[], int first, int last, int aux[], int *swapMerge, int *comparisonMerge)
{
  if (first >= last)
  {
    return;
  }
  int mid = (first + last) / 2;
  _merge(array, first, mid, aux, swapMerge, comparisonMerge);
  _merge(array, mid + 1, last, aux, swapMerge, comparisonMerge);
  _mergeVectors(array, first, mid, mid + 1, last, aux, swapMerge, comparisonMerge);
}
void mergeSort(int array[], int sizeOfArray)
{
  int *aux = malloc(sizeof(int) * sizeOfArray);
  int swapMerge = 0, comparisonMerge = 0;

  _merge(array, 0, sizeOfArray - 1, aux, &swapMerge, &comparisonMerge);

  printf("M %d %d %d\n", sizeOfArray, swapMerge, comparisonMerge);
}
void destroyVector(int *array)
{
  free(array);
}
