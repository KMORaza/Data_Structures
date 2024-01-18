#include <iostream>
#include <map>
int main() {
    std::map<std::string, int> sortedMap;
    sortedMap["one"] = 1;
    sortedMap["three"] = 3;
    sortedMap["two"] = 2;
    std::cout << "Sorted Map:" << std::endl;
    for (const auto& pair : sortedMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    return 0;
}
