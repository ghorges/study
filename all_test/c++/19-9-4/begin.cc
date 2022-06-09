#include <iostream>

using std::begin;
using std::end;

//
int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6};
    int *foo = begin(a);
    int *bar = end(a);
    
    std::cout << *foo << std::endl;
    std::cout << *(bar - 1) << std::endl;
    std::cout << "Hello world" << std::endl;
    return 0;
}

