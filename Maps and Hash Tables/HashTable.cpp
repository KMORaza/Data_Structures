#include <iostream>
#include <vector>
#include <list>
#include <utility>
class HashTable {
private:
    static const int TABLE_SIZE = 10; 
    std::vector<std::list<std::pair<int, std::string>>> table;
    int hash(int key) {
        return key % TABLE_SIZE;
    }
public:
    HashTable() : table(TABLE_SIZE) {}
    void insert(int key, const std::string& value) {
        int index = hash(key);
        table[index].emplace_back(key, value);
    }
    std::string get(int key) {
        int index = hash(key);
        for (const auto& entry : table[index]) {
            if (entry.first == key) {
                return entry.second;
            }
        }
        return "Key not found";
    }
};
int main() {
    HashTable myHashTable;
    myHashTable.insert(1, "One");
    myHashTable.insert(11, "Eleven");
    myHashTable.insert(21, "Twenty-One");
    std::cout << "Value for key 1: " << myHashTable.get(1) << std::endl;
    std::cout << "Value for key 11: " << myHashTable.get(11) << std::endl;
    std::cout << "Value for key 21: " << myHashTable.get(21) << std::endl;
    std::cout << "Value for key 5: " << myHashTable.get(5) << std::endl;
    return 0;
}
