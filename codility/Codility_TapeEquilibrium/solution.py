def solution(A):
    if len(A) <= 1:
        return 0
    total_sum = sum(A)
    left_sum = 0
    min_diff = float('inf')

    for i in range(len(A) - 1):
        left_sum += A[i]
        right_sum = total_sum - left_sum
        diff = abs(left_sum - right_sum)

        if diff < min_diff:
            min_diff = diff

    return min_diff


print(solution([-1000, 1000]))