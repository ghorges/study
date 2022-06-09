#include <iostream>
#include <queue>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include<functional>
#include <vector>
#include <unistd.h>

//最少线程数
#define MMin 15
//最大线程数
#define MMax 100

using namespace std;
//定义了一个可以指向void *(void *)函数的数据类型
typedef  void *(*typ_thread)(void *);

typedef struct{
    typ_thread p;
    void *q;
}typ_str_thread;
//queue <typ_thread> thread_tast_que;
//vector <pthread_t> thr_tid;

void *thread_run(void *);
void *r_thread_run(void *);
class my_thread
{
    public:
        //对当前工作的那个数量加锁
        pthread_mutex_t mutex_busy_num = PTHREAD_MUTEX_INITIALIZER;
        //生产者消费者的条件变量，是队列中的
        pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
        //条件变量，没有任务时，等待
        pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
        //普通线程
        //vector <pthread_t> tid_num(100);
        pthread_t tid_num[100];
        //管理者线程
        pthread_t r_tid;

        //当前存活的
        int live_thr_num;
        //当前工作的
        int busy_thr_num;
        //多出来要杀死的
        int wait_thr_num;

        //任务队列
        queue <typ_str_thread> tast;
    
        //线程池是关闭还是开启
        bool shutdown;
public:
    my_thread(void)
    {
        live_thr_num = MMin;
        busy_thr_num = 0;
        wait_thr_num = 0;
        
        shutdown = false;

        //创建初始线程
        for(int i = 0;i < MMin;i++)
        //for(int i = 0;i < 1;i++)
        {
            if(pthread_create(&tid_num[i],NULL,thread_run,(void *)this) < 0)
            {
                perror("create err:");
                exit(-1);
            }
        }
        if(pthread_create(&r_tid,NULL,r_thread_run,(void *)this) < 0)
        {
            perror("create err:");
            exit(-1);
        }
    }
    //新来的任务加入队列
    void thread_add(typ_thread p,void *q)
    {
        typ_str_thread t1;
        t1.p = p;
        t1.q = q;
        pthread_mutex_lock(&mutex1);
        this->tast.push(t1);
        cout << "成功加入队列"  << endl;
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex1);
    }
};
void *thread_run(void *p)
{
    //脱离控制
    pthread_detach(pthread_self());
    my_thread *q = (my_thread*)p;
    cout << "我是普通线程"  <<  pthread_self() << endl;
    while(1)
    {
        pthread_mutex_lock(&q->mutex1);
        while(q->tast.empty()){
            pthread_cond_wait(&q->cond,&q->mutex1);
            cout << "我被唤醒了" << endl;
        if(q->wait_thr_num > 0)
        {
            cout << "自杀小队，激活" << endl;
            q->wait_thr_num--;
            pthread_mutex_unlock(&q->mutex1);
            pthread_exit(NULL);
        }
        }
        //取出任务
        typ_str_thread ev_tast = q->tast.front();
        q->tast.pop();
        //立刻释放锁
        pthread_mutex_unlock(&q->mutex1);

        pthread_mutex_lock(&q->mutex_busy_num);
        q->busy_thr_num++;
        pthread_mutex_unlock(&q->mutex_busy_num);
        //执行
        ev_tast.p(ev_tast.q);

        pthread_mutex_lock(&q->mutex_busy_num);
        q->busy_thr_num--;
        pthread_mutex_unlock(&q->mutex_busy_num);
    } 
}
void *r_thread_run(void *p)
{
    pthread_detach(pthread_self());
    my_thread *q = (my_thread*)p;
    int sum = 0;
    while(1)
    {
        cout << "我是管理者线程" << ++sum;
        cout <<  "   " << q->live_thr_num << "   " << q->busy_thr_num << endl;
        if(((q->live_thr_num - q->busy_thr_num) < 10) && (q->live_thr_num < MMax))
        {
            for(int i = 0;i < MMin;i++)
            {   
                pthread_t t;
                if(pthread_create(&t,NULL,thread_run,p) < 0)
                {   
                    perror("create err:");
                    exit(-1);
                }
            }
            q->live_thr_num += MMin;
            cout << "建立一些线程" << endl;
        }

         if((q->live_thr_num - q->busy_thr_num) > 20 && q->live_thr_num > MMin)
         {
            q->wait_thr_num = 10;
            for(int i = 0;i < 10;i++)
            {
                pthread_cond_signal(&q->cond);
            }
            q->live_thr_num -= 10;
            cout << "清除一些线程" << endl;
         }
         sleep(1);
    }
}

void *p(void *a)
{
    usleep(100);
    cout << "成功执行函数" << a << endl;
}
/*
int main()
{
    my_thread t1;
    for(int i = 0;i < 1000;i++)
    {
        t1.thread_add(p,(void *)i);
        if(i % 100 == 0)
        {
            sleep(2);
        }
    }
    cout << "Hello world" << endl;
    sleep(10);
    return 0;
}
*/
