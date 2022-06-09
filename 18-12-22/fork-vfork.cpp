#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
//vfork绑定
using namespace std;
//Segmentation fault  没有绑定，就出现了这种问题
//确实vfork是子进程执行完，父进程才会执行
int main()
{
    signal(SIGCHLD,SIG_IGN);
    pid_t pid;
    pid = vfork();
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
        while(1)
        {
            sleep(1000);
        }
        execve("./hello",NULL,NULL);
        //printf("hello...\n");
    }
    return 0;
}

