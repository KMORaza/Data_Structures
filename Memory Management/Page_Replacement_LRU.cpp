#include <iostream>
#include <list>
#include <unordered_map>
class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity) {}
    int get(int key) {
        auto it = pageMap.find(key);
        if (it == pageMap.end()) {
            return -1;
        }
        pageList.splice(pageList.begin(), pageList, it->second);
        return it->second->second;
    }
    void put(int key, int value) {
        auto it = pageMap.find(key);
        if (it != pageMap.end()) {
            it->second->second = value;
            pageList.splice(pageList.begin(), pageList, it->second);
        } else {
            if (pageMap.size() == capacity) {
                int leastRecentlyUsedKey = pageList.back().first;
                pageMap.erase(leastRecentlyUsedKey);
                pageList.pop_back();
            }
            pageList.emplace_front(key, value);
            pageMap[key] = pageList.begin();
        }
    }
    void displayCacheState() const {
        std::cout << "Cache State: ";
        for (const auto& entry : pageList) {
            std::cout << "(" << entry.first << ", " << entry.second << ") ";
        }
        std::cout << std::endl;
    }
private:
    int capacity;
    std::list<std::pair<int, int>> pageList;  // Doubly linked list to maintain page order
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> pageMap;
};
int main() {
    LRUCache lruCache(3);
    lruCache.put(1, 1);
    lruCache.displayCacheState();
    lruCache.put(2, 2);
    lruCache.displayCacheState();
    lruCache.put(3, 3);
    lruCache.displayCacheState();
    lruCache.get(2);
    lruCache.displayCacheState();
    lruCache.put(4, 4);
    lruCache.displayCacheState();
    lruCache.get(1);
    lruCache.displayCacheState();
    return 0;
}
