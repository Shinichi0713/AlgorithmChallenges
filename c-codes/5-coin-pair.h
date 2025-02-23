#pragma once

const int V[6] = { 500 , 100, 50, 10, 5, 1 };
int* solution(int amountSpecified);
int* initializeArray(int initialSize);
void findPairSpecifiedNumber(int arr[], int n, int target, int start, int currSum, int comb[], int combIndex);