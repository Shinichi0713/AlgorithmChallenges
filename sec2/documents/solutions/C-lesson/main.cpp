#include <queue>
#include <stdio.h>
#include "3-maze-calculate.h"
#include <format>

using namespace std;
#define MAX_SIZE 100

void main() {
	printf("===maze search===\n");
	char filename[] = "./data/input_maze.txt";
	char array[MAX_SIZE][MAX_SIZE];
	int cols, rows;

	ReadFndFtoreFile(filename, array, &rows, &cols);
	DisplayArrayFile(array, rows, cols);

	int count = Solve(array);
	printf("shortest cost %d", count);
}
