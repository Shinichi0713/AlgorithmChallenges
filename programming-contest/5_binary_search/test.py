import unittest
from solution import solution

class TestSolution(unittest.TestCase):
    def test_1_sample(self):
        arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
        self.assertEqual(arr, 5)
    
    def test_2_sample(self):
        arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
        self.assertEqual(arr, 11)
    

unittest.main(argv=['first-arg-is-ignored'], exit=False)