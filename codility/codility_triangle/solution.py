# △不等式が成立しているペアを探す
def solution(A):
    if len(A) < 3:
        return 0
    else:
        # Implement your solution here
        A.sort()
        # 3つ連なった範囲で見つかるか
        for i in range(len(A) - 2):
            if A[i]>0:
                if A[i] + A[i+1] > A[i+2]:
                    return 1
        return 0