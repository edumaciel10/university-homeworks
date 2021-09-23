#include<stdio.h>
int main(){
  float a[2], b[2];

  scanf("%f %f",&a[0],&a[1]);

  scanf("%f %f",&b[0],&b[1]);

  float result = (b[0] -a[0])*30 + (b[1] - a[1])*0.5;

  result *= result < 0 ? -1 : 1;

  if(result > 180) {
    result = 360 - result;
  }

  printf("%f",result);

  return 0;
}
