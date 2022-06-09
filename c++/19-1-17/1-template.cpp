#include <iostream>
//template
using namespace std;
//1.显示类型调用
//2.自动类型推倒

//这个gdb -tui -q a.out
//真心好用！！！
//良心推荐
template <typename T>
void myswap(T &a,T &b)
{
    T c;
    c = a;
    a = b;
    b = c;
}

int main()
{
    int a = 10;
    int b = 5;
    //显式类型调用
    myswap<int>(a,b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    //自动类型推导（一般不用，有时候不好使）
    char c = 65;
    char d = 97;
    myswap(c,d);
    cout << "c = " << c << endl;
    cout << "d = " << d << endl;
    std::cout << "Hello world" << std::endl;
    return 0;
}

