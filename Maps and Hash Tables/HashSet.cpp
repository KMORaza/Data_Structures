#include <iostream>
#include <vector>
#include <list>
class HashSet {
private:
    std::vector<std::list<int>> table;
    size_t size;
    size_t hash(int key) const {
        return key % table.size();
    }
public:
    HashSet(size_t initialSize = 10) : size(0), table(initialSize) {}
    bool contains(int key) const {
        size_t index = hash(key);
        const std::list<int>& bucket = table[index];
        for (int value : bucket) {
            if (value == key) {
                return true;
            }
        }
        return false;
    }
    void insert(int key) {
        if (!contains(key)) {
            size_t index = hash(key);
            table[index].push_back(key);
            size++;
        }
    }
    void remove(int key) {
        size_t index = hash(key);
        std::list<int>& bucket = table[index];
        auto it = std::find(bucket.begin(), bucket.end(), key);
        if (it != bucket.end()) {
            bucket.erase(it);
            size--;
        }
    }
    void display() const {
        std::cout << "HashSet: { ";
        for (const auto& bucket : table) {
            for (int value : bucket) {
                std::cout << value << " ";
            }
        }
        std::cout << "}" << std::endl;
    }
};
int main() {
    HashSet myHashSet;
    myHashSet.insert(5);
    myHashSet.insert(10);
    myHashSet.insert(15);
    myHashSet.insert(20);
    std::cout << "After insertion:" << std::endl;
    myHashSet.display();
    int searchValue = 10;
    if (myHashSet.contains(searchValue)) {
        std::cout << searchValue << " is present in the HashSet." << std::endl;
    } else {
        std::cout << searchValue << " is not present in the HashSet." << std::endl;
    }
    int removeValue = 15;
    myHashSet.remove(removeValue);
    std::cout << "After removal of " << removeValue << ":" << std::endl;
    myHashSet.display();
    return 0;
}
