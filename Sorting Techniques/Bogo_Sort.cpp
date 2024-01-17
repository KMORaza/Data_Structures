#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
bool isSorted(const std::vector<int>& arr) {
    return std::is_sorted(arr.begin(), arr.end());
}
void bogoSort(std::vector<int>& arr) {
    std::random_device rd;
    std::mt19937 g(rd());
    while (!isSorted(arr)) {
        std::shuffle(arr.begin(), arr.end(), g);
    }
}
int main() {
    std::vector<int> arr = {5, 2, 1, 4, 3};
    std::cout << "Original Array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    bogoSort(arr);
    std::cout << "\nSorted Array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    return 0;
}
