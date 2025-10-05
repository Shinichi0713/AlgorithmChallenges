def solution(A, B):
    downstream = []
    alive_count = 0
    for i in range(len(A)):
        if B[i] == 1:
            downstream.append(A[i])
        # ではない場合、stockの中身確認
        else:
            while downstream and downstream[-1] < A[i]:
                downstream.pop()
            if not downstream:
                alive_count += 1
    alive_count += len(downstream)
    return alive_count