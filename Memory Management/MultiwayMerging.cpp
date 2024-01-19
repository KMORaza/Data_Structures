#include <iostream>
#include <vector>
#include <queue>
struct Element {
    int value;
    int sequenceIndex;
    Element(int val, int seqIdx) : value(val), sequenceIndex(seqIdx) {}
    bool operator>(const Element& other) const {
        return value > other.value; 
    }
};
std::vector<int> multiwayMerge(const std::vector<std::vector<int>>& sequences) {
    std::priority_queue<Element, std::vector<Element>, std::greater<Element>> minHeap;
    for (int i = 0; i < sequences.size(); ++i) {
        if (!sequences[i].empty()) {
            minHeap.push(Element(sequences[i][0], i));
        }
    }
    std::vector<int> mergedResult;
    while (!minHeap.empty()) {
        Element current = minHeap.top();
        minHeap.pop();
        mergedResult.push_back(current.value);
        if (!sequences[current.sequenceIndex].empty()) {
            minHeap.push(Element(
                sequences[current.sequenceIndex].front(),
                current.sequenceIndex
            ));
            sequences[current.sequenceIndex].erase(sequences[current.sequenceIndex].begin());
        }
    }
    return mergedResult;
}
int main() {
    std::vector<std::vector<int>> sequences = {
        {1, 3, 5, 7},
        {2, 4, 6, 8},
        {0, 9, 10, 11}
    };
    std::vector<int> mergedResult = multiwayMerge(sequences);
    std::cout << "Merged Result: ";
    for (int num : mergedResult) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}
