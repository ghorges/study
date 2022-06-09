#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

int read_timeout(int fd, unsigned int wait_seconds)
{
    int red = 0;
    if(wait_seconds > 0)
    {
        fd_set read_set;
        struct timeval tv;
        int retval;

        FD_ZERO(&read_set);
        FD_SET(fd,&read_set);

        tv.tv_sec = wait_seconds;
        tv.tv_usec = 0;

        do
        {
            red = select(fd + 1,&read_set,NULL,NULL,&tv);
        }while(red < 0 && errno == EINTR);

        if(red > 0)
        {
            red = 0;
        }
        if(red == 0)
        {
            red = -1;
            errno = ETIMEDOUT;
        }

    }
    return red;
}
int accept_timeout(int fd, struct sockaddr_in *addr, unsigned int wait_seconds)
{
    int ret = 0;
    if(wait_seconds > 0)
    return ret;
}
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

