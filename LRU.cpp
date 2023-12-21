#include <iostream>
#include <unordered_map>  // 哈希表头文件
#include <list>  // 双向链表头文件
using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {  // 构造函数，初始化缓存容量
        this->capacity = capacity;
    }
    
    int get(int key) {  // 获取键值对的值
        auto it = cache.find(key);  // 在哈希表中查找键
        if (it == cache.end()) return -1;  // 如果键不存在，返回-1
        pair<int, int> kv = *it->second;  // 获取键值对
        cache_list.erase(it->second);  // 将键值对从链表中移除
        cache_list.push_front(kv);  // 将键值对移到链表头部
        cache[key] = cache_list.begin();  // 更新哈希表中键对应的迭代器
        return kv.second;  // 返回键值对的值
    }
    
    void put(int key, int value) {  // 添加键值对
        auto it = cache.find(key);  // 在哈希表中查找键
        if (it != cache.end()) {  // 如果键已经存在
            cache_list.erase(it->second);  // 将键值对从链表中移除
        } else {  // 如果键不存在
            if (cache.size() == capacity) {  // 如果缓存已满
                int key_to_del = cache_list.back().first;  // 获取最近最少使用的键
                cache_list.pop_back();  // 将最近最少使用的键值对从链表中移除
                cache.erase(key_to_del);  // 将最近最少使用的键值对从哈希表中移除
            }
        }
        cache_list.push_front({key, value});  // 将键值对添加到链表头部
        cache[key] = cache_list.begin();  // 将键值对的迭代器添加到哈希表中
    }

private:
    int capacity;  // 缓存容量
    list<pair<int, int>> cache_list;  // 双向链表，存储键值对
    unordered_map<int, list<pair<int, int>>::iterator> cache;  // 哈希表，存储键值对的迭代器
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
