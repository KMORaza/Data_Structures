#include <iostream>
template <typename T, std::size_t MaxSize>
class ArrayIterator {
private:
    T elements[MaxSize];
    std::size_t size;
public:
    ArrayIterator() : size(0) {}
    void insert(const T& element) {
        if (size < MaxSize) {
            elements[size++] = element;
        } else {
            std::cout << "Array is full." << std::endl;
        }
    }
    class Iterator {
    private:
        T* current;
    public:
        Iterator(T* start) : current(start) {}
        T& operator*() const {
            return *current;
        }
        Iterator& operator++() {
            ++current;
            return *this;
        }
        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }
    };
    Iterator begin() {
        return Iterator(elements);
    }
    Iterator end() {
        return Iterator(elements + size);
    }
};
int main() {
    ArrayIterator<int, 5> myArray;
    myArray.insert(1);
    myArray.insert(2);
    myArray.insert(3);
    for (auto it = myArray.begin(); it != myArray.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    return 0;
}
