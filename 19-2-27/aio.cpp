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
    aios.aio_fildes = open("www.txt",O_RDONLY);
    if(aios.aio_fildes < 0)
    {
        perror("open err:");
        return -1;
    }
    aios.aio_offset = 0;
    char c[100] = { 0 };
    aios.aio_buf = (void *)c;
    aios.aio_nbytes = 100;
    aios.aio_sigevent.sigev_notify = SIGEV_SIGNAL;
    aios.aio_sigevent.sigev_signo = SIGRTMIN;
    aios.aio_sigevent.sigev_value.sival_ptr = (void *)c;

    if(aio_read(&aios) < 0)
    {
        perror("aid_read err:");
        return -1;
    }
    cout << "看看谁先执行" << endl;
    sleep(10);
    std::cout << "Hello world" << std::endl;
    return 0;
}

