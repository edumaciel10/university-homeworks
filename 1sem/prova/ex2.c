#include<stdio.h>
#include<stdlib.h>
/*
pato pato vaca vaca pato pato pat vac
pato
vaca
*/
int counter (char S[],char word[]) {
    int i,j,counter=0;
    for (i = 0; S[i] != '\0'; i++)
    {
        if (word[0] == S[i])
        {
            for (j = 1; word[j] != '\0'; j++)
            {
                if (word[j] != S[i + j])
                    break;
            }
            if (word[j]=='\0') {
                counter++;
            }
        }
    }
    return counter;
}
void countWords(char S[],char A[],char B[],int *qntdA, int *qntdB) {
    (*qntdA) = counter(S, A);
    (*qntdB) = counter(S, B);
}
int main()
{
    char S[50];
    char A[50];
    char B[50];
    int qntdA, qntdB;
    fgets(S, 50, stdin);
    scanf("%s",A);
    scanf("%s",B);
    countWords(S, A, B, &qntdA, &qntdB);
    printf("%d %d", qntdA,qntdB);
}
