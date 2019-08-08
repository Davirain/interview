# c++ 基础知识

面向对象的特性，
构造函数，
析构函数，
动态绑定
常用的设计模式

c++内存管理

数据结构和算法

字符串处理

并发控制

语言的基本概念

算法，复杂度

编程基础， 

计算机系统基础知识

OS的理解

文件操作

程序性能

多线程

程序安全

1.C++概念的理解

Q1: C++中， 有那4个与类型转黄相关的关键字？这些关键字各有什么特点，

应该在什么场合下使用？

Q2: 定义一个空的类型， 里面没有任何成员变量和成员函数，

对该类型求sizeof，得到的结果是多少？
A2: 1
空类型的实例不包含任何信息， 本来sizeof应该是0， 但是当我们声明该
类型的实例的时候， 它必须在内存中占有一定的空间, 否则无法使用这些实例。

如果在该类型中添加一个构造函数和析构函数， 再对该类型求sizeof

， 得到的结果又是多少？

还是1， 调用构造函数和析构函数只需要知道函数的地址即可，
而这些函数的地址只与类型相关，而与类型的实例无关，
编译器也不会因为这两个函数在实例内添加任何额外的信息。


如果把析构函数标记为虚函数？
c++编译器一旦发现一个类型中有虚拟函数， 就会为该类型生成虚函数表
并在该类型的每一个实例中添加一个指向虚函数表的指针。
在32位的机器上， 一个指针占4个字节的空间， 因此求sizeof得到4
在64位的机器上， 一个指针占8个字节的空间，因袭sizeof得到8

## 赋值运算符函数
为下面类型添加赋值元素符函数
```
class CMyString
{
public:
    CMyString(char* pData = NULL);
    CMyString(const CMyString & str);
    ~CMyString(void);
private:
    char* m_pData;
};
```
1. 是否把返回值的类型声明为该类型的引用，并在函数结束前
返回实例自身的应用(*this)。只有返回一个引用， 才可以允许连续赋值， 
否则如果函数的返回值是void，应用该赋值运算符将不能做
连续赋值。

2. 是否把传入的参数的类型声明为常量引用。如果传入的参数
不是引用而是实例， 那么从形参到实参会调用一次复制构造函数。
把参数声明为引用可以避免这样的平白无故的浪费，能提高代码的效率，
同时，我们在赋值运算符函数内不会改变传入的实例的状态， 
因此应该为传入的引用参数加上const关键字。

3. 是否释放实例自身已有的内存。如果忘记在分配新内存之前释放自身已有的空间，
程序将出现内存泄漏。

4.判断传入的参数和当前的实例（*this)是不是同一个实例。
如果是同一个，则不进行赋值操作，直接返回。如果事先不判断就进行赋值，那么在
释放实例自身的内存时候就会导致严重的问题；当*this和传入的参数是
同一个实例时， 那么一旦释放了自身的内存，传入的参数的内存也同时
被释放了，因此再也找不到需要赋值的内容了。

```
CMyString & CMyString::operator=(const CMyString & str)
{
    if(this == &str)
        return *this;
    delete [] m_pData;
    m_data = NULL;

    m_pData = new char[strlen(str.m_pData) + 1];
    strcpy(m_pData, str.m_pData);

    return *this;
}
```
## 异常安全性的解法
```
CMyString &CMyString::operator=(const CMyString & str)
{
    if(this != &str)
    {
        CMyString strTemp(str);

        char* pTemp = strTemp.m_pData;
        strTemp.m_pData = m_pData;
        m_pData = pTemp;
    }
    return *this;
}
```
## 单例模式

## 数据结构
数组 字符串 链表 树 栈 队列

栈是一个与递归紧密相关的数据结构，
队列也与广度优先遍历算法紧密相关，

数组简单的哈希表：

动态数组

C++/C，数组和指针;
当声明一个数组时， 其数组的名字也是一个指针，
该指针指向数组的第一个元素，可以用一个指针来访问数组。

## 数组

```
int GetSize(int data[])
{
    return sizeof(data);
}
int _tmain(int argc, _TCHAR * argv[])
{
    int data[] = {1, 2, 3, 4, 5};
    int size1 = sizeof(data1);

    int *data2 = data1;
    int size2 = sizeof(data2);

    int size3 = GetSize(data1);

    printf("%d, %d, %d", size1, size2, size3);
}
```








