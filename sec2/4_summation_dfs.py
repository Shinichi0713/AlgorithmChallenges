
import unittest


def solution(array_input, sum_desire, cursor=0):
    if sum_desire == 0:
        return True
    if cursor >= len(array_input):
        return False
    # curosrを使う
    if solution(array_input, sum_desire - array_input[cursor], cursor + 1):
        return True
    # cursorを使わない
    if solution(array_input, sum_desire, cursor + 1):
        return True

    return False


def solution_stack(array_input, sum_desire):
    stack = [(0, sum_desire)]  # (cursor, remaining_sum)
    
    while stack:
        cursor, remaining_sum = stack.pop()
        
        if remaining_sum == 0:
            return True
        if cursor >= len(array_input):
            continue
        
        # cursorを使う場合
        stack.append((cursor + 1, remaining_sum - array_input[cursor]))
        # cursorを使わない場合
        stack.append((cursor + 1, remaining_sum))
    
    return False


class UnitTest(unittest.TestCase):
    def test_1_sample(self):
        A = [1, 2, 4, 7]
        self.assertEqual(solution(A, 13), True)

    def test_2_sample(self):
        A = [1, 2, 4, 7]
        self.assertEqual(solution(A, 15), False)

    def test_3_sample(self):
        A = [1, 2, 4, 7]
        self.assertEqual(solution_stack(A, 13), True)

    def test_4_sample(self):
        A = [1, 2, 4, 7]
        self.assertEqual(solution_stack(A, 15), False)

if __name__ == "__main__":
    unittest.main(argv=['first-arg-is-ignored'], exit=False)
