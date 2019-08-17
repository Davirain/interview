#include <iostream>
#include <string>
using namespace std;
class B
{
public:
    B(){
        cout << "B constructor, ";
        s = "B";
       // cout << "** s **" << s << endl; 
    }
    void f() {
        cout << s;
        //cout << "#### s ### " << s << endl;
    }
private:
    string s;
};
class D
: public B
{
public:
   D():B()
    {
        cout << "D constructor, ";
        s = "D";
        //cout << "** s **" << s << endl; 
    }
    void f() {
        cout << s;
        //cout << "#### s ### " << s << endl;
    }
private:
    string s;
};
int main()
{
    B *b = new D();
    b->f();
    //cout <<"----" << endl;
    ((D*)b)->f();
    cout << endl;
    delete b;
    return 0;
}

