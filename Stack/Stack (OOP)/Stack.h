#ifndef STACK_H
#define STACK_H
#include "Node.h"
class Stack {
private:
    Node* top;
public:
    // Constructor
    Stack();
    // Destructor
    ~Stack();
    // Check if the stack is empty
    bool isEmpty() const;
    // Push an element onto the stack
    void push(int value);
    // Pop an element from the stack
    void pop();
    // Reverse the stack
    void reverse();
    // Traverse the stack
    void traverse() const;
    // Update an element in the stack
    void update(int oldValue, int newValue);
    // Display the elements in the stack
    void display() const;
    // Split the stack into two halves
    void split(Stack& stack2);
};
#endif
