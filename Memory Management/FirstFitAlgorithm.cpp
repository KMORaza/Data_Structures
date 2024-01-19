#include <iostream>
#include <vector>
class FirstFitAllocator {
public:
    FirstFitAllocator(int totalMemory);
    int allocateMemory(int size);
    void deallocateMemory(int index);
    void displayMemoryMap() const;
private:
    int totalMemory;
    std::vector<int> memoryBlocks;
};
FirstFitAllocator::FirstFitAllocator(int totalMemory) : totalMemory(totalMemory) {
    memoryBlocks.push_back(totalMemory);
}
int FirstFitAllocator::allocateMemory(int size) {
    for (size_t i = 0; i < memoryBlocks.size(); ++i) {
        if (memoryBlocks[i] >= size) {
            if (memoryBlocks[i] > size) {
                memoryBlocks.insert(memoryBlocks.begin() + i + 1, memoryBlocks[i] - size);
            }
            memoryBlocks[i] = size;
            return i;
        }
    }
    std::cout << "Memory allocation failed for size " << size << ". No suitable block found." << std::endl;
    return -1;
}
void FirstFitAllocator::deallocateMemory(int index) {
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
void FirstFitAllocator::displayMemoryMap() const {
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
    FirstFitAllocator allocator(100);
    int block1 = allocator.allocateMemory(20);
    int block2 = allocator.allocateMemory(30);
    int block3 = allocator.allocateMemory(10);
    allocator.displayMemoryMap();
    allocator.deallocateMemory(block2);
    allocator.displayMemoryMap();
    return 0;
}
