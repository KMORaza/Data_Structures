// LRU Cache Implementation
#include <iostream>
#include <unordered_map>
struct Node {
    int key;
    int value;
    Node* next;
    Node(int k, int v) : key(k), value(v), next(nullptr) {}
};
class LRUCache {
private:
    int capacity;
    Node* head; 
    Node* tail; 
    std::unordered_map<int, Node*> cacheMap; 
public:
    LRUCache(int capacity) : capacity(capacity), head(nullptr), tail(nullptr) {}
    int get(int key) {
        if (cacheMap.find(key) != cacheMap.end()) {
            Node* currentNode = cacheMap[key];
            moveToFront(currentNode);
            return currentNode->value;
        }
        return -1; 
    }
    void put(int key, int value) {
        if (cacheMap.find(key) != cacheMap.end()) {
            Node* currentNode = cacheMap[key];
            currentNode->value = value;
            moveToFront(currentNode);
        } else {
            Node* newNode = new Node(key, value);
            insertFront(newNode);
            if (cacheMap.size() > capacity) {
                removeLRU();
            }
            cacheMap[key] = newNode;
        }
    }
private:
    void moveToFront(Node* node) {
        if (node == head) {
            return; 
        }
        removeFromList(node);
        insertFront(node);
    }
    void removeLRU() {
        if (tail == nullptr) {
            return; 
        }
        removeFromList(tail);
        cacheMap.erase(tail->key);
        delete tail;
    }
    void removeFromList(Node* node) {
        if (node == nullptr) {
            return;
        }
        if (node->next != nullptr) {
            node->next = node->next->next;
        }
        if (node == head) {
            head = node->next;
        }
        if (node == tail) {
            tail = nullptr;
        }
    }
    void insertFront(Node* node) {
        if (node == nullptr) {
            return;
        }
        node->next = head;
        head = node;
        if (tail == nullptr) {
            tail = node;
        }
    }
};
int main() {
    LRUCache lruCache(3);
    lruCache.put(1, 1);
    lruCache.put(2, 2);
    lruCache.put(3, 3);
    std::cout << "Current cache state after initial puts:\n";
    std::cout << "Key 1: " << lruCache.get(1) << std::endl;
    std::cout << "Key 2: " << lruCache.get(2) << std::endl;
    std::cout << "Key 3: " << lruCache.get(3) << std::endl;
    lruCache.put(4, 4);
    std::cout << "\nCurrent cache state after putting a new key-value pair (4, 4):\n";
    std::cout << "Key 1: " << lruCache.get(1) << std::endl;
    std::cout << "Key 2: " << lruCache.get(2) << std::endl;
    std::cout << "Key 3: " << lruCache.get(3) << std::endl;
    std::cout << "Key 4: " << lruCache.get(4) << std::endl;
    return 0;
}
