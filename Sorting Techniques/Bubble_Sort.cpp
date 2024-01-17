#include <iostream>
#include <vector>
void bubbleSort(std::vector<int>& array) {
    int n = array.size();
    bool swapped;
    for (int i = 0; i < n - 1; ++i) {
        swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                std::swap(array[j], array[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}
void displayArray(const std::vector<int>& array) {
    for (int value : array) {
        std::cout << value << " ";
    }
    std::cout << "\n";
}
int main() {
    std::vector<int> array = {64, 34, 25, 12, 22, 11, 90};
    std::cout << "Original Array: ";
    displayArray(array);
    bubbleSort(array);
    std::cout << "Sorted Array: ";
    displayArray(array);
    return 0;
}
