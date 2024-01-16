#pragma once
class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int value);
};
class Deque {
private:
    Node* front;
    Node* rear;
public:
    Deque();
    ~Deque();
    bool isEmpty();
    void insertFront(int element);
    void insertRear(int element);
    void deleteFront();
    void deleteRear();
    int getFront();
    int getRear();
    void multiply(int factor);
    void split(Deque& secondDeque);
    void reverse();
    void traverse();
    bool search(int element);
    void update(int oldElement, int newElement);
};
