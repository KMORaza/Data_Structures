#include <iostream>
class TreeNode {
public:
    std::string name;
    int size;
    TreeNode* left;
    TreeNode* right;
    TreeNode(const std::string& nodeName, int nodeSize)
        : name(nodeName), size(nodeSize), left(nullptr), right(nullptr) {}
};
class DiskSpaceCalculator {
private:
    TreeNode* root;
    TreeNode* insert(TreeNode* node, const std::string& nodeName, int nodeSize) {
        if (node == nullptr) {
            return new TreeNode(nodeName, nodeSize);
        }
        if (nodeName < node->name) {
            node->left = insert(node->left, nodeName, nodeSize);
        } else if (nodeName > node->name) {
            node->right = insert(node->right, nodeName, nodeSize);
        }
        return node;
    }
    int calculateTotalDiskSpace(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        return node->size + calculateTotalDiskSpace(node->left) + calculateTotalDiskSpace(node->right);
    }
    void inOrderTraversal(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        inOrderTraversal(node->left);
        std::cout << node->name << ": " << node->size << " KB" << std::endl;
        inOrderTraversal(node->right);
    }
public:
    DiskSpaceCalculator() : root(nullptr) {}
    void insertFile(const std::string& fileName, int fileSize) {
        root = insert(root, fileName, fileSize);
    }
    int getTotalDiskSpace() {
        return calculateTotalDiskSpace(root);
    }
    void displayDiskContents() {
        std::cout << "Disk Contents:" << std::endl;
        inOrderTraversal(root);
    }
};
int main() {
    DiskSpaceCalculator diskSpace;
    diskSpace.insertFile("Documents", 150);
    diskSpace.insertFile("Pictures", 300);
    diskSpace.insertFile("Videos", 200);
    diskSpace.insertFile("Homework", 50);
    std::cout << "Total Disk Space: " << diskSpace.getTotalDiskSpace() << " KB" << std::endl;
    diskSpace.displayDiskContents();
    return 0;
}
