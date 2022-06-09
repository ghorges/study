#include <iostream>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

using namespace std;
//通过最后一个参数取地址传递
struct teacher
{
    char c[100];
    int age;
};
void *aaa(void *arg)
{
    teacher *t = (teacher *)arg;
    cout << "t = " << t << endl; 
    //...写了这个，相当于就不会有僵尸线程了，pthread_join也就不会等你了。。。
    //pthread_detach(pthread_self());
    strcpy(t->c,"wangping");
    t->age = 10;
    sleep(10);
    return t;
    pthread_exit(t);
}
int main()
{

    pthread_t tid = 0;
    teacher t1;
    memset(&t1,0,sizeof(t1));
    if(pthread_create(&tid,NULL,aaa,(void *)&t1) < 0)
    {
        perror("create err:");
        return -1;
    }
    cout << "&t1 = " << &t1 << endl;
    sleep(2);
    cout << "通过传参数传递" << endl;
    cout << t1.c << endl;
    cout << t1.age << endl;
    std::cout << "Hello world" << std::endl;
    //通过返回值传递
    teacher *t2 = NULL;
    pthread_join(tid,(void **)&t2);
    cout << "t2 = " << t2 << endl;
    cout << "通过返回值传递" << endl;
    cout << t2->c << endl;
    cout << t2->age << endl;
    return 0;
}

