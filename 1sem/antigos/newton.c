#include <stdio.h>
int main()
{
  int iterations=0;
  float inputNumber=0;
  scanf("%f %d",&inputNumber,&iterations);
  float R1 = inputNumber/2.0, rn=0;
  while (iterations > 1){
        rn = R1;
        R1++;
        R1 = (rn + (inputNumber/rn))/2;
        iterations--;

  }
  printf("%f\n",R1);
  return 0;
}
