def solution(S):
    # Implement your solution here
    stack = []
    for symbol in S:
        if symbol == "(":
            stack.append(symbol)
        else:
            if not stack:
                return 0
            if symbol == ")":
                stack.pop()
    if not stack:
        return 1
    else:
        return 0