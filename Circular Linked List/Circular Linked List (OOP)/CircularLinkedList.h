#pragma once
#include "Node.h"
class CircularLinkedList {
private:
    Node* head;
public:
    CircularLinkedList();
    ~CircularLinkedList();
    void insertAtEnd(int value);
    void deleteNode(int value);
    void reverseList();
    void traverseList();
    void multiplyList(int factor);
    Node* search(int value);
    void displayList();
    void concatenateLists(CircularLinkedList& otherList);
    std::pair<CircularLinkedList, CircularLinkedList> splitList();
    bool detectCycle();
};
