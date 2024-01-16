#include "Stack.h"
#include <iostream>
int main() {
    Stack myStack;
    myStack.push(5);
    myStack.push(10);
    myStack.push(15);
    std::cout << "Original Stack: ";
    myStack.display();
    myStack.reverse();
    std::cout << "Reversed Stack: ";
    myStack.display();
    myStack.update(10, 20);
    std::cout << "Stack after Update: ";
    myStack.display();
    Stack anotherStack;
    myStack.split(anotherStack);
    std::cout << "Original Stack after Split: ";
    myStack.display();
    std::cout << "New Stack after Split: ";
    anotherStack.display();
    return 0;
}
