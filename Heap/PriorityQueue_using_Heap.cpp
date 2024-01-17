#include <iostream>
#include <vector>
#include <algorithm>
class PriorityQueue {
private:
    std::vector<int> heap;
    void heapifyUp(int index) {
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (heap[index] < heap[parentIndex]) {
                std::swap(heap[index], heap[parentIndex]);
                index = parentIndex;
            } else {
                break;
            }
        }
    }
    void heapifyDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int smallest = index;
        if (leftChild < heap.size() && heap[leftChild] < heap[smallest]) {
            smallest = leftChild;
        }
        if (rightChild < heap.size() && heap[rightChild] < heap[smallest]) {
            smallest = rightChild;
        }
        if (smallest != index) {
            std::swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }
public:
    void enqueue(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }
    int dequeue() {
        if (heap.empty()) {
            std::cout << "Priority Queue is empty.\n";
            return -1;
        }
        int frontValue = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return frontValue;
    }
    bool isEmpty() const {
        return heap.empty();
    }
};
int main() {
    PriorityQueue priorityQueue;
    int choice;
    do {
        std::cout << "1] Enqueue\n";
        std::cout << "2] Dequeue\n";
        std::cout << "3] Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1: {
                int value;
                std::cout << "Enter the value to enqueue: ";
                std::cin >> value;
                priorityQueue.enqueue(value);
                break;
            }
            case 2: {
                int frontValue = priorityQueue.dequeue();
                if (frontValue != -1) {
                    std::cout << "Dequeued value: " << frontValue << "\n";
                }
                break;
            }
            case 3:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);
    return 0;
}
