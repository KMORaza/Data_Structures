#include <iostream>
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
    std::cout << "The elements of the array are: ";
    for (int i = 0; i < size; ++i) {
        std::cout << myArray[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
