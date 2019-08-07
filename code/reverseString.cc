#include <iostream>
#include <string.h>
/*
 * 给定字符串， 要求将字符串前面的若干位字符移动到字符串的尾部
 * */
/*char *s , size_t size
 * s字符串的首地址， size字符串的长度大小*/


void leftShiftOne(char *s, int n)
{
    /*保留第一个字符*/
    char t = s[0];
    for(int i = 1; i < n; i++)
    {
        s[i - 1] = s[i];
    }
    s[n - 1] = t;
}
void leftRotateString(char *s, int n, int m)
{
    while(m--)
    {
        leftShiftOne(s, n);
    }
}
/*反转字符串*/
void ReverString(char *s, int from, int to)
{
    while(from < to)
    {
        char t = s[from];
        s[from++] = s[to];
        s[to--] = t;
    }
}
void leftRotateString_1(char * s, int n, int m)
{
    /*若要左移大于n位，那么与%n是等价的*/
    m %= n;
    ReverString(s, 0, m - 1);
    ReverString(s, m, n - 1);
    ReverString(s, 0, n - 1);
}

int main()
{
    char str[] = "I am a student.";
    printf("str size = %ld\n", strlen(str));
    leftRotateString_1(str, strlen(str), strlen(str)/2);
    printf("str = %s\n", str);
    return 0;
}

