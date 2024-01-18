#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
template <typename T>
int partition(std::vector<T>& arr, int low, int high) {
    int randomIndex = low + rand() % (high - low + 1);
    std::swap(arr[randomIndex], arr[high]);
    T pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}
template <typename T>
T randomizedQuickSelect(std::vector<T>& arr, int low, int high, int k) {
    if (low <= high) {
        int partitionIndex = partition(arr, low, high);
        if (partitionIndex == k) {
            return arr[partitionIndex];
        } else if (partitionIndex < k) {
            return randomizedQuickSelect(arr, partitionIndex + 1, high, k);
        } else {
            return randomizedQuickSelect(arr, low, partitionIndex - 1, k);
        }
    }
    std::cerr << "Error: Invalid value of k" << std::endl;
    exit(EXIT_FAILURE);
}
int main() {
    srand(static_cast<unsigned>(time(0)));
    std::vector<int> arr = {12, 3, 5, 7, 4, 19, 26};
    int k = 3; 
    int result = randomizedQuickSelect(arr, 0, arr.size() - 1, k - 1);
    std::cout << "The " << k << "-th smallest element is: " << result << std::endl;
    return 0;
}
