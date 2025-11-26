#include "DynamicsPlanning.h"
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
#include <iostream>
#include <cmath>
#include <windows.h> // Unix系環境でのsleep関数 (Windowsの場合は <windows.h> と Sleep() を使用)
#include <iomanip> // setw, setprecision用
#include <algorithm>
#include <functional>
#include <vector>

// 定数設定
const int WIDTH = 80;    // コンソール幅
const int HEIGHT = 24;   // コンソール高さ
const double PI = 3.14159265358979323846;
const int DURATION_SEC = 20; // 実行時間（秒）
using namespace std;
int UNCALCULATED = -1;
// 描画設定
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800;
const int CENTER_X = WINDOW_WIDTH / 2;
const int CENTER_Y = WINDOW_HEIGHT / 2;
const int NUM_CIRCLES = 30; // 描画する円の数
const float RADIUS_STEP = 15.0f; // 円の半径の増分
const float ROTATION_SPEED = 0.5f; // アニメーションのための回転速度 (度/フレーム)


int FibonacciRecursive(int n, std::vector<int>& memo) {
    // 1. メモの確認 (既に計算済みであればそれを返す)
    // memoは呼び出し元のローカル変数を参照しているため、以前の計算結果が保持されている
    if (memo[n] != UNCALCULATED) {
        return memo[n];
    }

    // 2. ベースケース
    if (n == 0) return memo[n] = 0;
    if (n == 1) return memo[n] = 1;

    // 3. 再帰的な計算とメモ化
    int result = FibonacciRecursive(n - 1, memo) + FibonacciRecursive(n - 2, memo);

    // 計算結果をテーブルに保存 (メモ化)
    memo[n] = result;

    return result;
}

int DynamicsPlanning::solveFibonacciRecursive() {
    int n = 10;

    // 【重要なポイント】
    // メモ化テーブルは main 関数のローカル変数として定義される
    // std::vector<int> は動的メモリ（ヒープ）にデータを格納しますが、
    // 変数 memo 自体はローカルスタック上の変数です。
    // サイズ n+1 で初期化し、すべてを UNCALCULATED (-1) に設定
    std::vector<int> memo(n + 1, UNCALCULATED);

    std::cout << n << "番目のフィボナッチ数: "
        << FibonacciRecursive(n, memo)
        << std::endl;

    return 0;
}

// カーソル位置を移動させる関数 (VT100エスケープシーケンス)
void set_cursor_position(int x, int y) {
    // xは列、yは行 (ターミナルによって動作が異なる場合があります)
    std::cout << "\033[" << y << ";" << x << "H";
}

// 画面をクリアする関数
void clear_screen() {
    std::cout << "\033[2J"; // 画面全体を消去
}


DynamicsPlanning::DynamicsPlanning() {
	printf("Class DynamicsPlanning\n");
}


int DynamicsPlanning::Drawing() {
    // 画面初期設定
    clear_screen();
    std::cout.flush();

    // ターミナルの中心座標
    const int center_x = WIDTH / 2;
    const int center_y = HEIGHT / 2;

    for (int t = 0; t < DURATION_SEC * 60; ++t) { // 60fps相当でループ
        // 1. 画面のクリア（前回の模様を消す）
        clear_screen();

        // 2. 幾何模様（螺旋）の描画計算
        const int num_points = 100; // 描画する点の数

        for (int i = 0; i < num_points; ++i) {
            // 時間 t に依存して角度と半径を変化させる
            double angle = (double)i * 0.1 + (double)t * 0.05;
            double radius = (double)i * 0.15;

            // 渦巻きの最大半径を制限
            if (radius > (double)min((double)center_x, (double)center_y) - 2.0) {
                radius = (double)min((double)center_x, (double)center_y) - 2.0;
            }

            // 3. 座標計算 (極座標から直交座標へ)
            int x = center_x + (int)(radius * std::cos(angle));
            int y = center_y + (int)(radius * std::sin(angle) * 0.5); // 縦方向は圧縮 (アスペクト比調整)

            // 4. コンソールへの描画
            if (x >= 1 && x <= WIDTH && y >= 1 && y <= HEIGHT) {
                set_cursor_position(x, y);

                // 時間と位置によって文字を変化させる
                char pattern_char = (char)('!' + (t + i) % 94); // ASCIIコードで文字を変化
                std::cout << pattern_char;
            }
        }

        // 5. 描画の反映と待機
        std::cout.flush(); // 出力を強制的にターミナルに反映
        Sleep(100); // 1/60秒待機 (マイクロ秒)
    }

    // 終了時のカーソル位置調整
    set_cursor_position(1, HEIGHT);
    std::cout << "\n終了しました。\n";
    return 0;
}

