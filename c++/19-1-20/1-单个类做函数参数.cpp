#include <iostream>

using namespace std;
//要加<>
//如果上面加template，那么调用这个函数的时候要加上<>
template <typename T>
class a
{
public:
    a(T aa)
    {
        this->aa = aa;
    }
    void print()
    {
        cout << aa << endl;
    }
private:
    T aa;
};

template <typename T>
int qqq(a <T> p)
{
    p.print();
    return 0;
}
/*
int qqq(a<int> p)
{
    p.print();
    return 0;
}
*/

int main()
{
    a <int> p(10);
    //qqq(p);
    qqq<int>(p);
    std::cout << "Hello world" << std::endl;
    return 0;
}

