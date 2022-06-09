#include <iostream>
#include <string>
#include <cctype>

using std::string;

int main()
{
    string ss("some string");
    if (!ss.empty()) {
        ss[0] = toupper(ss[0]);
    }

    std::cout << ss << "\n";
    std::cout << "Hello world" << std::endl;
    return 0;
}

