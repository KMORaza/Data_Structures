// Implementing Queue in C++ with major operations.
#include <iostream>
#include <queue>
void displayQueue(const std::queue<int>& q) {
    std::queue<int> temp = q;
    while (!temp.empty()) {
        std::cout << temp.front() << " ";
        temp.pop();
    }
    std::cout << std::endl;
}
int main() {
    std::queue<int> myQueue;
    while (true) {
        std::cout << "Select:\n";
        std::cout << "1] Insertion (Enqueue)\n";
        std::cout << "2] Deletion (Dequeue)\n";
        std::cout << "3] Splitting\n";
        std::cout << "4] Concatenation\n";
        std::cout << "5] Search\n";
        std::cout << "6] Update\n";
        std::cout << "7] Display\n";
        std::cout << "8] Reversal\n";
        std::cout << "9] Traversal\n";
        std::cout << "10] Exit\n";
        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1: {
                int value;
                std::cout << "Enter the value to insert (enqueue): ";
                std::cin >> value;
                myQueue.push(value);
                std::cout << value << " inserted into the queue.\n";
                break;
            }
            case 2: {
                if (!myQueue.empty()) {
                    std::cout << myQueue.front() << " deleted from the queue.\n";
                    myQueue.pop();
                } else {
                    std::cout << "Queue is empty. Cannot dequeue.\n";
                }
                break;
            }
            case 3: {
                std::queue<int> queue1, queue2;
                int size = myQueue.size();
                int splitIndex;
                std::cout << "Enter the index to split the queue (0 to " << size << "): ";
                std::cin >> splitIndex;
                if (splitIndex < 0 || splitIndex > size) {
                    std::cout << "Invalid index.\n";
                    break;
                }
                for (int i = 0; i < splitIndex; ++i) {
                    queue1.push(myQueue.front());
                    myQueue.pop();
                }
                while (!myQueue.empty()) {
                    queue2.push(myQueue.front());
                    myQueue.pop();
                }
                std::cout << "Queue split into two at index " << splitIndex << ".\n";
                std::cout << "Queue 1: ";
                displayQueue(queue1);
                std::cout << "Queue 2: ";
                displayQueue(queue2);
                break;
            }
            case 4: {
                std::queue<int> queue1, queue2;
                std::cout << "Enter elements for Queue 1 (Enter -1 to stop):\n";
                int value;
                while (true) {
                    std::cin >> value;
                    if (value == -1) {
                        break;
                    }
                    queue1.push(value);
                }
                std::cout << "Enter elements for Queue 2 (Enter -1 to stop):\n";
                while (true) {
                    std::cin >> value;
                    if (value == -1) {
                        break;
                    }
                    queue2.push(value);
                }
                while (!queue2.empty()) {
                    queue1.push(queue2.front());
                    queue2.pop();
                }
                std::cout << "Queues concatenated.\n";
                std::cout << "Resulting Queue: ";
                displayQueue(queue1);
                break;
            }
            case 5: {
                int value;
                std::cout << "Enter the value to search: ";
                std::cin >> value;
                std::queue<int> temp = myQueue;
                int position = 1;
                while (!temp.empty()) {
                    if (temp.front() == value) {
                        std::cout << "Value " << value << " found at position " << position << ".\n";
                        break;
                    }
                    temp.pop();
                    ++position;
                }
                if (temp.empty()) {
                    std::cout << "Value " << value << " not found in the queue.\n";
                }
                break;
            }
            case 6: {
                int oldValue, newValue;
                std::cout << "Enter the value to update: ";
                std::cin >> oldValue;
                std::cout << "Enter the new value: ";
                std::cin >> newValue;
                std::queue<int> temp = myQueue;
                while (!temp.empty()) {
                    if (temp.front() == oldValue) {
                        std::cout << "Updating value " << oldValue << " to " << newValue << ".\n";
                        break;
                    }
                    temp.pop();
                }

                if (temp.empty()) {
                    std::cout << "Value " << oldValue << " not found in the queue. Cannot update.\n";
                } else {
                    // Update the original queue
                    std::queue<int> updatedQueue;
                    while (!myQueue.empty()) {
                        if (myQueue.front() == oldValue) {
                            updatedQueue.push(newValue);
                        } else {
                            updatedQueue.push(myQueue.front());
                        }
                        myQueue.pop();
                    }
                    myQueue = updatedQueue;
                }
                break;
            }
            case 7: {
                std::cout << "Queue: ";
                displayQueue(myQueue);
                break;
            }
            case 8: {
                std::stack<int> tempStack;
                while (!myQueue.empty()) {
                    tempStack.push(myQueue.front());
                    myQueue.pop();
                }
                while (!tempStack.empty()) {
                    myQueue.push(tempStack.top());
                    tempStack.pop();
                }
                std::cout << "Queue reversed.\n";
                break;
            }
            case 9: {
                std::queue<int> temp = myQueue;
                std::cout << "Queue: ";
                displayQueue(temp);
                break;
            }
            case 10: {
                std::cout << "Exiting...\n";
                return 0;
            }
            default: {
                std::cout << "Invalid option.\n";
                break;
            }
        }
    }
    return 0;
}
