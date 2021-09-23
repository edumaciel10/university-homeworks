#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct filme { char nome[20]; int avaliacao; int ano; };

int filterMovies(struct filme *A,struct filme *B) {
    int j = 0;
    for (int i = 0; i < 5; i++)
    {
        if(A[i].ano >= 2000) {
            B[j] = A[i];
            j++;
        }
    }
    return j;
}

int main() {
    struct filme A[5];
    struct filme B[5];
    int i = 0;
    for (i= 0; i < 5; i++)
    {
        setbuf(stdin, 0);
        fgets(A[i].nome, 20, stdin);
        scanf("%d", &A[i].avaliacao);
        scanf("%d", &A[i].ano);
    }
    int tamanho = filterMovies(A, B);
    for(i=0; i < tamanho; i++){
        printf("%s", B[i].nome);
    }
    return 0;
}
