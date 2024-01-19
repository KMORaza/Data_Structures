#include <iostream>
class Object {
public:
    Object() : refCount(1) {
        std::cout << "Object created. Reference count: " << refCount << std::endl;
    }
    void addReference() {
        ++refCount;
        std::cout << "Reference added. Reference count: " << refCount << std::endl;
    }
    void releaseReference() {
        --refCount;
        std::cout << "Reference released. Reference count: " << refCount << std::endl;
        if (refCount == 0) {
            delete this;
            std::cout << "Object deleted." << std::endl;
        }
    }
private:
    ~Object() {
        std::cout << "Destructor called." << std::endl;
    }
    int refCount;
};
int main() {
    Object* obj1 = new Object();
    Object* obj2 = obj1;
    obj1->addReference();
    obj2->addReference();
    obj1->releaseReference();
    obj2->releaseReference();
    return 0;
}
