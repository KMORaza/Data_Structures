#include "Deque.h"
int main() {
    Deque myDeque;
    Deque secondDeque;
    int choice, element;
    do {
        std::cout << "\nOperations:\n";
        std::cout << "1] Insert Front\n";
        std::cout << "2] Insert Rear\n";
        std::cout << "3] Delete Front\n";
        std::cout << "4] Delete Rear\n";
        std::cout << "5] Get Front\n";
        std::cout << "6] Get Rear\n";
        std::cout << "7] Multiply\n";
        std::cout << "8] Split\n";
        std::cout << "9] Reverse\n";
        std::cout << "10] Traverse\n";
        std::cout << "11] Search\n";
        std::cout << "12] Update\n";
        std::cout << "13] Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1:
                std::cout << "Enter element to insert at front: ";
                std::cin >> element;
                myDeque.insertFront(element);
                break;
            case 2:
                std::cout << "Enter element to insert at rear: ";
                std::cin >> element;
                myDeque.insertRear(element);
                break;
            case 3:
                myDeque.deleteFront();
                break;
            case 4:
                myDeque.deleteRear();
                break;
            case 5:
                std::cout << "Front element: " << myDeque.getFront() << "\n";
                break;
            case 6:
                std::cout << "Rear element: " << myDeque.getRear() << "\n";
                break;
            case 7:
                std::cout << "Enter factor to multiply: ";
                std::cin >> element;
                myDeque.multiply(element);
                break;
            case 8:
                myDeque.split(secondDeque);
                break;
            case 9:
                myDeque.reverse();
                break;
            case 10:
                myDeque.traverse();
                break;
            case 11:
                std::cout << "Enter element to search: ";
                std::cin >> element;
                if (myDeque.search(element)) {
                    std::cout << element << " found.\n";
                } else {
                    std::cout << element << " not found.\n";
                }
                break;
            case 12:
                int oldElement, newElement;
                std::cout << "Enter element to update: ";
                std::cin >> oldElement;
                std::cout << "Enter new element: ";
                std::cin >> newElement;
                myDeque.update(oldElement, newElement);
                break;
            case 13:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid option.\n";
        }
    } while (choice != 13);
    return 0;
}
