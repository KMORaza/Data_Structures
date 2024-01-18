#include <iostream>
#include <vector>
int lcsLength(const std::string& str1, const std::string& str2) {
    int m = str1.length();
    int n = str2.length();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}
std::string lcs(const std::string& str1, const std::string& str2) {
    int m = str1.length();
    int n = str2.length();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int len = dp[m][n];
    std::string result(len, ' ');
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            result[len - 1] = str1[i - 1];
            --i;
            --j;
            --len;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            --i;
        } else {
            --j;
        }
    }
    return result;
}
int main() {
    std::string str1 = "ABCBDAB";
    std::string str2 = "BDCAB";
    std::cout << "String 1: " << str1 << std::endl;
    std::cout << "String 2: " << str2 << std::endl;
    int length = lcsLength(str1, str2);
    std::cout << "Length of LCS: " << length << std::endl;
    std::string result = lcs(str1, str2);
    std::cout << "LCS: " << result << std::endl;
    return 0;
}
