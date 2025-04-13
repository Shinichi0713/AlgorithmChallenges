
#define MAX_K 100
#define MAX_N 100
#include <string.h>

bool dp[MAX_N][MAX_K];

int dpHomework[MAX_K];


bool solvePartialSum(int a[], int m[], int n, int K) {
	memset(dp, false, sizeof(dp));
	dp[0][0] = true;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= K; j++) {
			for (int k = 0; k <= m[i] && k * a[i] <= j; k++) {
				dp[i + 1][j] |= dp[i][j - k * a[i]];
			}
		}
	}
	if (dp[n][K]) return true;
	else return false;
}


int solveRecurrence(int n) {
	memset(dpHomework, 0, sizeof(dpHomework));
	dpHomework[1] = 2;
	for (int i = 1; i <= 5; i++) {
		dpHomework[i + 1] = dpHomework[i] * 3 + 1;
	}

	return dpHomework[n];
}

