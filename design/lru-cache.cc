/*
    Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

    get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
    put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

    The cache is initialized with a positive capacity.

    Follow up:
    Could you do both operations in O(1) time complexity?

    Example:

    LRUCache cache = new LRUCache( 2 * capacity);

    cache.put(1, 1);
    cache.put(2, 2);
    cache.get(1);       // returns 1
    cache.put(3, 3);    // evicts key 2
    cache.get(2);       // returns -1 (not found)
    cache.put(4, 4);    // evicts key 1
    cache.get(1);       // returns -1 (not found)
    cache.get(3);       // returns 3
    cache.get(4);       // returns 4
*/

#include <list>
#include <unordered_map>

using namespace std;

/* 
    Use doubly LL for constant time insertion and deletion.
    Move most frequently used element at the front when accessed, updated or created
    Keep mapping of key: value and key: node for constant time access
*/
class LRUCache {
    int cap;
    list<int> cache;
    unordered_map<int, list<int>::iterator> mapping;
    unordered_map<int, int> values;

    void maintainLRU(int key) {
        auto it = mapping[key];
        cache.erase(it);
        cache.push_front(key);
        mapping[key] = cache.begin();  // trick
    }

    void evict() {
        int key = cache.back();
        cache.pop_back();
        values.erase(key);
        mapping.erase(key);
    }

   public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        // if (mapping.find(key) == mapping.end()) return -1;
        // int val = values[key];
        // maintainLRU(key);
        // return val;

        auto it = values.find(key);
        if (it == values.end()) return -1;

        maintainLRU(key);

        int val = it->second;
        return val;
    }

    void put(int key, int value) {
        // update if key exists
        if (mapping.find(key) != mapping.end()) {
            values[key] = value;
            maintainLRU(key);
            return;
        }

        if (cache.size() == cap) evict();

        // insert new k: v
        cache.push_front(key);
        mapping[key] = cache.begin();
        values[key] = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
