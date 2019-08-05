#include <iostream>
using namespace std;

int main()
{
    char s[] = "abcde";
    s += 2;//error :: incomplatible types in assignment of "int" to "char[6]"
    printf("%c\n", s[0]);
}