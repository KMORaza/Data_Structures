#include <iostream>
#include <vector>
#include <list>
class PerfectHashTable {
private:
    std::vector<std::list<int>> primaryTable;
    std::vector<std::vector<int>> secondaryTables;
    int size;
public:
    PerfectHashTable(int size) : size(size) {
        primaryTable.resize(size);
        secondaryTables.resize(size);
    }
    int hashFunction(int key) {
        return key % size;
    }
    void insert(int key) {
        int primaryIndex = hashFunction(key);
        if (primaryTable[primaryIndex].empty()) {
            primaryTable[primaryIndex].push_back(key);
        } else {
            int secondarySize = primaryTable[primaryIndex].size();
            secondaryTables[primaryIndex].resize(secondarySize * secondarySize);
            for (int existingKey : primaryTable[primaryIndex]) {
                int secondaryIndex = existingKey % secondaryTables[primaryIndex].size();
                secondaryTables[primaryIndex][secondaryIndex] = existingKey;
            }
            primaryTable[primaryIndex].clear();
            secondaryTables[primaryIndex][key % secondaryTables[primaryIndex].size()] = key;
        }
    }
    bool search(int key) {
        int primaryIndex = hashFunction(key);
        if (!primaryTable[primaryIndex].empty()) {
            int secondaryIndex = key % secondaryTables[primaryIndex].size();
            return secondaryTables[primaryIndex][secondaryIndex] == key;
        }
        return false;
    }
};
int main() {
    PerfectHashTable perfectHash(10);
    perfectHash.insert(5);
    perfectHash.insert(15);
    perfectHash.insert(25);
    std::cout << "Search 15: " << (perfectHash.search(15) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search 10: " << (perfectHash.search(10) ? "Found" : "Not Found") << std::endl;
    return 0;
}
