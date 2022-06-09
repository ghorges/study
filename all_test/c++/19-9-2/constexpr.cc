#include <iostream>

using namespace std;

int main()
{
    constexpr int bar = 15;
    cout << bar << endl;
    int foo = 10;
    
    //write this,complian will err
    constexpr int faa = foo + 1;
    cout << faa << endl;
    std::cout << "Hello world" << std::endl;
    return 0;
}

