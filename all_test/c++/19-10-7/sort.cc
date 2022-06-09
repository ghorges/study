#include <bits/stdc++.h>

using namespace std;

void vsort(int *a, int i, int n)
{
    while (1) {
        if (i * 2 + 1 > n) 
            break;
        int t = max(a[i * 2 + 1], a[i * 2 + 2]);
        int sub;
        if (t == a[i * 2 + 1])
            sub = i * 2 + 1;
        else 
            sub = i * 2 + 2;

        if (a[i] < a[sub]) {
            int m = a[i];
            a[i] = a[sub];
            a[sub] = m;
            i = sub;
            continue;
        }
        else {
            return;
        }
    }
    return;
}


void ssort(int *a,int i)
{
    swap(a[0], a[i]);
    vsort(a, 0, i - 1);
}

void sort(int *a, int n)
{
    for (int i = ((n + 1) / 2); i >= 0; --i) {
        vsort(a, i, n);    
    }





    for (int i = n - 1; i > 0; --i) {
        ssort(a, i);
    }
    return;
}


int main()
{
    int n;
    int a[10005] = { 0 };
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, n);
    for (int i = 0; i < n; ++i) {
        cout << a[i];
    }
    std::cout << "Hello world" << std::endl;
    return 0;
}

