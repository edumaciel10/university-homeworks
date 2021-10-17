#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

            j -= gap;
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

int quick(int *vector, int leftIndex, int rightIndex)
{
  int operations = 0;

  if (leftIndex < rightIndex)
  {

    int pivot = vector[(int)((rightIndex + leftIndex) / 2)];
    operations++;

    int left = leftIndex, right = rightIndex;

    while (1)
    {

      operations++;
      while (vector[left] < pivot)
      {
        left++;
        operations++;
      }

      operations++;
      while (vector[right] > pivot)
      {
        right--;
        operations++;
      }

      if (left < right)
      {
        int tmp = vector[left];

        operations++;
        vector[left] = vector[right];

        operations++;
        vector[right] = tmp;

        operations++;
        left++;
        right--;
      }
      else
      {
        break;
      }
    }

    operations += quick(vector, leftIndex, right);
    operations += quick(vector, right + 1, rightIndex);
  }

  return operations;
}
int quickSort(int array[], int arraySize)
{
  int count = quick(array, 0, arraySize - 1);
  return count;
}

void compareMethods(int array[], int arraySize)
{
  int *shellArray = (int *)malloc(arraySize * sizeof(int));
  int *quickArray = (int *)malloc(arraySize * sizeof(int));
  for (int i = 0; i < arraySize; i++)
  {
    shellArray[i] = array[i];
    quickArray[i] = array[i];
  }

  int shellOperations = shellSort(shellArray, arraySize);
  int quickOperations = quickSort(quickArray, arraySize);
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
  free(shellArray);
  free(quickArray);
  shellArray = NULL;
  quickArray = NULL;
}

int main()
{
  int arraySize = 0;
  scanf("%d", &arraySize); // 4

  int array[arraySize];               // array[4]
  for (int i = 0; i < arraySize; i++) // [3 6 5 2 ]
  {
    scanf("%d", &array[i]);
  }

  int *tempArray = (int *)malloc((1) * sizeof(int));

  for (int i = 0; i < arraySize; i++)
  {
    for (int j = 0; j < i + 1; j++)
    {
      tempArray[j] = array[j];
    }
    compareMethods(tempArray, i + 1);
    free(tempArray);
    tempArray = NULL;
    tempArray = (int *)malloc((i + 1) * sizeof(int));
  }
  free(tempArray);
  return 0;
}