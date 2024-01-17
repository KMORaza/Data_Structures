#include <iostream>
#include <list>
class PriorityQueue {
private:
    std::list<int> sortedList;
public:
    bool isEmpty() const {
        return sortedList.empty();
    }
    void enqueue(int value) {
        auto it = sortedList.begin();
        while (it != sortedList.end() && *it < value) {
            ++it;
        }
        sortedList.insert(it, value);
    }
    int dequeue() {
        if (isEmpty()) {
            std::cerr << "Priority Queue is empty.\n";
            return -1;
        }
        int front = sortedList.front();
        sortedList.pop_front();
        return front;
    }
    void display() const {
        std::cout << "Priority Queue: ";
        for (int value : sortedList) {
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
