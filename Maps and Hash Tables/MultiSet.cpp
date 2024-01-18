#include <iostream>
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};
class Multiset {
private:
    Node* root;
    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        } else {
            node->right = insert(node->right, value);
        }
        return node;
    }
    void inOrderTraversal(Node* node) const {
        if (node != nullptr) {
            inOrderTraversal(node->left);
            std::cout << node->data << " ";
            inOrderTraversal(node->right);
        }
    }
public:
    Multiset() : root(nullptr) {}
    void insert(int value) {
        root = insert(root, value);
    }
    void display() const {
        std::cout << "Multiset: ";
        inOrderTraversal(root);
        std::cout << std::endl;
    }
};
int main() {
    Multiset myMultiset;
    myMultiset.insert(5);
    myMultiset.insert(10);
    myMultiset.insert(15);
    myMultiset.insert(10); 
    std::cout << "After insertion:" << std::endl;
    myMultiset.display();
    return 0;
}
