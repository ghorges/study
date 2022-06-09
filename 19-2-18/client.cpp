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
#include <signal.h>
//测试服务器关闭，这边是否会收到信号
using namespace std;

void handle(int a)
{
    if(a == SIGPIPE)
    {
        cout << "我已经关闭了，别给我发信号了" << endl;
        sleep(5);
    }
}
int main()
{
    signal(SIGPIPE,handle);
    int fd = socket(AF_INET,SOCK_STREAM,0);
    if(fd == -1)
    {
        perror("soc err:");
        return -1;
    }

    struct sockaddr_in conn_addr;
    conn_addr.sin_family = AF_INET;
    conn_addr.sin_port = htons(8888);
    conn_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if(connect(fd,(struct sockaddr*)&conn_addr,sizeof(conn_addr)) < 0)
    {
        perror("conn err:");
        return -1;
    }
    
    while(1)
    {
        char buf[100] = { 0 };
        memset(buf,0,sizeof(buf));
        cin >> buf;
        send(fd,buf,100,0);
    }

    std::cout << "Hello world" << std::endl;
    return 0;
}

