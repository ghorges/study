#include <iostream>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
//sigaction基本用法
using namespace std;
void handler(int a)
{
    if(a == SIGINT)
    {
        cout << "it's SIGINT" << endl;
    }
}
void aaa(int a,siginfo_t *p,void *q)
{
     if(a == SIGINT)
     {
         cout << "it's SIGINT" << endl;     
     }
}
/*
struct sigaction {
void     (*sa_handler)(int);
void     (*sa_sigaction)(int, siginfo_t *, void *);
sigset_t   sa_mask;
int        sa_flags;
void     (*sa_restorer)(void);
};
*/
int main()
{
    //相当于先定义，然后应用
    struct sigaction act;

    //act.sa_handler = handler;
    //sigaction(SIGINT,&act,NULL);
    act.sa_sigaction = aaa;
    sigaction(SIGINT,&act,NULL);
    while(1)
    {
        sleep(1);
    }
    
    
    return 0;
}

