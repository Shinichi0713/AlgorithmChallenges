import unittest

# 三角形の条件を満たす最大の周の長さを返す
def solution(A):
    length = 0
    A.sort()

    for i in range(len(A) - 2):
        if A[i] + A[i+1] > A[i+2]:
            length = A[i] + A[i+1] + A[i+2]
    return length



class TestSolution(unittest.TestCase):
    def test_1_sample(self):
        self.assertEqual(solution([2, 3, 4, 5, 10]), 12)
    

unittest.main(argv=['first-arg-is-ignored'], exit=False)



