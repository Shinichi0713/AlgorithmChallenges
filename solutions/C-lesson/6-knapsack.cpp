#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#define MAX_N 100
#define MAX_W 100

int dp[MAX_N + 1][MAX_W + 1];
int w[MAX_N], v[MAX_W];

int rec(int i, int j, int n) {
	if (dp[i][j] >= 0) {
		return dp[i][j];
	}
	int value;
	if (i == n) {
		value = 0;
	}
	else if (j < w[i]) {
		value = rec(i + 1, j, n);
	}
	else {
		value = std::max(rec(i + 1, j, n), rec(i + 1, j - w[i], n) + v[i]);
	}

	return dp[i][j] = value;
}

void solve() {
	memset(dp, -1, sizeof(dp));
	w[0] = 2;
	w[1] = 1;
	w[2] = 3;
	w[3] = 2;
	v[0] = 3;
	v[1] = 2;
	v[2] = 4;
	v[3] = 2;

	int n = 4;
	int W = 5;
	int value = rec(0, W, n);
	printf("%d \n", value);
}
