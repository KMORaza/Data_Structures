// Circular Linked List
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
Node* search(Node* head, int value) {
    if (head == nullptr) {
        return nullptr;
    }
    Node* current = head;
    do {
        if (current->data == value) {
            return current;
        }
        current = current->next;
    } while (current != head);
    return nullptr; 
}
Node* deleteNode(Node* head, int value) {
    if (head == nullptr) {
        return nullptr;
    }
    Node* current = head;
    Node* prev = nullptr;
    do {
        if (current->data == value) {
            if (prev == nullptr) {
                Node* tail = head;
                while (tail->next != head) {
                    tail = tail->next;
                }
                tail->next = head->next;
                delete head;
                return tail->next; 
            } else {
                prev->next = current->next;
                delete current;
                return head;
            }
        }
        prev = current;
        current = current->next;
    } while (current != head);
    return head;
}
void updateNode(Node* head, int oldValue, int newValue) {
    Node* nodeToUpdate = search(head, oldValue);
    if (nodeToUpdate != nullptr) {
        nodeToUpdate->data = newValue;
        std::cout << "Node updated successfully.\n";
    } else {
        std::cout << "Node with value " << oldValue << " not found.\n";
    }
}
void multiplyList(Node* head, int factor) {
    if (head == nullptr) {
        return;
    }
    Node* current = head;
    do {
        current->data *= factor;
        current = current->next;
    } while (current != head);

    std::cout << "List multiplied by " << factor << ".\n";
}
Node* reverseList(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }
    Node* current = head;
    Node* prev = nullptr;
    Node* nextNode = nullptr;
    do {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    } while (current != head);
    head->next = prev;
    head = prev;
    std::cout << "List reversed.\n";
    return head;
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
    int choice, value, oldValue, newValue, factor;
    Node* result = nullptr;
    do {
        std::cout << "\nCircular Linked List Operations:\n";
        std::cout << "1. Insert Node\n";
        std::cout << "2. Display List\n";
        std::cout << "3. Search Node\n";
        std::cout << "4. Delete Node\n";
        std::cout << "5. Update Node\n";
        std::cout << "6. Multiply List\n";
        std::cout << "7. Reverse List\n";
        std::cout << "8. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1:
                std::cout << "Enter the value to insert: ";
                std::cin >> value;
                head = insertAtEnd(head, value);
                break;
            case 2:
                std::cout << "Circular linked list: ";
                displayList(head);
                break;
            case 3:
                std::cout << "Enter the value to search: ";
                std::cin >> value;
                result = search(head, value);
                if (result != nullptr) {
                    std::cout << "Node found with value " << result->data << ".\n";
                } else {
                    std::cout << "Node not found.\n";
                }
                break;
            case 4:
                std::cout << "Enter the value to delete: ";
                std::cin >> value;
                head = deleteNode(head, value);
                break;
            case 5:
                std::cout << "Enter the value to update: ";
                std::cin >> oldValue;
                std::cout << "Enter the new value: ";
                std::cin >> newValue;
                updateNode(head, oldValue, newValue);
                break;
            case 6:
                std::cout << "Enter the factor to multiply: ";
                std::cin >> factor;
                multiplyList(head, factor);
                break;
            case 7:
                head = reverseList(head);
                break;
            case 8:
                deleteList(head);
                std::cout << "Exiting the program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 8);
    return 0;
}
