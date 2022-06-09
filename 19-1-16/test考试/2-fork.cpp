#include <iostream>
#include <signal.h>
#include <cstdio>
#include <cstring>
#include <errno.h>
#include <cstdlib>
#include <unistd.h>

using namespace std;

int main()
{
    int a;
    cout << "请输入进程数：";
    cin >> a;
    int b;
    cout << "请输入圈数:";
    cin >> b;

    while(a--)
    {
        int pid = fork();
        if(pid == 0)
        {
            int t = b;
            while(t--)
            {
                cout << "111" << endl;
                sleep(1);
            }
            return 0;
        }
        if(pid > 0)
        {
            ;
        }
        if(pid < 0)
        {
            cout << "err" << endl;
        }
    }
    wait();
    std::cout << "Hello world" << std::endl;
    return 0;
}

