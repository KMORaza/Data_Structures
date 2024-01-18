#include <iostream>
#include <vector>
class Node {
public:
    int key;
    std::vector<int> values;
    Node* left;
    Node* right;
    Node(int k, int value) : key(k), left(nullptr), right(nullptr) {
        values.push_back(value);
    }
};
class Multimap {
private:
    Node* root;
    Node* insert(Node* node, int key, int value) {
        if (node == nullptr) {
            return new Node(key, value);
        }
        if (key < node->key) {
            node->left = insert(node->left, key, value);
        } else if (key > node->key) {
            node->right = insert(node->right, key, value);
        } else {
            node->values.push_back(value);
        }
        return node;
    }
    void inOrderTraversal(Node* node) const {
        if (node != nullptr) {
            inOrderTraversal(node->left);
            std::cout << "Key: " << node->key << ", Values: ";
            for (int val : node->values) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
            inOrderTraversal(node->right);
        }
    }
public:
    Multimap() : root(nullptr) {}
    void insert(int key, int value) {
        root = insert(root, key, value);
    }
    void display() const {
        std::cout << "Multimap:" << std::endl;
        inOrderTraversal(root);
    }
};
int main() {
    Multimap myMultimap;
    myMultimap.insert(5, 10);
    myMultimap.insert(10, 20);
    myMultimap.insert(5, 15); 
    myMultimap.insert(15, 30);
    std::cout << "After insertion:" << std::endl;
    myMultimap.display();
    return 0;
}
