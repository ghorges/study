#include <iostream>
#include <signal.h>
#include <cstdio>
#include <cstring>
#include <errno.h>
#include <cstdlib>
#include <unistd.h>

using namespace std;
void handler(int a)
{
    if(a == SIGINT)
    {
        return;
    }
    if(a == SIGQUIT)
    {
        return;
    }
}
int main()
{
    while(1)
    {
        cout << "请输入你要读取的文件名:";
        char c[100] = { 0 };
        cin >> c;
        FILE *fd = NULL;
        fd = fopen(c,"r");
        if(fd == NULL)
        {
            perror("open err:");
            return -1;
        }
        /*
        signal(SIGINT,handler);
        signal(SIGQUIT,handler);
        */
        signal(SIGINT,SIG_IGN);
        signal(SIGQUIT,SIG_IGN);

        while(!feof(fd))
        {
            char d[100] = { 0 };
            fread(d,100,1,fd);
            cout << d;
            sleep(2);
        }
        signal(SIGINT,SIG_DFL);
        signal(SIGQUIT,SIG_DFL);
        fclose(fd);
    }
    std::cout << "Hello world" << std::endl;
    return 0;
}

