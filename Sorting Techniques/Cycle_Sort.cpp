#include <iostream>
void cycleSort(int arr[], int n) {
    for (int cycleStart = 0; cycleStart < n - 1; ++cycleStart) {
        int item = arr[cycleStart];
        int pos = cycleStart;
        for (int i = cycleStart + 1; i < n; ++i) {
            if (arr[i] < item) {
                ++pos;
            }
        }
        if (pos == cycleStart) {
            continue; 
        }
        while (item == arr[pos]) {
            ++pos;
        }
        std::swap(item, arr[pos]);
        while (pos != cycleStart) {
            pos = cycleStart;
            for (int i = cycleStart + 1; i < n; ++i) {
                if (arr[i] < item) {
                    ++pos;
                }
            }
            while (item == arr[pos]) {
                ++pos;
            }
            std::swap(item, arr[pos]);
        }
    }
}
int main() {
    int arr[] = {5, 2, 1, 4, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    std::cout << "Original Array: ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    cycleSort(arr, n);
    std::cout << "\nSorted Array: ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    return 0;
}
