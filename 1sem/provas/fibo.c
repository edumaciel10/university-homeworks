#include <stdio.h>
 
void fibonacci(int n);

int main()
{
    int n =0;
    scanf("%d", &n);
    fibonacci(n);
    return 0;
}
 
void fibonacci(int n)
{
    int fibo[n];
    fibo[0] = 1;
    fibo[1] = 1;
    for(int i =2; i<n;i++) {
      fibo[i] = fibo[i-1] + fibo[i-2];
    }
    for (int i = n-1; i >= 0; i--)
    {
      printf("%d ",fibo[i]);
    }
    
}
