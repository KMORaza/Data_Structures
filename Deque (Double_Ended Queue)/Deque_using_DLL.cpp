// Implementation of deque using DLL
#include <iostream>
class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};
class Deque {
private:
    Node* front;
    Node* rear;
public:
    Deque() : front(nullptr), rear(nullptr) {}
    bool isEmpty() {
        return front == nullptr;
    }
    void insertFront(int element) {
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
    void insertRear(int element) {
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
    void deleteFront() {
        if (isEmpty()) {
            std::cout << "Deque is empty. Cannot delete from front.\n";
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front != nullptr) {
            front->prev = nullptr;
        } else {
            rear = nullptr; 
        }
        delete temp;
        std::cout << "Deleted element from the front.\n";
    }
    void deleteRear() {
        if (isEmpty()) {
            std::cout << "Deque is empty. Cannot delete from rear.\n";
            return;
        }
        Node* temp = rear;
        rear = rear->prev;
        if (rear != nullptr) {
            rear->next = nullptr;
        } else {
            front = nullptr; 
        }
        delete temp;
        std::cout << "Deleted element from the rear.\n";
    }
    int getFront() {
        if (isEmpty()) {
            std::cout << "Deque is empty.\n";
            return -1;
        }
        return front->data;
    }
    int getRear() {
        if (isEmpty()) {
            std::cout << "Deque is empty.\n";
            return -1;
        }
        return rear->data;
    }
    ~Deque() {
        while (!isEmpty()) {
            deleteFront();
        }
    }
};
int main() {
    Deque myDeque;
    int choice, element;
    do {
        std::cout << "\nOperations:\n";
        std::cout << "1] Insert Front\n";
        std::cout << "2] Insert Rear\n";
        std::cout << "3] Delete Front\n";
        std::cout << "4] Delete Rear\n";
        std::cout << "5] Get Front\n";
        std::cout << "6] Get Rear\n";
        std::cout << "7] Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1:
                std::cout << "Enter element to insert at front: ";
                std::cin >> element;
                myDeque.insertFront(element);
                break;
            case 2:
                std::cout << "Enter element to insert at rear: ";
                std::cin >> element;
                myDeque.insertRear(element);
                break;
            case 3:
                myDeque.deleteFront();
                break;
            case 4:
                myDeque.deleteRear();
                break;
            case 5:
                std::cout << "Front element: " << myDeque.getFront() << "\n";
                break;
            case 6:
                std::cout << "Rear element: " << myDeque.getRear() << "\n";
                break;
            case 7:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 7);
    return 0;
}
