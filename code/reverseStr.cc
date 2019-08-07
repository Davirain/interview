#include <iostream>
#include <algorithm>
using std::swap;
#include <string.h>
using std::endl;
using std::cout;

/*反转字符串*/
void reverse(char * str)
{
    size_t len = strlen(str);
    for(size_t i = 0, j = len - 1; i < j; i++, j--)
    {
        swap(str[i], str[j]);
    }
}
/*课本答案*/
void reverse_normal(char * str)
{
    char * end = str;
    char tmp;
    if(str)
    {
        while(*end){/*找到字符串末尾*/
            ++end;
        }
        --end;/*回退一个字符，最后一个为null字符*/

        /*从字符串首尾开始交换两个字符，
         * 直至两个指针在中间碰头*/
        while(str < end)
        {
            tmp = * str;
            *str++ = *end;
            *end-- = tmp;
        }
    }
}
int main()
{
    char str[] = "hello";
    cout << "before " << str << endl;
    reverse_normal(str);
    cout << "after " << str << endl;
    return 0;
}

