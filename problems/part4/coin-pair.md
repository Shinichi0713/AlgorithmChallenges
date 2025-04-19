**問題: コイン問題**

あなたは nn 種類のコインを持っています。それぞれのコインの値段は a1,a2,…,ana_1, a_2, \dots, a_n です。コインを何枚でも使って構いませんが、合計金額を SS にする最小のコイン枚数を求めてください。

**入力例**

* コインの種類: {1, 3, 4}
* 合計金額: S=6S = 6

**出力例**

* 最小コイン数: 2 (3 + 3)

## Problem

You have nn types of coins, with values a1,a2,…,an.
You can use as many coins as you like. Determine the minimum number of coins needed to make a total amount of S.

**Input Example**

* Types of coins: {1, 3, 4}
* Total amount: S=6

**Output Example**

* Minimum number of coins: 2 (3 + 3)


## 解法について

具体的には、`dp[i][j]`は、「配列 `a`の最初の `i`個の要素を使って、合計 `j`を作れるかどうか」を表しています。この配列を用いることで、一度計算した結果を保存し、再度同じ計算を行うのを避けることで効率化しています。

以下のような役割を果たします：

1. **初期化** ：`dp[0][0] = true`では、「何も選ばずに合計0を作るのは可能」という状態を表しています。
2. **遷移** ：3重ループの中で、`dp[i+1][j]`が更新されています。`dp[i][j-k*a[i]]`の値に基づいて、`dp[i+1][j]`が導出されます。これは、「現在の値を使った場合の新しい状態」を計算するプロセスです。
3. **最終判定** ：`dp[n][K]`が `true`であれば、配列の要素で合計 `K`を作ることができるという結論になります。
