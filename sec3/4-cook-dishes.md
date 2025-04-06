### 問題文

高橋君は料理 1 から N の N 品の料理を作ろうとしています。

料理 i**i** はオーブンを連続した Ti 分間使うことで作れます。1 つのオーブンを 2 つ以上の料理のために同時に使うことはできません。

2 つのオーブンを使えるとき、N 品の料理を全て作るまでに最短で何分かかりますか？　なお、オーブンを使う時間以外は無視できるものとします。

### 制約

* 1≤N≤100
* 1≤Ti≤103
* 入力に含まれる値は全て整数である

---

### 入力

入力は以下の形式で標準入力から与えられる。

<pre><var><span><span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mi>N</mi></mrow></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut"></span><span class="mord mathnormal">N</span></span></span></span></span></var>
<var><span><span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><msub><mi>T</mi><mn>1</mn></msub></mrow></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut"></span><span class="mord"><span class="mord mathnormal">T</span><span class="msupsub"><span class="vlist-t vlist-t2"><span class="vlist-r"><span class="vlist"><span class=""><span class="pstrut"></span><span class="sizing reset-size6 size3 mtight"><span class="mord mtight">1</span></span></span></span><span class="vlist-s"></span></span><span class="vlist-r"><span class="vlist"><span class=""></span></span></span></span></span></span></span></span></span></span></var><var><span><span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mo>…</mo></mrow></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut"></span><span class="minner">…</span></span></span></span></span></var><var><span><span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><msub><mi>T</mi><mi>N</mi></msub></mrow></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut"></span><span class="mord"><span class="mord mathnormal">T</span><span class="msupsub"><span class="vlist-t vlist-t2"><span class="vlist-r"><span class="vlist"><span class=""><span class="pstrut"></span><span class="sizing reset-size6 size3 mtight"><span class="mord mathnormal mtight">N</span></span></span></span><span class="vlist-s"></span></span><span class="vlist-r"><span class="vlist"><span class=""></span></span></span></span></span></span></span></span></span></span></var>
</pre>

### 出力

答えを出力せよ。

---

### 入力例 1

```
5
8 3 7 2 5
```

### 出力例 1

```
13
```

例えば 2**2** つのオーブンを次のように使うことで、13**1**3 分で全ての料理を作ることができます。

* 1**1** つ目のオーブン：料理 5,1**5**,**1** を順に作る。
* 2**2** つ目のオーブン：料理 2,4,3**2**,**4**,**3** を順に作る。

---

### 入力例 2

```
2
1000 1
```

### 出力例 2

```
1000
```

---

### 入力例 3

```
9
3 14 15 9 26 5 35 89 79
```

### 出力例 3

```
138
```



## **Problem:**

Takahashi plans to cook a total of **N dishes** numbered  **1 to N** .
Dish **i** requires an oven to be used continuously for **T_i minutes** to prepare it.
The oven cannot be used for more than one dish at the same time.

If there are **two ovens** available, what is the minimum time required to cook all  **N dishes** ? Assume that all other times except oven usage are negligible.

**Constraints:**

* 1≤N≤1001
* 1≤Ti≤1031
* All input values are integers.

**Input Format:**
The input is provided as follows:

NT1T2…TNN


**Output Format:**
Output the answer.

**Example Input 1:**

```
5  
8 3 7 2 5  
```

**Example Output 1:**

```
13  
```

For instance, two ovens can be used as follows to complete all cooking in  **13 minutes** :

* **Oven 1:** Cook dishes **5, 1** in sequence.
* **Oven 2:** Cook dishes **2, 4, 3** in sequence.

**Example Input 2:**

```
2  
1000 1  
```

**Example Output 2:**

```
1000  
```

**Example Input 3:**

```
9  
3 14 15 9 26 5 35 89 79  
```

**Example Output 3:**

```
138  
```
