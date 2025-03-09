### Knapsack Problem

Given a set of items, each with a weight and a value, the objective is to determine the number of each item to include in a collection so that the total weight does not exceed a given limit and the total value is as large as possible.

In more formal terms, we are given a set of items 1,2,…,n1, 2, \ldots, n, each with a weight wiw_i and a value viv_i. The goal is to find a subset of these items such that the total weight is less than or equal to a given limit WW and the total value is maximized.

The problem can be expressed with the following equations:

Maximize:

$$
\sum_{i=1}^{n} v_i x_i
$$

Subject to:

$$
\sum_{i=1}^{n} w_i x_i \leq W
$$

Where x_i is 0 or 1, indicating whether item ii is included in the knapsack.
