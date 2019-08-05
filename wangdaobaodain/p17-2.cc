#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;

int main()
{
  char a[] = "abcd";
  char *p = a;
  int b = strlen(a);
  cout << "size = " << b << endl;
  *a = p[b];
  ++p;
  cout << p << endl;
  cout << a << endl;
  return 0;
}