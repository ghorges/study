#include <iostream>

using namespace std;

int main()
{
    int foo = 10;
    decltype(foo) t = 100;
    cout << "t = " << t << endl;
    std::cout << "Hello world" << std::endl;
    return 0;
}

