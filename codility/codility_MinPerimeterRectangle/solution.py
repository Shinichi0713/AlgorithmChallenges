import math
import sys

def solution(N):
    # Implement your solution here
    perimeter_min = sys.maxsize
    limit = int(math.sqrt(N))
    for i in range(1, limit+1):
        if N % i == 0:
            j = N // i
            if i + j < perimeter_min:
                perimeter_min = i + j
    return 2 * perimeter_min