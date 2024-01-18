#include <iostream>
#include <vector>
#include <string>
void computeLPS(const std::string& pattern, std::vector<int>& lps) {
    int patternLength = static_cast<int>(pattern.length());
    int len = 0;
    lps[0] = 0; 
    for (int i = 1; i < patternLength; ) {
        if (pattern[i] == pattern[len]) {
            ++len;
            lps[i] = len;
            ++i;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                ++i;
            }
        }
    }
}
void kmpSearch(const std::string& text, const std::string& pattern) {
    int textLength = static_cast<int>(text.length());
    int patternLength = static_cast<int>(pattern.length());
    std::vector<int> lps(patternLength, 0);
    computeLPS(pattern, lps);
    int i = 0; 
    int j = 0; 
    while (i < textLength) {
        if (pattern[j] == text[i]) {
            ++i;
            ++j;
        }
        if (j == patternLength) {
            std::cout << "Pattern found at position " << i - j << std::endl;
            j = lps[j - 1];
        } else if (i < textLength && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                ++i;
            }
        }
    }
}
int main() {
    std::string text = "ABABDABACDABABCABAB";
    std::string pattern = "ABABCABAB";
    std::cout << "Text: " << text << std::endl;
    std::cout << "Pattern: " << pattern << std::endl;
    kmpSearch(text, pattern);
    return 0;
}
