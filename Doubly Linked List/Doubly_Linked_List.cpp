#include <iostream>
class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};
class DoublyLinkedList {
private:
    Node* head;
public:
    DoublyLinkedList() : head(nullptr) {}
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }
    void deleteNode(int value) {
        if (head == nullptr) {
            std::cout << "List is empty. Nothing to delete.\n";
            return;
        }
        Node* current = head;
        while (current != nullptr && current->data != value) {
            current = current->next;
        }
        if (current == nullptr) {
            std::cout << "Node with value " << value << " not found. Cannot delete.\n";
            return;
        }
        if (current->prev != nullptr) {
            current->prev->next = current->next;
        } else {
            // Deleting the head
            head = current->next;
        }
        if (current->next != nullptr) {
            current->next->prev = current->prev;
        }
        delete current;
        std::cout << "Node with value " << value << " deleted successfully.\n";
    }
    void traverseList() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << "\n";
    }
    void reverseList() {
        Node* current = head;
        Node* temp = nullptr;
        while (current != nullptr) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }
        if (temp != nullptr) {
            head = temp->prev;
        }
    }
    void multiplyList(int factor) {
        Node* current = head;

        while (current != nullptr) {
            current->data *= factor;
            current = current->next;
        }
        std::cout << "List multiplied by " << factor << ".\n";
    }
    Node* search(int value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }
    void displayList() {
        traverseList();
    }
    void concatenateLists(DoublyLinkedList& otherList) {
        if (head == nullptr) {
            head = otherList.head;
        } else if (otherList.head != nullptr) {
            Node* last = head;
            while (last->next != nullptr) {
                last = last->next;
            }
            last->next = otherList.head;
            otherList.head->prev = last;
        }
        otherList.head = nullptr; // Avoid memory leak in the destructor
        std::cout << "Lists concatenated successfully.\n";
    }
    std::pair<DoublyLinkedList, DoublyLinkedList> splitList() {
        DoublyLinkedList firstHalf;
        DoublyLinkedList secondHalf;
        Node* slow = head;
        Node* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            firstHalf.insertAtEnd(slow->data);
            slow = slow->next;
            fast = fast->next->next;
        }
        while (slow != nullptr) {
            secondHalf.insertAtEnd(slow->data);
            slow = slow->next;
        }
        std::cout << "List split into two halves.\n";
        return {firstHalf, secondHalf};
    }
    bool detectCycle() {
        Node* slow = head;
        Node* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                std::cout << "Cycle detected in the list.\n";
                return true;
            }
        }
        std::cout << "No cycle detected in the list.\n";
        return false;
    }
};
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
    std::cout << "Reversed Doubly Linked List: ";
    doublyList.reverseList();
    doublyList.traverseList();
    doublyList.multiplyList(2);
    std::cout << "Doubly Linked List after multiplication: ";
    doublyList.traverseList();
    Node* searchResult = doublyList.search(8);
    if (searchResult != nullptr) {
        std::cout << "Node found with value 8.\n";
    } else {
        std::cout << "Node not found with value 8.\n";
    }
    std::cout << "Concatenating Doubly Linked Lists:\n";
    DoublyLinkedList secondList;
    secondList.insertAtEnd(6);
    secondList.insertAtEnd(7);
    secondList.insertAtEnd(8);
    secondList.insertAtEnd(9);
    std::cout << "Second Doubly Linked List: ";
    secondList.traverseList();
    doublyList.concatenateLists(secondList);
    std::cout << "Updated Doubly Linked List after concatenation: ";
    doublyList.traverseList();
    std::pair<DoublyLinkedList, DoublyLinkedList> splitLists = doublyList.splitList();
    std::cout << "First Half of the List: ";
    splitLists.first.traverseList();
    std::cout << "Second Half of the List: ";
    splitLists.second.traverseList();
    doublyList.detectCycle();
    return 0;
}
