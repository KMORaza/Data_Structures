// Implementation of deque using array
#include <iostream>
class Deque {
private:
    int *arr;
    int front, rear, capacity;
public:
    Deque(int size) {
        capacity = size;
        arr = new int[capacity];
        front = rear = -1;
    }
    bool isFull() {
        return (front == 0 && rear == capacity - 1) || (front == rear + 1);
    }
    bool isEmpty() {
        return front == -1;
    }
    void insertFront(int element) {
        if (isFull()) {
            std::cout << "Deque is full. Cannot insert at front.\n";
            return;
        }
        if (front == -1) {
            front = rear = 0;
        } else if (front == 0) {
            front = capacity - 1;
        } else {
            front--;
        }
        arr[front] = element;
        std::cout << "Inserted " << element << " at the front.\n";
    }
    void insertRear(int element) {
        if (isFull()) {
            std::cout << "Deque is full. Cannot insert at rear.\n";
            return;
        }
        if (front == -1) {
            front = rear = 0;
        } else if (rear == capacity - 1) {
            rear = 0;
        } else {
            rear++;
        }
        arr[rear] = element;
        std::cout << "Inserted " << element << " at the rear.\n";
    }
    void deleteFront() {
        if (isEmpty()) {
            std::cout << "Deque is empty. Cannot delete from front.\n";
            return;
        }
        if (front == rear) {
            front = rear = -1;
        } else if (front == capacity - 1) {
            front = 0;
        } else {
            front++;
        }
        std::cout << "Deleted element from the front.\n";
    }
    void deleteRear() {
        if (isEmpty()) {
            std::cout << "Deque is empty. Cannot delete from rear.\n";
            return;
        }
        if (front == rear) {
            front = rear = -1;
        } else if (rear == 0) {
            rear = capacity - 1;
        } else {
            rear--;
        }
        std::cout << "Deleted element from the rear.\n";
    }
    int getFront() {
        if (isEmpty()) {
            std::cout << "Deque is empty.\n";
            return -1;
        }
        return arr[front];
    }
    int getRear() {
        if (isEmpty() || rear < 0) {
            std::cout << "Deque is empty.\n";
            return -1;
        }
        return arr[rear];
    }
    ~Deque() {
        delete[] arr;
    }
};
int main() {
    int size;
    std::cout << "Enter the size of the deque: ";
    std::cin >> size;
    Deque myDeque(size);
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
