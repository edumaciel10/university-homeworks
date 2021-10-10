#include "caminho.h"
#include "ponto.h"

#include<stdlib.h>
#include<stdio.h>
#include<math.h>



//Cria um número racional a partir de dois inteiros
CAMINHO* criarCaminho(int tamanho)
{
    CAMINHO *caminho = (CAMINHO*) malloc(sizeof(CAMINHO));
    caminho->ponto = (PONTO **)malloc(sizeof(PONTO*) * tamanho);
    caminho->tamanho = tamanho;
    caminho->tamanhoAtual = 0;
    return caminho;
}
int adicionarPonto(CAMINHO *caminho,PONTO* ponto) {
    if(caminho!= NULL) {
        caminho->ponto[caminho->tamanhoAtual] = ponto;
        caminho->tamanhoAtual++;
        return caminho->tamanhoAtual; // if successfully
    }
    return 0; // if failed
}
void imprimirDistancia(CAMINHO *caminho)
{
    float distancia = 0;
    float distanciaX = 0;
    float distanciaY = 0;

    for (int i = 0; i < caminho->tamanho; i++)
    {
        distanciaX = pow(caminho->ponto[i + 1]->coordX - caminho->ponto[i]->coordX,2);
        distanciaY = pow(caminho->ponto[i + 1]->coordY - caminho->ponto[i]->coordY,2);
        distancia += sqrt(distanciaX + distanciaY);
        if (i + 2 == caminho->tamanho)
        {
            break;
        }
    }
    printf("%.2f", distancia);
}

void desmontarCaminhos(CAMINHO **caminho) {
}
int apagarCaminho(CAMINHO **caminho)
{
    if (*caminho != NULL)
    {
        free (*caminho);
        *caminho = NULL;
        return 1;
    }
    return 0;
}


// }
