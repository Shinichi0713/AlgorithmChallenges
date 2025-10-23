def solution(S, P, Q):
    length = len(S)
    impact_dict = {'A': 1, 'C': 2, 'G': 3, 'T': 4}
    impacts_S = [0] * 4
    impacts = [[0]*4 for _ in range(length+1)]

    for i in range(length):
        impacts_S[impact_dict[S[i]]-1] += 1
        for j in range(4):
            impacts[i+1][j] = impacts_S[j]

    result_output = []
    for i in range(len(P)):
        for j in range(4):
            sub = impacts[P[i]][j]
            if impacts[Q[i]+1][j] - sub > 0:
                result_output.append(j+1)
                break
    return result_output

print(solution('CAGCCTA', [2, 5, 0], [4, 5, 6]))
# [2, 4, 1]