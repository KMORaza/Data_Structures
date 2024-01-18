#include <iostream>
#include <unordered_map>
#include <vector>
class SuffixTrieNode {
public:
    std::unordered_map<char, SuffixTrieNode*> children;
    bool isEndOfWord;
    SuffixTrieNode() : isEndOfWord(false) {}
};
class SuffixTrie {
private:
    SuffixTrieNode* root;
public:
    SuffixTrie() {
        root = new SuffixTrieNode();
    }
    void insert(const std::string& text) {
        int textLength = static_cast<int>(text.length());
        for (int i = 0; i < textLength; ++i) {
            SuffixTrieNode* node = root;
            for (int j = i; j < textLength; ++j) {
                char ch = text[j];
                if (node->children.find(ch) == node->children.end()) {
                    node->children[ch] = new SuffixTrieNode();
                }
                node = node->children[ch];
            }
            node->isEndOfWord = true;
        }
    }
    bool search(const std::string& pattern) const {
        SuffixTrieNode* node = root;
        int patternLength = static_cast<int>(pattern.length());
        for (int i = 0; i < patternLength; ++i) {
            char ch = pattern[i];
            if (node->children.find(ch) == node->children.end()) {
                return false; 
            }
            node = node->children[ch];
        }
        return node->isEndOfWord;
    }
};
int main() {
    SuffixTrie suffixTrie;
    std::string text = "banana";
    for (int i = 0; i < text.length(); ++i) {
        suffixTrie.insert(text.substr(i));
    }
    std::cout << "Search 'an': " << (suffixTrie.search("an") ? "Found" : "Not found") << std::endl;
    std::cout << "Search 'na': " << (suffixTrie.search("na") ? "Found" : "Not found") << std::endl;
    std::cout << "Search 'xyz': " << (suffixTrie.search("xyz") ? "Found" : "Not found") << std::endl;
    return 0;
}
