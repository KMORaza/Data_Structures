 #include <iostream>
class Stack {
private:
    int* array;
    int capacity;
    int top;
public:
    Stack(int size) {
        capacity = size;
        array = new int[capacity];
        top = -1;
    }
    ~Stack() {
        delete[] array;
    }
    bool isEmpty() {
        return top == -1;
    }
    bool isFull() {
        return top == capacity - 1;
    }
    void push(int value) {
        if (isFull()) {
            std::cout << "Overflow.\n";
            return;
        }
        array[++top] = value;
        std::cout << "Pushed: " << value << std::endl;
    }
    void pop() {
        if (isEmpty()) {
            std::cout << "Underflow.\n";
            return;
        }
        int poppedValue = array[top--];
        std::cout << "Popped: " << poppedValue << std::endl;
    }
    void display() {
        if (isEmpty()) {
            std::cout << "Stack is empty.\n";
            return;
        }
        std::cout << "Stack elements: ";
        for (int i = 0; i <= top; ++i) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }
};
int main() {
    int size;
    std::cout << "Enter the size of the stack: ";
    std::cin >> size;
    Stack myStack(size);
    int choice;
    do {
        std::cout << "\nStack Operations:\n"
                  << "1. Push\n"
                  << "2. Pop\n"
                  << "3. Display\n"
                  << "0. Exit\n"
                  << "Enter your choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1: {
                int value;
                std::cout << "Enter the value to push: ";
                std::cin >> value;
                myStack.push(value);
                break;
            }
            case 2:
                myStack.pop();
                break;
            case 3:
                myStack.display();
                break;
            case 0:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);
    return 0;
}
