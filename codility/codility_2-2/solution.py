def solution(A):
    # Implement your solution here
    dict_found = {}
    leng_array = len(A)

    for i in range(leng_array-1, -1, -1):
        if A[i] in dict_found.keys():
            dict_found[A[i]] += 1
        else:
            dict_found[A[i]] = 1
    
    for key, value in dict_found.items():
        if value % 2 == 1:
            return key
    return None

