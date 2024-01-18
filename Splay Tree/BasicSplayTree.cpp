#include <iostream>
template <typename T>
class SplayTree {
private:
    struct Node {
        T key;
        Node* left;
        Node* right;
        Node(const T& val) : key(val), left(nullptr), right(nullptr) {}
    };
    Node* root;
    Node* splay(Node* root, const T& key) {
        if (!root || root->key == key) {
            return root;
        }
        if (key < root->key) {
            if (!root->left) {
                return root;
            }
            if (key < root->left->key) {
                root->left->left = splay(root->left->left, key);
                root = rotateRight(root);
            }
            else if (key > root->left->key) {
                root->left->right = splay(root->left->right, key);
                if (root->left->right) {
                    root->left = rotateLeft(root->left);
                }
            }
            return (root->left) ? rotateRight(root) : root;
        } else {
            if (!root->right) {
                return root;
            }
            if (key > root->right->key) {
                root->right->right = splay(root->right->right, key);
                root = rotateLeft(root);
            }
            else if (key < root->right->key) {
                root->right->left = splay(root->right->left, key);
                if (root->right->left) {
                    root->right = rotateRight(root->right);
                }
            }
            return (root->right) ? rotateLeft(root) : root;
        }
    }
    Node* rotateRight(Node* x) {
        Node* y = x->left;
        x->left = y->right;
        y->right = x;
        return y;
    }
    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        y->left = x;
        return y;
    }
    void deleteTree(Node* node) {
        if (node) {
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }
    }
public:
    SplayTree() : root(nullptr) {}
    ~SplayTree() {
        deleteTree(root);
    }
    void insert(const T& key) {
        root = splay(root, key);
        if (!root || root->key != key) {
            Node* newNode = new Node(key);
            if (root) {
                if (key < root->key) {
                    newNode->right = root;
                    newNode->left = root->left;
                    root->left = nullptr;
                } else {
                    newNode->left = root;
                    newNode->right = root->right;
                    root->right = nullptr;
                }
            }
            root = newNode;
        }
    }
    bool search(const T& key) {
        root = splay(root, key);
        return root && root->key == key;
    }
    void display() const {
        display(root);
        std::cout << std::endl;
    }
private:
    void display(Node* node) const {
        if (node) {
            display(node->left);
            std::cout << node->key << " ";
            display(node->right);
        }
    }
};
int main() {
    SplayTree<int> splayTree;
    splayTree.insert(50);
    splayTree.insert(30);
    splayTree.insert(70);
    splayTree.insert(20);
    splayTree.insert(40);
    std::cout << "Splay Tree after Insertion: ";
    splayTree.display();
    int searchKey = 30;
    if (splayTree.search(searchKey)) {
        std::cout << "Key " << searchKey << " found.\n";
    } else {
        std::cout << "Key " << searchKey << " not found.\n";
    }
    return 0;
}
