# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A):
    if len(A) < 3:
        return 0
    else:
        abses_A = [abs(num) for num in A]
        index_A = range(len(A))
        group_A = list(zip(A, index_A, abses_A))
        # ソート
        group_A_sorted = sorted(group_A, key=lambda x: x[2])
        # マイナス2個,プラス1個
        num_pulus = [num[0] for num in group_A_sorted if num[0]>0]
        num_minous = [num[0] for num in group_A_sorted if num[0]<0]

        candidates_max = []
        if len(num_minous) > 1 and len(num_pulus) > 0:
            num1, num2 = num_minous[-1], num_minous[-2]
            num3 = num_pulus[-1]
            candidates_max.append(num1 * num2 * num3)
        # 全部プラス
        if len(num_pulus) > 2:
            num1, num2, num3 = num_pulus[-1], num_pulus[-2], num_pulus[-3]
            candidates_max.append(num1 * num2 * num3)
        # 全部マイナス
        if len(num_minous) > 2:
            # かけたらマイナスなので0あれば優先的に
            if 0 in [num[0] for num in group_A]:
                candidates_max.append(0)
            else:
                num1, num2, num3 = num_minous[0], num_minous[1], num_minous[2]
                candidates_max.append(num1 * num2 * num3)
        if len(candidates_max) > 0:
            return max(candidates_max)
        else:
            return 0