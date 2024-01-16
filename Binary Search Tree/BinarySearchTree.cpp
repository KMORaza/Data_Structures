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
    TreeNode* remove(TreeNode* root, int value) {
        if (root == nullptr) {
            return root;
        }
        if (value < root->data) {
            root->left = remove(root->left, value);
        } else if (value > root->data) {
            root->right = remove(root->right, value);
        } else {
            if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            TreeNode* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = remove(root->right, temp->data);
        }
        return root;
    }
    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
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
    void postOrderTraversal(TreeNode* root) {
        if (root != nullptr) {
            postOrderTraversal(root->left);
            postOrderTraversal(root->right);
            std::cout << root->data << " ";
        }
    }
    void preOrderTraversal(TreeNode* root) {
        if (root != nullptr) {
            std::cout << root->data << " ";
            preOrderTraversal(root->left);
            preOrderTraversal(root->right);
        }
    }
public:
    BinarySearchTree() : root(nullptr) {}
    void insert(int value) {
        root = insert(root, value);
    }
    void remove(int value) {
        root = remove(root, value);
    }
    bool search(int value) {
        return search(root, value) != nullptr;
    }
    void inOrderTraversal() {
        inOrderTraversal(root);
        std::cout << std::endl;
    }
    void postOrderTraversal() {
        postOrderTraversal(root);
        std::cout << std::endl;
    }
    void preOrderTraversal() {
        preOrderTraversal(root);
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
    std::cout << "In-order Traversal: ";
    bst.inOrderTraversal();
    std::cout << "Post-order Traversal: ";
    bst.postOrderTraversal();
    std::cout << "Pre-order Traversal: ";
    bst.preOrderTraversal();
    int searchValue = 40;
    if (bst.search(searchValue)) {
        std::cout << searchValue << " found in the tree.\n";
    } else {
        std::cout << searchValue << " not found in the tree.\n";
    }
    int removeValue = 30;
    bst.remove(removeValue);
    std::cout << "In-order Traversal after removing " << removeValue << ": ";
    bst.inOrderTraversal();
    return 0;
}
