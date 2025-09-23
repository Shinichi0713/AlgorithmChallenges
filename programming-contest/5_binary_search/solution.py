

def solution(n, arr):
    arr.sort()
    for i in range(n):
        if arr[i] == i:
            return i
    return -1