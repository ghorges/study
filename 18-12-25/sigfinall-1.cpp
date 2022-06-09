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
    else
    {
        cout << "未知信号" << endl;
    }
}
sigset_t set1;
void handlerssss(int a)
{
    if(a == SIGALRM)
    {
            //sigset_t set1;
            sigpending(&set1);
            sigprint(&set1);
            
            sigemptyset(&set1);
            sigaddset(&set1,SIGINT);
            if(sigprocmask(SIG_UNBLOCK,&set1,NULL) == -1)
            {
                cout << "sigproc err" << endl;
            }
            else
            {
                cout << "sigproc success" << endl;

                sigset_t set2;
                sigemptyset(&set2);
                if(sigprocmask(SIG_UNBLOCK,NULL,&set2) == 0)
                {
                    cout << "sigproc suc" << endl;
                    sigprint(&set2);
                }
            }




            cout << "i'm alarm" <<endl;
            //sigemptyset(&set1);
            //sigprocmask(SIG_UNBLOCK,NULL,&set1);
            //sigprint(&set1);
    }
}
int main()
{

    struct sigaction act;
    act.sa_handler = handler;
    sigaction(SIGINT,&act,NULL);
    signal(SIGALRM,handlerssss);

    //sigset_t set1;
    sigemptyset(&set1);
    sigaddset(&set1,SIGINT);
    
    sigprocmask(SIG_BLOCK,&set1,NULL);
        alarm(2);
        int i = 5;
        while(i--)
        {
            if(i == 1)
            {
                //sigset_t set1;
                 //sigpending(&set1);
                //sigprint(&set1);

            }
            sleep(1);
        }


        sigemptyset(&set1);
        //sigaddset(&set1,SIGINT);
        sigprocmask(SIG_UNBLOCK,NULL,&set1);
        sigprint(&set1);
        alarm(2);
                                            i = 5;
                                            while(i--)
                                            {
                                                sleep(1);
                                            }
       printf("``````````````````````````\n");
       sigemptyset(&set1);
       sigprocmask(SIG_UNBLOCK,NULL,&set1);
       sigprint(&set1);
        return 0;

}
