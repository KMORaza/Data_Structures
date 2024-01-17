#include <iostream>
#include <vector>
class MinHeap {
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
public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
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
    return 0;
}
