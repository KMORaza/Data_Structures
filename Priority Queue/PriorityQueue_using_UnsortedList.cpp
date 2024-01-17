#include <iostream>
#include <list>
#include <algorithm>  
class PriorityQueue {
private:
    std::list<int> unsortedList;
public:
    bool isEmpty() const {
        return unsortedList.empty();
    }
    void enqueue(int value) {
        unsortedList.push_back(value);
    }
    int dequeue() {
        if (isEmpty()) {
            std::cerr << "Priority Queue is empty.\n";
            return -1;
        }
        auto itMax = std::max_element(unsortedList.begin(), unsortedList.end());
        int maxVal = *itMax;
        unsortedList.erase(itMax);
        return maxVal;
    }
    void display() const {
        std::cout << "Priority Queue: ";
        for (int value : unsortedList) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
};
int main() {
    PriorityQueue pq;
    pq.enqueue(5);
    pq.enqueue(2);
    pq.enqueue(8);
    pq.enqueue(1);
    pq.display();
    std::cout << "Dequeue: " << pq.dequeue() << std::endl;
    pq.display();
    return 0;
}
