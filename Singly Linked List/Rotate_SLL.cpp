// Rotation of SLL
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
int lengthOfList(Node* head) {
    int length = 0;
    Node* current = head;
    while (current != nullptr) {
        ++length;
        current = current->next;
    }
    return length;
}
Node* rotateList(Node* head, int k) {
    if (head == nullptr || k <= 0) {
        return head; 
    }
    int length = lengthOfList(head);
    k %= length; 
    if (k == 0) {
        return head; 
    }
    Node* current = head;
    Node* newHead = nullptr;
    Node* newTail = nullptr;
    for (int i = 0; i < length - k - 1; ++i) {
        current = current->next;
    }
    newTail = current;
    newHead = current->next;
    current->next = nullptr;
    current = newHead;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = head;
    return newHead;
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
    int n, value, k;
    std::cout << "Enter the number of nodes in the linked list: ";
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cout << "Enter the value for node " << i + 1 << ": ";
        std::cin >> value;
        head = insertAtEnd(head, value);
    }
    std::cout << "Original linked list: ";
    displayList(head);
    std::cout << "Enter the number of positions to rotate to the right: ";
    std::cin >> k;
    head = rotateList(head, k);
    std::cout << "Linked list after rotating to the right by " << k << " positions: ";
    displayList(head);
    deleteList(head);
    return 0;
}
