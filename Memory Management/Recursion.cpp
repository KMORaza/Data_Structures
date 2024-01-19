#include <iostream>
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};
class BinaryTree {
public:
    BinaryTree() : root(nullptr) {}
    ~BinaryTree();
    void insert(int value);
    void printInOrder() const;
private:
    TreeNode* root;
    void destroyTree(TreeNode* node);
    void insertRecursively(TreeNode*& node, int value);
    void printInOrderRecursively(TreeNode* node) const;
};
BinaryTree::~BinaryTree() {
    destroyTree(root);
}
void BinaryTree::destroyTree(TreeNode* node) {
    if (node) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}
void BinaryTree::insert(int value) {
    insertRecursively(root, value);
}
void BinaryTree::insertRecursively(TreeNode*& node, int value) {
    if (!node) {
        node = new TreeNode(value);
    } else if (value < node->data) {
        insertRecursively(node->left, value);
    } else {
        insertRecursively(node->right, value);
    }
}
void BinaryTree::printInOrder() const {
    printInOrderRecursively(root);
    std::cout << std::endl;
}
void BinaryTree::printInOrderRecursively(TreeNode* node) const {
    if (node) {
        printInOrderRecursively(node->left);
        std::cout << node->data << " ";
        printInOrderRecursively(node->right);
    }
}
int main() {
    BinaryTree tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);
    std::cout << "In-order traversal: ";
    tree.printInOrder();
    return 0;
}
