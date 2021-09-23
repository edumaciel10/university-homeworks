// Suponha que uma empresa de transporte trabalhe com 

//contêineres medindo A metros de largura, B metros de comprimento e C metros de altura.

// Um navio porta-contêineres pode ser visto como um retângulo horizontal de X metros de largura e Y metros de comprimento, e limite de Z metros de altura, sobre o qual os contêineres são colocados. Nenhuma parte de contêiner pode ficar para fora do navio.

// Os contêineres só podem ser colocados sobre o navio de tal forma que a largura e o comprimento do contêiner estejam paralelos à largura e ao comprimento do navio.

// Crie um programa que leia os valores de X, Y, Z e A, B, C (valores decimais, nessa ordem). Calcule e imprima a quantidade máxima de contêineres que o navio consegue transportar.


#include<stdio.h>

int main(){
  float X,Y,Z;
  float A,B,C;

  scanf("%f %f %f",&X,&Y,&Z);
  scanf("%f %f %f",&A,&B,&C);

  float quantidade[3];
  quantidade[0] = (int)(X/A);
  quantidade[1] = (int)(Y/B);
  quantidade[2] = (int)(Z/C);

  int menor =1;

  for(int i =0;i<3;i++) {
    menor *= quantidade[i];
  }
  printf("%d",menor);

  return 0;
}
