
#include <stdio.h>
#include <stdlib.h>

const int V[6] = { 500 , 100, 50, 10, 5, 1 };
void printCombination(int arr[], int data[], int start, int end, int index, int r, int target);

int* initializeArray(int initialSize) {
    int* array = (int*)malloc(initialSize * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    return array;
}

// 配列のサイズを変更する関数
int* resizeArray(int* array, int newSize) {
    array = (int*)realloc(array, newSize * sizeof(int));
    if (array == NULL) {
        printf("Memory reallocation failed\n");
        exit(1);
    }
    return array;
}

int* solution(int amountSpecified) {
    
    int* arrayOutput = initializeArray(1);

    int length = sizeof(V) / sizeof(V[0]);
    for (int i = 0; i < length; i++) {
        int number_usage = amountSpecified / V[i];
        arrayOutput = resizeArray(arrayOutput, i + 1);
        arrayOutput[i] = number_usage;
        amountSpecified -= V[i] * number_usage;
    }

	return arrayOutput;
}


// 組み合わせを見つけるためのヘルパー関数
void findCombinations(int arr[], int n, int r, int target) {
    int data[10];
    printCombination(arr, data, 0, n - 1, 0, r, target);
}

// 実際に組み合わせを生成し、条件に合うものを表示する関数
void printCombination(int arr[], int data[], int start, int end, int index, int r, int target) {
    if (index == r) {
        int sum = 0;
        for (int j = 0; j < r; j++) {
            sum += data[j];
        }
        if (sum == target) {
            for (int j = 0; j < r; j++) {
                printf("%d ", data[j]);
            }
            printf("\n");
        }
        return;
    }

    for (int i = start; i <= end && end - i + 1 >= r - index; i++) {
        data[index] = arr[i];
        printCombination(arr, data, i + 1, end, index + 1, r, target);
    }
}

// 再帰関数の定義
void findPairSpecifiedNumber(int arr[], int n, int target, int start, int currSum, int comb[], int combIndex) {
    if (currSum == target) {
        // 組み合わせが見つかった場合、表示する
        for (int i = 0; i < combIndex; i++) {
            printf("%d ", comb[i]);
            if (i < combIndex - 1) {
                printf("+ ");
            }
        }
        printf("= %d\n", target);
        return;
    }

    // 再帰的に要素を追加して組み合わせを探索する
    for (int i = start; i < n; i++) {
        if (currSum + arr[i] > target) {
            continue;
        }

        comb[combIndex] = arr[i];
        findPairSpecifiedNumber(arr, n, target, i + 1, currSum + arr[i], comb, combIndex + 1);
    }
}