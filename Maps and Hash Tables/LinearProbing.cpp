#include <iostream>
#include <vector>
#include <functional>
class LinearProbingHashTable {
private:
    std::vector<int> table;
    int capacity;
public:
    LinearProbingHashTable(int size) : capacity(size) {
        table.resize(capacity, -1);  // Initialize all slots to -1 (indicating empty)
    }
    int hashFunction(int key) const {
        return key % capacity;
    }
    void insert(int key) {
        int index = hashFunction(key);
        while (table[index] != -1) {
            index = (index + 1) % capacity;
        }
        table[index] = key;
    }
    bool search(int key) const {
        int index = hashFunction(key);
        while (table[index] != -1) {
            if (table[index] == key) {
                return true;  
            }
            index = (index + 1) % capacity;
        }
        return false; 
    }
    void display() const {
        std::cout << "Hash Table: ";
        for (int i = 0; i < capacity; ++i) {
            std::cout << table[i] << " ";
        }
        std::cout << std::endl;
    }
};
int main() {
    LinearProbingHashTable hashTable(10);
    hashTable.insert(5);
    hashTable.insert(25);
    hashTable.insert(15);
    hashTable.insert(35);
    hashTable.display();
    int keyToSearch = 15;
    if (hashTable.search(keyToSearch)) {
        std::cout << keyToSearch << " found in the hash table." << std::endl;
    } else {
        std::cout << keyToSearch << " not found in the hash table." << std::endl;
    }
    return 0;
}
