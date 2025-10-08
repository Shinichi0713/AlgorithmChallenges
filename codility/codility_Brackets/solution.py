# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(S):
    # Implement your solution here
    stack = []
    brackets = {')': '(', '}': '{', ']': '['}

    for char in S:
        if char in brackets.values():
            stack.append(char)
        elif char in brackets:
            if not stack or stack[-1] != brackets[char]:
                return 0
            stack.pop()
    return 1 if not stack else 0