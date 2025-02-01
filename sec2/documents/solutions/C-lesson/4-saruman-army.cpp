#include<stdio.h>



// 配列を分割する関数
int partition(int* arr, int low, int high) {
    int pivot = arr[high];  // ピボットとして最後の要素を選択
    int i = low - 1;  // 小さい要素のインデックス

    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

// クイックソートのメイン関数
void quickSort(int* arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // 分割後の配列を再帰的にソート
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int* ArrangeArray(int* arrayInput, int sizeArray) {
    int* arrayOutput = { };
    quickSort(arrayInput, 0, sizeArray - 1);
    for (int i = 0; i < sizeArray; i++) {
        printf("%d\n", arrayInput[i]);
    }
    return arrayInput;
}