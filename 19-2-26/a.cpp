#include <iostream>
using namespace std;
class my_thread
{
public:
    my_thread(void)
    {
        cout << "11111111111" << endl;
    }

};
int main()
{
    my_thread t1;
    std::cout << "Hello world" << std::endl;
    return 0;
}

