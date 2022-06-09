#include <iostream>
#include <iostream>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>

using namespace std;

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
void handler(int a)
{
    if(a == SIGINT)
    {
        cout << "it's sigint" << endl;
        return;
    }
    if(a == SIGRTMIN)
    {
        cout << "sigrtmin" << endl;
    }
    if(a == SIGALRM)
    {
        sigset_t set1;
        sigpending(&set1);
        sigprint(&set1);
        sigemptyset(&set1);
        //sigaddset(&set1,SIGINT);
        //sigaddset(&set1,SIGRTMIN);
        //sigdelset(&set1,SIGINT);
        //sigdelset(&set1,SIGRTMIN);

        sigprint(&set1);
        //sigprocmask(SIG_UNBLOCK,&set1,NULL);
        sigprocmask(SIG_SETMASK,&set1,NULL);
        cout << "i'm alrm" << endl;
        
        //sigemptyset(&set1);
        //sigprocmask(SIG_BLOCK,NULL,&set1);
        //sigprint(&set1);
    }
}
void handlerssss(int a)
{
    if(a == SIGALRM)
    {
            sigset_t set1;
            sigpending(&set1);
            sigprint(&set1);
            sigemptyset(&set1);
            sigprint(&set1);
            sigprocmask(SIG_SETMASK,&set1,NULL);
            cout << "i'm alrm" << endl;
            while(1)
            {
                sleep(1);
            }
    }
}
int main()
{
    pid_t pid;
        
    sigset_t set1;
    sigemptyset(&set1);
    sigaddset(&set1,SIGINT);
    sigaddset(&set1,SIGRTMIN);
    
    sigprocmask(SIG_BLOCK,&set1,NULL);

    //pid = fork();
    //if(pid > 0)
    if(1)
    {
        struct sigaction act;
        act.sa_handler = handler;
        sigaction(SIGINT,&act,NULL);
        sigaction(SIGRTMIN,&act,NULL);
        //sigaction(SIGALRM,&act,NULL);
        signal(SIGALRM,handlerssss);
        alarm(2);
        int i = 5;
        while(i--)
        {
            if(i == 1)
            {
                sigset_t set1;
                 sigpending(&set1);
                sigprint(&set1);

            }
            sleep(1);
        }
    }
    else
    {/*
        int i = 3;
        while(i--)
        {
            union sigval a;
            a.sival_int = 33;
            sigqueue(getppid(),SIGINT,a);
        }
        i = 3;
        while(i--)
        {
            union sigval a;
            a.sival_int = 22;
            sigqueue(getppid(),SIGRTMIN,a);
        }*/
        //sigqueue(getppid(),SIGUSER1,a);
    }
    return 0;
}

