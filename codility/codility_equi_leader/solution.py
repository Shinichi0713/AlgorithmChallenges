def solution(A):
    leader = -1
    leader_count = 0
    stack = []

    # find leader
    for value in A:
        if len(stack) == 0:
            stack.append(value)
        elif value != stack[-1]:
            stack.pop()
        else:
            stack.append(value)
    if len(stack) > 0:
        candidate = stack[0]
        count = A.count(candidate)
        if count > len(A) // 2:
            leader = candidate
            leader_count = count
    # Count the number of equi leaders
    equi_leaders = 0
    left_leader_count = 0
    for index, value in enumerate(A):
        if value == leader:
            left_leader_count += 1
        if left_leader_count > (index + 1) // 2 and leader_count - left_leader_count > (len(A) - index - 1) // 2:
            equi_leaders += 1
    return equi_leaders