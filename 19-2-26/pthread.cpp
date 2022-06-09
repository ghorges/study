#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

using namespace std;

void *pth(void *p)
{
    int *q = (int *)p;
    cout << *q << endl;
    sleep(2);
    cout << *q << endl;
}
int main()
{
    pthread_t tid;
    int i = 1;
    if(pthread_create(&tid,NULL,pth,(void *)&i) < 0)
    {
        perror("err:");
        return -1;
    }
    sleep(1);
    i = 2;
    cout << "改了" << endl;
    sleep(1);
    std::cout << "Hello world" << std::endl;
    return 0;
}

