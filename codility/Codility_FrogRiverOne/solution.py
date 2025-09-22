# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")


def solution(X, A):
    # Implement your solution here
    array_shouldbe = set(range(1, X+1))
    for i in range(0, len(A)):
        array_shouldbe -= set(A[i:i+1])
        if len(array_shouldbe) == 0:
            return i
    return -1