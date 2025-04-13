## 個数制限付き部分和問題

n種類の数a_{i}がそれぞれm_{i}個ずつあります。

これらの中からいくつか選択して、総和を丁度Kにすることが出来るか判定しなさい。

__制約__

```math
- 1 ≦ n ≦ 100
- 1 ≦ a_{i}, m_{i}} ≦ 100000
- 1≦ K ≦ 100000
```

## Problem

There are `n` types of numbers ai, each appearing mi times.

Determine if it's possible to select some of these numbers such that their total sum equals exactly K.

**Constraints**

```
- 1 ≦ n ≦ 100
- 1 ≦ a_{i}, m_{i} ≦ 100000
- 1 ≦ K ≦ 100000
```


input

```c
	int a[3] = { 3, 5, 8 };
	int m[3] = { 3, 2, 2 };
	int n = sizeof(a) / sizeof(a[0]);
	int K = 17;
```

output

```
true (can make the pair)
```
