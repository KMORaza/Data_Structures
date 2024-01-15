#include <iostream>
#include <cstdlib>
#include <ctime>
void generateRandomNumbers(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 100; 
    }
}
int main() {
    std::srand(std::time(0));
    std::cout << "Enter the size of the array: ";
    int size;
    std::cin >> size;
    int myArray[size];
    generateRandomNumbers(myArray, size);
    std::cout << "Generated array with pseudo-random numbers: ";
    for (int i = 0; i < size; ++i) {
        std::cout << myArray[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
