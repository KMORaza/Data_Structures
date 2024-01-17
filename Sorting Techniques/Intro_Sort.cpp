#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
void insertionSort(std::vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}
int partition(std::vector<int>& arr, int left, int right) {
    int pivot = arr[right];
    int i = left - 1;
    for (int j = left; j < right; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[right]);
    return i + 1;
}
void quickSort(std::vector<int>& arr, int left, int right, int depthLimit) {
    while (right - left > 16) {
        if (depthLimit == 0) {
            std::make_heap(arr.begin() + left, arr.begin() + right + 1);
            std::sort_heap(arr.begin() + left, arr.begin() + right + 1);
            return;
        }
        --depthLimit;
        int pivotIndex = partition(arr, left, right);
        if (pivotIndex - left < right - pivotIndex) {
            quickSort(arr, left, pivotIndex - 1, depthLimit);
            left = pivotIndex + 1;
        } else {
            quickSort(arr, pivotIndex + 1, right, depthLimit);
            right = pivotIndex - 1;
        }
    }
    insertionSort(arr, left, right);
}
void introSort(std::vector<int>& arr) {
    int depthLimit = 2 * static_cast<int>(log2(arr.size()));
    quickSort(arr, 0, arr.size() - 1, depthLimit);
}
int main() {
    std::vector<int> arr = {4, 2, 7, 1, 9, 3, 5, 8, 6};
    std::cout << "Original Array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    introSort(arr);
    std::cout << "\nSorted Array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    return 0;
}
