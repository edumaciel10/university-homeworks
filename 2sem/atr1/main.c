#include "ponto.h"
#include "caminho.h"

#include <stdio.h>
#include<stdlib.h>

int main()
{
  float x, y;
  int tamanho;
  scanf("%d", &tamanho);
  CAMINHO *caminho = criarCaminho(tamanho);
  PONTO *ponto;

  for (int i = 0; i < tamanho; i++) {
    scanf("%f %f", &x, &y);
    ponto = criarPonto(x, y);
    adicionarPonto(caminho, ponto);
  }
  imprimirDistancia(caminho);

  apagarPontos(caminho->ponto,tamanho);
  apagarCaminho(&caminho);

  return 0;
}
