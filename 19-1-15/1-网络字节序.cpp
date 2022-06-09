#include <iostream>
#include <arpa/inet.h>
#include <cstdio>
using namespace std;
//事实证明，网络字节序确实是大端序
int main()
{
    int p = 0x12345678;
    char *c = (char *)&p;
    printf("%x %x %x %x\n",c[0],c[1],c[2],c[3]);
    int q = htonl(p);
    c = (char *)&q;
    printf("%x %x %x %x\n",c[0],c[1],c[2],c[3]);
    std::cout << "Hello world" << std::endl;
    return 0;
}

