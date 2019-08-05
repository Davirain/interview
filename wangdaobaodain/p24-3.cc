#include <iostream>
#include <string.h>

using namespace std;


char * f(char * str, char ch)
{
  char * it1 = str;
  char * it2 = str;
  while(*it2 != '\0'){
    while(*it2 == ch){
      it2++;
    }
    *it1++=*it2++;
  }
  return str;
}
int main()
{
  char *a = new char[10];
  strcpy(a, "abcdcccd ");
  cout << f(a, 'c');
  delete [] a;
}