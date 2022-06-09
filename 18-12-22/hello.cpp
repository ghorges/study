#include <iostream>
extern char **environ;
using namespace std;
int main()
{
    for(int i = 0;environ[i] != NULL;i++)
        cout << environ[i] << endl;
    std::cout << "Hello world" << std::endl;
    return 0;
}

