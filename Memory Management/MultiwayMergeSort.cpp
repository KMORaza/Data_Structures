#include <iostream>
#include <vector>
#include <queue>
struct Element {
    int value;
    int sequenceIndex;
    int elementIndex;
    Element(int val, int seqIdx, int elemIdx) : value(val), sequenceIndex(seqIdx), elementIndex(elemIdx) {}
    bool operator<(const Element& other) const {
        return value > other.value; 
    }
};
std::vector<int> multiwayMergeSort(const std::vector<std::vector<int>>& sequences) {
    std::priority_queue<Element> minHeap;
    for (int i = 0; i < sequences.size(); ++i) {
        if (!sequences[i].empty()) {
            minHeap.push(Element(sequences[i][0], i, 0));
        }
    }
    std::vector<int> sortedResult;
    while (!minHeap.empty()) {
        Element current = minHeap.top();
        minHeap.pop();
        sortedResult.push_back(current.value);
        if (current.elementIndex + 1 < sequences[current.sequenceIndex].size()) {
            minHeap.push(Element(
                sequences[current.sequenceIndex][current.elementIndex + 1],
                current.sequenceIndex,
                current.elementIndex + 1
            ));
        }
    }
    return sortedResult;
}
int main() {
    std::vector<std::vector<int>> sequences = {
        {1, 3, 5, 7},
        {2, 4, 6, 8},
        {0, 9, 10, 11}
    };
    std::vector<int> sortedResult = multiwayMergeSort(sequences);
    std::cout << "Sorted Result: ";
    for (int num : sortedResult) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}
