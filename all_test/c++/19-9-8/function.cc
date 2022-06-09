#include <iostream>
//#include <function>
#include <functional>

using std::function;

int swaps(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
    return 0;
}

int main()
{
    //typedef function<int(int&, int&)> t;
    
    function<int(int&, int&)> t = swaps;
    //t = swaps;
    int a = 10;
    int b = 20;
    t(a, b);
    std::cout << b << "\n";
    std::cout << "Hello world" << std::endl;
    return 0;
}

