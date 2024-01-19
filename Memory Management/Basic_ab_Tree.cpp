// Implementation of basic (a,b) tree
#include <iostream>
#include <vector>
class TreeNode {
public:
    bool isLeaf;
    std::vector<int> keys;
    std::vector<TreeNode*> children;
    TreeNode() : isLeaf(true) {}
    TreeNode(int key) : isLeaf(false) {
        keys.push_back(key);
    }
};
class TwoFourTree {
public:
    TwoFourTree() : root(nullptr) {}
    void insert(int key) {
        if (!root) {
            root = new TreeNode(key);
        } else {
            TreeNode* newRoot = nullptr;
            root = insertInternal(root, key, newRoot);
            if (newRoot) {
                root = newRoot;
            }
        }
    }
    void display() {
        displayInternal(root, 0);
    }
private:
    TreeNode* root;
    TreeNode* insertInternal(TreeNode* node, int key, TreeNode*& newRoot) {
        if (node->isLeaf) {
            insertIntoNode(node, key);
        } else {
            int childIndex = findChildIndex(node, key);
            TreeNode* newChild = nullptr;
            node->children[childIndex] = insertInternal(node->children[childIndex], key, newChild);
            if (newChild) {
                insertIntoNode(node, newChild->keys[0]);
                node->children.insert(node->children.begin() + childIndex + 1, newChild->children.begin(), newChild->children.end());
                delete newChild;
            }
            if (node->keys.size() > 3) {
                splitNode(node, newRoot);
            }
        }
        return node;
    }
    void insertIntoNode(TreeNode* node, int key) {
        auto insertPosition = std::upper_bound(node->keys.begin(), node->keys.end(), key);
        node->keys.insert(insertPosition, key);
    }
    int findChildIndex(TreeNode* node, int key) {
        auto it = std::upper_bound(node->keys.begin(), node->keys.end(), key);
        return it - node->keys.begin();
    }
    void splitNode(TreeNode* node, TreeNode*& newRoot) {
        newRoot = new TreeNode(node->keys[2]);
        TreeNode* newLeft = new TreeNode(node->keys[0]);
        newLeft->children.push_back(node->children[0]);
        newLeft->children.push_back(node->children[1]);
        TreeNode* newRight = new TreeNode(node->keys[3]);
        newRight->children.push_back(node->children[2]);
        newRight->children.push_back(node->children[3]);
        delete node;
        newRoot->children.push_back(newLeft);
        newRoot->children.push_back(newRight);
    }
    void displayInternal(TreeNode* node, int level) {
        if (node) {
            std::cout << "Level " << level << ": ";
            for (int key : node->keys) {
                std::cout << key << " ";
            }
            std::cout << std::endl;

            if (!node->isLeaf) {
                for (TreeNode* child : node->children) {
                    displayInternal(child, level + 1);
                }
            }
        }
    }
};
int main() {
    TwoFourTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    tree.insert(6);
    tree.insert(12);
    tree.insert(30);
    tree.insert(7);
    tree.insert(17);
    tree.display();
    return 0;
}
