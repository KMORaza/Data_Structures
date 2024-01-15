// Quick sort in SLL
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
Node* getLastNode(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }
    while (head->next != nullptr) {
        head = head->next;
    }
    return head;
}
void swapData(Node* node1, Node* node2) {
    int temp = node1->data;
    node1->data = node2->data;
    node2->data = temp;
}
Node* partition(Node* low, Node* high) {
    int pivot = high->data;
    Node* i = low->next;
    for (Node* j = low; j != high; j = j->next) {
        if (j->data < pivot) {
            swapData(i, j);
            i = i->next;
        }
    }
    swapData(i, high);
    return i;
}
void quickSort(Node* low, Node* high) {
    if (low != nullptr && high != nullptr && low != high && low->next != high) {
        Node* pivot = partition(low, high);
        quickSort(low, pivot);
        quickSort(pivot->next, high);
    }
}
void quickSortList(Node* head) {
    Node* lastNode = getLastNode(head);
    quickSort(head, lastNode);
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
    quickSortList(head);
    std::cout << "Sorted linked list: ";
    displayList(head);
    deleteList(head);
    return 0;
}
