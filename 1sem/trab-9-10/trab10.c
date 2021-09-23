#include<stdio.h>
#include<string.h>
int main() {
    FILE *arq;
    int count =0;
    char fileText[20], wordToSearch[20];
    scanf("%s", wordToSearch);
    if ((arq = fopen("arquivo2.txt", "r+")) == NULL)    {
        printf("Erro ao abrir arquivo");
    }
    do{
        fscanf(arq, "%s", fileText);
        if(feof(arq))
            break;
        if (strstr(fileText, wordToSearch) != NULL)
        {
            count++;
        }
    } while(!feof(arq));
    fclose(arq);
    printf("%d", count);
    return 0;
}