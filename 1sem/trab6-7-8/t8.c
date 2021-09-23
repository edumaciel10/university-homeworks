#include<stdio.h>
#include<stdlib.h>
int * multiplesByNumber(int i,int *v) {

    v = (int *)calloc(i,sizeof(int));
    for (int j = 1; j <= i;j++) {
        v[j - 1] = j * i;
    }
    return v;
}
int main()
{
    int *v, n, i;
    scanf("%d", &n);
    
    v = multiplesByNumber(n, v);
    for (i = 0; i < n;i++) {
        printf("%d ", v[i]);
    }
    free(v);
    return 0;
}
