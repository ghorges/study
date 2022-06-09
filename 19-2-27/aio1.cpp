#include <iostream>
#include <aio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
using namespace std;
void p(int t,siginfo_t *q,void *r)
{
    char *c = (char *)q->si_ptr;
    cout << c << endl;
    cout << "读取完成" << endl;
}
int main()
{
    //注册信号
    struct sigaction act;
    memset(&act,0,sizeof(act));
    act.sa_sigaction = p;
    act.sa_flags = SA_SIGINFO | SA_RESTART;
    sigaction(SIGRTMIN,&act,NULL);
    //int aio_read(struct aiocb *aiocbp);
    struct aiocb aios;
    memset(&aios,0,sizeof(aios));
    aios.aio_fildes = open("nochange.mp3",O_RDONLY);
    if(aios.aio_fildes < 0)
    {
        perror("open err:");
        return -1;
    }
    aios.aio_offset = 0;
    char *c = (char *)calloc(4000000,1);
    aios.aio_buf = c;
    aios.aio_reqprio = 0;
    aios.aio_nbytes = 4000000;
    aios.aio_sigevent.sigev_notify = SIGEV_NONE;

    if(aio_read(&aios) < 0)
    {
        perror("aid_read err:");
        return -1;
    }
    while(1)
    {
        int t = aio_error(&aios);
        int flag = 0;
        switch(t)
        {
        case EINPROGRESS:
            cout << "请求尚未完成" << endl;
            break;
        case ECANCELED:
            cout << "请求取消了"  << endl;
            break;
        case -1:
            perror("aio err:");
            return -1;
        case 0:
            cout << "请求成功" << endl;
            flag = 1;
            break;
        }
        if(flag)
            break;
    }
    int aio_sum = aio_return(&aios);
    int fd = open("www.mp3",O_WRONLY);
    if(fd < 0)
    {
        cout << "err" << endl;
        return -1;
    }
    //int t = write(fd,c,2801111);
    int t = write(fd,c,4000000);
    cout << "t" << t << endl;
    cout << aio_sum << endl;
    std::cout << "Hello world" << std::endl;
    return 0;
}

