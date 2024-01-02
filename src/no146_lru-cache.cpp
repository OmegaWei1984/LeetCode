#include <iostream>
#include <list>
#include <unordered_map>
#include <algorithm>

using namespace std;

class LRUCache
{
public:
    LRUCache(int capacity)
    {
        capacity_ = capacity;
    }

    int get(int key)
    {
        auto it = data.find(key);
        if (it != data.end()) {
            used.splice(used.begin(), used, it->second);
            return it->second->second;
        }
        return -1;
    }

    void put(int key, int value)
    {
        auto it = data.find(key);
        if (it != data.end()) {
            used.splice(used.begin(), used, it->second);
            it->second->second = value;
            return;
        }
        used.emplace_front(key, value);
        data[key] = used.begin();
        if (used.size() > capacity_) {
            data.erase(used.back().first);
            used.pop_back();
        }
    }

private:
    int capacity_;
    unordered_map<int, list<pair<int, int>>::iterator> data;
    list<pair<int, int>> used;
};

int main(void)
{
    LRUCache *cache = new LRUCache(2);
    // // case 1
    // cache->put(1, 1);
    // cache->put(2, 2);
    // std::cout << cache->get(1) << std::endl;
    // cache->put(3, 3);
    // std::cout << cache->get(2) << std::endl;
    // cache->put(4, 4);
    // std::cout << cache->get(1) << std::endl;
    // std::cout << cache->get(3) << std::endl;
    // std::cout << cache->get(4) << std::endl;

    // case 2
    cache->put(2, 1);
    cache->put(1, 1);
    cache->put(2, 3);
    cache->put(4, 1);
    std::cout << cache->get(1) << std::endl;
    std::cout << cache->get(2) << std::endl;

    return 0;
}