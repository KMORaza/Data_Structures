#include <iostream>
#include <queue>
#include <unordered_map>
struct HuffmanNode {
    char data;
    unsigned frequency;
    HuffmanNode* left;
    HuffmanNode* right;
    HuffmanNode(char data, unsigned frequency) : data(data), frequency(frequency), left(nullptr), right(nullptr) {}
};
struct CompareNodes {
    bool operator()(HuffmanNode* a, HuffmanNode* b) {
        return a->frequency > b->frequency;
    }
};
HuffmanNode* buildHuffmanTree(const std::unordered_map<char, unsigned>& frequencies) {
    std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, CompareNodes> pq;
    for (const auto& pair : frequencies) {
        pq.push(new HuffmanNode(pair.first, pair.second));
    }
    while (pq.size() > 1) {
        HuffmanNode* left = pq.top();
        pq.pop();
        HuffmanNode* right = pq.top();
        pq.pop();
        HuffmanNode* internalNode = new HuffmanNode('$', left->frequency + right->frequency);
        internalNode->left = left;
        internalNode->right = right;
        pq.push(internalNode);
    }
    return pq.top(); 
}
void generateHuffmanCodes(HuffmanNode* root, std::unordered_map<char, std::string>& codes, std::string code = "") {
    if (root) {
        if (root->data != '$') {
            codes[root->data] = code;
        }
        generateHuffmanCodes(root->left, codes, code + "0");
        generateHuffmanCodes(root->right, codes, code + "1");
    }
}
std::string huffmanEncode(const std::string& message, const std::unordered_map<char, std::string>& codes) {
    std::string encodedMessage;
    for (char ch : message) {
        encodedMessage += codes.at(ch);
    }
    return encodedMessage;
}
std::string huffmanDecode(const std::string& encodedMessage, const HuffmanNode* root) {
    std::string decodedMessage;
    const HuffmanNode* current = root;
    for (char bit : encodedMessage) {
        if (bit == '0') {
            current = current->left;
        } else {
            current = current->right;
        }
        if (current->left == nullptr && current->right == nullptr) {
            decodedMessage += current->data;
            current = root;
        }
    }
    return decodedMessage;
}
int main() {
    std::string message = "huffman coding algorithm";
    std::unordered_map<char, unsigned> frequencies;
    for (char ch : message) {
        frequencies[ch]++;
    }
    HuffmanNode* root = buildHuffmanTree(frequencies);
    std::unordered_map<char, std::string> codes;
    generateHuffmanCodes(root, codes);
    std::cout << "Huffman Codes:" << std::endl;
    for (const auto& pair : codes) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    std::string encodedMessage = huffmanEncode(message, codes);
    std::cout << "\nEncoded Message: " << encodedMessage << std::endl;
    std::string decodedMessage = huffmanDecode(encodedMessage, root);
    std::cout << "Decoded Message: " << decodedMessage << std::endl;
    delete root;
    return 0;
}
