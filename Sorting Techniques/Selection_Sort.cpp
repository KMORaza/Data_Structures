#include <iostream>
#include <vector>
void selectionSort(std::vector<int>& array) {
    int n = array.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(array[i], array[minIndex]);
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
    selectionSort(array);
    std::cout << "Sorted Array: ";
    displayArray(array);
    return 0;
}
