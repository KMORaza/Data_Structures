#include <iostream>
template <typename Key, typename Value>
class Node {
public:
    Key key;
    Value value;
    Node* left;
    Node* right;
    Node(Key k, Value v) : key(k), value(v), left(nullptr), right(nullptr) {}
};
template <typename Key, typename Value>
class Map {
private:
    Node<Key, Value>* root;
    Node<Key, Value>* insert(Node<Key, Value>* node, Key key, Value value) {
        if (node == nullptr) {
            return new Node<Key, Value>(key, value);
        }
        if (key < node->key) {
            node->left = insert(node->left, key, value);
        } else if (key > node->key) {
            node->right = insert(node->right, key, value);
        } else {
            node->value = value;
        }
        return node;
    }
    Value search(Node<Key, Value>* node, Key key) const {
        if (node == nullptr) {
            return Value();
        }
        if (key < node->key) {
            return search(node->left, key);
        } else if (key > node->key) {
            return search(node->right, key);
        } else {
            return node->value;
        }
    }
public:
    Map() : root(nullptr) {}
    void insert(Key key, Value value) {
        root = insert(root, key, value);
    }
    Value get(Key key) const {
        return search(root, key);
    }
};
int main() {
    Map<std::string, int> myMap;
    myMap.insert("one", 1);
    myMap.insert("two", 2);
    myMap.insert("three", 3);
    std::cout << "Value for key 'two': " << myMap.get("two") << std::endl;
    std::cout << "Value for key 'four': " << myMap.get("four") << std::endl;
    return 0;
}
