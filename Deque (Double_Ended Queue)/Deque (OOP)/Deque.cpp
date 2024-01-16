#include "Deque.h"
#include <iostream>
Node::Node(int value) : data(value), next(nullptr), prev(nullptr) {}
Deque::Deque() : front(nullptr), rear(nullptr) {}
Deque::~Deque() {
    while (!isEmpty()) {
        deleteFront();
    }
}
bool Deque::isEmpty() {
    return front == nullptr;
}
void Deque::insertFront(int element) {
    Node* newNode = new Node(element);
    if (isEmpty()) {
        front = rear = newNode;
    } else {
        newNode->next = front;
        front->prev = newNode;
        front = newNode;
    }
    std::cout << "Inserted " << element << " at the front.\n";
}
void Deque::insertRear(int element) {
    Node* newNode = new Node(element);
    if (isEmpty()) {
        front = rear = newNode;
    } else {
        newNode->prev = rear;
        rear->next = newNode;
        rear = newNode;
    }
    std::cout << "Inserted " << element << " at the rear.\n";
}
void Deque::deleteFront() {
    if (isEmpty()) {
        std::cout << "Deque is empty. Cannot delete from front.\n";
        return;
    }
    Node* temp = front;
    if (front == rear) {
        front = rear = nullptr;
    } else {
        front = front->next;
        front->prev = nullptr;
    }
    delete temp;
    std::cout << "Deleted element from the front.\n";
}
void Deque::deleteRear() {
    if (isEmpty()) {
        std::cout << "Deque is empty. Cannot delete from rear.\n";
        return;
    }
    Node* temp = rear;
    if (front == rear) {
        front = rear = nullptr;
    } else {
        rear = rear->prev;
        rear->next = nullptr;
    }
    delete temp;
    std::cout << "Deleted element from the rear.\n";
}
int Deque::getFront() {
    if (isEmpty()) {
        std::cout << "Deque is empty.\n";
        return -1;
    }
    return front->data;
}
int Deque::getRear() {
    if (isEmpty()) {
        std::cout << "Deque is empty.\n";
        return -1;
    }
    return rear->data;
}
void Deque::multiply(int factor) {
    Node* current = front;
    while (current != nullptr) {
        current->data *= factor;
        current = current->next;
    }
    std::cout << "Multiplied all elements by " << factor << ".\n";
}
void Deque::split(Deque& secondDeque) {
    while (!isEmpty()) {
        secondDeque.insertRear(getFront());
        deleteFront();
    }
    std::cout << "Split deque into two.\n";
}
void Deque::reverse() {
    Node* temp = nullptr;
    Node* current = front;
    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != nullptr) {
        front = temp->prev;
    }
    std::cout << "Reversed deque.\n";
}
void Deque::traverse() {
    if (isEmpty()) {
        std::cout << "Deque is empty.\n";
        return;
    }
    Node* current = front;
    std::cout << "Deque: ";
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << "\n";
}
bool Deque::search(int element) {
    Node* current = front;
    while (current != nullptr) {
        if (current->data == element) {
            return true;
        }
        current = current->next;
    }
    return false;
}
void Deque::update(int oldElement, int newElement) {
    Node* current = front;
    while (current != nullptr) {
        if (current->data == oldElement) {
            current->data = newElement;
            std::cout << "Updated " << oldElement << " to " << newElement << ".\n";
            return;
        }
        current = current->next;
    }
    std::cout << oldElement << " not found. Update failed.\n";
}
