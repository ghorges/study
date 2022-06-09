#include <iostream>
#include <cstring>

using namespace std;
//这个就相当于有一个工厂，这个工厂是用来生产水果的，有各种各样的水果。
//这个不符合开辟原则，开辟原则是指，增加新的功能不改变原来的代码，这个要往里边增，会改
//其他23种设计模式，都符合开辟原则
class Fruit
{
public:
    virtual void getfruit() = 0;
};

class apple : public Fruit
{
public:
    void getfruit()
    {
        cout << "apple" << endl;
    }
};

class banana : public Fruit
{
public:
    void getfruit()
    {
        cout << "banana" << endl;
    }
};

class Factory
{
public:
    Fruit* create(char* p)
    {
        if(strcmp(p,"banana") == 0)
        {
            return new banana;
        } else if(strcmp(p,"apple") == 0)
        {
            return new apple;
        } else
        {
            cout << "???" << endl;
            return 0;
        }
    }
};

int main()
{
    Factory* t = new Factory;

    Fruit* p;
    p = t->create("banana");
    if(p == NULL)
    {
        cout << "create err" << endl;
    }
    p->getfruit();

    p = t->create("apple");
    p->getfruit();

    p = t->create("111");
    p->getfruit();
    delete p;
    delete t;
    std::cout << "Hello world" << std::endl;
    return 0;
}
