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

int panduan()
{
        sigset_t aaa;
        sigemptyset(&aaa);
        sigprocmask(SIG_BLOCK,NULL,&aaa);
        cout << "sigprocmask is:";
        sigprint(&aaa);

        //raise(SIGINT);

        sigset_t bbb;
        sigemptyset(&bbb);
        sigpending(&bbb);
        cout << "sigpending is:";
        sigprint(&bbb);
}
void handler(int a)
{
    if(a == SIGINT)
    {
        cout << "i'm SIGINT" << endl;
        //panduan();
        //sigset_t aaa;
        //sigemptyset(&aaa);
        //sigprocmask(SIG_BLOCK,NULL,&aaa);
        //sigprint(&aaa);
    }
}
void handlers(int a)
{
    if(a == SIGRTMIN)
    {
        panduan();
        sigset_t aaa;
        sigemptyset(&aaa);
        sigaddset(&aaa,SIGINT);
        sigprocmask(SIG_UNBLOCK,&aaa,NULL);
        
        int i = 3;
        while(i--)
        {
            pause();
        }
        //sigfillset(&aaa);
        //sigprocmask(SIG_BLOCK,&aaa,NULL);
        //panduan();
    }
}
void my_test()
{
    sigset_t aaa;
    sigemptyset(&aaa);
    sigaddset(&aaa,SIGINT);
    sigprocmask(SIG_BLOCK,&aaa,NULL);  
}

void my_test1()
{
    sigset_t aaa;
    sigemptyset(&aaa);
    sigaddset(&aaa,SIGRTMIN);
    sigprocmask(SIG_BLOCK,&aaa,NULL); 
}
int main()
{
    my_test();
    signal(SIGINT,handler);
    
    
    //my_test1();
    struct sigaction p;
    p.sa_handler = handlers;
    sigaction(SIGRTMIN,&p,NULL);
    int i = 3;
    raise(SIGRTMIN);
    while(i--)
    {
        sleep(1);
    }
    panduan();
    return 0;
}

