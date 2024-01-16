// Implementing queue with doubly linked list
#include <iostream>
class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};
class DoublyLinkedListQueue {
private:
    Node* front;
    Node* rear;
public:
    DoublyLinkedListQueue() : front(nullptr), rear(nullptr) {}
    ~DoublyLinkedListQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
    bool isEmpty() {
        return front == nullptr;
    }
    void enqueue(int item) {
        Node* newNode = new Node(item);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
        std::cout << item << " enqueued to the queue.\n";
    }
    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        } else {
            front->prev = nullptr;
        }
        std::cout << temp->data << " dequeued from the queue.\n";
        delete temp;
    }
    void display() {
        if (isEmpty()) {
            std::cout << "Queue is empty.\n";
            return;
        }
        Node* current = front;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
    void reverse() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot reverse.\n";
            return;
        }
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
        std::cout << "Queue reversed.\n";
    }
    void traverse() {
        if (isEmpty()) {
            std::cout << "Queue is empty.\n";
            return;
        }
        Node* current = front;
        while (current != nullptr) {
            std::cout << "Visited: " << current->data << std::endl;
            current = current->next;
        }
    }
    bool search(int item) {
        Node* current = front;
        while (current != nullptr) {
            if (current->data == item) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
    void update(int oldValue, int newValue) {
        Node* current = front;
        while (current != nullptr) {
            if (current->data == oldValue) {
                current->data = newValue;
                std::cout << "Value updated successfully.\n";
                return;
            }
            current = current->next;
        }
        std::cout << "Value not found. Update failed.\n";
    }
};
int main() {
    DoublyLinkedListQueue myQueue;
    while (true) {
        std::cout << "\nOperations:\n";
        std::cout << "1] Enqueue\n";
        std::cout << "2] Dequeue\n";
        std::cout << "3] Display\n";
        std::cout << "4] Reverse\n";
        std::cout << "5] Traverse\n";
        std::cout << "6] Search\n";
        std::cout << "7] Update\n";
        std::cout << "8] Exit\n";
        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1: {
                int item;
                std::cout << "Enter the element to enqueue: ";
                std::cin >> item;
                myQueue.enqueue(item);
                break;
            }
            case 2:
                myQueue.dequeue();
                break;
            case 3:
                myQueue.display();
                break;
            case 4:
                myQueue.reverse();
                break;
            case 5:
                myQueue.traverse();
                break;
            case 6: {
                int item;
                std::cout << "Enter the element to search: ";
                std::cin >> item;
                if (myQueue.search(item)) {
                    std::cout << "Element found in the queue.\n";
                } else {
                    std::cout << "Element not found in the queue.\n";
                }
                break;
            }
            case 7: {
                int oldValue, newValue;
                std::cout << "Enter the value to update: ";
                std::cin >> oldValue;
                std::cout << "Enter the new value: ";
                std::cin >> newValue;
                myQueue.update(oldValue, newValue);
                break;
            }
            case 8:
                std::cout << "Exiting...\n";
                return 0;
            default:
                std::cout << "Invalid option.\n";
        }
    }
    return 0;
}
