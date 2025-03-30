#include <iostream>
#include <chrono>

#define MAX_N 1000
#define MAX_M 1000
int dp[MAX_M][MAX_N];	// dp

int solveBcd(char s[], char t[], int n, int m) {
	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i] == t[j]) {
				dp[i + 1][j + 1] = dp[i][j] + 1;
			}
			else {
				// comparing lager value
				dp[i + 1][j + 1] = (dp[i][j + 1]>dp[i + 1][j]? dp[i][j + 1] : dp[i + 1][j]);
			}
		}
	}
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duration = end - start;
	std::cout << "Time taken: " << duration.count() << " seconds" << std::endl;
	return dp[n][m];
}