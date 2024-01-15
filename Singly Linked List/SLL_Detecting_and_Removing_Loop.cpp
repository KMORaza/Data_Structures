// Implementing Floyd algorithm for detecting and removing loop
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
void detectAndRemoveLoop(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return; 
    }
    Node* slow = head;
    Node* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            break;
        }
    }
    if (slow != fast) {
        return;
    }
    slow = head;
    Node* prev = nullptr;
    while (slow != fast) {
        prev = fast;
        slow = slow->next;
        fast = fast->next;
    }
    prev->next = nullptr;
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
    Node* tail = head;
    while (tail->next != nullptr) {
         tail = tail->next;
     }
    tail->next = head->next;
    detectAndRemoveLoop(head);
    if (head == nullptr) {
        std::cout << "Loop detected and removed. List is empty now.\n";
    } else {
        std::cout << "Loop removed. List is:\n";
        while (head != nullptr) {
            std::cout << head->data << " ";
            head = head->next;
        }
        std::cout << "\n";
    }
    deleteList(head);
    return 0;
}
