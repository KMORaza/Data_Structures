#include <iostream>
#include <unordered_map>
class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children;
    bool isEndOfWord;
    TrieNode() : isEndOfWord(false) {}
};
class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    void insert(const std::string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->isEndOfWord = true;
    }
    bool search(const std::string& word) const {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                return false; 
            }
            node = node->children[ch];
        }
        return node->isEndOfWord;
    }
    bool startsWith(const std::string& prefix) const {
        TrieNode* node = root;
        for (char ch : prefix) {
            if (node->children.find(ch) == node->children.end()) {
                return false; 
            }
            node = node->children[ch];
        }
        return true;
    }
};
int main() {
    Trie trie;
    trie.insert("apple");
    trie.insert("app");
    trie.insert("banana");
    std::cout << "Search 'apple': " << (trie.search("apple") ? "Found" : "Not found") << std::endl;
    std::cout << "Search 'app': " << (trie.search("app") ? "Found" : "Not found") << std::endl;
    std::cout << "Search 'orange': " << (trie.search("orange") ? "Found" : "Not found") << std::endl;
    std::cout << "StartsWith 'app': " << (trie.startsWith("app") ? "Exists" : "Does not exist") << std::endl;
    std::cout << "StartsWith 'ban': " << (trie.startsWith("ban") ? "Exists" : "Does not exist") << std::endl;
    std::cout << "StartsWith 'or': " << (trie.startsWith("or") ? "Exists" : "Does not exist") << std::endl;
    return 0;
}
