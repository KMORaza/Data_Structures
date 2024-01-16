#include <iostream>
template <typename T>
class Positional_List {
private:
    struct Node {
        T data;
        Node* next;
    };
    Node* head;
public:
    PositionalList() : head(nullptr) {}
    ~PositionalList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void insertAtBeginning(const T& element) {
        Node* newNode = new Node{element, head};
        head = newNode;
    }
    void insertAtEnd(const T& element) {
        Node* newNode = new Node{element, nullptr};
        if (!head) {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
    void display() const {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};
int main() {
    PositionalList<int> myList;
    myList.insertAtEnd(1);
    myList.insertAtBeginning(2);
    myList.insertAtEnd(3);
    myList.insertAtBeginning(4);
    myList.display();
    return 0;
}
