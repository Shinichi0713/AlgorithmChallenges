#include "RxClass.h"


#include <iostream>
#include <vector>
#include <stdexcept> // 例外処理のために使用

// 構造体を定義して、演算子をオーバーロードするための準備
struct While_Loop_Wrapper {};

// 演算子 `<<` をオーバーロードし、常に true を返すようにする
// これにより、forループの条件式が常に満たされる
While_Loop_Wrapper operator<<(While_Loop_Wrapper wrapper, const char* str) {
    std::cout << str << std::endl;
    return While_Loop_Wrapper{};
}

// マクロを使って、C++のforループを「WHILE」文に見せる
#define WHILE for(While_Loop_Wrapper __while_wrapper{}; __while_wrapper << "Looping...", true; )

int RxClass::Countning() {
    int counter = 0;

    // 見た目は英語の文章だが、中身は無限ループ
    WHILE{
        if (counter >= 3) {
            break; // 意図的にループを終了
        }
        std::cout << "  Count: " << counter << std::endl;
        counter++;
    }
    std::cout << "Done." << std::endl;
    return 0;
}


using Matrix = std::vector<std::vector<int>>;

/**
 * @brief 2つの行列 (A * B) を掛け算する関数
 * * @param A 左側の行列 (m x k)
 * @param B 右側の行列 (k x n)
 * @return Matrix 結果の行列 (m x n)。掛け算不可能な場合は空の行列。
 */
Matrix multiply_matrices(const Matrix& A, const Matrix& B) {
    if (A.empty() || A[0].empty() || B.empty() || B[0].empty()) {
        throw std::invalid_argument("Input matrices cannot be empty.");
    }

    // 行列 A のサイズ: m x k
    int m = A.size();
    int k_A = A[0].size();

    // 行列 B のサイズ: k x n
    int k_B = B.size();
    int n = B[0].size();

    // 行列の掛け算の条件チェック: Aの列数 (k_A) と Bの行数 (k_B) が一致しなければならない
    if (k_A != k_B) {
        throw std::invalid_argument(
            "Matrix dimensions are incompatible for multiplication. A's columns must equal B's rows."
        );
    }

    // 結果の行列 C (m x n) を初期化
    Matrix C(m, std::vector<int>(n, 0));

    // 三重ループによる計算 (標準的な行列乗算アルゴリズム)
    // i: 行 A の行インデックス (0 から m-1)
    for (int i = 0; i < m; ++i) {
        // j: 行 B の列インデックス (0 から n-1)
        for (int j = 0; j < n; ++j) {
            // l: 共通のインデックス (0 から k-1)
            for (int l = 0; l < k_A; ++l) { // k_A == k_B
                C[i][j] += A[i][l] * B[l][j];
            }
        }
    }

    return C;
}

// 行列を出力するための補助関数
void print_matrix(const Matrix& M) {
    for (const auto& row : M) {
        for (int val : row) {
            std::cout << val << "\t";
        }
        std::cout << std::endl;
    }
}

// --- 使用例 ---
int RxClass::MultipleMatrix() {
    // 行列 A (2 x 3)
    Matrix A = {
        {1, 2, 3},
        {4, 5, 6}
    };

    // 行列 B (3 x 2)
    Matrix B = {
        {7, 8},
        {9, 10},
        {11, 12}
    };

    std::cout << "--- Matrix A (2x3) ---" << std::endl;
    print_matrix(A);
    std::cout << "--- Matrix B (3x2) ---" << std::endl;
    print_matrix(B);

    try {
        // C = A x B は 2 x 2 行列になる
        Matrix C = multiply_matrices(A, B);

        std::cout << "\n--- Result Matrix C (A x B: 2x2) ---" << std::endl;
        print_matrix(C);

        // 検算: C[0][0] = (1*7) + (2*9) + (3*11) = 7 + 18 + 33 = 58
        // 検算: C[1][1] = (4*8) + (5*10) + (6*12) = 32 + 50 + 72 = 154

    }
    catch (const std::invalid_argument& e) {
        std::cerr << "\nError: " << e.what() << std::endl;
    }

    // エラー例 (次元不一致)
    Matrix D = { {1, 2} };
    try {
        multiply_matrices(A, D); // 2x3 * 1x2 -> 不可
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "\nError during invalid multiplication: " << e.what() << std::endl;
    }

    return 0;
}



