#include <iostream>
#include <unordered_map>
int main() {
    std::unordered_map<std::string, int> unsortedMap;
    unsortedMap["one"] = 1;
    unsortedMap["three"] = 3;
    unsortedMap["two"] = 2;
    std::cout << "Unsorted Map:" << std::endl;
    for (const auto& pair : unsortedMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    return 0;
}
