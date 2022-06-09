#include <iostream>
#include <sys/types.h>
#include <signal.h>
#include <errno.h>
#include <unistd.h>
using namespace std;

int main()
{
    pid_t pid;
    cout << "pid is " << getpid() << endl;

    pid = fork();
    if(pid > 0)
    {
        cout << "parent" << getpid() << endl;
    }
    else
    {
        cout << "child" << getpid() << endl;
    }
    return 0;
}

