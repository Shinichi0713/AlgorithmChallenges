import math

def solution(N):
    count_split = 0
    for num in range(1, int(math.sqrt(N)) + 1):
        if N % num == 0:
            # If divisors are equal, count only one
            if N / num == num:
                count_split += 1
            else: # Otherwise count both
                count_split += 2
    return count_split