#include <iostream>
#include <vector>
class QuadraticProbingHashTable {
private:
    static const int TABLE_SIZE = 10;
    std::vector<int> table;
public:
    QuadraticProbingHashTable() : table(TABLE_SIZE, -1) {}
    void insert(int key) {
        int index = hash(key);
        int i = 1;
        while (table[index] != -1) {
            index = (index + i * i) % TABLE_SIZE;
            ++i;
        }
        table[index] = key;
    }
    bool search(int key) {
        int index = hash(key);
        int i = 1;
        while (table[index] != -1) {
            if (table[index] == key) {
                return true;
            }
            index = (index + i * i) % TABLE_SIZE;
            ++i;
        }
        return false;
    }
private:
    int hash(int key) {
        return key % TABLE_SIZE;
    }
};
int main() {
    QuadraticProbingHashTable quadraticProbingHashTable;
    quadraticProbingHashTable.insert(5);
    quadraticProbingHashTable.insert(15);
    quadraticProbingHashTable.insert(25);
    std::cout << "Search 15: " << (quadraticProbingHashTable.search(15) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search 10: " << (quadraticProbingHashTable.search(10) ? "Found" : "Not Found") << std::endl;
    return 0;
}
