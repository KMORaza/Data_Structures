#include <iostream>
#include <vector>
#include <algorithm>
class Object;
class GarbageCollector {
public:
    void allocate(Object* obj) {
        allocatedObjects.push_back(obj);
    }
    void mark(Object* root) {
        std::cout << "Marking phase..." << std::endl;
        markRecursive(root);
    }
    void sweep() {
        std::cout << "Sweeping phase..." << std::endl;
        sweepUnused();
    }
private:
    class Object {
    public:
        Object() : marked(false) {}
        void mark() {
            marked = true;
        }
        void unmark() {
            marked = false;
        }
        bool isMarked() const {
            return marked;
        }
    private:
        bool marked;
    };
    std::vector<Object*> allocatedObjects;
    void markRecursive(Object* obj) {
        if (obj && !obj->isMarked()) {
            obj->mark();
            for (Object* reference : referencesTo(obj)) {
                markRecursive(reference);
            }
        }
    }
    std::vector<Object*> referencesTo(Object* obj) const {
        std::vector<Object*> references;
        for (Object* allocatedObj : allocatedObjects) {
            if (allocatedObj != obj && (rand() % 2 == 0)) {
                references.push_back(allocatedObj);
            }
        }
        return references;
    }
    void sweepUnused() {
        auto markPredicate = [](const Object* obj) { return obj->isMarked(); };
        allocatedObjects.erase(
            std::remove_if(allocatedObjects.begin(), allocatedObjects.end(), markPredicate),
            allocatedObjects.end());
        for (Object* obj : allocatedObjects) {
            obj->unmark();
        }
    }
};
int main() {
    GarbageCollector gc;
    GarbageCollector::Object* obj1 = new GarbageCollector::Object();
    GarbageCollector::Object* obj2 = new GarbageCollector::Object();
    GarbageCollector::Object* obj3 = new GarbageCollector::Object();
    gc.allocate(obj1);
    gc.allocate(obj2);
    gc.allocate(obj3);
    gc.mark(obj1);
    gc.sweep();
    delete obj1;
    delete obj2;
    delete obj3;
    return 0;
}
