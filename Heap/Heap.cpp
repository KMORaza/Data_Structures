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
    void deleteKey(int key) {
        auto it = std::find(heap.begin(), heap.end(), key);
        if (it != heap.end()) {
            int index = std::distance(heap.begin(), it);
            heap[index] = heap.back();
            heap.pop_back();
            heapifyDown(index);
        } else {
            std::cout << "Element not found in the heap.\n";
        }
    }
    int extractMin() {
        if (heap.empty()) {
            std::cout << "Heap is empty.\n";
            return -1;
        }
        int minValue = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return minValue;
    }
    void updateKey(int oldKey, int newKey) {
        deleteKey(oldKey);
        insert(newKey);
    }
    void display() {
        std::cout << "Heap: ";
        for (int value : heap) {
            std::cout << value << " ";
        }
        std::cout << "\n";
    }
};
int main() {
    MinHeap minHeap;
    int choice;
    do {
        std::cout << "1] Insertion\n";
        std::cout << "2] Deletion\n";
        std::cout << "3] Extraction (Extract Min)\n";
        std::cout << "4] Update\n";
        std::cout << "5] Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1: {
                int value;
                std::cout << "Enter the value to insert: ";
                std::cin >> value;
                minHeap.insert(value);
                minHeap.display();
                break;
            }
            case 2: {
                int key;
                std::cout << "Enter the value to delete: ";
                std::cin >> key;
                minHeap.deleteKey(key);
                minHeap.display();
                break;
            }
            case 3: {
                int minValue = minHeap.extractMin();
                if (minValue != -1) {
                    std::cout << "Minimum value extracted: " << minValue << "\n";
                    minHeap.display();
                }
                break;
            }
            case 4: {
                int oldKey, newKey;
                std::cout << "Enter the value to update: ";
                std::cin >> oldKey;
                std::cout << "Enter the new value: ";
                std::cin >> newKey;
                minHeap.updateKey(oldKey, newKey);
                minHeap.display();
                break;
            }
            case 5:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);
    return 0;
}
