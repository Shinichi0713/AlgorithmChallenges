#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 100 
#define MAX_COLS 100

void read_and_store_chars(const char* filename, char array[MAX_ROWS][MAX_COLS], int* rows, int* cols) {
    errno_t err;
    FILE* file;
    err = fopen_s(&file, filename, "r");
    if (file == NULL) {
        perror("ファイルを開くことができませんでした");
        exit(EXIT_FAILURE);
    }

    char ch;
    *rows = 0;
    *cols = 0;
    int col = 0;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            (*rows)++;
            *cols = col;
            col = 0;
            if (*rows >= MAX_ROWS) break;
        }
        else if (ch == 'L' || ch == 'W') {
            array[*rows][col] = ch;
            col++;
            if (col >= MAX_COLS) {
                col = 0;
                (*rows)++;
                if (*rows >= MAX_ROWS) break;
            }
        }
    }

    
    fclose(file);
}

void display_array(char array[MAX_ROWS][MAX_COLS], int rows, int cols) {
    printf("\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c",array[i][j]);
        }
        printf("\n");
    }
}

void dfs(char array[MAX_ROWS][MAX_COLS],int x, int y) {
    array[x][y] = 'L';

    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            int nx = x + dx;
            int ny = y + dy;
            if (0 <= nx && nx < MAX_ROWS && 0 <= ny && ny < MAX_COLS && array[nx][ny] == 'W')
                dfs(array, nx, ny);
        }
    }
}

int solve(char array[MAX_ROWS][MAX_COLS]) {
    int count = 0;
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            if (array[i][j] == 'W') {
                dfs(array, i, j);
                count++;
            }
        }
    }
    return count;
}


