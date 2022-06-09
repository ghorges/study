#include <iostream>

using std::cout;

int main()
{
    const int i = 10;
    const_cast<int>(i) = 5;
    std::cout << "i = " << i << "\n";
    std::cout << "Hello world" << std::endl;
    return 0;
}

