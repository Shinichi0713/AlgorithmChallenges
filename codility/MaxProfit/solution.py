def solution(A):
    if len(A) == 0:
        return 0

    max_profit = 0
    min_price = A[0]

    for price in A:
        min_price = min(min_price, price)
        max_profit = max(max_profit, price - min_price)

    return max_profit
