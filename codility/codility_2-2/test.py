import unittest
from solution import solution


class TestSolution(unittest.TestCase):
    def test_1_sample(self):
        self.assertEqual(solution([9, 3, 9, 3, 9, 7, 9])  , 7)
    
    def test_2_sample(self):
        self.assertEqual(solution([9, 3, 9, 3, 9, 9])  , None)
    
    def test_3_sample(self):
        self.assertEqual(solution([1, 3, 1])  , 3)

    def test_4_sample(self):
        self.assertEqual(solution([1, 1])  , None)


unittest.main(argv=['first-arg-is-ignored'], exit=False)
