#include <iostream>
#include <unistd.h>

int main()
{
    using std::cout;
    
    char *c = nullptr;
    c = static_cast<char*>(sbrk(100));
    c[10] = 'a';
    cout << c[10] << "\n";
    std::cout << "Hello world" << std::endl;
    return 0;
}

