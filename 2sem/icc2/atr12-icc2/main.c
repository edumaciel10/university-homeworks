// Faça um programa em C que leia a quantidade de esquinas de ruas na horizontal (linhas) e quantidade de ruas na vertical (colunas). Após isso, leia os valores de cada rua, representada pelo par de IDs da rua, seguido da quantidade de amigos entre elas (veja exemplo abaixo). O seu programa deve imprimir o máximo de amigos que você vai conseguir cumprimentar durante o seu deslocamento entre o ponto A (ponto mais acima a esquerda) e o ponto B (ponto mais abaixo a direita).
#include <stdio.h>
#include <stdlib.h>


int _caminho(int **cache,int **rua, int ponto, int passos, int x, int y, int SOMA_VIZINHO, int ESQUINAS_VERTICAIS, int ESQUINAS_HORIZONTAIS) {
    if(rua[ponto][0] == -1) { // cheguei no ultimo
        return 0;
    }
    int possoIrParaBaixo = 1, possoIrParaDireita = 1;

    if(rua[ponto][1] == -1) { // estou em uma das bordas
        if(x == ESQUINAS_HORIZONTAIS-1 ) { // estou na borda lateral direita
            possoIrParaDireita=0;
        } 
        if(y == ESQUINAS_VERTICAIS-1) { // estou na borda inferior
            possoIrParaBaixo=0;
        }
    }
    
    int idaParaBaixo = 0, idaParaDireita = 0;
    if(possoIrParaBaixo) {
        if(x == ESQUINAS_HORIZONTAIS-1 )  {
            idaParaBaixo = rua[ponto][0] + _caminho(cache,rua, ponto+SOMA_VIZINHO, passos+1, x,y+1,SOMA_VIZINHO, ESQUINAS_VERTICAIS, ESQUINAS_HORIZONTAIS);
        } else {
            idaParaBaixo = rua[ponto][1] + _caminho(cache,rua, ponto+SOMA_VIZINHO, passos+1, x,y+1,SOMA_VIZINHO, ESQUINAS_VERTICAIS, ESQUINAS_HORIZONTAIS);
        }
    }

    if(possoIrParaDireita) {
        idaParaDireita = rua[ponto][0] + _caminho(cache,rua, ponto+1, passos+1, x+1,y,SOMA_VIZINHO, ESQUINAS_VERTICAIS, ESQUINAS_HORIZONTAIS);
    }

    if(idaParaBaixo > idaParaDireita) { // retorna o caminho maior
        return idaParaBaixo;
    } else {
        return idaParaDireita;
    }
}

int caminho(int **rua, int SOMA_VIZINHO, int ESQUINAS_VERTICAIS, int ESQUINAS_HORIZONTAIS) {
    int **cache;
    cache = malloc(sizeof(int*)*(ESQUINAS_HORIZONTAIS*ESQUINAS_VERTICAIS));

    for(int i = 0; i < ESQUINAS_HORIZONTAIS*ESQUINAS_VERTICAIS; i++) {
        cache[i] = malloc(sizeof(int)*2);
        cache[i][0] = -1;
        cache[i][1] = -1;
    }

    int tamanho = _caminho(cache,rua, 0 , 0 , 0 , 0 , SOMA_VIZINHO, ESQUINAS_VERTICAIS, ESQUINAS_HORIZONTAIS);
    printf("%d",tamanho);
    return 0;
}

int main() {
    int ESQUINAS_VERTICAIS = 0;
    int ESQUINAS_HORIZONTAIS = 0;
    scanf("%d %d", &ESQUINAS_VERTICAIS, &ESQUINAS_HORIZONTAIS);

    int totalPontos = ESQUINAS_VERTICAIS * ESQUINAS_HORIZONTAIS;
    int SOMA_VIZINHO = ESQUINAS_HORIZONTAIS;

    int **rua = malloc(sizeof(int*) * (totalPontos));

    for(int i = 0; i<totalPontos; i++) {
        rua[i] = calloc(2, sizeof(int*));
    }

    for(int i = 0; i < ESQUINAS_VERTICAIS; i++) {
        for(int j = 0; j < ESQUINAS_HORIZONTAIS; j++) {
            if(i < ESQUINAS_VERTICAIS-1 && j < ESQUINAS_HORIZONTAIS-1) {
                int pontoA;
                scanf("%d %*d", &pontoA);
                scanf("%d",&rua[pontoA][0]);
                scanf("%*d %*d %d",&rua[pontoA][1]);
            }
            else if(i == ESQUINAS_VERTICAIS-1 && j == ESQUINAS_HORIZONTAIS-1) {
                int ultimaEsquina = (ESQUINAS_HORIZONTAIS*ESQUINAS_VERTICAIS)-1;
                rua[ultimaEsquina][0] = -1;
                rua[ultimaEsquina][1] = -1;
            }
            else if(i == ESQUINAS_VERTICAIS-1 || j == ESQUINAS_HORIZONTAIS-1) {
                int pontoA;
                scanf("%d %*d", &pontoA);
                scanf("%d",&rua[pontoA][0]);
                rua[pontoA][1] = -1;
            }
        }
    }
    caminho(rua, SOMA_VIZINHO, ESQUINAS_VERTICAIS, ESQUINAS_HORIZONTAIS);
    
    return 0;
}
