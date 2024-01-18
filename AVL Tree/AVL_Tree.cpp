#include <iostream>
#include <algorithm>
class AVLNode {
public:
    int key;
    AVLNode* left;
    AVLNode* right;
    int height;
    AVLNode(int k) : key(k), left(nullptr), right(nullptr), height(1) {}
};
class AVLTree {
private:
    AVLNode* root;
    int getHeight(AVLNode* node) {
        return (node != nullptr) ? node->height : 0;
    }
    int getBalanceFactor(AVLNode* node) {
        return (node != nullptr) ? getHeight(node->left) - getHeight(node->right) : 0;
    }
    AVLNode* rotateRight(AVLNode* y) {
        AVLNode* x = y->left;
        AVLNode* T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
        return x;
    }
    AVLNode* rotateLeft(AVLNode* x) {
        AVLNode* y = x->right;
        AVLNode* T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
        return y;
    }
    AVLNode* insertNode(AVLNode* root, int key) {
        if (root == nullptr) {
            return new AVLNode(key);
        }
        if (key < root->key) {
            root->left = insertNode(root->left, key);
        } else if (key > root->key) {
            root->right = insertNode(root->right, key);
        } else {
            return root;
        }
        root->height = 1 + std::max(getHeight(root->left), getHeight(root->right));
        int balance = getBalanceFactor(root);
        if (balance > 1 && key < root->left->key) {
            return rotateRight(root);
        }
        if (balance < -1 && key > root->right->key) {
            return rotateLeft(root);
        }
        if (balance > 1 && key > root->left->key) {
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }
        if (balance < -1 && key < root->right->key) {
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }
        return root;
    }
    AVLNode* minValueNode(AVLNode* node) {
        AVLNode* current = node;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }
    AVLNode* deleteNode(AVLNode* root, int key) {
        if (root == nullptr) {
            return root;
        }
        if (key < root->key) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->key) {
            root->right = deleteNode(root->right, key);
        } else {
            if (root->left == nullptr || root->right == nullptr) {
                AVLNode* temp = root->left ? root->left : root->right;
                if (temp == nullptr) {
                    temp = root;
                    root = nullptr;
                } else {
                    *root = *temp; 
                }
                delete temp;
            } else {
                AVLNode* temp = minValueNode(root->right);
                root->key = temp->key;
                root->right = deleteNode(root->right, temp->key);
            }
        }
        if (root == nullptr) {
            return root;
        }
        root->height = 1 + std::max(getHeight(root->left), getHeight(root->right));
        int balance = getBalanceFactor(root);
        if (balance > 1 && getBalanceFactor(root->left) >= 0) {
            return rotateRight(root);
        }
        if (balance > 1 && getBalanceFactor(root->left) < 0) {
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }
        if (balance < -1 && getBalanceFactor(root->right) <= 0) {
            return rotateLeft(root);
        }
        if (balance < -1 && getBalanceFactor(root->right) > 0) {
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }
        return root;
    }
    void inOrderTraversal(AVLNode* root) {
        if (root != nullptr) {
            inOrderTraversal(root->left);
            std::cout << root->key << " ";
            inOrderTraversal(root->right);
        }
    }
public:
    AVLTree() : root(nullptr) {}
    void insert(int key) {
        root = insertNode(root, key);
    }
    void remove(int key) {
        root = deleteNode(root, key);
    }
    void displayInOrder() {
        std::cout << "In-Order Traversal: ";
        inOrderTraversal(root);
        std::cout << "\n";
    }
};
int main() {
    AVLTree avlTree;
    avlTree.insert(10);
    avlTree.insert(20);
    avlTree.insert(30);
    avlTree.displayInOrder();
    avlTree.remove(20);
    avlTree.displayInOrder();
    return 0;
}
