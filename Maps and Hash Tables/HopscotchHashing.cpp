#include <iostream>
#include <vector>
class HopscotchHashTable {
private:
    static const int TABLE_SIZE = 10;
    static const int HOP_RANGE = 3;
    std::vector<int> table;
public:
    HopscotchHashTable() : table(TABLE_SIZE, -1) {}
    void insert(int key) {
        int index = hash(key);
        for (int i = 0; i < HOP_RANGE; ++i) {
            if (table[index] == -1) {
                table[index] = key;
                return;
            }
            index = (index + 1) % TABLE_SIZE;
        }
        std::cout << "Error: Unable to insert key " << key << ", hopscotch range exceeded." << std::endl;
    }
    bool search(int key) {
        int index = hash(key);
        for (int i = 0; i < HOP_RANGE; ++i) {
            if (table[index] == key) {
                return true;
            }
            index = (index + 1) % TABLE_SIZE;
        }
        return false;
    }
private:
    int hash(int key) {
        return key % TABLE_SIZE;
    }
};
int main() {
    HopscotchHashTable hopscotchHashTable;
    hopscotchHashTable.insert(5);
    hopscotchHashTable.insert(15);
    hopscotchHashTable.insert(25);
    std::cout << "Search 15: " << (hopscotchHashTable.search(15) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search 10: " << (hopscotchHashTable.search(10) ? "Found" : "Not Found") << std::endl;
    return 0;
}
