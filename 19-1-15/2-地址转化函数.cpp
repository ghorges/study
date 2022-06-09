#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

using namespace std;
//就是学习了地址转化函数

int main()
{
    char *p = "127.0.0.1";
    int a = inet_addr(p);
    cout << a << endl;

    struct in_addr b;

    inet_aton(p,&b);

    cout << b.s_addr << endl;

    char *q = inet_ntoa(b);
    cout << q << endl;
    std::cout << "Hello world" << std::endl;
    return 0;
}

