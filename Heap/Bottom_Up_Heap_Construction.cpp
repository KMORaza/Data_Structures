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
    void buildHeapBottomUp() {
        for (int i = (heap.size() - 1) / 2; i >= 0; --i) {
            heapifyDown(i);
        }
    }
public:
    MinHeap(const std::vector<int>& array) : heap(array) {
        buildHeapBottomUp();
    }
    void display() const {
        for (int value : heap) {
            std::cout << value << " ";
        }
        std::cout << "\n";
    }
};
int main() {
    std::vector<int> array = {4, 8, 2, 5, 1};
    MinHeap minHeap(array);
    std::cout << "Min Heap after Bottom-Up Heap Construction:\n";
    minHeap.display();
    return 0;
}
