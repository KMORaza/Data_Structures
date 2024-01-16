#include <iostream>
#include <memory>
template <typename T>
class Node {
public:
    T data;
    std::shared_ptr<Node<T>> next;
    std::shared_ptr<Node<T>> prev;
    Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}
};
template <typename T>
class LinkedPositionalList {
private:
    std::shared_ptr<Node<T>> header;
    std::shared_ptr<Node<T>> trailer;
    std::size_t size;
public:
    LinkedPositionalList() : size(0) {
        header = std::make_shared<Node<T>>(T());
        trailer = std::make_shared<Node<T>>(T());
        header->next = trailer;
        trailer->prev = header;
    }
    std::shared_ptr<Node<T>> insert(const T& element) {
        return insertAfter(trailer->prev, element);
    }
    std::shared_ptr<Node<T>> insertAfter(const std::shared_ptr<Node<T>>& position, const T& element) {
        std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(element);
        newNode->prev = position;
        newNode->next = position->next;
        position->next->prev = newNode;
        position->next = newNode;
        ++size;
        return newNode;
    }
    class Iterator {
    private:
        std::shared_ptr<Node<T>> current;
    public:
        Iterator(const std::shared_ptr<Node<T>>& node) : current(node) {}
        T& operator*() const {
            return current->data;
        }
        Iterator& operator++() {
            current = current->next;
            return *this;
        }
        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }
    };
    Iterator begin() const {
        return Iterator(header->next);
    }
    Iterator end() const {
        return Iterator(trailer);
    }
};
int main() {
    LinkedPositionalList<int> myList;
    myList.insert(1);
    myList.insert(2);
    myList.insert(3);
    for (auto it = myList.begin(); it != myList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    return 0;
}
