// ContestChallenge.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include "DynamicsPlanning.h"
#include <algorithm> // std::min を使用するために必要
#include <vector>

using namespace std;

// std::min はテンプレート関数なので、double型を渡せばdouble型として機能します。
void find_min_two_args() {
    double a = 3.14;
    double b = 2.71;

    // std::min(a, b) の結果が最小値となる
    double min_val = std::min(a, b);

    std::cout << "引数 (" << a << ", " << b << ") の最小値は: " << min_val << std::endl;
}

void Exe1() {
    int num = 4;
    int w[4] = { 2, 2, 3, 2 }, v[4] = {3, 2, 4, 2};
    int LimitW = 5;

}

void Exe2() {
    int n = 10;
    DynamicsPlanning* dp = new DynamicsPlanning();

    dp->solveFibonacciRecursive();

}

int main()
{
    Exe2();
}