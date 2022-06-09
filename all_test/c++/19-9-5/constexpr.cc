#include <iostream>

constexpr int handle(int t)
{
    return t * t;
}

int main()
{
    int bar = 10;
    int foo = handle(bar);

    //int foo = handle(2);
    std::cout << "foo = " << foo << std::endl;
    std::cout << "Hello world" << std::endl;
    return 0;
}

