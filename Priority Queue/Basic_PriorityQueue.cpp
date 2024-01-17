#include <iostream>
#include <vector>
class PriorityQueue {
private:
    std::vector<int> heap;
    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index] > heap[parent]) {
                std::swap(heap[index], heap[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }
    void heapifyDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;
        if (leftChild < heap.size() && heap[leftChild] > heap[largest]) {
            largest = leftChild;
        }
        if (rightChild < heap.size() && heap[rightChild] > heap[largest]) {
            largest = rightChild;
        }
        if (largest != index) {
            std::swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }
public:
    bool isEmpty() const {
        return heap.empty();
    }
    void enqueue(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }
    int dequeue() {
        if (isEmpty()) {
            std::cerr << "Priority Queue is empty.\n";
            return -1;
        }
        int front = heap[0];
        std::swap(heap[0], heap.back());
        heap.pop_back();
        heapifyDown(0);
        return front;
    }
    void display() const {
        std::cout << "Priority Queue: ";
        for (int value : heap) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
};
int main() {
    PriorityQueue pq;
    pq.enqueue(5);
    pq.enqueue(2);
    pq.enqueue(8);
    pq.enqueue(1);
    pq.display();
    std::cout << "Dequeue: " << pq.dequeue() << std::endl;
    pq.display();
    return 0;
}
