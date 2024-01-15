// Searching the k-th to the last element
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
Node* kthToLast(Node* head, int k) {
    if (head == nullptr || k <= 0) {
        return nullptr;
    }
    Node* ahead = head;
    Node* behind = head;
    for (int i = 0; i < k; ++i) {
        if (ahead == nullptr) {
            return nullptr; 
        }
        ahead = ahead->next;
    }
    while (ahead != nullptr) {
        ahead = ahead->next;
        behind = behind->next;
    }

    return behind; 
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
    std::cout << "Linked list: ";
    displayList(head);
    std::cout << "Enter the value of k: ";
    std::cin >> k;
    Node* result = kthToLast(head, k);
    if (result != nullptr) {
        std::cout << "The k-th to the last element is: " << result->data << "\n";
    } else {
        std::cout << "Invalid input or k is greater than the length of the list.\n";
    }
    deleteList(head);
    return 0;
}
