## 最小共通部分列問題
2つの文字列{s1,s2,s3,....}, {t1,t2,t3,....}があります。これらの２つの共通部分文字列の長さを求めるプログラムを作成せよ。  
ただし、文字列{s1, s2, s3...}の部分文字列とは、{sl1, sl2, sl3...} (l1<l2<l3<....)と表すことが出来る文字列のことです。  

制約:  
- 1≦ n, m ≦1000


## Longest Common Subsequence Problem
Given two strings {s1, s2, s3,....} and {t1, t2, t3,....}, create a program to find the length of their longest common subsequence.  
A subsequence of the string {s1, s2, s3...} is a string that can be represented as {sl1, sl2, sl3...} (where l1 < l2 < l3 <....).  

Constraints:
1 ≤ n, m ≤ 1000


## code to measure duration of process

```c
#include <iostream>
#include <chrono>

// Function to find the length of the longest common subsequence
int longestCommonSubsequence(const std::string &s1, const std::string &s2) {
    int n = s1.size();
    int m = s2.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}

int main() {
    std::string s1 = "ABCBDAB";
    std::string s2 = "BDCAB";

    // Start measuring time
    auto start = std::chrono::high_resolution_clock::now();

    int length = longestCommonSubsequence(s1, s2);

    // Stop measuring time
    auto end = std::chrono::high_resolution_clock::now();

    // Calculate the duration
    std::chrono::duration<double> duration = end - start;

    std::cout << "Length of Longest Common Subsequence: " << length << std::endl;
    std::cout << "Time taken: " << duration.count() << " seconds" << std::endl;

    return 0;
}
```

