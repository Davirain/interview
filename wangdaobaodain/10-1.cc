#include <iostream>
using namespace std;
int main()
{
  int i = 11;
  int const * p = &i;
  p++;//opput Garbage value
  
  printf("%d\n", *p);
}