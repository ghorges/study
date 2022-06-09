#include <iostream>

//#define NEDBUG

int main()
{
#ifndef NEDBUG
    std::cerr << "nedbug" << std::endl;
    std::cerr << __FILE__ << std::endl;
    std::cerr << __TIME__ << std::endl;
#endif
    std::cout << "Hello world" << std::endl;
    return 0;
}

