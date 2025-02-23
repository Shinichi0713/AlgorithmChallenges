#include <stdio.h>
#include <stdlib.h>
#include <utility>
#include <queue>
#include <iostream>

#define MAX_ROWS 100
#define MAX_COLS 100
#define INF 10000000

typedef std::pair<int, int> P;
int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };

void ReadFndFtoreFile(const char* filename, char array[MAX_ROWS][MAX_COLS], int* rows, int* cols) {
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
        else if (ch == 'S' || ch == '.' || ch == '#' || ch == 'G') {
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


void DisplayArrayFile(char array[MAX_ROWS][MAX_COLS], int rows, int cols) {
    printf("\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c", array[i][j]);
        }
        printf("\n");
    }
}

P FinderCharacter(char array[MAX_ROWS][MAX_COLS], char characterTarget) {
    P positionTarget = std::make_pair(-1, -1);

    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            if (array[i][j] == characterTarget) {
                positionTarget = std::make_pair(i, j);
                break;
            }
        }
        if (positionTarget != std::make_pair(-1, -1)) break;
    }
    return positionTarget;
}

int(*MakeInf())[MAX_COLS]{
    int dx[MAX_ROWS][MAX_COLS];
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            dx[i][j] = INF;
        }
    }
    return dx;
}


// search algorithm
int Bfs(char array[MAX_ROWS][MAX_COLS], P positionStart, P positionGoal) {
    std::queue<P> quePosition;      // look around position
    int (*dist)[MAX_COLS] = MakeInf();
    quePosition.push({ positionStart.first, positionStart.second });
    dist[positionStart.first][positionStart.second] = 0;

    // キューが空になるまで
    while (quePosition.size()) {
        P p = quePosition.front(); quePosition.pop();
        if (p.first == positionGoal.first && p.second == positionGoal.second) break;
        // 4方をループ
        for (int i = 0; i < 4; i++) {
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            // 移動可能か確認
            if (0 <= nx && nx < MAX_ROWS && 0 <= ny && ny < MAX_COLS) {
                if (array[nx][ny] != '#' && dist[nx][ny] == INF && array[nx][ny] != 'ﾌ') {
                    quePosition.push(P(nx, ny));
                    dist[nx][ny] = dist[p.first][p.second] + 1;
                }
            }
        }
    }

    return dist[positionGoal.first][positionGoal.second];
}


int Solve(char array[MAX_ROWS][MAX_COLS]) {
    P positionStart = FinderCharacter(array, 'S');
    P positionGoal = FinderCharacter(array, 'G');

    int distanceGoal = Bfs(array, positionStart, positionGoal);
    return distanceGoal;
}

