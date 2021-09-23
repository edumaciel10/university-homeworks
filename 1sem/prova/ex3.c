#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *arq;
    char A[20], B[20],fileText[20];
    char oldWord[20];
    int i = 0, counter = 0;
    if ((arq = fopen("texto.txt", "r+")) == NULL)
        printf("\nErro abrindo arquivo.\n");

    scanf("%s", A);
    scanf("%s", B);


    do{
        fscanf(arq, "%s", fileText);
        i++;

        if (feof(arq)) break;
        if(i==1) {
            strcpy(oldWord, fileText);
            continue;
        }
        if(strcmp(A,oldWord) ==0 &&  strcmp(B,fileText) ==0 ) {
            counter++;
        }
        strcpy(oldWord, fileText);
    } while(!feof(arq));
    fclose(arq);
    printf("%d", counter);
    return 0;
}
