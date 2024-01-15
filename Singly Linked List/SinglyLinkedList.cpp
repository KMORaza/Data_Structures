// Implementing singly linked list with major operations
#include <iostream>
struct Node {
    int data;
    Node* next;
};
Node* insertAtBeginning(Node* head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    return newNode;
}
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
Node* deleteNode(Node* head, int value) {
    if (head == nullptr) {
        std::cout << "Linked list is empty. Cannot delete.\n";
        return nullptr;
    }
    if (head->data == value) {
        Node* newHead = head->next;
        delete head;
        return newHead;
    }
    Node* current = head;
    while (current->next != nullptr && current->next->data != value) {
        current = current->next;
    }
    if (current->next == nullptr) {
        std::cout << "Node with value " << value << " not found.\n";
        return head;
    }
    Node* temp = current->next;
    current->next = current->next->next;
    delete temp;
    return head;
}
bool searchNode(Node* head, int value) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}
void displayList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
Node* findMiddle(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }
    Node* slow = head;
    Node* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
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
    int choice, value;
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Insert at Beginning\n";
        std::cout << "2. Insert at End\n";
        std::cout << "3. Delete Node\n";
        std::cout << "4. Search Node\n";
        std::cout << "5. Display List\n";
        std::cout << "6. Reverse List\n";
        std::cout << "7. Find Middle Element\n";
        std::cout << "8. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1:
                std::cout << "Enter the value to insert at the beginning: ";
                std::cin >> value;
                head = insertAtBeginning(head, value);
                break;
            case 2:
                std::cout << "Enter the value to insert at the end: ";
                std::cin >> value;
                head = insertAtEnd(head, value);
                break;
            case 3:
                std::cout << "Enter the value to delete: ";
                std::cin >> value;
                head = deleteNode(head, value);
                break;
            case 4:
                std::cout << "Enter the value to search: ";
                std::cin >> value;
                if (searchNode(head, value)) {
                    std::cout << "Node with value " << value << " found.\n";
                } else {
                    std::cout << "Node with value " << value << " not found.\n";
                }
                break;
            case 5:
                displayList(head);
                break;
            case 6:
                head = reverseList(head);
                std::cout << "Linked list reversed.\n";
                break;
            case 7: {
                Node* middle = findMiddle(head);
                if (middle != nullptr) {
                    std::cout << "Middle element: " << middle->data << "\n";
                } else {
                    std::cout << "Linked list is empty.\n";
                }
                break;
            }
            case 8:
                std::cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 8);
    deleteList(head);
    return 0;
}
