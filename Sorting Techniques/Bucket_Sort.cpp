#include <iostream>
#include <vector>
#include <algorithm>
void bucketSort(std::vector<float>& arr) {
    int n = arr.size();
    std::vector<std::vector<float>> buckets(n);
    for (int i = 0; i < n; ++i) {
        int bucketIndex = n * arr[i];
        buckets[bucketIndex].push_back(arr[i]);
    }
    for (int i = 0; i < n; ++i) {
        std::sort(buckets[i].begin(), buckets[i].end());
    }
    int index = 0;
    for (int i = 0; i < n; ++i) {
        for (float value : buckets[i]) {
            arr[index++] = value;
        }
    }
}
void displayArray(const std::vector<float>& arr) {
    for (float value : arr) {
        std::cout << value << " ";
    }
    std::cout << "\n";
}
int main() {
    std::vector<float> arr = {0.42, 0.32, 0.33, 0.52, 0.37, 0.47, 0.51};
    std::cout << "Original Array: ";
    displayArray(arr);
    bucketSort(arr);
    std::cout << "Sorted Array: ";
    displayArray(arr);
    return 0;
}
