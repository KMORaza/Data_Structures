#include <iostream>
#include <string>
void naivePatternSearch(const std::string& text, const std::string& pattern) {
    int textLength = static_cast<int>(text.length());
    int patternLength = static_cast<int>(pattern.length());
    for (int i = 0; i <= textLength - patternLength; ++i) {
        int j;
        for (j = 0; j < patternLength; ++j) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }
        if (j == patternLength) {
            std::cout << "Pattern found at position " << i << std::endl;
        }
    }
}
int main() {
    std::string text = "AABAACAADAABAAABAA";
    std::string pattern = "AABA";
    std::cout << "Text: " << text << std::endl;
    std::cout << "Pattern: " << pattern << std::endl;
    naivePatternSearch(text, pattern);
    return 0;
}
