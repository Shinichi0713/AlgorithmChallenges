
import unittest

def solution(A):
    A.sort()
    length = 0
    for i in range(len(A) - 2):
        if A[i] + A[i + 1] > A[i + 2]:
            length = A[i] + A[i + 1] + A[i + 2]
    return length

class UnitTest(unittest.TestCase):
    def test_1_sample(self):
        A = [2,3,4,5,10]
        self.assertEqual(solution(A), 12)

    def test_2_sample(self):
        A = [2,3]
        self.assertEqual(solution(A), 0)
    
    def test_3_sample(self):
        A = [2]
        self.assertEqual(solution(A), 0)

    def test_4_sample(self):
        A = [2,3,4,5,10,11]
        self.assertEqual(solution(A), 26)



if __name__ == "__main__":
    unittest.main(argv=['first-arg-is-ignored'], exit=False)