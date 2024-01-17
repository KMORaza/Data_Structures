#include <iostream>
#include <vector>
void librarySort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int item = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > item) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = item;
    }
}
int main() {
    std::vector<int> arr = {5, 2, 1, 4, 3};
    std::cout << "Original Array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    librarySort(arr);
    std::cout << "\nSorted Array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    return 0;
}
