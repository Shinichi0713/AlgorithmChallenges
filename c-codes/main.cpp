#include <queue>
#include <stdio.h>
#include "3-maze-calculate.h"
#include "4-saruman-army.h"
#include "5-coin-pair.h"
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


void main() {
	solution_5_exception();
}