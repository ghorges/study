#include <iostream>
#include <ctring>
//区别
//工厂模式只能生产一个产品（香蕉或苹果）
//抽象工厂可以生产一个产品族（里边有很多产品组成）

//以前是具体工厂，现在是一个抽象工厂
//抽象工厂提前将这个规划出来

//产品线写死了
class factory{
public:

    virtual void banana() = 0;

    virtual void apple() = 0;
};

using namespace std;

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

