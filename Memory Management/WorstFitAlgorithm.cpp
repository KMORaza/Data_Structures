#include <iostream>
#include <vector>
class WorstFitAllocator {
public:
    WorstFitAllocator(int totalMemory);
    int allocateMemory(int size);
    void deallocateMemory(int index);
    void displayMemoryMap() const;
private:
    int totalMemory;
    std::vector<int> memoryBlocks;
};
WorstFitAllocator::WorstFitAllocator(int totalMemory) : totalMemory(totalMemory) {
    memoryBlocks.push_back(totalMemory);
}
int WorstFitAllocator::allocateMemory(int size) {
    int worstFitIndex = -1;
    int worstFitSize = -1;
    for (size_t i = 0; i < memoryBlocks.size(); ++i) {
        if (memoryBlocks[i] >= size && memoryBlocks[i] > worstFitSize) {
            worstFitIndex = i;
            worstFitSize = memoryBlocks[i];
        }
    }
    if (worstFitIndex != -1) {
        if (memoryBlocks[worstFitIndex] > size) {
            memoryBlocks.insert(memoryBlocks.begin() + worstFitIndex + 1, memoryBlocks[worstFitIndex] - size);
        }
        memoryBlocks[worstFitIndex] = size;
        return worstFitIndex;
    }
    std::cout << "Memory allocation failed for size " << size << ". No suitable block found." << std::endl;
    return -1;
}
void WorstFitAllocator::deallocateMemory(int index) {
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
void WorstFitAllocator::displayMemoryMap() const {
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
    WorstFitAllocator allocator(100);
    int block1 = allocator.allocateMemory(20);
    int block2 = allocator.allocateMemory(30);
    int block3 = allocator.allocateMemory(10);
    allocator.displayMemoryMap();
    allocator.deallocateMemory(block2);
    allocator.displayMemoryMap();
    return 0;
}
