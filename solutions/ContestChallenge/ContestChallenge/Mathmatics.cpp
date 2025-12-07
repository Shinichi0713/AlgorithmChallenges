#include "Mathmatics.h"
#include <iostream>
#include <cmath>
#include <functional>
#include <algorithm> // std::swap を使用
#include <random> 
#include <chrono>
#include <math.h>

// 微分したい関数 f(x) を定義

double my_function(double x) {
    // 例: f(x) = x^3 + 2x^2 + 1
    return pow(x, 3) + 2.0 * pow(x, 2) + 1.0;
}

/**
 * @brief 中心差分法を用いて関数 f(x) の x における導関数を近似する
 * * @param f 微分したい関数 (std::function<double(double)>)
 * @param x 微分係数を求めたい点
 * @param h 非常に小さな差分 (小さいほど精度が上がるが、浮動小数点誤差も増える)
 * @return double 近似された微分係数 f'(x)
 */
double numerical_derivative(std::function<double(double)> f, double x, double h = 1e-6) {
    // f'(x) ≈ (f(x + h) - f(x - h)) / (2h)
    return (f(x + h) - f(x - h)) / (2.0 * h);
}

int Mathmatics::solve() {
    double x_value = 2.0;

    // f'(x) の解析解 (3x^2 + 4x) に x=2 を代入
    // 3*(2^2) + 4*(2) = 12 + 8 = 20
    double exact_derivative = 3.0 * pow(x_value, 2) + 4.0 * x_value;

    double approx_derivative = numerical_derivative(my_function, x_value);

    std::cout << "元の関数: f(x) = x^3 + 2x^2 + 1" << std::endl;
    std::cout << "点 x = " << x_value << " における微分係数:" << std::endl;
    std::cout << "  - 理論値: " << exact_derivative << std::endl;
    std::cout << "  - 近似値: " << approx_derivative << std::endl;

    return 0;
}

// 非常に簡略化されたデュアル数（フォワードモードADの基礎）
struct DualNumber {
    double val; // 値 (f(x))
    double der; // 導関数 (f'(x))

    // コンストラクタ（xを初期化する場合、x'は1）
    DualNumber(double v, double d) : val(v), der(d) {}
};

// 演算子のオーバーロードの概念（例: 加算）
DualNumber operator+(const DualNumber& a, const DualNumber& b) {
    // (u + v)' = u' + v'
    return DualNumber(a.val + b.val, a.der + b.der);
}

// 演算子のオーバーロードの概念（例: 乗算）
DualNumber operator*(const DualNumber& a, const DualNumber& b) {
    // (u * v)' = u'v + uv' (積の微分公式)
    return DualNumber(a.val * b.val, a.val * b.der + a.der * b.val);
}

/* * 実際には、sin, cos, exp などの数学関数に対してもオーバーロードが必要です。
 */

double trapezoidal_integration(std::function<double(double)> f, double a, double b, int n = 1000) {
    if (n <= 0) return 0.0;

    double h = (b - a) / n;
    double integral = 0.0;

    // 最初の項 f(x0)
    integral += f(a) / 2.0;

    // 中間の項 2 * f(xi) の総和
    for (int i = 1; i < n; ++i) {
        double x_i = a + i * h;
        integral += f(x_i);
    }

    // 最後の項 f(xn)
    integral += f(b) / 2.0;

    // h を掛けて最終的な積分値
    return integral * h;
}

double newton_method(std::function<double(double)> f, double x0, double tolerance = 1e-6, int max_iterations = 100) {
    double x_n = x0;

    for (int i = 0; i < max_iterations; ++i) {
        double fx = f(x_n);
        // 数値微分で f'(x) を計算
        double dfx = numerical_derivative(f, x_n);

        if (std::abs(dfx) < 1e-10) {
            // 微分係数がゼロに近い場合、収束しない可能性があるため中断
            std::cerr << "警告: 微分係数がゼロに近くなりました。" << std::endl;
            break;
        }

        // ニュートン法の反復式
        double x_next = x_n - (fx / dfx);

        // 収束判定
        if (std::abs(x_next - x_n) < tolerance) {
            return x_next;
        }

        x_n = x_next;
    }

    std::cerr << "警告: 最大反復回数に達しました。" << std::endl;
    return x_n;
}


/**
 * @brief モンテカルロ法を用いて円周率 Pi の近似値を計算する
 * * @param num_trials 試行回数（発生させる乱数の点の数）
 * @return double Pi の近似値
 */
double calculate_pi_monte_carlo(long long num_trials) {

    // 乱数生成器のセットアップ
    // 実行ごとに異なる結果を得るために、現在の時間に基づいてシードを設定します。
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);

    // [-1.0, 1.0] の範囲で一様な実数を生成する分布
    std::uniform_real_distribution<double> distribution(-1.0, 1.0);

    long long points_in_circle = 0; // 円の内部に入った点の数

    // 試行回数だけループ
    for (long long i = 0; i < num_trials; ++i) {
        // x, y 座標を [-1.0, 1.0] の範囲でランダムに生成
        double x = distribution(generator);
        double y = distribution(generator);

        // 原点 (0, 0) からの距離の二乗を計算 (d^2 = x^2 + y^2)
        // 距離が 1.0 以下（r^2 = 1^2 = 1.0）であれば、円の内部に入る
        double distance_squared = x * x + y * y;

        if (distance_squared <= 1.0) {
            points_in_circle++;
        }
    }

    // Pi の近似値を計算: 4 * (円内の点 / 全試行回数)
    return 4.0 * ((double)points_in_circle / num_trials);
}

int solver() {
    // 試行回数は多いほど精度が向上する（ただし計算時間もかかる）
    const long long trials = 10000000; // 1000万回試行

    std::cout.precision(10); // 表示精度を設定

    double pi_approx = calculate_pi_monte_carlo(trials);

    std::cout << "--- モンテカルロ法による円周率の近似 ---" << std::endl;
    std::cout << "試行回数: " << trials << std::endl;
    std::cout << "近似された Pi: " << pi_approx << std::endl;

    return 0;
}