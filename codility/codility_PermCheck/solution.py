def solution(A):
    set_shouldbe = set(range(1, len(A)+1)) 
    set_diff = set_shouldbe - set(A)
    if len(set_diff) == 0:
        return 1
    else:
        return 0