#include <iostream>
#include <vector>
void flip(std::vector<int>& arr, int i) {
    int start = 0;
    while (start < i) {
        std::swap(arr[start], arr[i]);
        start++;
        i--;
    }
}
int findMaxIndex(const std::vector<int>& arr, int n) {
    int maxIndex = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}
void pancakeSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int currSize = n; currSize > 1; currSize--) {
        int maxIndex = findMaxIndex(arr, currSize);       
        if (maxIndex != currSize - 1) {
            flip(arr, maxIndex);
            flip(arr, currSize - 1);
        }
    }
}
int main() {
    std::vector<int> arr = {5, 2, 9, 1, 5, 6};   
    std::cout << "Original Array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    pancakeSort(arr);
    std::cout << "\nSorted Array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    return 0;
}
