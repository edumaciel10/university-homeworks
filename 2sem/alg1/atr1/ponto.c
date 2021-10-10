#include "ponto.h"

#include <stdlib.h>
#include <stdio.h>

PONTO *criarPonto(float coordX, float coordY)
{
    PONTO *ponto = (PONTO *)malloc(sizeof(PONTO));
    ponto->coordX = coordX;
    ponto->coordY = coordY;

    return ponto;
}
int apagarPontos(PONTO **ponto,int tamanho)
{
    if (*ponto != NULL)
    {
        for (int i = 0; i < tamanho;i++) {
            free(ponto[i]);
            ponto[i] = NULL ;
        }
        free(ponto);
        *ponto = NULL;
        return 1;
    }
    return 0;
}
