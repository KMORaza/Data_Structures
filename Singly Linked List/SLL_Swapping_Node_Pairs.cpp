// Swapping nodes pairs in SLL
#include <iostream>
struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};
Node* insertAtEnd(Node* head, int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        return newNode;
    }
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}
Node* swapPairs(Node* head) {
    Node* dummy = new Node(0); 
    dummy->next = head;
    Node* prev = dummy;
    Node* current = head;
    while (current != nullptr && current->next != nullptr) {
        Node* first = current;
        Node* second = current->next;
        first->next = second->next;
        second->next = first;
        prev->next = second;
        prev = first;
        current = first->next;
    }

    head = dummy->next; 
    delete dummy; 
    return head;
}
void displayList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
void deleteList(Node* head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
int main() {
    Node* head = nullptr;
    int n, value;
    std::cout << "Enter the number of nodes in the linked list: ";
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cout << "Enter the value for node " << i + 1 << ": ";
        std::cin >> value;
        head = insertAtEnd(head, value);
    }
    std::cout << "Original linked list: ";
    displayList(head);
    head = swapPairs(head);
    std::cout << "Linked list after swapping nodes in pairs: ";
    displayList(head);
    deleteList(head);
    return 0;
}
