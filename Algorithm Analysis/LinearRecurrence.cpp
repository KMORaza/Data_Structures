#include <iostream>
#include <vector>
int linearRecurrence(int n, const std::vector<int>& coefficients, const std::vector<int>& initialValues, std::function<int(int)> F) {
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
// Linear recurrence relation a_n = 2 * a_{n-1} - a_{n-2} + n
int nonHomogeneousTerm(int n) {
    return n;
}
int main() {
    std::vector<int> coefficients = {2, -1}; // For a_n = 2 * a_{n-1} - a_{n-2}
    std::vector<int> initialValues = {1, 2}; // Initial values a_0 and a_1
    int n;
    std::cout << "Enter the term (n): ";
    std::cin >> n;
    int result = linearRecurrence(n, coefficients, initialValues, nonHomogeneousTerm);
    std::cout << "The " << n << "th term is: " << result << std::endl;
    return 0;
}
