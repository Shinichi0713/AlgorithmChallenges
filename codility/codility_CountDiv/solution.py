# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A, B, K):
    return B // K - (A // K) + (1 if A % K == 0 else 0)