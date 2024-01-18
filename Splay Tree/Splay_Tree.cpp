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
    void insert(const T& value, Node*& root) {
        if (!root) {
            root = new Node(value);
            return;
        }
        splay(value, root);
        if (value < root->key) {
            Node* newNode = new Node(value);
            newNode->left = root->left;
            newNode->right = root;
            root->left = nullptr;
            root = newNode;
        } else if (value > root->key) {
            Node* newNode = new Node(value);
            newNode->right = root->right;
            newNode->left = root;
            root->right = nullptr;
            root = newNode;
        }
    }
    void remove(const T& value, Node*& root) {
        if (!root) {
            return;
        }
        splay(value, root);
        if (value == root->key) {
            Node* temp = root;
            if (!root->left) {
                root = root->right;
            } else {
                Node* newRoot = root->left;
                splay(value, newRoot);
                newRoot->right = root->right;
                root = newRoot;
            }
            delete temp;
        }
    }
    void split(const T& value, Node*& root, Node*& left, Node*& right) {
        if (!root) {
            left = nullptr;
            right = nullptr;
            return;
        }
        splay(value, root);
        if (value == root->key) {
            left = root->left;
            right = root->right;
            root->left = nullptr;
            root->right = nullptr;
        } else if (value < root->key) {
            left = root->left;
            right = root;
            root = nullptr;
        } else {
            left = root;
            right = root->right;
            root->right = nullptr;
        }
    }
    void merge(Node*& left, Node*& right) {
        if (!left) {
            root = right;
            return;
        }
        splay(std::numeric_limits<T>::max(), left);
        left->right = right;
        root = left;
    }
    void inOrderTraversal(Node* root) const {
        if (root) {
            inOrderTraversal(root->left);
            std::cout << root->key << " ";
            inOrderTraversal(root->right);
        }
    }
    void preOrderTraversal(Node* root) const {
        if (root) {
            std::cout << root->key << " ";
            preOrderTraversal(root->left);
            preOrderTraversal(root->right);
        }
    }
    void postOrderTraversal(Node* root) const {
        if (root) {
            postOrderTraversal(root->left);
            postOrderTraversal(root->right);
            std::cout << root->key << " ";
        }
    }
public:
    SplayTree() : root(nullptr) {}
    void insert(const T& value) {
        insert(value, root);
    }
    void remove(const T& value) {
        remove(value, root);
    }
    void split(const T& value, SplayTree<T>& leftTree, SplayTree<T>& rightTree) {
        Node* left = nullptr;
        Node* right = nullptr;
        split(value, root, left, right);
        leftTree.root = left;
        rightTree.root = right;
    }
    void merge(SplayTree<T>& leftTree, SplayTree<T>& rightTree) {
        merge(leftTree.root, rightTree.root);
    }
    void inOrderTraversal() const {
        inOrderTraversal(root);
        std::cout << std::endl;
    }
    void preOrderTraversal() const {
        preOrderTraversal(root);
        std::cout << std::endl;
    }
    void postOrderTraversal() const {
        postOrderTraversal(root);
        std::cout << std::endl;
    }
};
int main() {
    SplayTree<int> splayTree;
    splayTree.insert(50);
    splayTree.insert(30);
    splayTree.insert(70);
    splayTree.insert(20);
    splayTree.insert(40);
    splayTree.insert(60);
    splayTree.insert(80);
    std::cout << "In-order traversal: ";
    splayTree.inOrderTraversal();
    std::cout << "Pre-order traversal: ";
    splayTree.preOrderTraversal();
    std::cout << "Post-order traversal: ";
    splayTree.postOrderTraversal();
    splayTree.remove(30);
    std::cout << "In-order traversal after deletion: ";
    splayTree.inOrderTraversal();
    SplayTree<int> leftTree;
    SplayTree<int> rightTree;
    splayTree.split(40, leftTree, rightTree);
    SplayTree<int> mergedTree;
    mergedTree.merge(leftTree, rightTree);
    std::cout << "In-order traversal of merged tree: ";
    mergedTree.inOrderTraversal();
    return 0;
}
