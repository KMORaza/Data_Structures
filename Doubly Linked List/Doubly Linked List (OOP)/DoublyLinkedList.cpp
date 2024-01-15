#include "DoublyLinkedList.h"
#include <iostream>
DoublyLinkedList::DoublyLinkedList() : head(nullptr) {}
void DoublyLinkedList::insertAtBeginning(int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}
void DoublyLinkedList::insertAtEnd(int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}
void DoublyLinkedList::deleteNode(int value) {
    if (head == nullptr) {
        std::cout << "List is empty. Nothing to delete.\n";
        return;
    }
    Node* current = head;
    while (current != nullptr && current->data != value) {
        current = current->next;
    }
    if (current == nullptr) {
        std::cout << "Node with value " << value << " not found. Cannot delete.\n";
        return;
    }
    if (current->prev != nullptr) {
        current->prev->next = current->next;
    } else {
        // Deleting the head
        head = current->next;
    }
    if (current->next != nullptr) {
        current->next->prev = current->prev;
    }
    delete current;
    std::cout << "Node with value " << value << " deleted successfully.\n";
}
void DoublyLinkedList::traverseList() {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << "\n";
}
void DoublyLinkedList::reverseList() {
    Node* current = head;
    Node* temp = nullptr;
    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != nullptr) {
        head = temp->prev;
    }
}
void DoublyLinkedList::multiplyList(int factor) {
    Node* current = head;
    while (current != nullptr) {
        current->data *= factor;
        current = current->next;
    }
    std::cout << "List multiplied by " << factor << ".\n";
}
Node* DoublyLinkedList::search(int value) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == value) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}
void DoublyLinkedList::displayList() {
    traverseList();
}
void DoublyLinkedList::concatenateLists(DoublyLinkedList& otherList) {
    if (head == nullptr) {
        head = otherList.head;
    } else if (otherList.head != nullptr) {
        Node* last = head;
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = otherList.head;
        otherList.head->prev = last;
    }
    otherList.head = nullptr; // Avoid memory leak in the destructor
    std::cout << "Lists concatenated successfully.\n";
}
std::pair<DoublyLinkedList, DoublyLinkedList> DoublyLinkedList::splitList() {
    DoublyLinkedList firstHalf;
    DoublyLinkedList secondHalf;
    Node* slow = head;
    Node* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        firstHalf.insertAtEnd(slow->data);
        slow = slow->next;
        fast = fast->next->next;
    }
    while (slow != nullptr) {
        secondHalf.insertAtEnd(slow->data);
        slow = slow->next;
    }
    std::cout << "List split into two halves.\n";
    return {firstHalf, secondHalf};
}
bool DoublyLinkedList::detectCycle() {
    Node* slow = head;
    Node* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            std::cout << "Cycle detected in the list.\n";
            return true;
        }
    }
    std::cout << "No cycle detected in the list.\n";
    return false;
}
