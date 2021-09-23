#include <stdio.h>
#include <stdlib.h>

int * aloca1(int n) {
    int *v, i;
    v= (int *) malloc(n*sizeof(int));

    for (i=0; i<n; i++)
        v[i]=i;

    return v;
}

void aloca2(int n, int **v) {
    int i;
    *v= (int *) malloc(n*sizeof(int));

    for (i=0; i<5; i++)
        (*v)[i]=i;
}

int positivos(int n, int *v) {
    int i, soma=0;
    for (i=0; i<n; i++) {
        if (v[i]%2==0)
            soma += v[i];
    }
    return soma;
}

int main() {
int *v1, *v2, n=5, s, i;

v1=aloca1(n);
aloca2(n, &v2);

s=positivos(n, v1);
printf("Soma: %d\n", s);

s=positivos(n, v2);
printf("Soma: %d\n", s);

printf("v1: ");
for (i=0; i<n; i++)
    printf("%d ", v1[i]);

printf("\nv2: ");
for (i=0; i<n; i++)
    printf("%d ", v2[i]);
}
