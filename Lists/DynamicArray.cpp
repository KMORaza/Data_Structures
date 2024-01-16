#include <iostream>
int main() {
    int size;
    std::cout << "Enter the size of the dynamic array: ";
    std::cin >> size;
    int* dynamicArray = new int[size];
    for (int i = 0; i < size; ++i) {
        dynamicArray[i] = i * 10;
    }
    std::cout << "Dynamic Array Elements: ";
    for (int i = 0; i < size; ++i) {
        std::cout << dynamicArray[i] << " ";
    }
    delete[] dynamicArray;
    return 0;
}
