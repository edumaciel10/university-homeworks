// O cometa Halley é um dos cometas de menor período do Sistema Solar, completando uma volta em torno do Sol a cada 76 anos. 
//A última ocasião em que ele tornou-se visível do planeta Terra foi no ano de 
//1986.
//2062

// Crie um programa que, dado um determinado ano (igual ou maior do que 2021), 
//mostra qual o próximo ano em que o cometa Halley será visível novamente do planeta Terra.

#include<stdio.h>

int main(){
  int year = 0, nextYear=1986;
  scanf("%d",&year);
  while(nextYear <= year) {
    nextYear+= 76;
  }
  printf("%d",nextYear);
  
}
