#include <iostream>
#include <vector>
void merge(std::vector<int>& array, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<int> leftArray(n1);
    std::vector<int> rightArray(n2);
    for (int i = 0; i < n1; ++i) {
        leftArray[i] = array[left + i];
    }
    for (int j = 0; j < n2; ++j) {
        rightArray[j] = array[mid + 1 + j];
    }
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            array[k] = leftArray[i];
            ++i;
        } else {
            array[k] = rightArray[j];
            ++j;
        }
        ++k;
    }
    while (i < n1) {
        array[k] = leftArray[i];
        ++i;
        ++k;
    }
    while (j < n2) {
        array[k] = rightArray[j];
        ++j;
        ++k;
    }
}
void mergeSort(std::vector<int>& array, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}
void displayArray(const std::vector<int>& array) {
    for (int value : array) {
        std::cout << value << " ";
    }
    std::cout << "\n";
}
int main() {
    std::vector<int> array = {64, 25, 12, 22, 11};
    std::cout << "Original Array: ";
    displayArray(array);
    mergeSort(array, 0, array.size() - 1);
    std::cout << "Sorted Array: ";
    displayArray(array);
    return 0;
}
