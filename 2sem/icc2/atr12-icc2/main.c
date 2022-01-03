// Faça um programa em C que leia a quantidade de esquinas de ruas na horizontal (linhas) e quantidade de ruas na vertical (colunas). Após isso, leia os valores de cada rua, representada pelo par de IDs da rua, seguido da quantidade de amigos entre elas (veja exemplo abaixo). O seu programa deve imprimir o máximo de amigos que você vai conseguir cumprimentar durante o seu deslocamento entre o ponto A (ponto mais acima a esquerda) e o ponto B (ponto mais abaixo a direita).
#include <stdio.h>
#include <stdlib.h>

// int SOMA_VIZINHO = 0;
// int ESQUINAS_VERTICAIS = 0;
// int ESQUINAS_HORIZONTAIS = 0;

// talvez seja muito melhor eu mandar o ponto e a sua esquina vertical e horizontal atual para poder validar melhor qual que é a posição correta dele
int _caminho(int **rua, int ponto, int passos, int x, int y, int SOMA_VIZINHO, int ESQUINAS_VERTICAIS, int ESQUINAS_HORIZONTAIS) {
    if(rua[ponto][0] == -1) { // cheguei no ultimo
        return 0;
    }
    int debugPulo = 1;
    int possoIrParaBaixo = 1, possoIrParaDireita = 1;
    // printf("TENTANDO ACESSAR rua[%d][1] = %d\n" , ponto, rua[ponto][1]);
    if(rua[ponto][1] == -1) { // estou em uma das bordas
        // não é tão válido, eu preciso verificar se bate com o SOMA_VIZINHO, pq ela pode ser maior verticalmente tb
        printf("PONTO:%d X:%d Y:%d H:%d V:%d\n", ponto, x, y, ESQUINAS_HORIZONTAIS, ESQUINAS_VERTICAIS);
        if(x == ESQUINAS_HORIZONTAIS-1 ) { // estou na borda lateral direita
            if(debugPulo) printf("ESTOU PULANDO PARA O %d\n", ponto+SOMA_VIZINHO);
            // printf("ESTOU NA BORDA DO X %d\n", ponto);
            possoIrParaDireita=0;
        } 
        if(y == ESQUINAS_VERTICAIS-1) {
            // printf("ESTOU NA BORDA DO Y.%d\n", ponto);
            possoIrParaBaixo=0;
        }
    }

    int idaParaBaixo = 0, idaParaDireita = 0;
    if(debugPulo) {
        // printf("ponto: %d idaParaBaixo: %d idaParaDireita: %d\n",ponto, possoIrParaBaixo,possoIrParaDireita);
    }

    if(debugPulo) {
        printf("PONTO:\t%d\tX:\t%d\tY:\t%d\t%d\t%d \n", ponto,x,y,possoIrParaBaixo,possoIrParaDireita);
    }
    if(possoIrParaBaixo) {
        // printf("ESTOU IR PARA BAIXO\n");
        printf("BAIXO:\t%d\tX:\t%d\tY:\t%d \n", ponto,x,y);

        if(x == ESQUINAS_HORIZONTAIS-1 )  {
            // printf("DEVERIA SER %d MAS É %d\n", rua[ponto][0], rua[ponto][1]);
            idaParaBaixo = rua[ponto][0] + _caminho(rua, ponto+SOMA_VIZINHO, passos+1, x,y+1,SOMA_VIZINHO, ESQUINAS_VERTICAIS, ESQUINAS_HORIZONTAIS);
        } else {
            idaParaBaixo = rua[ponto][1] + _caminho(rua, ponto+SOMA_VIZINHO-1, passos+1, x,y+1,SOMA_VIZINHO, ESQUINAS_VERTICAIS, ESQUINAS_HORIZONTAIS);
        }
        // printf("IDA PARA BAIXO DO PONTO %d : %d \n", ponto, idaParaBaixo);

    }

    if(possoIrParaDireita) {
        idaParaDireita = rua[ponto][0] + _caminho(rua, ponto+1, passos+1, x+1,y,SOMA_VIZINHO, ESQUINAS_VERTICAIS, ESQUINAS_HORIZONTAIS);
        // printf("IDA PARA DIREITA DO PONTO %d : %d + %d = %d\n", ponto, rua[ponto][0], idaParaDireita-rua[ponto][0], idaParaDireita);
    }


    if(idaParaBaixo > idaParaDireita) { // retorna o caminho maior
        return idaParaBaixo;
    } else {
        return idaParaDireita;
    }
    
    // TODO: validar se pode chamar o da direita ou o de baixo
}

int caminho(int **rua, int SOMA_VIZINHO, int ESQUINAS_VERTICAIS, int ESQUINAS_HORIZONTAIS) {
    int tamanho = _caminho(rua, 0 , 0, 0,0, SOMA_VIZINHO, ESQUINAS_VERTICAIS, ESQUINAS_HORIZONTAIS);
    printf("SOMA_VIZINHO: %d\n", SOMA_VIZINHO);
    printf("%d",tamanho);
    return 0;
}

int main() {
    int ESQUINAS_VERTICAIS = 0;
    int ESQUINAS_HORIZONTAIS = 0;
    scanf("%d %d", &ESQUINAS_VERTICAIS, &ESQUINAS_HORIZONTAIS);

    int totalPontos = ESQUINAS_VERTICAIS * ESQUINAS_HORIZONTAIS;
    int SOMA_VIZINHO = ESQUINAS_HORIZONTAIS > ESQUINAS_VERTICAIS ? ESQUINAS_HORIZONTAIS : ESQUINAS_VERTICAIS;
    // printf("SOMA_VIZINHO: %d\n", SOMA_VIZINHO);
    // printf("%d\n", SOMA_VIZINHO);
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
    for(int i = 0; i < totalPontos; i++) {
        printf("i = %d %d %d\n", i, rua[i][0], rua[i][1]);
    }
    caminho(rua, SOMA_VIZINHO, ESQUINAS_VERTICAIS, ESQUINAS_HORIZONTAIS);
    
    return 0;
}
