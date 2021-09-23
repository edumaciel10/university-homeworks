#ifndef CAMINHO_H
#define CAMINHO_H

typedef struct ponto_ PONTO;

typedef struct caminho_
{
    PONTO **ponto;
    int tamanho;
    int tamanhoAtual;
} CAMINHO;

CAMINHO* criarCaminho(int tamanho);
int adicionarPonto(CAMINHO *caminho, PONTO *ponto);
void imprimirDistancia(CAMINHO *caminho);
int apagarCaminho(CAMINHO **caminho);

#endif //CAMINHO_H
