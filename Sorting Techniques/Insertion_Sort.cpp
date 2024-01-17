#include <iostream>
#include <vector>
void insertionSort(std::vector<int>& array) {
    int n = array.size();
    for (int i = 1; i < n; ++i) {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }
}
void displayArray(const std::vector<int>& array) {
    for (int value : array) {
        std::cout << value << " ";
    }
    std::cout << "\n";
}
int main() {
    std::vector<int> array = {12, 11, 13, 5, 6};
    std::cout << "Original Array: ";
    displayArray(array);
    insertionSort(array);
    std::cout << "Sorted Array: ";
    displayArray(array);
    return 0;
}
