#include <iostream>
#include <vector>
template <typename T>
int pruneAndSearch(const std::vector<T>& arr, const T& target) {
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    for (int i = std::max(0, high); i < std::min(n, low + 1); ++i) {
        if (arr[i] == target) {
            return i; 
        }
    }
    return -1; 
}
int main() {
    std::vector<int> sortedArray = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 7;
    int index = pruneAndSearch(sortedArray, target);
    if (index != -1) {
        std::cout << "Element " << target << " found at index " << index << std::endl;
    } else {
        std::cout << "Element " << target << " not found in the array" << std::endl;
    }
    return 0;
}
