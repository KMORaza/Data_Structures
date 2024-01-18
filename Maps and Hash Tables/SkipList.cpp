#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
const int MAX_LEVEL = 4;
struct Node {
    int value;
    Node** forward;
    Node(int level, int &value) : value(value) {
        forward = new Node*[level + 1];
        memset(forward, 0, sizeof(Node*) * (level + 1));
    }
    ~Node() {
        delete[] forward;
    }
};
class SkipList {
private:
    int level;
    Node* header;
public:
    SkipList();
    ~SkipList();
    int getRandomLevel();
    Node* createNode(int level, int &value);
    void insert(int &value);
    void remove(int &value);
    bool search(int &value);
    void display();
}
SkipList::SkipList() {
    level = 0;
    header = new Node(MAX_LEVEL, INT_MIN);
}
SkipList::~SkipList() {
    delete header;
}
int SkipList::getRandomLevel() {
    int lvl = 0;
    while (rand() % 2 && lvl < MAX_LEVEL)
        lvl++;
    return lvl;
}
Node* SkipList::createNode(int level, int &value) {
    return new Node(level, value);
}
void SkipList::insert(int &value) {
    Node* update[MAX_LEVEL + 1];
    memset(update, 0, sizeof(Node*) * (MAX_LEVEL + 1));
    Node* current = header;
    for (int i = level; i >= 0; i--) {
        while (current->forward[i] != nullptr && current->forward[i]->value < value) {
            current = current->forward[i];
        }
        update[i] = current;
    }
    int newLevel = getRandomLevel();
    if (newLevel > level) {
        for (int i = level + 1; i <= newLevel; i++) {
            update[i] = header;
        }
        level = newLevel;
    }
    Node* newNode = createNode(newLevel, value);
    for (int i = 0; i <= newLevel; i++) {
        newNode->forward[i] = update[i]->forward[i];
        update[i]->forward[i] = newNode;
    }
}
void SkipList::remove(int &value) {
    Node* update[MAX_LEVEL + 1];
    memset(update, 0, sizeof(Node*) * (MAX_LEVEL + 1));
    Node* current = header;
    for (int i = level; i >= 0; i--) {
        while (current->forward[i] != nullptr && current->forward[i]->value < value) {
            current = current->forward[i];
        }
        update[i] = current;
    }
    if (current->forward[0] != nullptr && current->forward[0]->value == value) {
        Node* deletedNode = current->forward[0];
        for (int i = 0; i <= level; i++) {
            if (update[i]->forward[i] != deletedNode)
                break;
            update[i]->forward[i] = deletedNode->forward[i];
        }
        delete deletedNode;
        while (level > 0 && header->forward[level] == nullptr) {
            level--;
        }
    }
}
bool SkipList::search(int &value) {
    Node* current = header;
    for (int i = level; i >= 0; i--) {
        while (current->forward[i] != nullptr && current->forward[i]->value < value) {
            current = current->forward[i];
        }
    }
    current = current->forward[0];
    return (current != nullptr && current->value == value);
}
void SkipList::display() {
    std::cout << "Skip List (level " << level << "):" << std::endl;
    for (int i = level; i >= 0; i--) {
        Node* current = header->forward[i];
        std::cout << "Level " << i << ": ";
        while (current != nullptr) {
            std::cout << current->value << " ";
            current = current->forward[i];
        }
        std::cout << std::endl;
    }
}
int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    SkipList skipList;
    int values[] = {3, 6, 7, 9, 12, 19, 17, 26, 21, 25};
    int size = sizeof(values) / sizeof(values[0]);
    for (int i = 0; i < size; i++) {
        skipList.insert(values[i]);
    }
    std::cout << "After insertion:" << std::endl;
    skipList.display();
    int searchValue = 17;
    if (skipList.search(searchValue)) {
        std::cout << searchValue << " found in the skip list." << std::endl;
    } else {
        std::cout << searchValue << " not found in the skip list." << std::endl;
    }
    int removeValue = 17;
    skipList.remove(removeValue);
    std::cout << "After removing " << removeValue << ":" << std::endl;
    skipList.display();
    return 0;
}
