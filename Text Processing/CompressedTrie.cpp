#include <iostream>
#include <unordered_map>
class CompressedTrieNode {
public:
    std::unordered_map<char, CompressedTrieNode*> children;
    bool isEndOfWord;
    std::string prefix;
    CompressedTrieNode() : isEndOfWord(false) {}
};
class CompressedTrie {
private:
    CompressedTrieNode* root;
public:
    CompressedTrie() {
        root = new CompressedTrieNode();
    }
    void insert(const std::string& word) {
        CompressedTrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                node->children[ch] = new CompressedTrieNode();
            }
            node = node->children[ch];
        }
        node->isEndOfWord = true;
    }
    bool search(const std::string& word) const {
        CompressedTrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                return false; 
            }
            node = node->children[ch];
        }
        return node->isEndOfWord;
    }
};
int main() {
    CompressedTrie compressedTrie;
    compressedTrie.insert("apple");
    compressedTrie.insert("app");
    compressedTrie.insert("banana");
    std::cout << "Search 'apple': " << (compressedTrie.search("apple") ? "Found" : "Not found") << std::endl;
    std::cout << "Search 'app': " << (compressedTrie.search("app") ? "Found" : "Not found") << std::endl;
    std::cout << "Search 'orange': " << (compressedTrie.search("orange") ? "Found" : "Not found") << std::endl;
    return 0;
}
