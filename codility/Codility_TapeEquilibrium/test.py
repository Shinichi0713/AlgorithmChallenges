import unittest
from solution import solution


class TestSolution(unittest.TestCase):
    def test_1_sample(self):
        self.assertEqual(solution([3,1,2,4,3]), 1)
    
    def test_2_sample(self):
        self.assertEqual(solution([-1000, 1000])  , 2000)
    
    def test_3_sample(self):
        self.assertEqual(solution([1, 3, 1])  , 3)

    def test_4_sample(self):
        self.assertEqual(solution([1]), 0)

unittest.main(argv=['first-arg-is-ignored'], exit=False)