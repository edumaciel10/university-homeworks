#include<stdio.h>
void transformNegativeToPositive(int *v);
int main()
{
    int i,numbers[10];
    for (i = 0; i < 10;i++) {
        scanf("%d", &numbers[i]);
    }
    transformNegativeToPositive(numbers);
    for (int i = 0; i < 10;i++) {
        printf("%d ",numbers[i]);
    }
    return 0;
}
void transformNegativeToPositive(int vet[]){
    for (int i = 0; i < 10;i++) {
        if(vet[i] <0)
            vet[i] *= -1;
    }
}
