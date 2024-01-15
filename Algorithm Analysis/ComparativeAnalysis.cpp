#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
void bubbleSort(std::vector<int>& array) {
    int n = array.size();
    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < n-i-1; ++j) {
            if (array[j] > array[j+1]) {
                std::swap(array[j], array[j+1]);
            }
        }
    }
}
void quickSort(std::vector<int>& array, int low, int high) {
    if (low < high) {
        int pivot = array[high];
        int i = low - 1;
        for (int j = low; j <= high - 1; ++j) {
            if (array[j] < pivot) {
                ++i;
                std::swap(array[i], array[j]);
            }
        }
        std::swap(array[i + 1], array[high]);
        int pivotIndex = i + 1;
        quickSort(array, low, pivotIndex - 1);
        quickSort(array, pivotIndex + 1, high);
    }
}
int main() {
    std::vector<int> testArray(10000);
    std::generate(testArray.begin(), testArray.end(), []() { return rand() % 10000; });
    auto startBubble = std::chrono::high_resolution_clock::now();
    bubbleSort(testArray);
    auto stopBubble = std::chrono::high_resolution_clock::now();
    auto durationBubble = std::chrono::duration_cast<std::chrono::microseconds>(stopBubble - startBubble);
    std::cout << "Bubble Sort Time: " << durationBubble.count() << " microseconds\n";
    std::random_shuffle(testArray.begin(), testArray.end());
    auto startQuick = std::chrono::high_resolution_clock::now();
    quickSort(testArray, 0, testArray.size() - 1);
    auto stopQuick = std::chrono::high_resolution_clock::now();
    auto durationQuick = std::chrono::duration_cast<std::chrono::microseconds>(stopQuick - startQuick);
    std::cout << "Quick Sort Time: " << durationQuick.count() << " microseconds\n";
    return 0;
}
