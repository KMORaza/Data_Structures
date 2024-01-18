#include <iostream>
#include <vector>
class LinearCongruentialHash {
private:
    unsigned long long int a, c, m; 
    size_t tableSize; 
    std::vector<std::string> hashTable; 
public:
    LinearCongruentialHash(unsigned long long int a, unsigned long long int c, unsigned long long int m, size_t tableSize)
        : a(a), c(c), m(m), tableSize(tableSize), hashTable(tableSize, "") {}
    size_t hash(const std::string& key) const {
        unsigned long long int hashValue = 0;
        for (char ch : key) {
            hashValue = (a * hashValue + static_cast<unsigned long long int>(ch)) % m;
        }
        return hashValue % tableSize;
    }
    void insert(const std::string& key) {
        size_t index = hash(key);
        hashTable[index] = key;
    }
    bool search(const std::string& key) const {
        size_t index = hash(key);
        return hashTable[index] == key;
    }
    void display() const {
        for (size_t i = 0; i < tableSize; ++i) {
            std::cout << "Bucket " << i << ": " << hashTable[i] << std::endl;
        }
    }
};
int main() {
    LinearCongruentialHash linearCongruentialHash(3, 7, 13, 10); // LCG parameters and table size
    linearCongruentialHash.insert("apple");
    linearCongruentialHash.insert("banana");
    linearCongruentialHash.insert("cherry");
    linearCongruentialHash.insert("date");
    std::cout << "HashTable after insertion:" << std::endl;
    linearCongruentialHash.display();
    std::cout << "\nSearching for 'banana': ";
    if (linearCongruentialHash.search("banana")) {
        std::cout << "Found\n";
    } else {
        std::cout << "Not Found\n";
    }
    std::cout << "\nSearching for 'grape': ";
    if (linearCongruentialHash.search("grape")) {
        std::cout << "Found\n";
    } else {
        std::cout << "Not Found\n";
    }
    return 0;
}
