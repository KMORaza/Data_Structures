#include <iostream>
#include <cmath>
class RollingHash {
private:
    static const int base = 256; 
    static const int prime = 101; 
    int hashValue;
    int basePower;
public:
    RollingHash() : hashValue(0), basePower(1) {}
    void append(char ch) {
        hashValue = (hashValue * base + ch) % prime;
        basePower = (basePower * base) % prime;
    }
    void skip(char ch) {
        hashValue = (hashValue - ch * basePower + prime * base) % prime;
        if (hashValue < 0) {
            hashValue += prime;
        }
    }
    int getHash() const {
        return hashValue;
    }
};
int main() {
    RollingHash rollingHash;
    std::string text = "rollinghash";
    std::string pattern = "hash";
    int patternHash = 0;
    for (char ch : pattern) {
        patternHash = (patternHash * RollingHash::base + ch) % RollingHash::prime;
    }
    for (int i = 0; i < text.size(); ++i) {
        rollingHash.append(text[i]);
        if (i >= pattern.size() - 1 && rollingHash.getHash() == patternHash) {
            std::cout << "Pattern found at index " << i - (pattern.size() - 1) << std::endl;
        }
        if (i >= pattern.size() - 1) {
            rollingHash.skip(text[i - (pattern.size() - 1)]);
        }
    }
    return 0;
}
