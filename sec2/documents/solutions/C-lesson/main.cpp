#include <queue>
#include <stdio.h>
#include "2-lake-counting.h"

using namespace std;
#define MAX_SIZE 100

void main() {
	printf("===lake count===\n");

	char filename[] = "C:/Users/yoshinaga/Desktop/3_lake_counting.txt";
	char array[MAX_SIZE][MAX_SIZE];
	int cols, rows;

	read_and_store_chars(filename, array, &rows, &cols);
	display_array(array, rows, cols);

	int count = solve(array);
	printf("%d\n", count);
	display_array(array, rows, cols);
}
