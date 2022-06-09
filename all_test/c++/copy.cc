#include <iostream>
#include <vector>


//经测试，这个copy & copy_back != while(first != last) { *result = *first;++result;++first; }
//这个是吧之前的数据先保存起来，避免程序员有误操作
int main()
{
    std::vector<int> p;
    for (int i = 0; i < 5; i++)
        p.push_back(i);

    std::copy(p.begin(), p.begin() + 4, p.begin() + 1);
    // std::copy_backward(p.begin(), p.begin() + 3, p.begin() + 2);
    for (int &i : p)
        std::cout << "i = " << i << "\n";
    std::cout << "Hello world" << std::endl;
    return 0;
}

