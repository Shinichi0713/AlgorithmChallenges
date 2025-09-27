import unittest
from solution import solution

class TestSolution(unittest.TestCase):
    def test_1_sample(self):
        self.assertEqual(solution([23171, 21011, 21123, 21366, 21013, 21367]), 356)
    
    def test_2_sample(self):
        self.assertEqual(solution([9, 3, 9, 3, 9, 9])  , 6)
    
    def test_3_sample(self):
        self.assertEqual(solution([1, 3, 1])  , 2)

    def test_4_sample(self):
        self.assertEqual(solution([1, 1])  , 0)

    def test_3_sample(self):
        self.assertEqual(solution([9, 8, 7, 5])  , 2)



unittest.main(argv=['first-arg-is-ignored'], exit=False)