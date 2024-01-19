#include <iostream>
#include <vector>
class BestFitAllocator {
public:
    BestFitAllocator(int totalMemory);
    int allocateMemory(int size);
    void deallocateMemory(int index);
    void displayMemoryMap() const;
private:
    int totalMemory;
    std::vector<int> memoryBlocks;
};
BestFitAllocator::BestFitAllocator(int totalMemory) : totalMemory(totalMemory) {
    memoryBlocks.push_back(totalMemory);
}
int BestFitAllocator::allocateMemory(int size) {
    int bestFitIndex = -1;
    int bestFitSize = totalMemory + 1;
    for (size_t i = 0; i < memoryBlocks.size(); ++i) {
        if (memoryBlocks[i] >= size && memoryBlocks[i] < bestFitSize) {
            bestFitIndex = i;
            bestFitSize = memoryBlocks[i];
        }
    }
    if (bestFitIndex != -1) {
        if (memoryBlocks[bestFitIndex] > size) {
            memoryBlocks.insert(memoryBlocks.begin() + bestFitIndex + 1, memoryBlocks[bestFitIndex] - size);
        }
        memoryBlocks[bestFitIndex] = size;
        return bestFitIndex;
    }
    std::cout << "Memory allocation failed for size " << size << ". No suitable block found." << std::endl;
    return -1;
}
void BestFitAllocator::deallocateMemory(int index) {
    if (index < 0 || index >= memoryBlocks.size()) {
        std::cout << "Invalid index for deallocation." << std::endl;
        return;
    }
    int freedSize = memoryBlocks[index];
    memoryBlocks.erase(memoryBlocks.begin() + index);
    size_t i = 0;
    while (i < memoryBlocks.size() - 1) {
        if (memoryBlocks[i] >= 0 && memoryBlocks[i + 1] >= 0) {
            memoryBlocks[i] += memoryBlocks[i + 1];
            memoryBlocks.erase(memoryBlocks.begin() + i + 1);
        } else {
            ++i;
        }
    }
    std::cout << "Memory block at index " << index << " deallocated. Freed size: " << freedSize << std::endl;
}
void BestFitAllocator::displayMemoryMap() const {
    std::cout << "Memory Map:" << std::endl;
    for (size_t i = 0; i < memoryBlocks.size(); ++i) {
        if (memoryBlocks[i] >= 0) {
            std::cout << "Block " << i << ": Allocated - Size: " << memoryBlocks[i] << std::endl;
        } else {
            std::cout << "Block " << i << ": Free - Size: " << -memoryBlocks[i] << std::endl;
        }
    }
    std::cout << std::endl;
}
int main() {
    BestFitAllocator allocator(100);
    int block1 = allocator.allocateMemory(20);
    int block2 = allocator.allocateMemory(30);
    int block3 = allocator.allocateMemory(10);
    allocator.displayMemoryMap();
    allocator.deallocateMemory(block2);
    allocator.displayMemoryMap();
    return 0;
}
