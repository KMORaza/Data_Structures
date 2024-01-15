// Basic Circular Linked List
#include <iostream>
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};
Node* insertAtEnd(Node* head, int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        newNode->next = newNode; 
        return newNode;
    }
    Node* current = head;
    while (current->next != head) {
        current = current->next;
    }

    current->next = newNode;
    newNode->next = head; 
    return head;
}
void displayList(Node* head) {
    if (head == nullptr) {
        return;
    }
    Node* current = head;
    do {
        std::cout << current->data << " ";
        current = current->next;
    } while (current != head);
    std::cout << std::endl;
}
void deleteList(Node* head) {
    if (head == nullptr) {
        return;
    }
    Node* current = head;
    Node* nextNode;
    do {
        nextNode = current->next;
        delete current;
        current = nextNode;
    } while (current != head);
}
int main() {
    Node* head = nullptr;
    int n, value;
    std::cout << "Enter the number of nodes in the circular linked list: ";
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cout << "Enter the value for node " << i + 1 << ": ";
        std::cin >> value;
        head = insertAtEnd(head, value);
    }
    std::cout << "Circular linked list: ";
    displayList(head);
    deleteList(head);
    return 0;
}
