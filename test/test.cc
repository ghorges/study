#include <iostream>

using namespace std;

class a{
public:
    ~a() {
        cout << "a delete" << endl;
    }
};

class b : public a{
public:
    ~b() {
        cout << "b delete" << endl;
    }
};

int main()
{
    b* t = new b;
    delete t;
    std::cout << "Hello world" << std::endl;
    return 0;
}

