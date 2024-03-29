#include <iostream>
#include <vector>
template <typename T>
class Amortized_Analysis_of_Dynamic_Array {
private:
    std::vector<T> dynamicArray;
public:
    Amortized_Analysis_of_Dynamic_Array() {
        dynamicArray.reserve(1);
    }
    void addElement(const T& element) {
        dynamicArray.push_back(element);
        if (dynamicArray.size() == dynamicArray.capacity()) {
            dynamicArray.reserve(2 * dynamicArray.capacity());
            std::cout << "Resizing: New Capacity = " << dynamicArray.capacity() << std::endl;
        }
    }
    void displayElements() {
        std::cout << "Dynamic Array Elements: ";
        for (const T& element : dynamicArray) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
};
int main() {
    Amortized_Analysis_of_Dynamic_Array<int> dynamicArray;
    for (int i = 1; i <= 10; ++i) {
        dynamicArray.addElement(i);
        dynamicArray.displayElements();
    }
    return 0;
}
