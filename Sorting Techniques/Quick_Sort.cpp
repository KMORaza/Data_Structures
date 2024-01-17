#include <iostream>
#include <vector>
int partition(std::vector<int>& array, int low, int high) {
    int pivot = array[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (array[j] <= pivot) {
            i++;
            std::swap(array[i], array[j]);
        }
    }
    std::swap(array[i + 1], array[high]);
    return i + 1;
}
void quickSort(std::vector<int>& array, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(array, low, high);
        quickSort(array, low, pivotIndex - 1);
        quickSort(array, pivotIndex + 1, high);
    }
}
void displayArray(const std::vector<int>& array) {
    for (int value : array) {
        std::cout << value << " ";
    }
    std::cout << "\n";
}
int main() {
    std::vector<int> array = {64, 25, 12, 22, 11};
    std::cout << "Original Array: ";
    displayArray(array);
    quickSort(array, 0, array.size() - 1);
    std::cout << "Sorted Array: ";
    displayArray(array);
    return 0;
}
