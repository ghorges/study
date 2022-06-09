#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    // vector is simple
    int myints[] = {10, 20, 30, 30, 20, 10, 10, 20};
    std::vector<int> myvector(myints, myints + 8);

    std::replace(myvector.begin(), myvector.end(), 20, 99);
    
    std::cout << "myvector contains:";
    for (int &i : myvector) {
        std::cout << i << " ";
    }
    std::cout << "Hello world" << std::endl;
    return 0;
}

