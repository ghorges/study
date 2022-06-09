#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
//这个是测试回调函数可以写在不同地方,以及正规写法
using namespace std;

void handler(int a)
{
    switch(a)
    {
    case SIGINT:
        cout << "i'm SIGINT" << endl;
        break;
    case SIGCHLD:
        break;
    }
    return;
}
int main()
{/*//这个是测试回调函数先写在上面，后写在下面，内核执行的不同
    signal(SIGINT,handler);
    int i = 3;
    while(i--)
    {
        pause();
    }
    signal(SIGINT,SIG_DFL);
    while(1)
    {
        pause();
    }*/
    /*
    //这个是测试返回值
    __sighandler_t old =  signal(SIGINT,handler);
    int i = 3;
    while(i--)
    {
        pause();
                             
    }
    signal(SIGINT,old);
    while(1)
    {
        pause();                                 
    }

    */
    //这个是正规写法
    if(signal(SIGINT,handler) == SIG_ERR)
    {
        perror("sigerr");
        exit(0);
    }else{
        
    }
   return 0;
}

