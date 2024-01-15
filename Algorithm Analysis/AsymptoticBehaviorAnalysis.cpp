#include <iostream>
#include <functional>
#include <cmath>
void analyzeFunction(std::function<double(double)> function, int inputSize) {
    for (int i = 1; i <= inputSize; ++i) {
        double input = static_cast<double>(i);
        auto start = std::chrono::high_resolution_clock::now();
        double result = function(input);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << "Input: " << input << " | Result: " << result
                  << " | Elapsed Time: " << duration.count() << " microseconds\n";
    }
}
int main() {
    std::string userInput;
    std::cout << "Enter a mathematical function (in terms of x): ";
    std::getline(std::cin, userInput);
    auto userFunction = [userInput](double x) {
        double result = std::nan("");
        try {
            result = std::stod(userInput);
        } catch (const std::invalid_argument&) {
            try {
                result = std::stod(userInput.substr(1)); 
            } catch (const std::invalid_argument&) {
                std::cerr << "Invalid function expression.\n";
            }
        }
        return result;
    };
    int maxInputSize;
    std::cout << "Enter the maximum input size: ";
    std::cin >> maxInputSize;
    analyzeFunction(userFunction, maxInputSize);
    return 0;
}
