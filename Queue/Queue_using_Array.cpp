#include <iostream>
class ArrayQueue {
private:
    int front, rear, capacity;
    int *array;
public:
    ArrayQueue(int size) {
        capacity = size;
        front = rear = -1;
        array = new int[capacity];
    }
    ~ArrayQueue() {
        delete[] array;
    }
    bool isEmpty() {
        return front == -1;
    }
    bool isFull() {
        return (rear + 1) % capacity == front;
    }
    void enqueue(int item) {
        if (isFull()) {
            std::cout << "Queue is full. Cannot enqueue.\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }
        array[rear] = item;
        std::cout << item << " enqueued to the queue.\n";
    }
    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }
        std::cout << array[front] << " dequeued from the queue.\n";
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
    }
    void display() {
        if (isEmpty()) {
            std::cout << "Queue is empty.\n";
            return;
        }
        int i = front;
        do {
            std::cout << array[i] << " ";
            i = (i + 1) % capacity;
        } while (i != (rear + 1) % capacity);
        std::cout << std::endl;
    }
    void reverse() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot reverse.\n";
            return;
        }
        int* tempArray = new int[capacity];
        int index = 0;
        while (!isEmpty()) {
            tempArray[index++] = array[front];
            dequeue();
        }
        for (int i = index - 1; i >= 0; --i) {
            enqueue(tempArray[i]);
        }
        delete[] tempArray;
        std::cout << "Queue reversed.\n";
    }
};
int main() {
    int size;
    std::cout << "Enter the size of the queue: ";
    std::cin >> size;
    ArrayQueue myQueue(size);
    while (true) {
        std::cout << "\nOperations:\n";
        std::cout << "1] Enqueue\n";
        std::cout << "2] Dequeue\n";
        std::cout << "3] Display\n";
        std::cout << "4] Reverse\n";
        std::cout << "5] Exit\n";
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
                std::cout << "Exiting...\n";
                return 0;
            default:
                std::cout << "Invalid option.\n";
        }
    }
    return 0;
}
