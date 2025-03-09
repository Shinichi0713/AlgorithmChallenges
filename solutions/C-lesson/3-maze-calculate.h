#pragma once
#define MAX_ROWS 100 
#define MAX_COLS 100

void ReadFndFtoreFile(const char* filename, char array[MAX_ROWS][MAX_COLS], int* rows, int* cols);
void DisplayArrayFile(char array[MAX_ROWS][MAX_COLS], int rows, int cols);
int Solve(char array[MAX_ROWS][MAX_COLS]);


