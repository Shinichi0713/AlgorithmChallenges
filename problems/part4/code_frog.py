


def solution(X, Y, D):
    if D == 0:
        return 0
    else:
        dist = Y - X
        return ceil_up(dist, D)

def ceil_up(a, b):
    if a % b == 0:
        return a // b
    else:
        return a // b + 1


if __name__ == "__main__":
    print(solution(10, 85, 30))

