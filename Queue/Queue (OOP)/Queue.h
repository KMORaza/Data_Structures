#ifndef QUEUE_H
#define QUEUE_H
#include "Node.h"
class Queue {
private:
    Node* rear;
public:
    Queue();
    ~Queue();
    bool isEmpty();
    void enqueue(int item);
    void dequeue();
    void display();
    void reverse();
    void traverse();
    bool search(int item);
    void update(int oldValue, int newValue);
};
#endif 
