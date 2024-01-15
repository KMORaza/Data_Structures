#include <iostream>
#include <vector>
int binarySearch(const std::vector<int>& array, int target, int low, int high) {
    if (low > high) {
        return -1;
    }
    int mid = low + (high - low) / 2;
    if (array[mid] == target) {
        return mid;
    } else if (array[mid] > target) {
        return binarySearch(array, target, low, mid - 1);
    } else {
        return binarySearch(array, target, mid + 1, high);
    }
}
int main() {
    std::vector<int> sortedArray = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target;
    std::cout << "Enter the target value: ";
    std::cin >> target;
    int result = binarySearch(sortedArray, target, 0, sortedArray.size() - 1);
    if (result != -1) {
        std::cout << "Element found at index " << result << std::endl;
    } else {
        std::cout << "Element not found in the array." << std::endl;
    }
    return 0;
}
