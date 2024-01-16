// Implementation of deque using circular linked list
#include <iostream>
class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
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
            rear->next = front; 
        } else {
            newNode->next = front;
            front = newNode;
            rear->next = front; 
        }
        std::cout << "Inserted " << element << " at the front.\n";
    }
    void insertRear(int element) {
        Node* newNode = new Node(element);
        if (isEmpty()) {
            front = rear = newNode;
            rear->next = front; 
        } else {
            rear->next = newNode;
            rear = newNode;
            rear->next = front; 
        }
        std::cout << "Inserted " << element << " at the rear.\n";
    }
    void deleteFront() {
        if (isEmpty()) {
            std::cout << "Deque is empty. Cannot delete from front.\n";
            return;
        }
        Node* temp = front;
        if (front == rear) {
            front = rear = nullptr;
        } else {
            front = front->next;
            rear->next = front;
        }
        delete temp;
        std::cout << "Deleted element from the front.\n";
    }
    void deleteRear() {
        if (isEmpty()) {
            std::cout << "Deque is empty. Cannot delete from rear.\n";
            return;
        }
        Node* temp = front;
        while (temp->next != rear) {
            temp = temp->next;
        }
        temp->next = front; 
        delete rear;
        rear = temp; 
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
                std::cout << "Invalid option.\n";
        }
    } while (choice != 7);
    return 0;
}
