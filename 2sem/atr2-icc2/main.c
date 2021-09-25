#include <stdio.h>
#include <stdlib.h>

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
    for (int j = 0; j < arraySize[i]; j++)
    {
      printf("%d", array[i][j]);
    }
  }
}