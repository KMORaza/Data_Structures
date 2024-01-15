// Implementation for searching intersection point of two linked lists
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
int getLength(Node* head) {
    int length = 0;
    while (head != nullptr) {
        ++length;
        head = head->next;
    }
    return length;
}
Node* findIntersection(Node* list1, Node* list2) {
    int len1 = getLength(list1);
    int len2 = getLength(list2);
    while (len1 > len2) {
        list1 = list1->next;
        --len1;
    }
    while (len2 > len1) {
        list2 = list2->next;
        --len2;
    }
    while (list1 != nullptr && list2 != nullptr) {
        if (list1 == list2) {
            return list1;
        }
        list1 = list1->next;
        list2 = list2->next;
    }
    return nullptr; 
}
void deleteList(Node* head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
int main() {
    Node* head1 = nullptr;
    Node* head2 = nullptr;
    int n1, n2, commonValue;
    std::cout << "Enter the number of nodes in the first linked list: ";
    std::cin >> n1;
    for (int i = 0; i < n1; ++i) {
        int value;
        std::cout << "Enter the value for node " << i + 1 << ": ";
        std::cin >> value;
        head1 = insertAtEnd(head1, value);
    }
    std::cout << "Enter the number of common nodes: ";
    std::cin >> commonValue;
    std::cout << "Enter the number of nodes in the second linked list: ";
    std::cin >> n2;
    for (int i = 0; i < n2; ++i) {
        int value;
        std::cout << "Enter the value for node " << i + 1 << ": ";
        std::cin >> value;
        head2 = insertAtEnd(head2, value);
    }
    Node* commonNode = nullptr;
    for (int i = 0; i < commonValue; ++i) {
        int value;
        std::cout << "Enter the value for common node " << i + 1 << ": ";
        std::cin >> value;
        commonNode = insertAtEnd(commonNode, value);
    }
    Node* current1 = head1;
    while (current1->next != nullptr) {
        current1 = current1->next;
    }
    current1->next = commonNode;
    Node* current2 = head2;
    while (current2->next != nullptr) {
        current2 = current2->next;
    }
    current2->next = commonNode;
    Node* intersectionPoint = findIntersection(head1, head2);
    if (intersectionPoint != nullptr) {
        std::cout << "Intersection point value: " << intersectionPoint->data << "\n";
    } else {
        std::cout << "No intersection point exists!\n";
    }
    deleteList(head1);
    deleteList(head2);
    return 0;
}
