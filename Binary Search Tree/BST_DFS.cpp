// Implementation of depth-first traversal in binary search tree
#include <iostream>
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};
void inOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    inOrderTraversal(root->left);
    std::cout << root->data << " ";
    inOrderTraversal(root->right);
}
void preOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    std::cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}
void postOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    std::cout << root->data << " ";
}
int main() {
    TreeNode* root = new TreeNode(50);
    root->left = new TreeNode(30);
    root->right = new TreeNode(70);
    root->left->left = new TreeNode(20);
    root->left->right = new TreeNode(40);
    root->right->left = new TreeNode(60);
    root->right->right = new TreeNode(80);
    std::cout << "In-order Traversal: ";
    inOrderTraversal(root);
    std::cout << std::endl;
    std::cout << "Pre-order Traversal: ";
    preOrderTraversal(root);
    std::cout << std::endl;
    std::cout << "Post-order Traversal: ";
    postOrderTraversal(root);
    std::cout << std::endl;
    return 0;
}
