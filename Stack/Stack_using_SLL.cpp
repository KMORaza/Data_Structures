// Implementing stack using singly linked list
#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};
class Stack {
private:
    Node* top;
public:
    Stack() : top(nullptr) {}
    bool isEmpty() {
        return top == nullptr;
    }
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        std::cout << "Pushed: " << value << std::endl;
    }
    void pop() {
        if (isEmpty()) {
            std::cout << "Stack Underflow. Cannot pop element from an empty stack.\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        int poppedValue = temp->data;
        delete temp;
        std::cout << "Popped: " << poppedValue << std::endl;
    }
    void display() {
        if (isEmpty()) {
            std::cout << "Stack is empty.\n";
            return;
        }
        std::cout << "Stack elements: ";
        Node* current = top;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
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
