#include <iostream>
#include <vector>
const int MIN_DEGREE = 2;
class BTreeNode {
public:
    bool isLeaf;
    std::vector<int> keys;
    std::vector<BTreeNode*> children;
    BTreeNode(bool leaf = true) : isLeaf(leaf) {}
    void insertNonFull(int key) {
        int i = keys.size() - 1;
        if (isLeaf) {
            keys.push_back(0);
            while (i >= 0 && key < keys[i]) {
                keys[i + 1] = keys[i];
                i--;
            }
            keys[i + 1] = key;
        } else {
            while (i >= 0 && key < keys[i]) {
                i--;
            }
            if (children[i + 1]->keys.size() == (2 * MIN_DEGREE - 1)) {
                splitChild(i + 1, children[i + 1]);
                if (key > keys[i + 1]) {
                    i++;
                }
            }
            children[i + 1]->insertNonFull(key);
        }
    }
    void splitChild(int i, BTreeNode* y) {
        BTreeNode* z = new BTreeNode(y->isLeaf);
        keys.insert(keys.begin() + i, y->keys[MIN_DEGREE - 1]);
        children.insert(children.begin() + i + 1, z);
        z->keys.assign(y->keys.begin() + MIN_DEGREE, y->keys.end());
        y->keys.erase(y->keys.begin() + MIN_DEGREE - 1, y->keys.end());
        if (!y->isLeaf) {
            z->children.assign(y->children.begin() + MIN_DEGREE, y->children.end());
            y->children.erase(y->children.begin() + MIN_DEGREE, y->children.end());
        }
    }
    void print(int level = 0) const {
        std::cout << "Level " << level << ": ";
        for (int key : keys) {
            std::cout << key << " ";
        }
        std::cout << std::endl;
        if (!isLeaf) {
            for (const BTreeNode* child : children) {
                child->print(level + 1);
            }
        }
    }
};
class BTree {
public:
    BTree() : root(nullptr) {}
    void insert(int key) {
        if (!root) {
            root = new BTreeNode(true);
            root->keys.push_back(key);
        } else {
            if (root->keys.size() == (2 * MIN_DEGREE - 1)) {
                BTreeNode* newRoot = new BTreeNode(false);
                newRoot->children.push_back(root);
                splitChild(0, root, newRoot);
                root = newRoot;
            }
            root->insertNonFull(key);
        }
    }
    void print() const {
        if (root) {
            root->print();
        }
    }
private:
    BTreeNode* root;
    void splitChild(int i, BTreeNode* x, BTreeNode* newRoot) {
        BTreeNode* z = new BTreeNode(x->isLeaf);
        newRoot->keys.push_back(x->keys[MIN_DEGREE - 1]);
        newRoot->children.push_back(z);
        z->keys.assign(x->keys.begin() + MIN_DEGREE, x->keys.end());
        x->keys.erase(x->keys.begin() + MIN_DEGREE - 1, x->keys.end());
        if (!x->isLeaf) {
            z->children.assign(x->children.begin() + MIN_DEGREE, x->children.end());
            x->children.erase(x->children.begin() + MIN_DEGREE, x->children.end());
        }
    }
};
int main() {
    BTree bTree;
    bTree.insert(3);
    bTree.insert(7);
    bTree.insert(1);
    bTree.insert(5);
    bTree.insert(9);
    bTree.insert(2);
    bTree.insert(6);
    bTree.insert(4);
    bTree.insert(8);
    bTree.print();
    return 0;
}
