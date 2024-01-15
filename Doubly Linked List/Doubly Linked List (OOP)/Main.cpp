#include "DoublyLinkedList.h"
int main() {
    DoublyLinkedList doublyList;
    doublyList.insertAtBeginning(3);
    doublyList.insertAtBeginning(2);
    doublyList.insertAtBeginning(1);
    doublyList.insertAtEnd(4);
    doublyList.insertAtEnd(5);
    std::cout << "Doubly Linked List: ";
    doublyList.traverseList();
    doublyList.deleteNode(2);
    doublyList.deleteNode(5);
    std::cout << "Updated Doubly Linked List: ";
    doublyList.traverseList();
    return 0;
}
