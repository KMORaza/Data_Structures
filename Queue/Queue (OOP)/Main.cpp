#include "Queue.h"
#include <iostream>
int main() {
    Queue myQueue;
    int choice;
    do {
        std::cout << "Operations:\n";
        std::cout << "1] Enqueue\n";
        std::cout << "2] Dequeue\n";
        std::cout << "3] Display\n";
        std::cout << "4] Reverse\n";
        std::cout << "5] Search\n";
        std::cout << "6] Update\n";
        std::cout << "7] Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1: {
                int value;
                std::cout << "Enter the value to enqueue: ";
                std::cin >> value;
                myQueue.enqueue(value);
                break;
            }
            case 2:
                myQueue.dequeue();
                break;
            case 3:
                myQueue.display();
                break;
            case 4:
                myQueue.reverse();
                break;
            case 5: {
                int value;
                std::cout << "Enter the value to search: ";
                std::cin >> value;
                if (myQueue.search(value)) {
                    std::cout << "Value found in the queue.\n";
                } else {
                    std::cout << "Value not found in the queue.\n";
                }
                break;
            }
            case 6: {
                int oldValue, newValue;
                std::cout << "Enter the value to update: ";
                std::cin >> oldValue;
                std::cout << "Enter the new value: ";
                std::cin >> newValue;
                myQueue.update(oldValue, newValue);
                break;
            }
            case 7:
                std::cout << "Exiting the program.\n";
                break;
            default:
                std::cout << "Invalid option.\n";
        }
    } while (choice != 7);
    return 0;
}
