#include <iostream>
#include <vector>
class BinaryTreeArray {
private:
    std::vector<int> treeArray;
public:
    BinaryTreeArray() {}
    void insert(int value) {
        treeArray.push_back(value);
    }
    int getParentIndex(int index) const {
        return (index - 1) / 2;
    }
    int getLeftChildIndex(int index) const {
        return 2 * index + 1;
    }
    int getRightChildIndex(int index) const {
        return 2 * index + 2;
    }
    void inOrderTraversal(int index) const {
        if (index < treeArray.size()) {
            inOrderTraversal(getLeftChildIndex(index));
            std::cout << treeArray[index] << " ";
            inOrderTraversal(getRightChildIndex(index));
        }
    }
    void preOrderTraversal(int index) const {
        if (index < treeArray.size()) {
            std::cout << treeArray[index] << " ";
            preOrderTraversal(getLeftChildIndex(index));
            preOrderTraversal(getRightChildIndex(index));
        }
    }
    void postOrderTraversal(int index) const {
        if (index < treeArray.size()) {
            postOrderTraversal(getLeftChildIndex(index));
            postOrderTraversal(getRightChildIndex(index));
            std::cout << treeArray[index] << " ";
        }
    }
};
int main() {
    BinaryTreeArray binaryTreeArray;
    binaryTreeArray.insert(5);
    binaryTreeArray.insert(3);
    binaryTreeArray.insert(7);
    binaryTreeArray.insert(2);
    binaryTreeArray.insert(4);
    binaryTreeArray.insert(6);
    binaryTreeArray.insert(8);
    std::cout << "In-Order Traversal: ";
    binaryTreeArray.inOrderTraversal(0);
    std::cout << std::endl;
    std::cout << "Pre-Order Traversal: ";
    binaryTreeArray.preOrderTraversal(0);
    std::cout << std::endl;
    std::cout << "Post-Order Traversal: ";
    binaryTreeArray.postOrderTraversal(0);
    std::cout << std::endl;
    return 0;
}
