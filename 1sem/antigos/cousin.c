#include<stdio.h>

int main() {
  int input =0, array[1000];

  scanf("%d",&input);

  for (int i = 0; i < 1000; i++) // clear array
  {
    array[i] = 0;
  }

  for(int i =2; i<input+1; i++) { // get cousin numbers
    for(int j =2; j<=i; j++) {
      if(i%j != 0) {
        continue;
      }
      if(i%j ==0 && j<i) {
        break;
      }

      if(i%j ==0 && i==j) {
        array[i-2] = j;
      }
    }
  }
  for (int i = 0; i < 1000; i++)
  {
    if(array[i] > 0) {
      printf("%d ",array[i]);
    }
  }
  
  return 0;
}
