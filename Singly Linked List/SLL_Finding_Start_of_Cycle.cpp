// Implementing Floyd algorith to find starting of cycle
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
Node* detectAndFindStartOfCycle(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return nullptr;
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
        return nullptr; 
    }
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
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
    Node* startOfCycle = detectAndFindStartOfCycle(head);

    if (startOfCycle != nullptr) {
        std::cout << "Start of the cycle in the linked list: " << startOfCycle->data << "\n";
    } else {
        std::cout << "No cycle exists.\n";
    }
    deleteList(head);
    return 0;
}
