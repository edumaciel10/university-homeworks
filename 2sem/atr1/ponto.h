#ifndef PONTO_H
#define PONTO_H

typedef struct ponto_
{
  float coordX;
  float coordY;
} PONTO;

PONTO *criarPonto(float x, float y);
int apagarPontos(PONTO **ponto, int tamanho);

#endif //PONTO_H
