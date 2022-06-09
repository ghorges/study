#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <signal.h>

using namespace std;

int main()
{
    //这个就是当子进程终止时，父亲会忽略这个信号！
    //如果我猜的没错，应该是上层linux内核就会接收，然后释放资源
    //signal(SIGCHLD,SIG_IGN);
    pid_t pid;
    pid = fork();
    if(pid > 0)
    {
        while(1)
        sleep(1);
    }
    else
    {
        return 0;
    }
    return 0;
}

