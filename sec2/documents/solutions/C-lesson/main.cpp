#include <queue>
#include <stdio.h>
#include "3-maze-calculate.h"
#include "4-saruman-army.h"
#include <format>

using namespace std;
#define MAX_SIZE 100

void solution_4();

void main() {
	solution_4();
}


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
	int* arrayArranged = ArrangeArray(points, sizeof(points)/sizeof(*points));
}
