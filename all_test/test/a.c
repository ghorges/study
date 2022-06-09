#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
static int t = 0;

void* handle(void* p)
{
    int i;
    for(i = 0;i < 100000000;i++)
    {
        int aaaaa;
        aaaaa = i;
        t++;
    }
}


int main()
{
    pthread_t tid;
    pthread_t tid_1;
    pthread_create(&tid,NULL,handle,NULL);
    pthread_create(&tid_1,NULL,handle,NULL);

    pthread_join(tid,NULL);
    pthread_join(tid_1,NULL);
    printf("t = %d\n",t);
    return 0;
}
