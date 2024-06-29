import unittest

# 2分け探索
def search_binary(x, n, K):
    l = 0
    r = n
    while r-l >= 1:
        i = (l + r) // 2
        if K[i] == x:
            return True
        elif K[i] < x:
            l = i + 1
        else:
            r = i
    return False

def solution(n, m, K):
    K.sort()
    result = False
    for a in K:
        for b in K:
            for c in K:
                if search_binary(m - a - b - c, n, K):
                    result = True
    return result

class TestSolution(unittest.TestCase):
    def test_1_sample(self):
        self.assertEqual(solution(3, 10, [1, 3, 5]), True)
    

unittest.main(argv=['first-arg-is-ignored'], exit=False)



