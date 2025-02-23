#pragma once

#define MAX_ROWS 100 
#define MAX_COLS 100

void read_and_store_chars(const char* filename, char array[MAX_ROWS][MAX_COLS], int* rows, int* cols);
void display_array(char array[MAX_ROWS][MAX_COLS], int rows, int cols);

int solve(char array[MAX_ROWS][MAX_COLS]);