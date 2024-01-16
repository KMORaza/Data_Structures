// Implementation of binary tree with major operations
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
    // Insert a value into the binary tree
    void insert(const T& value) {
        root = insertRecursive(root, value);
    }
    // Recursive insertion
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
    // Delete a value from the binary tree
    void remove(const T& value) {
        root = removeRecursive(root, value);
    }
    // Recursive deletion
    TreeNode<T>* removeRecursive(TreeNode<T>* node, const T& value) {
        if (node == nullptr) {
            return nullptr;
        }
        if (value < node->data) {
            node->left = removeRecursive(node->left, value);
        } else if (value > node->data) {
            node->right = removeRecursive(node->right, value);
        } else {
            if (node->left == nullptr) {
                TreeNode<T>* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                TreeNode<T>* temp = node->left;
                delete node;
                return temp;
            }
            TreeNode<T>* temp = findMin(node->right);
            node->data = temp->data;
            node->right = removeRecursive(node->right, temp->data);
        }
        return node;
    }
    // Find the node with the smallest value in a subtree
    TreeNode<T>* findMin(TreeNode<T>* node) const {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
    // Search for a value in the binary tree
    TreeNode<T>* search(const T& value) const {
        return searchRecursive(root, value);
    }
    // Recursive search
    TreeNode<T>* searchRecursive(TreeNode<T>* node, const T& value) const {
        if (node == nullptr || node->data == value) {
            return node;
        }
        if (value < node->data) {
            return searchRecursive(node->left, value);
        } else {
            return searchRecursive(node->right, value);
        }
    }
    // Update a value in the binary tree
    void update(const T& oldValue, const T& newValue) {
        remove(oldValue);
        insert(newValue);
    }
    // In-order traversal of the binary tree
    void inOrderTraversal() const {
        inOrderTraversalRecursive(root);
        std::cout << std::endl;
    }
    // Recursive in-order traversal
    void inOrderTraversalRecursive(TreeNode<T>* node) const {
        if (node != nullptr) {
            inOrderTraversalRecursive(node->left);
            std::cout << node->data << " ";
            inOrderTraversalRecursive(node->right);
        }
    }
    // Pre-order traversal of the binary tree
    void preOrderTraversal() const {
        preOrderTraversalRecursive(root);
        std::cout << std::endl;
    }
    // Recursive pre-order traversal
    void preOrderTraversalRecursive(TreeNode<T>* node) const {
        if (node != nullptr) {
            std::cout << node->data << " ";
            preOrderTraversalRecursive(node->left);
            preOrderTraversalRecursive(node->right);
        }
    }
    // Post-order traversal of the binary tree
    void postOrderTraversal() const {
        postOrderTraversalRecursive(root);
        std::cout << std::endl;
    }
    // Recursive post-order traversal
    void postOrderTraversalRecursive(TreeNode<T>* node) const {
        if (node != nullptr) {
            postOrderTraversalRecursive(node->left);
            postOrderTraversalRecursive(node->right);
            std::cout << node->data << " ";
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
    std::cout << "In-Order Traversal: ";
    binaryTree.inOrderTraversal();
    std::cout << "Pre-Order Traversal: ";
    binaryTree.preOrderTraversal();
    std::cout << "Post-Order Traversal: ";
    binaryTree.postOrderTraversal();
    TreeNode<int>* searchResult = binaryTree.search(6);
    if (searchResult != nullptr) {
        std::cout << "Value 6 found in the binary tree." << std::endl;
    } else {
        std::cout << "Value 6 not found in the binary tree." << std::endl;
    }
    binaryTree.update(6, 9);
    std::cout << "In-Order Traversal after updating: ";
    binaryTree.inOrderTraversal();
    binaryTree.remove(4);
    std::cout << "In-Order Traversal after removal: ";
    binaryTree.inOrderTraversal();
    return 0;
}
