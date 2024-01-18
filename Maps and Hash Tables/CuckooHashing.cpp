#include <iostream>
#include <vector>
#include <functional>
class CuckooHashTable {
private:
    static const int TABLE_SIZE = 10;
    std::vector<int> table1;
    std::vector<int> table2;
    std::vector<std::hash<int>> hashFunctions;
public:
    CuckooHashTable() : table1(TABLE_SIZE, -1), table2(TABLE_SIZE, -1) {
        hashFunctions.push_back(std::hash<int>());
        hashFunctions.push_back(std::hash<int>() ^ (std::hash<int>() << 1));
    }
    void insert(int key) {
        for (const auto& hashFunction : hashFunctions) {
            int index1 = hashFunction(key) % TABLE_SIZE;
            if (table1[index1] == -1) {
                table1[index1] = key;
                return;
            }
            std::swap(key, table1[index1]);
            int index2 = hashFunctions[1](key) % TABLE_SIZE;
            if (table2[index2] == -1) {
                table2[index2] = key;
                return;
            }
            std::swap(key, table2[index2]);
        }
        std::cout << "Rehashing is required for key: " << key << std::endl;
    }
    bool search(int key) {
        int index1 = hashFunctions[0](key) % TABLE_SIZE;
        int index2 = hashFunctions[1](key) % TABLE_SIZE;
        return (table1[index1] == key) || (table2[index2] == key);
    }
};
int main() {
    CuckooHashTable cuckooHashTable;
    cuckooHashTable.insert(5);
    cuckooHashTable.insert(15);
    cuckooHashTable.insert(25);
    std::cout << "Search 15: " << (cuckooHashTable.search(15) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search 10: " << (cuckooHashTable.search(10) ? "Found" : "Not Found") << std::endl;
    return 0;
}
