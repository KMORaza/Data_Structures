#include <iostream>
#include <vector>
#include <functional>
#include <limits>
class RobinHoodHashTable {
private:
    static const int TABLE_SIZE = 10;
    std::vector<int> table;
    std::vector<int> distances;
public:
    RobinHoodHashTable() : table(TABLE_SIZE, -1), distances(TABLE_SIZE, 0) {}
    void insert(int key) {
        int index = hash(key);
        int distance = 0;
        while (table[index] != -1 && distance <= distances[index]) {
            if (distances[index] < distance) {
                std::swap(table[index], key);
                std::swap(distances[index], distance);
            }
            index = (index + 1) % TABLE_SIZE;
            ++distance;
        }
        table[index] = key;
        distances[index] = distance;
    }
    bool search(int key) {
        int index = hash(key);
        int distance = 0;
        while (table[index] != -1 && distance <= distances[index]) {
            if (table[index] == key) {
                return true;
            }
            index = (index + 1) % TABLE_SIZE;
            ++distance;
        }
        return false;
    }
private:
    int hash(int key) {
        return key % TABLE_SIZE;
    }
};
int main() {
    RobinHoodHashTable robinHoodHashTable;
    robinHoodHashTable.insert(5);
    robinHoodHashTable.insert(15);
    robinHoodHashTable.insert(25);
    std::cout << "Search 15: " << (robinHoodHashTable.search(15) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search 10: " << (robinHoodHashTable.search(10) ? "Found" : "Not Found") << std::endl;
    return 0;
}
