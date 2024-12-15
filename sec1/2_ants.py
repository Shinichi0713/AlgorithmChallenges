import unittest

# ありの落ちるまでの時間を計測する
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
    
    def test_2_sample(self):
        self.assertEqual(solution(3, [1]), (1, 2))

    def test_3_sample(self):
        self.assertEqual(solution(20, [4,5,6]), (6, 16))
    
    def test_4_sample(self):
        self.assertEqual(solution(100, [20,40,60,80,85]), (40, 85))

unittest.main(argv=['first-arg-is-ignored'], exit=False)



