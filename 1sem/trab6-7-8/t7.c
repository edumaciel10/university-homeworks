#include<stdio.h>
int getDivisors(int i,int *v);
int main()
{
    int n,divisors[20],length;
    scanf("%d", &n);
    length = getDivisors(n, divisors);
    for (int i = 0; i < length;i++) {
        printf("%d ",divisors[i]);
    }
    return 0;
}
int getDivisors(int i,int vet[]){
    int length = 0;
    for (int j = i-1; j > 0; j--)
    {
        if(i%j == 0) {
            vet[length] = j;
            length++;
        }
    }
    return length;
}
