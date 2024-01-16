#include <iostream>
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};
class BinarySearchTree {
private:
    TreeNode* root;
    TreeNode* insert(TreeNode* root, int value) {
        if (root == nullptr) {
            return new TreeNode(value);
        }
        if (value < root->data) {
            root->left = insert(root->left, value);
        } else if (value > root->data) {
            root->right = insert(root->right, value);
        }
        return root;
    }
    TreeNode* search(TreeNode* root, int value) {
        if (root == nullptr || root->data == value) {
            return root;
        }
        if (value < root->data) {
            return search(root->left, value);
        } else {
            return search(root->right, value);
        }
    }
    void inOrderTraversal(TreeNode* root) {
        if (root != nullptr) {
            inOrderTraversal(root->left);
            std::cout << root->data << " ";
            inOrderTraversal(root->right);
        }
    }
public:
    BinarySearchTree() : root(nullptr) {}
    void insert(int value) {
        root = insert(root, value);
    }
    bool search(int value) {
        return search(root, value) != nullptr;
    }
    void inOrderTraversal() {
        inOrderTraversal(root);
        std::cout << std::endl;
    }
};
int main() {
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    std::cout << "Inorder Traversal: ";
    bst.inOrderTraversal();
    int searchValue = 40;
    if (bst.search(searchValue)) {
        std::cout << searchValue << " found in the tree.\n";
    } else {
        std::cout << searchValue << " not found in the tree.\n";
    }
    return 0;
}
