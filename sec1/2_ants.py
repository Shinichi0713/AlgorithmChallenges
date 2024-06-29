import unittest

# 三角形の条件を満たす最大の周の長さを返す
def solution(L, X):
    n = len(X)
    Lmin = 0
    Lmax = 0
    # 最小時間
    for i in range(n):
        Lmin = max(Lmin, min(X[i], L - X[i]))

    # 最大時間
    for i in range(n):
        Lmax = max(Lmax, max(X[i], L - X[i]))
    
    return Lmin, Lmax

class TestSolution(unittest.TestCase):
    def test_1_sample(self):
        self.assertEqual(solution(10, [2, 6, 7]), (4, 8))
    

unittest.main(argv=['first-arg-is-ignored'], exit=False)



