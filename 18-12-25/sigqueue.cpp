#include <iostream>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
//sigqueue传数据,顺便把不可靠信号测试了，确实不可靠
using namespace std;
/*
struct sigaction {
void     (*sa_handler)(int);
void     (*sa_sigaction)(int, siginfo_t *, void *);
sigset_t   sa_mask;
int        sa_flags;
void     (*sa_restorer)(void);
};
*/
void aaa(int sig,siginfo_t *info,void *p)
{
    if(sig == SIGINT)
    {
        printf("it's sigint\n");
        printf("the num is %d\n",info->si_int);
        sleep(3);
        return;
    }
}
int main()
{
    pid_t pid;
    pid = fork();
    if(pid == -1)
    {
        perror("fork err");
        return 0;
    }
    //让子进程给父进程发信号
    if(pid == 0)
    {
        //int sigqueue(pid_t pid, int sig, const union sigval value);
        union sigval a1;
        a1.sival_int = 336;
        //发送
        while(1)
        {
            sigqueue(getppid(),SIGINT, a1);
            sleep(1);
        }
        return 0;
    }
    else
    {
        //相当于先定义，然后应用
        struct sigaction act;

        //act.sa_handler = handler;
        //sigaction(SIGINT,&act,NULL);
        act.sa_sigaction = aaa;
        //这个置为SA_SIGINFO，因为要传值
        act.sa_flags = SA_SIGINFO;
        sigaction(SIGINT,&act,NULL);
        while(1)
        {
            sleep(1);
        }
    }
    return 0;
}

