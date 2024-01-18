#include <iostream>
template <typename T>
class SplayTree {
private:
    struct Node {
        T key;
        Node* left;
        Node* right;
        Node(const T& value) : key(value), left(nullptr), right(nullptr) {}
    };
    Node* root;
    void rotateLeft(Node*& x) {
        Node* y = x->right;
        x->right = y->left;
        y->left = x;
        x = y;
    }
    void rotateRight(Node*& x) {
        Node* y = x->left;
        x->left = y->right;
        y->right = x;
        x = y;
    }
    void splay(const T& value, Node*& root) {
        if (!root || root->key == value) {
            return;
        }
        if (value < root->key) {
            if (!root->left) {
                return;
            }
            if (value < root->left->key) {
                splay(value, root->left->left);
                rotateRight(root);
            } else if (value > root->left->key) {
                splay(value, root->left->right);
                if (root->left->right) {
                    rotateLeft(root->left);
                }
            }
            if (root->left) {
                rotateRight(root);
            }
        } else {
            if (!root->right) {
                return;
            }
            if (value < root->right->key) {
                splay(value, root->right->left);
                if (root->right->left) {
                    rotateRight(root->right);
                }
            } else if (value > root->right->key) {
                splay(value, root->right->right);
                rotateLeft(root);
            }

            if (root->right) {
                rotateLeft(root);
            }
        }
    }
public:
    SplayTree() : root(nullptr) {}
    void splayAndPrint(const T& value) {
        splay(value, root);
        std::cout << "Splaying for key " << value << ": ";
        inOrderTraversal();
        std::cout << std::endl;
    }
    void insert(const T& value) {
        Node* newNode = new Node(value);
        newNode->left = root;
        newNode->right = nullptr;
        root = newNode;
        splay(value, root);
    }
    void inOrderTraversal() const {
        inOrderTraversal(root);
    }
    void inOrderTraversal(Node* root) const {
        if (root) {
            inOrderTraversal(root->left);
            std::cout << root->key << " ";
            inOrderTraversal(root->right);
        }
    }
};
int main() {
    SplayTree<int> splayTree;
    splayTree.insert(10);
    splayTree.insert(5);
    splayTree.insert(15);
    splayTree.insert(3);
    splayTree.insert(7);
    splayTree.insert(12);
    splayTree.insert(18);
    splayTree.splayAndPrint(7);
    splayTree.splayAndPrint(15);
    splayTree.splayAndPrint(3);
    return 0;
}
