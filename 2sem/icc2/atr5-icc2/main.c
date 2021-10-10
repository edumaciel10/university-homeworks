#include <stdio.h>
#include <stdlib.h>

void compareMethods(int array[], int arraySize);
void shellSort(int array[], int arraySize, int *operations);
void quickSort(int array[], int arraySize, int *operations);

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
    tempArray = (int *)realloc(tempArray, (i + 1) * sizeof(int));
    compareMethods(tempArray, i + 1);
  }

  return 0;
}
// A ideia deste método é ver qual fez menos operações para printar.
// Ai você coloca a quantidade de operações dentro do programa
// a unica coisa que você vai alterar é o metodo ShellSort, ok?
void compareMethods(int array[], int arraySize)
{
  int *shellOperations = malloc(1 * sizeof(int));
  shellSort(array, arraySize, shellOperations);
  int *quickOperations = malloc(1 * sizeof(int));
  quickSort(array, arraySize, quickOperations);
  if (*quickOperations < *shellOperations)
  {
    printf("Q ");
  }
  if (*shellOperations < *quickOperations)
  {
    printf("S ");
  }
  if (*shellOperations == *quickOperations)
  {
    printf("- ");
  }
}
void shellSort(int array[], int arraySize, int *operations)
{
  *operations = 10;
}

void quickSort(int array[], int arraySize, int *operations)
{
  *operations = 30;
}

// Faça um programa em C que leia o número N de elementos de um vetor V. Após isso, leia os N elementos de V. O programa deve ordenar todos os subvetores de V utilizando os métodos Shell Sort e Quick Sort. Para cada subvetor de V, deve-se imprimir qual método fez menos operações (comparação + cópias), imprimindo Q quando for o Quick Sort, S quando for o Shell Sort e o caractere hífen quando o número de contagens for igual. O Shell deve utilizar os gaps no formato 2^k - 1, e o Quick Sort deve utilizar o elemento do meio como pivô (como os códigos vistos em aula).

// Por exemplo, considere o seguinte vetor V: [3, 6, 5, 2]. Os subvetores de V são: V1: [3], V2: [3, 6], V3: [3, 6, 5], e V4 = [3, 6, 5, 2]. Para V1, o número de operações é o mesmo para os dois métodos. Para V2, V3 e V4, o Shell Sort realiza menos operações. Portanto, seu programa deve imprimir: - S S S