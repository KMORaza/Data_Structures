#include <iostream>
void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}
int main() {
    std::cout << "Enter the size of the array: ";
    int size;
    std::cin >> size;
    int myArray[size];
    std::cout << "Enter " << size << " elements for the array:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << "Element " << i + 1 << ": ";
        std::cin >> myArray[i];
    }
    insertionSort(myArray, size);
    std::cout << "Sorted array using Insertion Sort: ";
    for (int i = 0; i < size; ++i) {
        std::cout << myArray[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
