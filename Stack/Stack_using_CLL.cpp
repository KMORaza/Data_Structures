// Implementing stack using circular linked list
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
        if (isEmpty()) {
            newNode->next = newNode;
        } else {
            newNode->next = top->next;
            top->next = newNode;
        }
        top = newNode;
        std::cout << "Pushed: " << value << std::endl;
    }
    void pop() {
        if (isEmpty()) {
            std::cout << "Underflow!\n";
            return;
        }
        Node* temp = top;
        if (temp->next == temp) {
            top = nullptr; // Stack becomes empty
        } else {
            top->next = temp->next;
        }
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
        Node* current = top->next;
        do {
            std::cout << current->data << " ";
            current = current->next;
        } while (current != top->next);
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
