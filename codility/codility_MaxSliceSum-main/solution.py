# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A):
    # Implement your solution here
    if len(A) ==  0:
        return 0
    
    max_sum = -float('inf')
    summation = 0
    for i, value in enumerate(A):
        summation += value
        if summation < 0:
            summation = 0
        if max_sum < summation and summation>0:
            max_sum = summation
    if max_sum == -float('inf'):
        return max(A)
    else:
        return max_sum