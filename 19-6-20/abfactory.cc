#include <iostream>
#include <cstring>
//工厂模式
using namespace std;

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

class abFactory
{
public:
    virtual Fruit* create() = 0;
};

class Factorybanana : public abFactory
{
public:
    Fruit* create()
    {
        return new banana;
    }
};

class Factoryapple : public abFactory
{
public:
    Fruit* create()
    {
        return new apple;
    }
};

int main()
{
    abFactory* t = NULL;
    Fruit* p;
    
    t = new Factorybanana;
    p = t->create();
    p->getfruit();

    delete p;
    delete t;
    std::cout << "Hello world" << std::endl;
    return 0;
}
