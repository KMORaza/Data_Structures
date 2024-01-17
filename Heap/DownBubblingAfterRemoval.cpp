#include <iostream>
#include <vector>
class MinHeap {
private:
    std::vector<int> heap;
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
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }
    int removeMin() {
        if (heap.empty()) {
            std::cerr << "Heap is empty. Cannot remove minimum.\n";
            return -1;
        }
        int minValue = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return minValue;
    }
    void display() const {
        for (int value : heap) {
            std::cout << value << " ";
        }
        std::cout << "\n";
    }
};
int main() {
    MinHeap minHeap;
    minHeap.insert(4);
    minHeap.display();
    minHeap.insert(8);
    minHeap.display();
    minHeap.insert(2);
    minHeap.display();
    minHeap.insert(5);
    minHeap.display();
    minHeap.insert(1);
    minHeap.display();
    int minValue = minHeap.removeMin();
    if (minValue != -1) {
        std::cout << "Removed minimum value: " << minValue << "\n";
        minHeap.display();
    }
    return 0;
}
