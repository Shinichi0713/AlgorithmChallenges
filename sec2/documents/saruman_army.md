## Problem

**Saruman's Army**

Saruman is preparing his army for an upcoming battle. He has a number of soldiers, each with a specific height. Saruman wants to organize his soldiers in such a way that they form the longest possible sequence of soldiers where each soldier is taller than the previous one. This sequence does not need to be contiguous.

Given an array of integers representing the heights of the soldiers, your task is to determine the length of the longest increasing subsequence.

**Input:**

* An integer `n` representing the number of soldiers.
* An array of `n` integers where each integer represents the height of a soldier.

**Output:**

* An integer representing the length of the longest increasing subsequence of soldiers' heights.


## コードの解釈

```
// 配列を分割する関数 int partition(int* arr, int low, int high) { int pivot = arr[high]; // ピボットとして最後の要素を選択 int i = low - 1; // 小さい要素のインデックス for (int j = low; j < high; ++j) { if (arr[j] < pivot) { ++i; int temp = arr[i]; arr[i] = arr[j]; arr[j] = temp; } } int temp = arr[i + 1]; arr[i + 1] = arr[high]; arr[high] = temp; return i + 1; }

```

iをインクリメント
