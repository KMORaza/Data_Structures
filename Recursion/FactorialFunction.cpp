#include <iostream>
unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return static_cast<unsigned long long>(n) * factorial(n - 1);
    }
}
int main() {
    int number;
    std::cout << "Enter a non-negative integer: ";
    std::cin >> number;
    if (number < 0) {
        std::cerr << "Please enter a non-negative integer.\n";
        return 1; 
    }
    unsigned long long result = factorial(number);
    std::cout << "Factorial of " << number << " is: " << result << std::endl;
    return 0;
}
