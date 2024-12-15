import unittest

# 2分け探索
def search_binary(num_desired, array_kuji):
    posi_start = 0
    posi_end = len(array_kuji) - 1
    while posi_end - posi_start >= 0:
        posi_mid = (posi_start + posi_end) // 2
        if array_kuji[posi_mid] == num_desired:
            return True
        elif array_kuji[posi_mid] < num_desired:
            posi_start = posi_mid + 1
        else:
            posi_end = posi_mid
    return False



# 4回のくじ引きで合計がsum_desiredになる組み合わせがあるかどうかを判定する
def solution(sum_desired, array_kuji):
    array_kuji.sort()
    for i in range(len(array_kuji)):
        for j in range(len(array_kuji)):
            for k in range(len(array_kuji)):
                num_desired = sum_desired - array_kuji[i] - array_kuji[j] - array_kuji[k]
                # 4回目のくじ引きが残りの合計金額になるかどうかを判定
                if search_binary(num_desired, array_kuji):
                    return True
    return False


class TestSolution(unittest.TestCase):
    def test_1_sample(self):
        self.assertEqual(solution(10, [1, 3, 5]), True)
    
    def test_2_sample(self):
        self.assertEqual(solution(5, [1]), False)

    def test_3_sample(self):
        self.assertEqual(solution(4, [1]), True)

unittest.main(argv=['first-arg-is-ignored'], exit=False)
