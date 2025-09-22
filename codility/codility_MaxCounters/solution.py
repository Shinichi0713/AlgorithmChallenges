def solution(N, A):
    array_output = [0] * N
    max_counter = 0
    last_update = 0
    for command in A:
        if 1 <= command <= N:
            if array_output[command - 1] < last_update:
                array_output[command - 1] = last_update
            array_output[command - 1] += 1
            if array_output[command - 1] > max_counter:
                max_counter = array_output[command - 1]
        else:
            last_update = max_counter
    for i in range(0, N):
        if array_output[i] < last_update:
            array_output[i] = last_update
    return array_output