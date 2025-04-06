## **Problem:**

Given integers x, d, and k, output the k-th term of a sequence defined as follows:

```
・ a_1 = x
・ a_n = a_{n-1} + d (n ≧ 2)
```

#### **Hint:**

You can find the answer using the arithmetic sequence formula instead of dynamic programming (DP), but as practice, try solving it with DP. To approach DP problems, start by thinking about the recurrence relation. The recurrence relation here is an=an−1+da_n = a_{n-1} + d. Use this formula to calculate each term step by step until you reach aka_k.

#### input

```
0 7 9
```

#### output

```
56
```
