#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct filme { char nome[20]; int avaliacao; int ano; };

int main() {
    FILE *arq;
    char P[20];
    setbuf(stdin, 0);
    scanf("%s", P);
    if ((arq = fopen("filmes.dat", "rb+")) == NULL)
        printf("\nErro abrindo arquivo.\n");
    struct filme movie;
    while (!feof(arq))
    {
        if(feof(arq))
            break;
        fread(&movie, sizeof(struct filme), 1, arq);
        if(movie.ano >= 2000 && strstr(movie.nome,P)!= NULL) {
            printf("%s", movie.nome);
        }
    }
    fclose(arq);
    return 0;
}
