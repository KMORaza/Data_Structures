#pragma once
#include "Node.h"
class DoublyLinkedList {
protected:
    Node* head;
public:
    DoublyLinkedList();
    void insertAtBeginning(int value);
    void insertAtEnd(int value);
    void deleteNode(int value);
    void traverseList();
    void reverseList();
    void multiplyList(int factor);
    Node* search(int value);
    void displayList();
    void concatenateLists(DoublyLinkedList& otherList);
    std::pair<DoublyLinkedList, DoublyLinkedList> splitList();
    bool detectCycle();
};
