// Implementing queue using circular linked list
#include <iostream>
class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};
class CircularLinkedListQueue {
private:
    Node* rear;
public:
    CircularLinkedListQueue() : rear(nullptr) {}
    ~CircularLinkedListQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
    bool isEmpty() {
        return rear == nullptr;
    }
    void enqueue(int item) {
        Node* newNode = new Node(item);
        if (isEmpty()) {
            newNode->next = newNode; 
            rear = newNode;
        } else {
            newNode->next = rear->next;  
            rear->next = newNode;
            rear = newNode;
        }
        std::cout << item << " enqueued to the queue.\n";
    }
    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }
        Node* temp = rear->next;
        if (temp == rear) {
            rear = nullptr;
        } else {
            rear->next = temp->next;
        }
        std::cout << temp->data << " dequeued from the queue.\n";
        delete temp;
    }
    void display() {
        if (isEmpty()) {
            std::cout << "Queue is empty.\n";
            return;
        }
        Node* current = rear->next;
        do {
            std::cout << current->data << " ";
            current = current->next;
        } while (current != rear->next);
        std::cout << std::endl;
    }
    void reverse() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot reverse.\n";
            return;
        }
        Node* prev = nullptr;
        Node* current = rear->next;
        Node* nextNode;
        do {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        } while (current != rear->next);
        rear = rear->next;  
        std::cout << "Queue reversed.\n";
    }
    void traverse() {
        if (isEmpty()) {
            std::cout << "Queue is empty.\n";
            return;
        }
        Node* current = rear->next;
        do {
            std::cout << "Visited: " << current->data << std::endl;
            current = current->next;
        } while (current != rear->next);
    }
    bool search(int item) {
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
    void update(int oldValue, int newValue) {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot update.\n";
            return;
        }
        Node* current = rear->next;
        do {
            if (current->data == oldValue) {
                current->data = newValue;
                std::cout << "Value updated successfully.\n";
                return;
            }
            current = current->next;
        } while (current != rear->next);
        std::cout << "Value not found. Update failed.\n";
    }
};
int main() {
    CircularLinkedListQueue myQueue;
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
                std::cout << "Exiting the program.\n";
                return 0;
            default:
                std::cout << "Invalid option.\n";
        }
    }
    return 0;
}
