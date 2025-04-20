## 問題

次のコードに追加し、**“**12**”**と表示されるプログラムを完成させなさい**。**

ただし、変数 x に数値 12 を直接代入するのではなく、ポインタ変数 p を使用して x の値を 12 にすること**。**

```C
int     x;
int*    p;

// xの値を12にする

printf( "%d\n", x );
```

## 問題

次のコードに追加し、**‘**h**’**と**‘**w**’**を大文字にすることにより、**“**Hello World**”**と表示されるプログラムを完成させなさい**。**

ただし、配列の添え字を使用しないこと**。**（ str[0] = 'H';と書いてはいけない）

| ※ | **‘**h**’**は 0 番目、**‘**w**’**は 6 番目の文字であることを利用してよい**。** |
| -- | ---------------------------------------------------------------------------------------------------------------- |

```C
char　str[] = "hello world";

// 'h'と'w'を大文字にする

printf( "%s\n", str );
```

## 問題

次のプログラムを作成しなさい**。**

* 10 個の数値を入力する**。**
* 入力された順番と逆の順番で 10 個の数値を表示する**。**

ただし、配列の添え字を使用しないこと**。**

## Problem

Add to the following code to complete a program that displays  **"12"** .

However, instead of directly assigning the value **12** to the variable `x`, use a pointer variable `p` to set the value of `x` to  **12** .

C

```
int     x;
int*    p;

// Set the value of x to 12

printf( "%d\n", x );
```

## Problem

Add to the following code to complete a program that displays **"Hello World"** by converting **'h'** and **'w'** to uppercase.

However, do not use array indices. (You cannot write `str[0] = 'H';`)

| Note | You may use the fact that**'h'**is the 0th character and**'w'**is the 6th character. |
| ---- | ------------------------------------------------------------------------------------------ |

C

```
char str[] = "hello world";

// Convert 'h' and 'w' to uppercase

printf( "%s\n", str );
```

## Problem

Create a program as follows:

* Input 10 numbers.
* Display the 10 numbers in reverse order of input.

However, do not use array indices.


## メモ

ポインタとは、プログラミングにおいて**メモリ上の特定の場所（アドレス）を指し示す変数**のことです。ポインタを使うことで、変数や配列、関数などのデータを効率的に操作することができます。

* **アドレスの取得** : `&` 演算子を使って変数のアドレスを取得します。
* **ポインタ変数の宣言** : `*` を使ってポインタ変数を宣言します。
* **間接参照** : `*` を使ってポインタが指し示すアドレスの値を操作します。

```C
int x = 10;      // 変数 x を宣言し、値 10 を代入
int *p = &x;     // ポインタ p に x のアドレスを代入
*p = 20;         // ポインタを使って x の値を変更
printf("%d\n", x); // x の値を表示（結果は 20）
```
