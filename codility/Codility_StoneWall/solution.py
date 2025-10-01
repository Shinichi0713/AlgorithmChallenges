def solution(H):
    stack = []
    block_count = 0
    # 連続する長さを見つける
    for i in range(len(H)):
        while stack and stack[-1] > H[i]:
            stack.pop()
        if stack and stack[-1] == H[i]:
            continue
        else:
            block_count += 1
            stack.append(H[i])

    return block_count