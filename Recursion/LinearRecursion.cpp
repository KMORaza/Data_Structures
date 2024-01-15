#include <iostream>
#include <vector>
#include <functional>
int linearRecursion(int n, const std::vector<int>& coefficients, const std::vector<int>& initialValues, std::function<int(int)> F) {
    int k = coefficients.size();
    if (n < k) {
        return initialValues[n];
    }
    std::vector<int> sequence(initialValues);
    for (int i = k; i <= n; ++i) {
        int term = 0;
        for (int j = 0; j < k; ++j) {
            term += coefficients[j] * sequence[i - k + j];
        }
        term += F(i);
        sequence.push_back(term);
    }
    return sequence.back();
}
int main() {
    int k;
    std::cout << "Enter the order (k) of the linear recurrence relation: ";
    std::cin >> k;
    std::vector<int> coefficients(k);
    std::vector<int> initialValues(k);
    std::cout << "Enter the coefficients of the linear recurrence relation (c1, c2, ..., ck): ";
    for (int i = 0; i < k; ++i) {
        std::cin >> coefficients[i];
    }
    std::cout << "Enter the initial values of the sequence (a0, a1, ..., a[k-1]): ";
    for (int i = 0; i < k; ++i) {
        std::cin >> initialValues[i];
    }
    std::cout << "Enter the non-homogeneous term function F(n), e.g., n^2: ";
    std::string nonHomogeneousTerm;
    std::cin.ignore(); 
    std::getline(std::cin, nonHomogeneousTerm);
    std::function<int(int)> F = [nonHomogeneousTerm](int n) {
        size_t found = nonHomogeneousTerm.find('n');
        if (found != std::string::npos) {
            nonHomogeneousTerm.replace(found, 1, std::to_string(n));
        }
        return std::stoi(nonHomogeneousTerm);
    };
    int term;
    std::cout << "Enter the term (n) to calculate: ";
    std::cin >> term;
    int result = linearRecursion(term, coefficients, initialValues, F);
    std::cout << "The " << term << "th term is: " << result << std::endl;
    return 0;
}
