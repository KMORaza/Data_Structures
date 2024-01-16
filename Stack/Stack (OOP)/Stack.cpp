#include "Stack.h"
#include <iostream>
Stack::Stack() : top(nullptr) {}
Stack::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}
bool Stack::isEmpty() const {
    return top == nullptr;
}
void Stack::push(int value) {
    Node* newNode = new Node(value);
    newNode->next = top;
    top = newNode;
}
void Stack::pop() {
    if (!isEmpty()) {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}
void Stack::reverse() {
    Node* prev = nullptr;
    Node* current = top;
    Node* next = nullptr;
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    top = prev;
}
void Stack::traverse() const {
    Node* current = top;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
void Stack::update(int oldValue, int newValue) {
    Node* current = top;
    while (current != nullptr) {
        if (current->data == oldValue) {
            current->data = newValue;
            break;
        }
        current = current->next;
    }
}
void Stack::display() const {
    Node* current = top;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
void Stack::split(Stack& stack2) {
    Node* slow = top;
    Node* fast = top;
    while (fast != nullptr && fast->next != nullptr) {
        stack2.push(slow->data);
        slow = slow->next;
        fast = fast->next->next;
    }
    top = slow;
}
