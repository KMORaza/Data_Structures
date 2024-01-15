// Merge sort for SLL
#include <iostream>
struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};
Node* insertAtEnd(Node* head, int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        return newNode;
    }
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}
Node* merge(Node* list1, Node* list2) {
    Node* dummy = new Node(0);
    Node* current = dummy;
    while (list1 != nullptr && list2 != nullptr) {
        if (list1->data < list2->data) {
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }
    current->next = (list1 != nullptr) ? list1 : list2;
    Node* mergedList = dummy->next;
    delete dummy;
    return mergedList;
}
Node* mergeSort(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    Node* slow = head;
    Node* fast = head->next;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* secondHalf = slow->next;
    slow->next = nullptr; 
    Node* sortedFirstHalf = mergeSort(head);
    Node* sortedSecondHalf = mergeSort(secondHalf);
    return merge(sortedFirstHalf, sortedSecondHalf);
}
void displayList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
void deleteList(Node* head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
int main() {
    Node* head = nullptr;
    int n, value;
    std::cout << "Enter the number of nodes in the linked list: ";
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cout << "Enter the value for node " << i + 1 << ": ";
        std::cin >> value;
        head = insertAtEnd(head, value);
    }
    std::cout << "Original linked list: ";
    displayList(head);
    head = mergeSort(head);
    std::cout << "Sorted linked list: ";
    displayList(head);
    deleteList(head);
    return 0;
}
