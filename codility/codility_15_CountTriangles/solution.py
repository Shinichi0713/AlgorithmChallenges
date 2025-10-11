def solution(A):
    if len(A) < 3:
        return 0
    else:
        A.sort()
        count_triangle = 0
        for i in range(len(A) - 2):
            k = i + 2
            for j in range(i+1,len(A)-1):
                while k < len(A) and A[i] + A[j] > A[k]:
                    k += 1
            count_triangle += k - j - 1
        return count_triangle