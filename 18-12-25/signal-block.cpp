#include <iostream>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
//block测试&pending测试
using namespace std;

void handler(int a)
{
    if(a == SIGINT)
    {
        cout << "it's sigint" << endl;
        return;
        //exit(0);
    }
}

void sigprint(sigset_t *pset)
{
    int i = 0;
    for(i = 0;i < 64;i++)
    {
        if(sigismember(pset,i+1))
            printf("1");
        else
            printf("0");
    }
    printf("\n");
}
int main()
{
    if(signal(SIGINT,handler) == SIG_ERR)
    {
        perror("signal error");
    }
    sigset_t pset;
    sigset_t bset;

    sigemptyset(&bset);
    //在这个信号集里边注册阻塞信号为SIGINT
    sigaddset(&bset,SIGINT);
    //设置阻塞
    sigprocmask(SIG_BLOCK,&bset,NULL);
    
    int i = 5;
    while(1)
    {
        sigpending(&pset);

        sigprint(&pset);
        sleep(1);
        i--;
        if(i == 0)
        {
            sigprocmask(SIG_UNBLOCK,&bset,NULL);
        }
    }
    return 0;
}
