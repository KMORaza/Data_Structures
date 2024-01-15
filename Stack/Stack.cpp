#include <iostream>
#include <vector>
class Stack {
private:
    std::vector<int> data;
public:
    void insert(int value) {
        data.push_back(value);
        std::cout << "Inserted: " << value << std::endl;
    }
    void deletion() {
        if (!data.empty()) {
            int deletedValue = data.back();
            data.pop_back();
            std::cout << "Deleted: " << deletedValue << std::endl;
        } else {
            std::cout << "Stack is empty. Cannot delete.\n";
        }
    }
    void update(int value) {
        if (!data.empty()) {
            data.back() = value;
            std::cout << "Updated top element to: " << value << std::endl;
        } else {
            std::cout << "Stack is empty. Cannot update.\n";
        }
    }
    void multiplication(int value) {
        if (!data.empty()) {
            data.back() *= value;
            std::cout << "Multiplied top element by: " << value << std::endl;
        } else {
            std::cout << "Stack is empty. Cannot multiply.\n";
        }
    }
    void display() {
        if (!data.empty()) {
            std::cout << "Stack elements: ";
            for (int i : data) {
                std::cout << i << " ";
            }
            std::cout << std::endl;
        } else {
            std::cout << "Stack is empty.\n";
        }
    }
    void lifo() {
        if (!data.empty()) {
            int topValue = data.back();
            std::cout << "Last-In-First-Out (LIFO) element: " << topValue << std::endl;
        } else {
            std::cout << "Stack is empty. Cannot perform LIFO.\n";
        }
    }
    void fifo() {
        if (!data.empty()) {
            int frontValue = data.front();
            std::cout << "First-In-First-Out (FIFO) element: " << frontValue << std::endl;
        } else {
            std::cout << "Stack is empty. Cannot perform FIFO.\n";
        }
    }
    void filo() {
        if (!data.empty()) {
            int frontValue = data.front();
            std::cout << "First-In-Last-Out (FILO) element: " << frontValue << std::endl;
        } else {
            std::cout << "Stack is empty. Cannot perform FILO.\n";
        }
    }
};
int main() {
    Stack myStack;
    int choice;
    do {
        std::cout << "\nOperations:\n"
                  << "1. Insertion\n"
                  << "2. Deletion\n"
                  << "3. Update\n"
                  << "4. Multiplication\n"
                  << "5. Display\n"
                  << "6. LIFO\n"
                  << "7. FIFO\n"
                  << "8. FILO\n"
                  << "9. Exit\n"
                  << "Enter your choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1: {
                int value;
                std::cout << "Enter the value to insert: ";
                std::cin >> value;
                myStack.insert(value);
                break;
            }
            case 2:
                myStack.deletion();
                break;
            case 3: {
                int value;
                std::cout << "Enter the value to update: ";
                std::cin >> value;
                myStack.update(value);
                break;
            }
            case 4: {
                int value;
                std::cout << "Enter the value to multiply: ";
                std::cin >> value;
                myStack.multiplication(value);
                break;
            }
            case 5:
                myStack.display();
                break;
            case 6:
                myStack.lifo();
                break;
            case 7:
                myStack.fifo();
                break;
            case 8:
                myStack.filo();
                break;
            case 9:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 9);
    return 0;
}
