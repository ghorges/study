#include <iostream>

int main()
{
    wchar_t ftt = 'a';
    char16_t bar = '中';
    char32_t foo = '贵';
    std::cout << ftt << "\n";
    std::cout << bar << "\n";
    std::cout << foo << "\n";

    std::cout << "Hello world" << std::endl;
    return 0;
}

