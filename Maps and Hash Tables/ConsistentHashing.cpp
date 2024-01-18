#include <iostream>
#include <map>
#include <string>
class ConsistentHashRing {
private:
    std::map<size_t, std::string> ring;
    size_t virtualNodes;
    size_t hash(const std::string& key) const {
        size_t result = 0;
        for (char c : key) {
            result = (result * 31) + static_cast<size_t>(c);
        }
        return result;
    }
public:
    ConsistentHashRing(size_t virtualNodes) : virtualNodes(virtualNodes) {}
    void addNode(const std::string& node) {
        for (size_t i = 0; i < virtualNodes; ++i) {
            size_t hashValue = hash(node + std::to_string(i));
            ring[hashValue] = node;
        }
    }
    std::string getNode(const std::string& key) const {
        if (ring.empty()) {
            return "";
        }
        size_t hashValue = hash(key);
        auto it = ring.lower_bound(hashValue);
        if (it == ring.end()) {
            return ring.begin()->second;
        }
        return it->second;
    }
};
int main() {
    ConsistentHashRing hashRing(3);
    hashRing.addNode("NodeA");
    hashRing.addNode("NodeB");
    hashRing.addNode("NodeC");
    std::cout << "Key1 is assigned to: " << hashRing.getNode("Key1") << std::endl;
    std::cout << "Key2 is assigned to: " << hashRing.getNode("Key2") << std::endl;
    std::cout << "Key3 is assigned to: " << hashRing.getNode("Key3") << std::endl;
    return 0;
}
