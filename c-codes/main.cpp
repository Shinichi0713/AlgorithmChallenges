#include <queue>
#include <stdio.h>
#include "3-maze-calculate.h"
#include "4-saruman-army.h"
#include "5-coin-pair.h"
#include "6-knapsack.h"
#include "7-LCS-search.h"
#include "8-recursive-relation.h"
#include <format>

using namespace std;
#define MAX_SIZE 100



void solution_3() {
	printf("===maze search===\n");
	char filename[] = "./data/input_maze.txt";
	char array[MAX_SIZE][MAX_SIZE];
	int cols, rows;

	ReadFndFtoreFile(filename, array, &rows, &cols);
	DisplayArrayFile(array, rows, cols);

	int count = Solve(array);
	printf("shortest cost %d", count);
}

void solution_4() {
	printf("===saluman's army===\n");
	int points[] = { 15, 20, 7, 1, 50, 30 };
	int radiousValid = 6;
	int* arrayArranged = ArrangeArray(points, sizeof(points)/sizeof(*points));
	int countSign = solve(arrayArranged, sizeof(points) / sizeof(*points), radiousValid);

	printf("answer of sign number:%d\n", countSign);
}


void solution_5() {
	printf("===coin pair===\n");
	int amountSpecified = 650;
	printf("specified amount: %d\n", amountSpecified);
	int* pairCoin = solution(amountSpecified);
	int length = sizeof(V) / sizeof(V[0]);
	for (int i = 0; i < length; i++) {
		printf("%d : %d\n", V[i], pairCoin[i]);
	}
}


void solution_5_exception() {
	printf("===find pairs===\n");
	
	int arr[] = { 2, 4, 6, 8 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int target = 10;
	printf("target number: %d\n", target);
	int comb[4]; // 現在の組み合わせを格納するための配列
	findPairSpecifiedNumber(arr, n, target, 0, 0, comb, 0);
}

void solution_6_knapsack() {
	printf("===knapsack problem===\n");
	int w[4], v[4];
	w[0] = 2;
	w[1] = 1;
	w[2] = 3;
	w[3] = 2;
	v[0] = 3;
	v[1] = 2;
	v[2] = 4;
	v[3] = 2;
	int n = sizeof(w) / sizeof(w[0]);
	int W = 5;
	int value = solve(w, v, W, n);
	printf("best value: %d \n", value);
}

void solution_7_lcs() {
	int numInput = 6;
	bool result = isPrimenumber(numInput);
	const char* boolStr = result ? "true" : "false";
	printf("result : %s\n", boolStr);

	printf("===LCS problem===\n");
	char s[] = "apple";
	char t[] = "pile";
	int n = sizeof(s) / sizeof(s[0]);
	int m = sizeof(t) / sizeof(t[0]);
	int bcd = solveBcd(s, t, n, m);
	printf("LCB value: %d \n", bcd);
}

void solution_8_recurrence() {
	checkPrimeFactors(100);

	int x, d, k;
	// x, d, k の値を入力
	scanf_s("%d %d %d", &x, &d, &k);
	int ans = solveRcurrence(x, d, k);
	printf("ans:%d\n", ans);
}

void main() {
	solution_8_recurrence();
}