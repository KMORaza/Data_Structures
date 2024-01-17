#include <iostream>
#include <vector>
class MinHeap {
private:
    std::vector<int> heap;
    int getParentIndex(int index) {
        return (index - 1) / 2;
    }
    int getLeftChildIndex(int index) {
        return 2 * index + 1;
    }
    int getRightChildIndex(int index) {
        return 2 * index + 2;
    }
    void heapifyUp(int index) {
        while (index > 0 && heap[index] < heap[getParentIndex(index)]) {
            std::swap(heap[index], heap[getParentIndex(index)]);
            index = getParentIndex(index);
        }
    }
    void heapifyDown(int index) {
        int leftChildIndex = getLeftChildIndex(index);
        int rightChildIndex = getRightChildIndex(index);
        int smallest = index;
        if (leftChildIndex < heap.size() && heap[leftChildIndex] < heap[smallest]) {
            smallest = leftChildIndex;
        }
        if (rightChildIndex < heap.size() && heap[rightChildIndex] < heap[smallest]) {
            smallest = rightChildIndex;
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
    int extractMin() {
        if (heap.empty()) {
            std::cerr << "Heap is empty.\n";
            return -1;
        }
        int min = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return min;
    }
    void display() const {
        std::cout << "Heap: ";
        for (int value : heap) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
};
int main() {
    MinHeap minHeap;
    minHeap.insert(5);
    minHeap.insert(2);
    minHeap.insert(8);
    minHeap.insert(1);
    minHeap.display();
    std::cout << "Extract Min: " << minHeap.extractMin() << std::endl;
    minHeap.display();
    return 0;
}
