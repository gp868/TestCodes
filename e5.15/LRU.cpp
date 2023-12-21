#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class LRUCache{
public:
    LRUCache(int capacity){
        this->capacity = capacity;
    }

    int get(int key){
        auto it = cache.find(key);
        if(it == cache.end()){
            return -1;
        }
        pair<int, int> kv = *it->second;
        cacheList.erase(it->second);
        cacheList.push_front(kv);
        cache[key] = cacheList.begin();
        return kv.second;
    }

    void put(int key, int val){
        auto it = cache.find(key);
        if(it != cache.end()){
            cacheList.erase(it->second);
        }else{
            if(cache.size() == capacity){
                int key_to_del = cacheList.back().first;
                cacheList.pop_back();
                cache.erase(key_to_del);
            }
        }
        cacheList.push_front({key, val});
        cache[key] = cacheList.begin();
    }

private:
    int capacity;
    list<pair<int, int>> cacheList;
    unordered_map<int, list<pair<int, int>>::iterator> cache;
};


int main() {
    LRUCache cache(2);  // 创建LRU缓存，容量为2
    cache.put(1, 1);  // 缓存中添加键1，值1
    cache.put(2, 2);  // 缓存中添加键2，值2
    cout << cache.get(1) << endl;  // 从缓存中获取键1的值，输出1
    cache.put(3, 3);  // 缓存中添加键3，值3，此时缓存已满，键2被淘汰
    cout << cache.get(2) << endl;  // 从缓存中获取键2的值，输出-1
    cache.put(4, 4);  // 缓存中添加键4，值4，此时缓存已满，键1被淘汰
    cout << cache.get(1) << endl;  // 从缓存中获取键1的值，输出-1
    cout << cache.get(3) << endl;  // 从缓存中获取键3的值，输出3
    cout << cache.get(4) << endl;  // 从缓存中获取键4的值，输出4
    // 输出为：1 -1 -1 3 4     ^_^
    return 0;
}
