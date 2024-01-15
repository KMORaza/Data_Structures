// Flavius Josephus Problem
#include <iostream>
struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};
Node* createCircularList(int n) {
    if (n <= 0) {
        return nullptr;
    }
    Node* head = new Node(1);
    Node* current = head;
    for (int i = 2; i <= n; ++i) {
        current->next = new Node(i);
        current = current->next;
    }
    current->next = head;
    return head;
}
int josephusProblem(Node*& head, int k) {
    if (head == nullptr || k <= 0) {
        return -1; 
    }
    Node* current = head;
    Node* prev = nullptr;
    while (current->next != head) {
        prev = current;
        current = current->next;
    }
    while (current->next != current) {
        for (int i = 1; i < k; ++i) {
            prev = current;
            current = current->next;
        }
        prev->next = current->next;
        delete current;
        current = prev->next;
    }
    int survivor = current->data;
    delete current;
    head = nullptr; 
    return survivor;
}
int main() {
    int n, k;
    std::cout << "Enter the number of people: ";
    std::cin >> n;
    std::cout << "Enter the elimination step (k): ";
    std::cin >> k;
    Node* head = createCircularList(n);
    std::cout << "Initial circle of people:\n";
    Node* current = head;
    do {
        std::cout << current->data << " ";
        current = current->next;
    } while (current != head);
    std::cout << std::endl;
    int survivor = josephusProblem(head, k);

    if (survivor != -1) {
        std::cout << "The survivor in the Flavius Josephus problem is person " << survivor << "\n";
    } else {
        std::cout << "Invalid input for the Flavius Josephus problem.\n";
    }
    return 0;
}
