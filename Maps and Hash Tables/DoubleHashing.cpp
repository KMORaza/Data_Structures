#include <iostream>
#include <vector>
#include <functional>
class DoubleHashTable {
private:
    static const int TABLE_SIZE = 10;
    std::vector<int> table;
    std::vector<std::hash<int>> hashFunctions;
public:
    DoubleHashTable() : table(TABLE_SIZE, -1) {
        hashFunctions.push_back(std::hash<int>());
        hashFunctions.push_back(std::hash<int>() ^ (std::hash<int>() << 1));
    }
    void insert(int key) {
        int index = hashFunctions[0](key) % TABLE_SIZE;
        int step = hashFunctions[1](key) % (TABLE_SIZE - 1) + 1;
        for (int i = 0; i < TABLE_SIZE; ++i) {
            if (table[index] == -1) {
                table[index] = key;
                return;
            }
            index = (index + i * step) % TABLE_SIZE;
        }
        std::cout << "Unable to insert key: " << key << std::endl;
    }
    bool search(int key) {
        int index = hashFunctions[0](key) % TABLE_SIZE;
        int step = hashFunctions[1](key) % (TABLE_SIZE - 1) + 1;
        for (int i = 0; i < TABLE_SIZE; ++i) {
            if (table[index] == key) {
                return true;
            }
            index = (index + i * step) % TABLE_SIZE;
        }
        return false;
    }
};
int main() {
    DoubleHashTable doubleHashTable;
    doubleHashTable.insert(5);
    doubleHashTable.insert(15);
    doubleHashTable.insert(25);
    std::cout << "Search 15: " << (doubleHashTable.search(15) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search 10: " << (doubleHashTable.search(10) ? "Found" : "Not Found") << std::endl;
    return 0;
}
