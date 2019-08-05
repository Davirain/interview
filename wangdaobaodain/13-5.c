#include <stdio.h>
void sum(int *a)
{
  a[0] = a[1];
}
main()
{
  int i;
  int aa[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  for(i  = 2; i >= 0; i--) sum(&aa[i]);
  printf("%d\n", aa[0]);
}