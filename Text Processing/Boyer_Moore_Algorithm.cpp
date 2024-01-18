#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
const int ALPHABET_SIZE = 256;
int max(int a, int b) {
    return (a > b) ? a : b;
}
void computeBadCharShift(const std::string& pattern, std::vector<int>& badCharShift) {
    int patternLength = static_cast<int>(pattern.length());
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        badCharShift[i] = patternLength;
    }
    for (int i = 0; i < patternLength - 1; ++i) {
        badCharShift[static_cast<int>(pattern[i])] = patternLength - 1 - i;
    }
}
void computeGoodSuffixShift(const std::string& pattern, std::vector<int>& goodSuffixShift) {
    int patternLength = static_cast<int>(pattern.length());
    std::vector<int> suffixes(patternLength, 0);
    for (int i = patternLength - 2, j = 0; i >= 0; --i) {
        while (j > 0 && pattern[i] != pattern[patternLength - 1 - j]) {
            j = patternLength - 1 - suffixes[patternLength - 1 - j];
        }
        if (pattern[i] == pattern[patternLength - 1 - j]) {
            ++j;
        }
        suffixes[i] = j;
    }
    for (int i = 0; i < patternLength; ++i) {
        goodSuffixShift[i] = patternLength - suffixes[patternLength - 1];
    }
    for (int i = 0; i < patternLength - 1; ++i) {
        int j = patternLength - 1 - suffixes[i];
        if (j < i + 1 && goodSuffixShift[j] > i + 1 - j) {
            goodSuffixShift[j] = i + 1 - j;
        }
    }
}
void boyerMooreSearch(const std::string& text, const std::string& pattern) {
    int textLength = static_cast<int>(text.length());
    int patternLength = static_cast<int>(pattern.length());
    std::vector<int> badCharShift(ALPHABET_SIZE, 0);
    std::vector<int> goodSuffixShift(patternLength, 0);
    computeBadCharShift(pattern, badCharShift);
    computeGoodSuffixShift(pattern, goodSuffixShift);
    int i = 0;
    while (i <= textLength - patternLength) {
        int j = patternLength - 1;
        while (j >= 0 && pattern[j] == text[i + j]) {
            --j;
        }
        if (j < 0) {
            std::cout << "Pattern found at position " << i << std::endl;
            i += goodSuffixShift[0];
        } else {
            i += max(badCharShift[static_cast<int>(text[i + j])] - (patternLength - 1 - j),
                     goodSuffixShift[j]);
        }
    }
}
int main() {
    std::string text = "ABAAABCD";
    std::string pattern = "ABC";
    std::cout << "Text: " << text << std::endl;
    std::cout << "Pattern: " << pattern << std::endl;
    boyerMooreSearch(text, pattern);
    return 0;
}
