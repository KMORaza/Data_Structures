// Implementing array with all operations
#include <iostream>
const int MAX_SIZE = 100;
void displayArray(int arr[], int size) {
    std::cout << "Array elements: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
void addElement(int arr[], int& size) {
    if (size < MAX_SIZE) {
        std::cout << "Enter the element to add: ";
        std::cin >> arr[size];
        ++size;
        std::cout << "Element added successfully." << std::endl;
    } else {
        std::cout << "Array is full. Cannot add more elements." << std::endl;
    }
}
void deleteElement(int arr[], int& size) {
    if (size > 0) {
        std::cout << "Enter the index of the element to delete (0 to " << size - 1 << "): ";
        int index;
        std::cin >> index;
        if (index >= 0 && index < size) {
            for (int i = index; i < size - 1; ++i) {
                arr[i] = arr[i + 1];
            }
            --size;
            std::cout << "Element deleted successfully." << std::endl;
        } else {
            std::cout << "Invalid index. Please enter a valid index." << std::endl;
        }
    } else {
        std::cout << "Array is empty. Cannot delete elements." << std::endl;
    }
}
void updateElement(int arr[], int size) {
    if (size > 0) {
        std::cout << "Enter the index of the element to update (0 to " << size - 1 << "): ";
        int index;
        std::cin >> index;
        if (index >= 0 && index < size) {
            std::cout << "Enter the new value: ";
            std::cin >> arr[index];
            std::cout << "Element updated successfully." << std::endl;
        } else {
            std::cout << "Invalid index. Please enter a valid index." << std::endl;
        }
    } else {
        std::cout << "Array is empty. Cannot update elements." << std::endl;
    }
}
int main() {
    int myArray[MAX_SIZE];
    int size = 0;
    int choice;
    do {
        std::cout << "\nMenu:" << std::endl;
        std::cout << "1. Display Array" << std::endl;
        std::cout << "2. Add Element" << std::endl;
        std::cout << "3. Delete Element" << std::endl;
        std::cout << "4. Update Element" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1:
                displayArray(myArray, size);
                break;
            case 2:
                addElement(myArray, size);
                break;
            case 3:
                deleteElement(myArray, size);
                break;
            case 4:
                updateElement(myArray, size);
                break;
            case 5:
                std::cout << "Exiting the application" << std::endl;
                break;
            default:
                std::cout << "Invalid option." << std::endl;
        }

    } while (choice != 5);

    return 0;
}
