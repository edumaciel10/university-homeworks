//Escreva uma função que dado um número real passado como parâmetro, retorne a parte inteira e a parte fracionária deste número através de ponteiros
#include<stdio.h>
float getValues(float *x);
int main()
{
  int inum;
  float x,fnum;
  scanf("%f", &x);
  getValues(&x);
  printf("%d %f", inum, fnum);
  return 0;
}
float getValues(float *x) {
  int inum;
  float fnum;
  inum = (int)(x);
  printf("%f", *x);
  printf("%d", inum);
}
