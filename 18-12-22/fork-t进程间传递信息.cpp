#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
using namespace std;
int main()
{
    signal(SIGCHLD,SIG_IGN);
    pid_t pid;
    pid = fork();
    if(pid == -1)
    {
        perror("forkerror");
    }
    if(pid > 0)
    {
        cout << "pid:" << getpid() << "  child pid:" << pid << endl;
    }
    else
    {
        char *envp[] = {"aa=1234","bb=2345","cc=3456",NULL};
        execve("./hello.out",NULL,envp);
    }
    return 0;
}

