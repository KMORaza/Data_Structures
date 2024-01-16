#include <iostream>
template <typename T, std::size_t MaxSize>
class Positional_List_using_Array {
private:
    T elements[MaxSize];
    std::size_t size;
public:
    Positional_List_using_Array() : size(0) {}
    void insertAtPosition(const T& element, std::size_t position) {
        if (position >= MaxSize || size >= MaxSize) {
            std::cout << "Invalid position or list is full." << std::endl;
            return;
        }
        for (std::size_t i = size; i > position; --i) {
            elements[i] = elements[i - 1];
        }
        elements[position] = element;
        ++size;
    }
    void display() const {
        for (std::size_t i = 0; i < size; ++i) {
            std::cout << elements[i] << " ";
        }
        std::cout << std::endl;
    }
};
int main() {
    Positional_List_using_Array<int, 5> myList;
    myList.insertAtPosition(1, 0);
    myList.insertAtPosition(2, 1);
    myList.insertAtPosition(3, 1);
    myList.insertAtPosition(4, 0);
    myList.display();
    return 0;
}
