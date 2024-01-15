#include <iostream>
class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};
class DoublyLinkedList {
private:
    Node* head;
public:
    DoublyLinkedList() : head(nullptr) {}
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }
    void deleteNode(int value) {
        if (head == nullptr) {
            std::cout << "List is empty. Nothing to delete.\n";
            return;
        }
        Node* current = head;
        while (current != nullptr && current->data != value) {
            current = current->next;
        }
        if (current == nullptr) {
            std::cout << "Node with value " << value << " not found. Cannot delete.\n";
            return;
        }
        if (current->prev != nullptr) {
            current->prev->next = current->next;
        } else {
            // Deleting the head
            head = current->next;
        }
        if (current->next != nullptr) {
            current->next->prev = current->prev;
        }
        delete current;
        std::cout << "Node with value " << value << " deleted successfully.\n";
    }
    void traverseList() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << "\n";
    }
};
int main() {
    DoublyLinkedList doublyList;
    doublyList.insertAtBeginning(3);
    doublyList.insertAtBeginning(2);
    doublyList.insertAtBeginning(1);
    doublyList.insertAtEnd(4);
    doublyList.insertAtEnd(5);
    std::cout << "Doubly Linked List: ";
    doublyList.traverseList();
    doublyList.deleteNode(2);
    doublyList.deleteNode(5);
    std::cout << "Updated Doubly Linked List: ";
    doublyList.traverseList();
    return 0;
}
