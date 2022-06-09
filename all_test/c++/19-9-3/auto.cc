#include <iostream>

using namespace std;

int main()
{
    const int bar = 10;
    //auto &foo = bar;
    auto &foo = 42;
    std::cout << "Hello world" << std::endl;
    return 0;
}
