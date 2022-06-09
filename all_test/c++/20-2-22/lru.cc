#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class lru{
public:
    lru(int num):capacity(num) {}
    int get(int key) {
        if (pos.find(key) == pos.end())
            return -1;
        put(key, pos[key]->second);
        return pos[key]->second;
    }
    
    int put(int key, int value) {
        if (pos.find(key) != pos.end()) {
            recent.erase(pos[key]);
        } else if (recent.size() >= capacity) {
            pos.erase(recent.back().first);
            recent.pop_back();
        }

        recent.push_front({key, value});
        pos[key] = recent.begin();
    }

private:
    int capacity;
    list<pair<int,int>> recent;
    unordered_map<int, list<pair<int,int>>::iterator> pos;
};
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

