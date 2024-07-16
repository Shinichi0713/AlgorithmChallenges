import unittest
import os

dir_current = os.path.dirname(__file__)

# 池カウント
def solution(C, price):
    payment = [0 for i in range(len(C))]
    coins = [1, 5, 10, 50, 100, 500]
    for i in range(len(C)-1, 0, -1):
        payment[i] = min(price // coins[i], C[i])
        price -= payment[i] * coins[i]
    if price != 0:
        return None
    else:
        return sum(payment)


class TestSolution(unittest.TestCase):
    def test_1(self):
        self.assertEqual(solution([0,0,0,0,0,0], 400), None)
    
    def test_2(self):
        self.assertEqual(solution([20,20,20,20,20,2], 1000), 2)

    def test_3(self):
        self.assertEqual(solution([20,20,20,20,20,1], 1000), 6)

unittest.main(argv=['first-arg-is-ignored'], exit=False)