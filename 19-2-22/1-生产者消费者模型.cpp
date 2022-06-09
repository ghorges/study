#include <iostream>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

using namespace std;
#define pro 4
#define buy 2

//锁
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
//这个也不知道怎么说
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int cont = 0;

void *buys(void *p)
{
    int *num = (int *)p;
    while(1)
    {
        pthread_mutex_lock(&mutex);
        cout << "我是消费者" << num << "号线程" << endl;
        while(cont == 0)
        {
            cout << "休眠" << endl;
            //1.把锁丢掉2.休眠3.等人来激活
            pthread_cond_wait(&cond,&mutex);
        }
        cont--;
        cout << "消费成功" << cont << endl;
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    pthread_exit(0);
}


void *pros(void *p)
{
    int *num = (int *)p;
    
    while(1)
    {
        pthread_mutex_lock(&mutex);
        cout << "我是生产者" << num << "号线程" << endl; 
        cont++;
        cout << "生产并放出信号" << cont << endl;
        //通知休眠的，等我把锁子解开了，就可以给你用了
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }

    pthread_exit(0);
}


int main()
{
    //记录创建线程的线程号
    pthread_t t[100];
    int m = 0;
    memset(t,0,sizeof(t));

    //批量创建消费者线程
    for(int i = 0;i < buy;i++)
    {
        if(pthread_create(&t[m++],NULL,buys,(void *)i) < 0)
        {
            perror("create err:");
            return -1;
        }
    }
    //批量创建生产者线程
    for(int i = 0;i < pro;i++)
    {
        if(pthread_create(&t[m++],NULL,pros,(void *)i) < 0)
        {
             perror("create err:");
             return -1;         
        }
    }

    //等待所有子线程
    for(int i = 0;i < m;i++)
    {
        pthread_join(t[i],NULL);
    }
    return 0;
}

