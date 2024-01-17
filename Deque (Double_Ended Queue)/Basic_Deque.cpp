#include <iostream>
#include <deque>
int main() {
    std::deque<int> myDeque;
    int choice, element;
    do {
        std::cout << "\nOperations:\n";
        std::cout << "1] Push Front\n";
        std::cout << "2] Push Back\n";
        std::cout << "3] Pop Front\n";
        std::cout << "4] Pop Back\n";
        std::cout << "5] Front\n";
        std::cout << "6] Back\n";
        std::cout << "7] Size\n";
        std::cout << "8] Check if empty\n";
        std::cout << "9] Clear\n";
        std::cout << "10] Display\n";
        std::cout << "11] Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1:
                std::cout << "Enter element to push front: ";
                std::cin >> element;
                myDeque.push_front(element);
                break;
            case 2:
                std::cout << "Enter element to push back: ";
                std::cin >> element;
                myDeque.push_back(element);
                break;
            case 3:
                if (!myDeque.empty()) {
                    myDeque.pop_front();
                    std::cout << "Front element popped.\n";
                } else {
                    std::cout << "Deque is empty.\n";
                }
                break;
            case 4:
                if (!myDeque.empty()) {
                    myDeque.pop_back();
                    std::cout << "Back element popped.\n";
                } else {
                    std::cout << "Deque is empty.\n";
                }
                break;
            case 5:
                if (!myDeque.empty()) {
                    std::cout << "Front element: " << myDeque.front() << "\n";
                } else {
                    std::cout << "Deque is empty.\n";
                }
                break;
            case 6:
                if (!myDeque.empty()) {
                    std::cout << "Back element: " << myDeque.back() << "\n";
                } else {
                    std::cout << "Deque is empty.\n";
                }
                break;
            case 7:
                std::cout << "Size of deque: " << myDeque.size() << "\n";
                break;
            case 8:
                std::cout << "Is deque empty? " << (myDeque.empty() ? "Yes" : "No") << "\n";
                break;
            case 9:
                myDeque.clear();
                std::cout << "Deque cleared.\n";
                break;
            case 10:
                if (!myDeque.empty()) {
                    std::cout << "Deque elements: ";
                    for (const auto& e : myDeque) {
                        std::cout << e << " ";
                    }
                    std::cout << "\n";
                } else {
                    std::cout << "Deque is empty.\n";
                }
                break;
            case 11:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid option.\n";
        }
    } while (choice != 11);
    return 0;
}
