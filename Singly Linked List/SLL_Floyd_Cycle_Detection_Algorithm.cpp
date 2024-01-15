// Floyd's Cycle Detection Algorithm
#include <iostream>
struct Node {
    int data;
    Node* next;
};
Node* insertAtEnd(Node* head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
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
bool detectCycle(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return false;
    }
    Node* slow = head;
    Node* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }
    return false;
}

int main() {
    Node* head = nullptr;
    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 3);
    head = insertAtEnd(head, 4);
    head->next->next->next->next = head->next;
    if (detectCycle(head)) {
        std::cout << "Cycle exists\n";
    } else {
        std::cout << "Cycle does not exist\n";
    }
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}
