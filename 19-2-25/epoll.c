#include <stdio.h>
#include <unistd.h>
#include <sys/epoll.h>

#define mmax 2000
void epoll_run(int port)
{
    int epfd = epoll_create(mmax);
    if(epfd == -1)
    {
        perror("epoll_create err:");
        return;
    }
    int lfd = 1;
    //int lfd = init_listen_fd(port,epfd);
    struct epoll_event all[mmax];
    while(1)
    {
        int ret = epoll_wait(epfd,all,mmax,-1);
        if(ret == -1)
        {
            perror("epoll err:");
            return;
        }
        for(int i = 0;i < ret;++i)
        {
            struct epoll_event *pev = &all[i];
            if(!(pev->events & EPOLLIN))
            {
                //如果不是读事件
                continue;
            }

            if(pev->data.fd == lfd)
            {
                //接受连接
            }
            else
            {
                //处理消息
            }
        }
    }
}

int main()
{
    printf("Hello world\n");
    return 0;
}
