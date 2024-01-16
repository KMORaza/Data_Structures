#include <iostream>
template <typename T>
struct TreeNode {
    T data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(const T& value) : data(value), left(nullptr), right(nullptr) {}
};
template <typename T>
class BinaryTree {
private:
    TreeNode<T>* root;
public:
    BinaryTree() : root(nullptr) {}
    void insert(const T& value) {
        root = insertRecursive(root, value);
    }
    TreeNode<T>* insertRecursive(TreeNode<T>* node, const T& value) {
        if (node == nullptr) {
            return new TreeNode<T>(value);
        }
        if (value < node->data) {
            node->left = insertRecursive(node->left, value);
        } else if (value > node->data) {
            node->right = insertRecursive(node->right, value);
        }
        return node;
    }
    void inOrderTraversal() const {
        inOrderTraversalRecursive(root);
        std::cout << std::endl;
    }
    void inOrderTraversalRecursive(TreeNode<T>* node) const {
        if (node != nullptr) {
            inOrderTraversalRecursive(node->left);
            std::cout << node->data << " ";
            inOrderTraversalRecursive(node->right);
        }
    }
};
int main() {
    BinaryTree<int> binaryTree;
    binaryTree.insert(5);
    binaryTree.insert(3);
    binaryTree.insert(7);
    binaryTree.insert(2);
    binaryTree.insert(4);
    binaryTree.insert(6);
    binaryTree.insert(8);
    std::cout << "In-order Traversal: ";
    binaryTree.inOrderTraversal();
    return 0;
}
