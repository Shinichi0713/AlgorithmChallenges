#include <stdio.h>

int solveRcurrence(int x, int d, int k) {
    
    // 配列を使用してDPで数列を計算
    int dp[100]; // 配列を確保
    dp[1] = x;     // 初項を設定

    for (int i = 2; i <= k; i++) {
        dp[i] = dp[i - 1] + d; // 漸化式を適用
    }
    return dp[k];
}


bool checkPrimenumber(int numberTarget) {
    int countDivide = 0;
    for (int i = 2; i < numberTarget; i++) {
        if (numberTarget % i == 0) {
            countDivide++;
        }
    }

    if (countDivide == 0) return true;
    else return false;
}

void checkPrimeFactors(int numberTarget) {
    int limitUpper = numberTarget / 2;
    for (int i = 2; i <= limitUpper; i++) {
        if (checkPrimenumber(i)) {
            while (numberTarget % i == 0) {
                numberTarget = numberTarget / i;
                printf("%d\t", i);
            }
        }
    }
    printf("\n");
}



