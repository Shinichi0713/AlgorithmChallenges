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






// 行列 A と B の積を計算し、結果を C に格納する関数
// A: M x K 行列, B: K x N 行列, C: M x N 行列
void multiplyMatrices(const std::vector<std::vector<int>>& A,
    const std::vector<std::vector<int>>& B,
    std::vector<std::vector<int>>& C) {
    int M = A.size();
    if (M == 0) return;
    int K = A[0].size();
    if (K == 0) return;
    int N = B[0].size();
    if (N == 0) return;

    // 行列 C のサイズが正しいことを確認し、0で初期化
    C.resize(M, std::vector<int>(N, 0));

    // 行列積の計算メインループ
    for (int i = 0; i < M; ++i) { // Aの行
        for (int j = 0; j < N; ++j) { // Bの列
            for (int k = 0; k < K; ++k) { // Aの列/Bの行
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// 行列を表示する関数
void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int element : row) {
            // 要素を見やすく表示
            std::cout << std::setw(4) << element << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    // 例として 2x3 行列 A と 3x2 行列 B を定義
    // 積 C は 2x2 行列になります
    std::vector<std::vector<int>> A = {
        {1, 2, 3},
        {4, 5, 6}
    };

    std::vector<std::vector<int>> B = {
        {7, 8},
        {9, 10},
        {11, 12}
    };

    std::vector<std::vector<int>> C; // 結果を格納する行列

    // 行列積の計算を実行
    multiplyMatrices(A, B, C);

    // 結果の表示
    std::cout << "Matrix A:" << std::endl;
    printMatrix(A);
    std::cout << "\nMatrix B:" << std::endl;
    printMatrix(B);
    std::cout << "\nResult Matrix C (A * B):" << std::endl;
    printMatrix(C);

    return 0;
}



// グラフを隣接リストで表現
// Graph[i] は頂点 i から到達可能な頂点のリスト（vector）を保持する
using Graph = std::vector<std::vector<int>>;

// 頂点数 V と辺数 E を入力としてグラフを構築する関数
Graph createGraph(int V, int E) {
    Graph G(V);
    std::cout << "辺の情報を入力してください (例: 0 1, 0 2):" << std::endl;
    for (int i = 0; i < E; ++i) {
        int u, v;
        std::cin >> u >> v;
        // 無向グラフなので、両方の頂点に辺を追加
        G[u].push_back(v);
        G[v].push_back(u);
    }
    return G;
}

std::vector<bool> visited_dfs; // DFS用の訪問済みフラグ（グローバルまたはクラスメンバとして定義）

void dfs(const Graph& G, int v) {
    visited_dfs[v] = true;
    std::cout << v << " ";

    // 隣接する頂点を再帰的に探索
    for (int neighbor : G[v]) {
        if (!visited_dfs[neighbor]) {
            dfs(G, neighbor);
        }
    }
}

void run_dfs(const Graph& G, int start_node) {
    visited_dfs.assign(G.size(), false);
    std::cout << "DFS 探索順序: ";
    dfs(G, start_node);
    std::cout << std::endl;
}


// 行列（二次元vector）の型エイリアス
using Matrix = std::vector<std::vector<double>>;

/**
 * LU分解を実行する関数。
 *
 * @param A 入力行列。分解後、L（下三角）とU（上三角）の要素がAに上書きされる。
 */
void luDecomposition(Matrix& A) {
    int n = A.size();
    if (n == 0) return;
    int m = A[0].size();
    if (n != m) {
        throw std::runtime_error("Input matrix must be square.");
    }

    for (int k = 0; k < n; ++k) {
        // 対角要素がゼロの場合、数値的な問題が発生する（ピボット選択が必要）
        if (std::abs(A[k][k]) < 1e-12) {
            throw std::runtime_error("Pivot element is zero or near zero. Cannot proceed without pivoting.");
        }

        // 行 k より下の行に対して反復処理
        for (int i = k + 1; i < n; ++i) {
            // 乗数 (multiplier) L[i][k] を計算
            A[i][k] /= A[k][k];

            // 行 i の残りの要素から、行 k の要素を引く
            for (int j = k + 1; j < n; ++j) {
                A[i][j] -= A[i][k] * A[k][j];
            }
        }
    }
    // 分解後、Aの左下（対角要素含まず）がL、右上（対角要素含む）がUとなる。
    // Lの対角要素は全て1とみなす。
}

// 行列を表示するユーティリティ関数
void printMatrix(const Matrix& mat) {
    for (const auto& row : mat) {
        for (double val : row) {
            std::cout << std::setw(10) << std::fixed << std::setprecision(4) << val << " ";
        }
        std::cout << std::endl;
    }
}

int CalcMat() {
    // 例となる正方行列 A (3x3)
    // 
    // A = [ 2,  1,  1 ]
    //     [ 4, -2,  3 ]
    //     [ 2,  5,  2 ]
    // 
    Matrix A = {
        {2.0, 1.0, 1.0},
        {4.0, -2.0, 3.0},
        {2.0, 5.0, 2.0}
    };

    std::cout << "Original Matrix A:" << std::endl;
    printMatrix(A);
    std::cout << std::endl;

    try {
        // LU分解を実行
        luDecomposition(A);

        std::cout << "Matrix after LU Decomposition (L and U combined):" << std::endl;
        printMatrix(A);
        std::cout << std::endl;

        // L行列とU行列の抽出（表示目的）
        Matrix L(3, std::vector<double>(3, 0.0));
        Matrix U(3, std::vector<double>(3, 0.0));

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (i > j) {
                    L[i][j] = A[i][j];
                }
                else if (i == j) {
                    L[i][j] = 1.0; // Lの対角要素は常に1
                    U[i][j] = A[i][j];
                }
                else {
                    U[i][j] = A[i][j];
                }
            }
        }

        std::cout << "L Matrix (Lower Triangular):" << std::endl;
        printMatrix(L);
        std::cout << std::endl;

        std::cout << "U Matrix (Upper Triangular):" << std::endl;
        printMatrix(U);
        std::cout << std::endl;

    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}



