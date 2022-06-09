#include <iostream>

using namespace std;

int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    char c[100] = { 0 };
    getline(cin, c, '\n');
    for (int i = 0; i < n; i++)
    {
        cout << c[i] << endl;
    }
    std::cout << "Hello world" << std::endl;
    return 0;
}

