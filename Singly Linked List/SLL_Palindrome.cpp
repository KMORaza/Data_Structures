// Detection of palindrome in SLL
#include <iostream>
#include <stack>
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
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* nextNode = nullptr;
    while (current != nullptr) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    return prev;
}
bool isPalindrome(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return true;
    }
    Node* slow = head;
    Node* fast = head;
    std::stack<int> halfValues;
    while (fast != nullptr && fast->next != nullptr) {
        halfValues.push(slow->data);
        slow = slow->next;
        fast = fast->next->next;
    }
    if (fast != nullptr) {
        slow = slow->next;
    }
    while (slow != nullptr) {
        if (slow->data != halfValues.top()) {
            return false;
        }
        slow = slow->next;
        halfValues.pop();
    }

    return true; 
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
    std::cout << "Linked list: ";
    displayList(head);
    if (isPalindrome(head)) {
        std::cout << "The linked list is a palindrome.\n";
    } else {
        std::cout << "The linked list is not a palindrome.\n";
    }
    deleteList(head);
    return 0;
}
