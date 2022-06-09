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
#include <unistd.h>

using namespace std;


int main()
{
    //socket相当于通过告知内核，产出一个描述符，下一步就可以连接了
    int fd = socket(AF_INET,SOCK_STREAM,0);
    if(fd == -1)
    {
        perror("socket err:");
        return -1;
    }
/*
 * int connect(int sockfd, const struct sockaddr *addr,
 *                    socklen_t addrlen);
 */
    //观察到connect的参数，第一个是描述符，第二个是填写网络地址，端口，tcp
    //等之类的，第三个就是第二个的长度，记得sockaddr_in要转为sockaddr
    struct sockaddr_in con_addr;
    memset(&con_addr,0,sizeof(con_addr));
    con_addr.sin_family = AF_INET;
    con_addr.sin_port = htons(8008);
    con_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if(connect(fd,(struct sockaddr *)&con_addr,sizeof(con_addr)) < 0)
    {
        perror("conn err:");
        return -1;
    }
    //每隔几秒发送
    //while(1)
    {
        sleep(1);
        sleep(500);
        send(fd,"hello...\n",9,0);
    }
        std::cout << "Hello world" << std::endl;
    return 0;
}

