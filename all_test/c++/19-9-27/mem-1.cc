#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

class person
{
public:
    person() : id(10), num(20) {}
    virtual void print() {
        cout << "print" << endl;
    }
    virtual void job() {
        cout << "person" << endl;
    }
    /* virtual */ ~person() {
        cout << "~person" << endl;
    }
protected:
    static int sid;
    int id;
    int num;
};

void fff()
{

}

int main(int argc, char **argv)
{
    person a;
    int *p = (int*)&a;
    using t = function<void()>;
    void **foo = (void**)(*(void**)&a);
    
    typedef void (*FuncPtr)();
    for (; *foo != NULL; ++foo) {
        FuncPtr func = (FuncPtr)*foo;
        func();
        /*
        t t1 = (t*)*foo;
        t1();
        */
    }
    sleep(10);
    //using function <void(void)> = t;
    cout << "id = " << *p << " address = " << p << endl;
    ++p;
    cout << "num = " << *p << "address = " << p << endl;
    
    ++p;
    cout << "id = " << *p << " address = " << p << endl;
    ++p;
    cout << "num = " << *p << "address = " << p << endl;
    
    std::cout << "Hello world" << std::endl;
    return 0;
}

