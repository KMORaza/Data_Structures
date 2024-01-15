#include <iostream>
class Stack {
private:
    static const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int top;
public:
    Stack() : top(-1) {}
    bool isEmpty() {
        return top == -1;
    }
    bool isFull() {
        return top == MAX_SIZE - 1;
    }
    void push(int value) {
        if (isFull()) {
            std::cout << "Stack Overflow. Cannot push element onto a full stack.\n";
            return;
        }
        arr[++top] = value;
        std::cout << "Pushed: " << value << std::endl;
    }
    void pop() {
        if (isEmpty()) {
            std::cout << "Stack Underflow. Cannot pop element from an empty stack.\n";
            return;
        }
        int poppedValue = arr[top--];
        std::cout << "Popped: " << poppedValue << std::endl;
    }
    void display() {
        if (isEmpty()) {
            std::cout << "Stack is empty.\n";
            return;
        }
        std::cout << "Stack elements: ";
        for (int i = 0; i <= top; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};
int main() {
    Stack myStack;
    myStack.push(5);
    myStack.push(10);
    myStack.push(15);
    myStack.display();
    myStack.pop();
    myStack.display();
    myStack.pop();
    myStack.display();
    myStack.pop(); 
    myStack.display();
    return 0;
}
