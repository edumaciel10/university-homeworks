// Counting sort method using a counting array.
#include <stdio.h>
#include <stdlib.h>

int main () {
  int keys = 0; // até aonde os valores vão
  int size = 0; // tamanho do array
  int *counting = NULL;

  scanf("%d",&keys);
  scanf("%d",&size);
  counting = (int*)malloc(sizeof(int)*size);

  for(int i = 0; i < size; i++) {
    scanf("%d",&counting[i]);
  }

  int *counters = (int*)calloc(keys,sizeof(int));
  int *startPosition = (int*)calloc(keys,sizeof(int));
  int *sorted = (int*)calloc(size,sizeof(int));

  for(int i = 0; i < size; i++) {
    counters[counting[i]]++;
  }
  
  for(int i = 0; i < keys; i++) {
    if(i == 0) {
      startPosition[i] = 0;
      continue;
    }
    startPosition[i] = startPosition[i-1] + counters[i-1];
  }

  for(int i = 0; i < size; i++) {
    sorted[startPosition[counting[i]]] = counting[i];
    printf("%d %d",counting[i],startPosition[counting[i]]);
    startPosition[counting[i]]++;
    printf("\n");
  }

  free(counting);
  free(counters);
  free(startPosition);
}