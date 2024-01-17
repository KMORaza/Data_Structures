#include <iostream>
#include <vector>
void gravitySort(std::vector<int>& arr, int n) {
    int maxVal = *std::max_element(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < maxVal; j++) {
            for (int k = 0; k < n; k++) {
                if (arr[k] > j) {
                    std::cout << "1 ";
                } else {
                    std::cout << "0 ";
                }
            }
            std::cout << std::endl;
        }
    }
    std::cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
int main() {
    std::vector<int> arr = {3, 7, 4, 8, 6, 2, 1, 5};
    int n = arr.size();
    std::cout << "Original Array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    gravitySort(arr, n);
    return 0;
}
