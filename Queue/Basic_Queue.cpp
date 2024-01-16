#include <iostream>
#include <queue>
int main() {
    std::queue<int> myQueue;
    while (true) {
        std::cout << "Select:\n";
        std::cout << "1] Enqueue\n";
        std::cout << "2] Dequeue\n";
        std::cout << "3] Front\n";
        std::cout << "4] Check if empty\n";
        std::cout << "5] Exit\n";
        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1: {
                int value;
                std::cout << "Enter the value to enqueue: ";
                std::cin >> value;
                myQueue.push(value);
                std::cout << value << " enqueued to the queue.\n";
                break;
            }
            case 2: {
                if (!myQueue.empty()) {
                    std::cout << myQueue.front() << " dequeued from the queue.\n";
                    myQueue.pop();
                } else {
                    std::cout << "Queue is empty. Cannot dequeue.\n";
                }
                break;
            }
            case 3: {
                if (!myQueue.empty()) {
                    std::cout << "Front element: " << myQueue.front() << std::endl;
                } else {
                    std::cout << "Queue is empty.\n";
                }
                break;
            }
            case 4: {
                if (myQueue.empty()) {
                    std::cout << "Queue is empty.\n";
                } else {
                    std::cout << "Queue is not empty.\n";
                }
                break;
            }
            case 5: {
                std::cout << "Exiting...\n";
                return 0;
            }
            default: {
                std::cout << "Invalid option!\n";
                break;
            }
        }
    }
    return 0;
}
