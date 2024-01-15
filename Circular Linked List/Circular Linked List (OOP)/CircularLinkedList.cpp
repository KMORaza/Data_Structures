#include "CircularLinkedList.h"
#include <iostream>
CircularLinkedList::CircularLinkedList() : head(nullptr) {}
CircularLinkedList::~CircularLinkedList() {
    Node* current = head;
    Node* nextNode;
    while (current != nullptr) {
        nextNode = current->next;
        delete current;
        current = nextNode;
        if (current == head) {
            break;
        }
    }
}
void CircularLinkedList::insertAtEnd(int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
        newNode->next = head;
    } else {
        Node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        last->next = newNode;
        newNode->next = head;
    }
}
void CircularLinkedList::deleteNode(int value) {
    if (head == nullptr) {
        std::cout << "List is empty.\n";
        return;
    }
    Node* current = head;
    Node* prev = nullptr;
    do {
        if (current->data == value) {
            if (prev != nullptr) {
                prev->next = current->next;
                delete current;
                return;
            } else {
                // Deleting the head
                Node* last = head;
                while (last->next != head) {
                    last = last->next;
                }
                if (head == head->next) {
                    // List has only one element
                    delete head;
                    head = nullptr;
                    return;
                }
                last->next = head->next;
                delete head;
                head = last->next;
                return;
            }
        }
        prev = current;
        current = current->next;
    } while (current != head);
    std::cout << "Node with value " << value << " not found.\n";
}
void CircularLinkedList::reverseList() {
    if (head == nullptr || head->next == head) {
        std::cout << "List is empty or has only one node. No need to reverse.\n";
        return;
    }
    Node* prev = nullptr;
    Node* current = head;
    Node* nextNode;
    do {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    } while (current != head);
    head->next = prev;
    head = prev;
    std::cout << "List reversed successfully.\n";
}
void CircularLinkedList::traverseList() {
    if (head == nullptr) {
        std::cout << "List is empty.\n";
        return;
    }
    Node* current = head;
    do {
        std::cout << current->data << " ";
        current = current->next;
    } while (current != head);
    std::cout << "\n";
}
void CircularLinkedList::multiplyList(int factor) {
    if (head == nullptr) {
        std::cout << "List is empty.\n";
        return;
    }
    Node* current = head;
    do {
        current->data *= factor;
        current = current->next;
    } while (current != head);
    std::cout << "List multiplied by " << factor << " successfully.\n";
}
Node* CircularLinkedList::search(int value) {
    if (head == nullptr) {
        std::cout << "List is empty.\n";
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
void CircularLinkedList::displayList() {
    traverseList();
}
void CircularLinkedList::concatenateLists(CircularLinkedList& otherList) {
    if (head == nullptr) {
        head = otherList.head;
    } else if (otherList.head) {
        Node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        last->next = otherList.head;
        Node* lastOther = otherList.head;
        while (lastOther->next != otherList.head) {
            lastOther = lastOther->next;
        }
        lastOther->next = head;
    }
    otherList.head = nullptr;
    std::cout << "Lists concatenated successfully.\n";
}
std::pair<CircularLinkedList, CircularLinkedList> CircularLinkedList::splitList() {
    CircularLinkedList firstHalf;
    CircularLinkedList secondHalf;
    if (head == nullptr) {
        return std::make_pair(firstHalf, secondHalf);
    }
    Node* slowPtr = head;
    Node* fastPtr = head;
    while (fastPtr->next != head && fastPtr->next->next != head) {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }
    Node* middle = slowPtr->next;
    slowPtr->next = head;
    firstHalf.head = head;
    secondHalf.head = middle;
    Node* lastFirst = firstHalf.head;
    while (lastFirst->next != head) {
        lastFirst = lastFirst->next;
    }
    lastFirst->next = head;
    Node* lastSecond = secondHalf.head;
    while (lastSecond->next != middle) {
        lastSecond = lastSecond->next;
    }
    lastSecond->next = middle;
    std::cout << "List split successfully.\n";
    return std::make_pair(firstHalf, secondHalf);
}
bool CircularLinkedList::detectCycle() {
    Node* slowPtr = head;
    Node* fastPtr = head;
    while (fastPtr != nullptr && fastPtr->next != nullptr) {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
        if (slowPtr == fastPtr) {
            return true;
        }
    }
    return false;
}
