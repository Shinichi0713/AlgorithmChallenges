def solution(A):
    candidate = -1
    candidate_count = 0
    candidate_index = -1

    # Find a candidate for dominator.
    for index, value in enumerate(A):
        if candidate_count == 0:
            candidate = value
            candidate_index = index
            candidate_count += 1
        else:
            if value != candidate:
                candidate_count -= 1
            else:
                candidate_count += 1

    # Verify the candidate.
    if A.count(candidate) > len(A) // 2:
        return candidate_index
    else:
        return -1