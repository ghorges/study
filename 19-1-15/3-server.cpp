#include <iostream>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <errno.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <cstring>
#include <cstdlib>

using namespace std;


int main()
{
    int sockfd = 0;
    sockfd = socket(AF_INET,SOCK_STREAM,0);
    if(sockfd == -1)
    {
        perror("socket err:");
        return -1;
    }

/*
int connect(int sockfd, const struct sockaddr *addr,socklen_t addrlen);
*/
    struct sockaddr_in connaddr;
    memset(&connaddr,0,sizeof(connaddr));
    connaddr.sin_family = AF_INET;
    connaddr.sin_port = htons(8008);
    connaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    if(bind(sockfd,(struct sockaddr *)&connaddr,sizeof(connaddr)) < 0)
    {
        perror("conn err:");
        return -1;
    }
    if(listen(sockfd,20) < 0)
    {
        perror("listen err:");
        return -1;
    }



    std::cout << "Hello world" << std::endl;
    return 0;
}

