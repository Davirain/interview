#include <iostream>
#include <string.h>
#include <assert.h>

using std::endl;
using std::cout;

bool find(const char* const src, const char * const des)
{
    assert(src != NULL & des != NULL);
    int lenSrc = strlen(src);
    int lenDes = strlen(des);
    if(lenSrc < lenDes)
        return false;
    int k;
    /*类似暴力法*/
    for(int i = 0; i < lenSrc; i++)
    {
        k = i;/*从src要匹配的字符创中，从第一字符可是匹配
               如果， 且k - i 最后的长度等于 lenDes， 则找到了这个 des字符串
               */
        for(int j = 0; j < lenDes; j++)
        {
            if(src[k++ % lenSrc] != des[j])
                break;
        }
        /*这里k - i 是因为， 在上面的stc[k++ % lenSrc] != des[j]
         中每执行一次，k就会加一，*/
        if(k - i == lenDes)
            return true;
    }
    return false;
}
int main()
{
    char str1[] = "ABCD";
    char str2[] = "ACBD";
    bool ret = find(str1, str2);
    cout << "ret = " << ret << endl;
    return 0;
}

