#include<stdio.h>
int special(int number);

int main(){
  int number =0;
  scanf("%d",&number);
  int specialNumber = special(number);
  printf("%d",specialNumber);
  return 0;
}

int special(int number) {
  int accumulator=0;
  for(int i =0;i<number; i++) {
    accumulator+= i;
    if(accumulator< number) {
      continue;
    }
    if(accumulator == number) {
      return 1;
    }
    if(accumulator > number) {
      return 0;
    }
  }
  return 0;
}
