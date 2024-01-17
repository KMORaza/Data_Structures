#include <iostream>
#include <vector>
void stoogeSort(std::vector<int>& arr, int low, int high) {
    if (low >= high) {
        return;
    }
    if (arr[low] > arr[high]) {
        std::swap(arr[low], arr[high]);
    }
    if (high - low + 1 > 2) {
        int t = (high - low + 1) / 3;
        stoogeSort(arr, low, high - t);
        stoogeSort(arr, low + t, high);
        stoogeSort(arr, low, high - t);
    }
}
int main() {
    std::vector<int> arr = {5, 2, 9, 1, 5, 6};
    std::cout << "Original Array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    stoogeSort(arr, 0, arr.size() - 1);
    std::cout << "\nSorted Array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    return 0;
}
