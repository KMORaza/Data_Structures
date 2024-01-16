#include "Queue.h"
#include <iostream>
Queue::Queue() : rear(nullptr) {}
Queue::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}
bool Queue::isEmpty() {
    return rear == nullptr;
}
void Queue::enqueue(int item) {
    Node* newNode = new Node(item);
    if (isEmpty()) {
        newNode->next = newNode; 
    } else {
        newNode->next = rear->next;  
        rear->next = newNode;      
    }
    rear = newNode; 
}
void Queue::dequeue() {
    if (!isEmpty()) {
        Node* front = rear->next;
        if (front == rear) {
            rear = nullptr;
        } else {
            rear->next = front->next;
        }
        delete front;
    }
}
void Queue::display() {
    if (isEmpty()) {
        std::cout << "Queue is empty.\n";
        return;
    }
    Node* current = rear->next;
    do {
        std::cout << current->data << " ";
        current = current->next;
    } while (current != rear->next);
    std::cout << "\n";
}
void Queue::reverse() {
    if (!isEmpty()) {
        Node* prev = nullptr;
        Node* current = rear->next;
        Node* nextNode;
        do {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        } while (current != rear->next);
        rear = prev; 
    }
}
bool Queue::search(int item) {
    if (isEmpty()) {
        return false;
    }
    Node* current = rear->next;
    do {
        if (current->data == item) {
            return true; 
        }
        current = current->next;
    } while (current != rear->next);
    return false; 
}
void Queue::update(int oldValue, int newValue) {
    if (!isEmpty()) {
        Node* current = rear->next;
        do {
            if (current->data == oldValue) {
                current->data = newValue; 
                return;
            }
            current = current->next;
        } while (current != rear->next);
    }
}
