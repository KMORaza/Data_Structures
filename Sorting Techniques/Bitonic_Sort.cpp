#include <iostream>
#include <vector>
void bitonicMerge(std::vector<int>& arr, int low, int count, bool order) {
    if (count > 1) {
        int k = count / 2;
        for (int i = low; i < low + k; ++i) {
            if ((arr[i] > arr[i + k]) == order) {
                std::swap(arr[i], arr[i + k]);
            }
        }
        bitonicMerge(arr, low, k, order);
        bitonicMerge(arr, low + k, k, order);
    }
}
void bitonicSort(std::vector<int>& arr, int low, int count, bool order) {
    if (count > 1) {
        int k = count / 2;
        bitonicSort(arr, low, k, true);
        bitonicSort(arr, low + k, k, false);
        bitonicMerge(arr, low, count, order);
    }
}
void bitonicSortWrapper(std::vector<int>& arr, bool order) {
    int n = arr.size();
    bitonicSort(arr, 0, n, order);
}
int main() {
    std::vector<int> arr = {3, 7, 4, 8, 6, 2, 1, 5};
    std::cout << "Original Array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    bitonicSortWrapper(arr, true);
    std::cout << "\nSorted Array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    return 0;
}
