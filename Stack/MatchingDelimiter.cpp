#include <iostream>
#include <stack>
#include <string>
bool isMatched(const std::string& expression) {
    const std::string opening = "({[";
    const std::string closing = ")}]";
    std::stack<char> buffer;
    for (char c : expression) {
        if (opening.find(c) != std::string::npos) {
            buffer.push(c);
        } else if (closing.find(c) != std::string::npos) {
            if (buffer.empty()) {
                return false;
            }
            if (closing.find(c) != opening.find(buffer.top())) {
                return false;
            }
            buffer.pop();
        }
    }
    return buffer.empty();
}
int main() {
    std::string expression;
    std::cout << "Enter an expression: ";
    std::getline(std::cin, expression);
    if (isMatched(expression)) {
        std::cout << "MATCHED\n";
    } else {
        std::cout << "MISMATCHED\n";
    }
    return 0;
}
