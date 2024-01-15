#include <iostream>
#include "CircularLinkedList.h"
int main() {
    CircularLinkedList circularList;
    CircularLinkedList otherList;
    // Insertion operations
    circularList.insertAtEnd(1);
    circularList.insertAtEnd(2);
    circularList.insertAtEnd(3);
    otherList.insertAtEnd(4);
    otherList.insertAtEnd(5);
    // Display original lists
    std::cout << "Circular List 1: ";
    circularList.displayList();
    std::cout << "Circular List 2: ";
    otherList.displayList();
    // Concatenation
    circularList.concatenateLists(otherList);
    // Display concatenated list
    std::cout << "Concatenated List: ";
    circularList.displayList();
    // Splitting
    auto [firstHalf, secondHalf] = circularList.splitList();
    // Display split lists
    std::cout << "First Half: ";
    firstHalf.displayList();
    std::cout << "Second Half: ";
    secondHalf.displayList();
    // Reversal
    circularList.reverseList();
    // Display reversed list
    std::cout << "Reversed List: ";
    circularList.displayList();
    // Multiplication
    circularList.multiplyList(2);
    // Display multiplied list
    std::cout << "Multiplied List: ";
    circularList.displayList();
    // Search and Update
    Node* searchResult = circularList.search(6);
    if (searchResult) {
        std::cout << "Node found. Updating...\n";
        circularList.updateNode(6, 10);
    } else {
        std::cout << "Node not found.\n";
    }
    // Display updated list
    std::cout << "Updated List: ";
    circularList.displayList();
    // Detect cycle
    bool hasCycle = circularList.detectCycle();
    if (hasCycle) {
        std::cout << "The list contains a cycle.\n";
    } else {
        std::cout << "The list does not contain a cycle.\n";
    }
    return 0;
}
