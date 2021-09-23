#include <stdio.h>
// Criar uma função que receba um número real (E) e um número de iterações (n) e retorne a raiz quadrada (R) do número real através de Newton:

// R1 = E/2

// Rn+1 = (Rn + (E/Rn))/2

// Ex: para E=16 e n=4 -> R=4,0012
int main()
{
  int inputNumber=0, interations=0;
  float result =0;
  scanf("%d %d",&inputNumber,&interations);
  for(int i=0;i<interations;i++) {
    result = (inputNumber + (inputNumber/i) )/2;
    printf("%f",result);
  }
  return 0;
}
