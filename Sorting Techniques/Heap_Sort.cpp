#include <iostream>
#include <vector>

void heapify(std::vector<int>& array, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && array[left] > array[largest]) {
        largest = left;
    }

    if (right < n && array[right] > array[largest]) {
        largest = right;
    }

    if (largest != i) {
        std::swap(array[i], array[largest]);
        heapify(array, n, largest);
    }
}

void heapSort(std::vector<int>& array) {
    int n = array.size();

    // Build max heap
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(array, n, i);
    }

    // Extract elements one by one from the heap
    for (int i = n - 1; i > 0; --i) {
        std::swap(array[0], array[i]);
        heapify(array, i, 0);
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

    heapSort(array);

    std::cout << "Sorted Array: ";
    displayArray(array);

    return 0;
}
