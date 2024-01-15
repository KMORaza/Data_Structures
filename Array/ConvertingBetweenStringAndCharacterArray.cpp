#include <iostream>
#include <cstring>
int main() {
    const int maxSize = 100;
    std::cout << "Enter a string: ";
    std::string inputString;
    std::getline(std::cin, inputString);
    char charArray[maxSize];
    std::cout << "Enter a character array: ";
    std::cin.getline(charArray, maxSize);
    const char* charPtr = inputString.c_str();
    std::string stringFromCharArray(charArray);
    std::cout << "\nString: " << inputString << std::endl;
    std::cout << "Character Array: " << charArray << std::endl;
    std::cout << "Character Array from String: " << charPtr << std::endl;
    std::cout << "String from Character Array: " << stringFromCharArray << std::endl;
    return 0;
}
