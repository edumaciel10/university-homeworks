#include<stdio.h>
void changeValues(int *x, int *y);
int main()
{
  int x, y;
  scanf("%d %d",&x,&y);
  changeValues(&x, &y);
  printf("%d %d", x, y);
  return 0;
}
void changeValues(int *x, int *y) {
  int aux = *x;
  *x = *y;
  *y = aux;
}
