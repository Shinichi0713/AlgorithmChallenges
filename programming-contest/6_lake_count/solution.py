import unittest
import os, copy

# 探索の再帰関数
def solution(array_target):
    count_lake = 0
    array_count = copy.deepcopy(array_target)
    for i in range(len(array_count)):
        for j in range(len(array_count[0])):
            if array_count[i][j] == "1":
                count_lake += 1
                find_neighbor(array_count, i, j)
    return count_lake

# 再帰的に1がなくなるまで近隣探索を行う
def find_neighbor(array_target, row, col):
    for i in range(-1, 2):
        for j in range(-1, 2):
            if 0 <= row + i < len(array_target) and 0 <= col + j < len(array_target[0]):
                if array_target[row + i][col + j] == "1":
                    array_target[row + i][col + j] = "0"
                    find_neighbor(array_target, row + i, col + j)

def read_input(file_target):
    array_read = []
    with open(file_target) as f:
        text_list = f.readlines()
        text_list = [text.replace("\n", "") for text in text_list]
        for text in text_list:
            array_read.append(text.strip().split(" "))
    return array_read

class TestSolution(unittest.TestCase):
    def test_1_sample(self):
        array_read = read_input(f"{os.path.dirname(__file__)}/test.txt")
        self.assertEqual(solution(array_read), 10)
    

if __name__ == "__main__":
    # array_read = read_input(f"{os.path.dirname(__file__)}/test.txt")
    # print(solution(array_read))
    unittest.main(argv=['first-arg-is-ignored'], exit=False)