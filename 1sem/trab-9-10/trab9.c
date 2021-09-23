#include<stdio.h>
#include<string.h>
int main() {
    FILE *arq;
    int count =0;
    char fileText[20], wordToSearch[20];
    scanf("%s", wordToSearch);
    if ((arq = fopen("arquivo.txt", "r+")) == NULL)
    {
        printf("Erro ao abrir arquivo");
    }
    while(!feof(arq)) {
        fscanf(arq, "%s", fileText);
        if(strcmp(wordToSearch,fileText) ==0) {
            count++;
        }
    }
    fclose(arq);
    printf("%d", count);
    return 0;
}
