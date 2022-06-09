#include <iostream>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

int main()
{
    int a[2] = { 0 };
    int c = pipe(a);
    if(c < 0)
    {
        perror("pipe err:");
        return -1;
    }
    write(a[1],"11122222",10);
    cout << "write suc" << endl;

    char b[100] = { 0 };
    read(a[0],b,100);
    cout << b << endl;
    std::cout << "Hello world" << std::endl;
    return 0;
}

