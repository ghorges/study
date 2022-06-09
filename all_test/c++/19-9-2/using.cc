#include <iostream>

using namespace std;

int main()
{
    {
        using t = int;
        t t1 = 100;
        cout << t1 << endl;
    }
    t t2 = 200;
    cout << t2 << endl;
    std::cout << "Hello world" << std::endl;
    return 0;
}

