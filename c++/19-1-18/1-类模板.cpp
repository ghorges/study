#include <iostream>
//类模板
using namespace std;
//好处：将数据结构和算法有效的分离。。。

template <typename T>
class tclass
{
public:
    tclass(T a)
    {
        this->a = a;
    }
private:
    T a;
};

//模板类派生时，要具体化模板类
//要知道父亲所占内存大小是多少,因为只有数据类型固定下来，才知道如何分配内存
//数据类型是固定大小内存块的别名
class b : public tclass <int>
{
public:
    //tclass <int>(a)  把这个尽量写上
    b(int a = 10,int c = 20) : tclass <int>(a)
    {
        this->c = c;
    }
private:
    int c;
};

int main()
{
    b b1;
    std::cout << "Hello world" << std::endl;
    return 0;
}

